#include "pch.h"
#include "CS.h"
#include <iostream>

int main()
{		
	//a sample input
	std::list<EV> evList;
    evList.insert(evList.end(), EV(4,4,4.4,8,10,58,0));
	evList.insert(evList.end(), EV(0,4,12.32,28,7,63,1));
	evList.insert(evList.end(), EV(0,5,14.256,43.2,9,52,2));
	evList.insert(evList.end(), EV(4, 5, 5.28, 16, 10, 89, 3));
	evList.insert(evList.end(), EV(1, 3, 3.96, 12, 5, 46, 4));
	evList.insert(evList.end(), EV(5, 5, 1.76, 3.2, 4, 25, 5));
	
	//std::list<EV> evList = evGenerator(6); //use this method to generate n random EV profiles instead of sample input
	CS aCS(10, 12, evList); //generate a charging station with capacity for 10 EVs, power capacity of 12 kWh and EVs given in evList	
	aCS.FOCS();
	//aCS.WFAIR();			//allocate resources by WFAIR algorithm
	std::cout << "Allocation finished" << std::endl << "----------Input:" << std::endl;
	for (const auto& ev : aCS.getEvList())
		std::cout << ev << std::endl;
	std::cout << "-----------Output CS status:\n" << aCS << std::endl;

	return 0;
}