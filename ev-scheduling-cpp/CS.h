#pragma once
#include "EV.h"
#include <vector>
#include <list>
#include <random>
#include <functional>



//Time horizon {1...24}
const size_t TL = 6;
using slot = size_t;

class EV;

//charging station class
class CS
{
	int n;
	int evCapacity;						//size of charging station	
	int pwCapacity;						//maximum output power of station at each time slot (kWh)
	slot curSlot;						//current time slot	
	std::list<EV> evList;
	std::vector<std::vector<double>> Y; //n * TL matrix where Y[i][j] indicates allocated resource to EV i at time slot j 

public:
	CS() = delete;
	CS(int e, int p, std::list<EV> evList);
	CS(int e, int p, int n);
	std::list<std::list<EV>> convertEvListToMatrix(const std::list<EV>& allEvs);

	void WFAIR(slot t);
	void WFAIR();
	void WRAND(slot t);
	void FOCS();
	void FOCS(slot t);
	std::list<EV> getEvList()
	{
		return evList;
	}

	friend std::ostream& operator << (std::ostream& os, const CS& cs);
};

std::list<EV> evGenerator(int n);

std::ostream& operator << (std::ostream& os, const EV& ev);
std::ostream& operator << (std::ostream& os, const CS& cs);

int randi(int a, int b);		//[a,b]
int randi(int b);				//[0,b]
double randf(int a, int b);		//[a,b]
double randf(int b);			//[0,b]
