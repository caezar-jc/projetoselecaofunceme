#include "stdafx.h"
#include "Priority.h"
#include <algorithm>
VectorOfPriorityZones entry;

VectorOfPriorityZones PriorityUtils::zonesAvailableSupply(std::vector<int> pArray,
	std::vector<float> vArray, float minimumVolume, float maximumVolume, float currentVolume)
{
	VectorOfPriorityZones v;
	if (pArray.size() != vArray.size()) {
		return v;
	}
	
	std::sort(pArray.begin(), pArray.end());
	std::sort(vArray.begin(), vArray.end());
	std::vector<int>::iterator it = pArray.begin();
	float previousZone = minimumVolume;
	for (const auto& i :vArray) {
		float volume;
		if(i >= maximumVolume)
			volume = currentVolume - previousZone;
		else
			volume = i - previousZone;
		PriorityZone p(volume, *(it++));
		v.push_back(p);
		previousZone = i;
	}
	return v;
}