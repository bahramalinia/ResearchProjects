#include "pch.h"
#include "EV.h"
#include <iostream>


EV::EV(size_t a, size_t d, double v, double D, double k, double b, size_t id) :
	arrival{ a }, deadline{ d }, value{ v }, demand{ D }, maxRate{ k }, batteryCapacity{ b }, csID{ id }, isFullyCharged_{ false },
	remDemand{ D }, p{ value / demand }, parkTime{ d - a + 1 }, y(TL, 0)
{
	size_t minWaitingTime{ static_cast<size_t>(ceil(demand / maxRate)) };
	if (a < 0 || d < 0 || v <= 0 || D <= 0 || k <= 0 || minWaitingTime > parkTime || D > batteryCapacity) //enforce invariant
	{
		std::cout << "bad object created:" << std::endl;
		std::cout << "a:" << a << " d:" << d << " v:" << v << " D:" << D << " k:" << k << " b:" << b << " minWaitingTime:" << minWaitingTime << std::endl;
		throw std::string{ "bad object" };
	}
}

std::ostream& operator << (std::ostream& os, const EV& ev)
{
	//os << "constructor arguments: " <<  ev.arrival << "," << ev.deadline << "," 
	//   << ev.value << "," << ev.demand << ","
	//   << ev.maxRate << "," << ev.batteryCapacity << "," << ev.csID << "\n";

	os << "a:" << ev.arrival << " ";
	os << "d:" << ev.deadline << " ";
	os << "v:" << ev.value << " ";
	os << "D:" << ev.demand << " ";
	os << "K:" << ev.maxRate << " ";
	os << "b" << ev.batteryCapacity << " ";
	os << "id" << ev.csID << " ";

	os << "p:" << ev.p << " ";
	os << "rD:" << ev.remDemand << " ";
	os << "pTime:" << ev.parkTime << "\n";

	os << "y vector: ";
	for (size_t i = 0; i < TL; ++i)
		os << ev.y[i] << " ";
	return os;
}