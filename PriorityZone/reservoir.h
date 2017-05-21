#pragma once
#include <vector>
#include "PriorityZone.h"
class Reservoir
{
private:
	static Reservoir *instance;
public:
	std::string currentPath;
	std::string currentFileName;
	std::vector<double> pZonesMaxVolume;

	double minimumVolume;
	double maximumVolume;
	double currentVolume;
private:
	Reservoir();
public:
	~Reservoir();

	static Reservoir* getInstance();
	static void CleanInstance();

	void deletePriorityZone();
	bool EditZoneMaximumVolume(int index, double maximumVolume);
	bool addDefaultPriorityZone();
	VectorOfPriorityZones getVolumeInPriorityZones();
	double getZoneMinVolume(int index);

	bool isMinimumVolumeValid();
	bool isMaximumVolumeValid();
	bool isCurrentVolumeValid();

	void saveReservoir(std::string path, std::string filename);
	void loadReservoir(std::string path, std::string filename);
};

