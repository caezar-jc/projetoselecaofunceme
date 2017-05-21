#pragma once

#ifndef __PRIORITY_ZONE__
#define __PRIORITY_ZONE__

#include <vector>

class PriorityZone
{
protected:
	double m_availableVolume;
	int m_priority;
public:
	PriorityZone(double availableVolume, int priority);
	double getAvailableVolume();
	int getPriority();
};

using VectorOfPriorityZones = std::vector<PriorityZone>;

#endif /**__PRIORITY_ZONE__**/