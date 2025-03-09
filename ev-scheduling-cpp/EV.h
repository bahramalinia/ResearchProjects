#pragma once
#include <vector>
#include "CS.h"

using slot = size_t;

class EV
{
	size_t arrival;   //arrival time slot
	size_t deadline;  //desired departure time slot
	double value;     //value of demand (could represent price, priority, etc)	
	double demand;    //electricty demand (kWh)	
	double maxRate;   //maximum charging rate of EV in kWh

	double batteryCapacity;
	double remDemand; //remaining demand (dynamically updated)	
	double p;         //value/demand ratio
	size_t parkTime;  //number of time slots from arrival to departure
	std::vector<double> y;  //y[i] is charging rate of the EV at time slot arrival+i
	size_t csID;
	bool isFullyCharged_;

public:
	EV() = delete;
	EV(size_t a, size_t d, double v, double D, double k, double b, size_t id);

	bool isFullyCharged() const
	{
		return isFullyCharged_;
	}
	bool isPresent(slot t) const
	{
		return (t >= arrival && t <= deadline);
	}
	bool isActive(slot t) const
	{
		return (!isFullyCharged() && isPresent(t));
	}

	friend std::ostream& operator << (std::ostream& os, const EV& ev);
	friend class CS;
};
