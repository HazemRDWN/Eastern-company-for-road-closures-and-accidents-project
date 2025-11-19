#pragma once
#include"PriorityQueue.h"
#include"Vehicles.h"

template<class T>
class Lanes {
private:
	int LaneID, IntersectionID;
	PriorityQueue<Vehicles>* EV_List;
	
};