#include "pch.h"
#include "CS.h"
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <ctime>




CS::CS(int e, int p, std::list<EV> evList) : n{ static_cast<int>(evList.size()) }, evList{ evList }, evCapacity{ e }, pwCapacity{ p }, Y(evList.size(), std::vector<double>(TL, 0))
{
	if (e <= 0 || p <= 0)
	{
		throw std::string{ "bad object" };
	}
}

CS::CS(int e, int p, int n) : n{ n }, evCapacity { e }, pwCapacity{ p }, Y(n, std::vector<double>(TL, 0))
{
	if (e <= 0 || p <= 0)
	{
		throw std::string{ "bad object" };
	}

	evList = evGenerator(n);
}

std::list<std::list<EV>> CS::convertEvListToMatrix(const std::list<EV>& allEvs)
{
	std::list<std::list<EV>> allEvsMatrix_(TL);
	
	for (const auto& ev : allEvs)
	{
		auto it = allEvsMatrix_.begin();
		std::advance(it, ev.arrival);
		(*it).insert((*it).end(), ev);
	}
	return allEvsMatrix_;
}

void CS::WFAIR(slot t)
{
	//std::cout << "==============Time slot " << t << std::endl;
	if (t > TL - 1 || t < 0)
	{
		throw std::string{"invalid time slot"};
	}

	double yTotal = 0;				//remaining power capacity at slot t	
	std::for_each(evList.begin(), evList.end(), [&yTotal, t](const EV& ev)
	{
		yTotal += ev.y[t];
	});
	while (yTotal < pwCapacity-0.01)
	{		
		std::list<EV*> curEvs;		//list of active EVs at time slot t	
		for (auto& ev : evList)
		{
			if (ev.isActive(t) && ev.y[t] < ev.maxRate)
			{
				curEvs.insert(curEvs.end(), &ev);				
			}
		}
		//std::cout << "curEvs: ";
		//for (const auto& ev : curEvs)
		//{
		//	std::cout << ev->csID << " ";
		//}
		//std::cout << "\n";

		if (curEvs.size() == 0)
		{
			break;
		}
		
		double pTotal = 0;
		for (const auto& ev : curEvs)
		{
			if (!ev->isFullyCharged() && !(ev->y[t] == ev->maxRate))
			{
				pTotal += ev->p;
			}
		}
		//std::cout << "pTotal: " << pTotal << " yTotal: " << yTotal << " pwCapacity:" << pwCapacity <<std::endl;
		
		std::vector<double> delta(curEvs.size(), 0);
		size_t count = 0;
		for (const auto& ev : curEvs)
		{
			delta[count++] = std::min((ev->p/pTotal)*(pwCapacity-yTotal),std::min(ev->remDemand,ev->maxRate-ev->y[t]));
		}
		count = 0;
		for (auto& ev : curEvs)
		{
			auto it{ evList.begin() };
			std::advance(it, ev->csID);
			it->y[t] += delta[count];
			//std::cout << "Delivered " << delta[count] << " kWh to EV " << it->csID << std::endl;

			it->remDemand -= delta[count];
			yTotal += delta[count];
			Y[it->csID][t] += delta[count];

			if (it->remDemand == 0)
			{
				it->isFullyCharged_ = true;
			}
			++count;
		}
	}  
}

void CS::WFAIR()
{
	for (slot t = 0; t < TL; ++t)
	{
		WFAIR(t);
		//std::cout << *this << std::endl; //uncommect to print status of allocations at the end of time slot t
	}
}

void CS::FOCS(slot t)
{
	if (t > TL - 1 || t < 0)
	{
		throw std::string{ "invalid time slot" };
	}

	double yTotal = 0;				//remaining power capacity at slot t	
	std::for_each(evList.begin(), evList.end(), [&yTotal, t](const EV& ev)
	{
		yTotal += ev.y[t];
	});

	std::list<EV*> curEvs;		//list of active EVs at time slot t	
	for (auto& ev : evList)
	{
		if (ev.isActive(t) && ev.y[t] < ev.maxRate)
		{
			curEvs.insert(curEvs.end(), &ev);
		}
	}

	auto comp = [](EV* e1, EV* e2) 
	{
		return e1->p > e2->p; 
	};

	curEvs.sort(comp); //descending sort based on value-demand ratio

	for (auto ev : curEvs)
	{
		if (yTotal > pwCapacity - 0.01)
		{
			break;
		}
		auto it{ evList.begin() };
		std::advance(it, ev->csID);
		double delta = std::min(pwCapacity - yTotal, std::min(ev->remDemand, ev->maxRate - ev->y[t]));
		it->y[t] += delta;

		it->remDemand -= delta;
		yTotal += delta;
		Y[it->csID][t] += delta;

		if (it->remDemand == 0)
		{
			it->isFullyCharged_ = true;
		}
	}
}

void CS::FOCS()
{
	for (slot t = 0; t < TL; ++t)
	{
		FOCS(t);
		//std::cout << *this << std::endl; //uncommect to print status of allocations at the end of time slot t
	}
}

//generate n random (feasible) EV profiles for testing
std::list<EV> evGenerator(int n)
{
	std::list<EV> ret;
	for (size_t id = 0; id < n; ++id)
	{
		//creating EV i with random profile
		double b = randf(1, 69) + 21;
		double k;
		if (b < 50)
			k = randf(1, 4) + 2;
		else
			k = randf(1, 4) + 6;

		size_t a = randi(0, TL - 1);
		size_t d = randi(a, TL - 1);
		double maxDemand = (d - a + 1)*k;
		double D = std::min(0.8 * maxDemand,b);
		double v = randi(1, 5) * 0.11 * D; // 0.11 = average electricity price in US	
		ret.emplace_back(EV{ a,d,v,D,k,b,id});		
	}
	return ret;
}

/*
generate a pseudo-random number in closed interval [a,b]
*/
int randi(int a, int b)
{
	std::random_device random_device;
	std::mt19937 random_engine(random_device());
	std::uniform_int_distribution<> dist{ a,b };
	auto const randomNumber = dist(random_engine);
	return randomNumber;
}

int randi(int b)
{
	return randi(0, b);
}

double randf(int a, int b)
{
	return static_cast<double> (randi(a, b));
}

double randf(int b)
{
	return static_cast<double> (randi(0, b));
}



std::ostream& operator << (std::ostream& os, const CS& cs)
{
	for (size_t i = 0; i < cs.n; ++i)
	{
		std::cout << "EV " << i << " : ";
		for (slot t = 0; t < TL; ++t)
		{
			std::cout << cs.Y[i][t] << " ";
		}
		std::cout << "\n";
	}
	return os;
}