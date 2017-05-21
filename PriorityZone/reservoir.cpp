#include "stdafx.h"
#include "reservoir.h"
#include "Priority.h"

#include <fstream>

Reservoir* Reservoir::instance = nullptr;

Reservoir::Reservoir()
{
}

Reservoir::~Reservoir()
{
}

Reservoir* Reservoir::getInstance()
{
	if (instance == nullptr)
		instance = new Reservoir();
	return instance;
}

void Reservoir::CleanInstance()
{
	if (instance != nullptr)
		delete instance;
	instance = new Reservoir();
}

void Reservoir::deletePriorityZone()
{
	pZonesMaxVolume.pop_back();
}

bool Reservoir::EditZoneMaximumVolume(int index, double maximumVolume)
{
	if (maximumVolume <= 0 || maximumVolume < minimumVolume)
		return false;
	if (index == 0 ||
		(index > 0 && pZonesMaxVolume[index-1] < maximumVolume)) {
		pZonesMaxVolume[index] = maximumVolume;
		return true;
	}
	return false;
}

bool Reservoir::addDefaultPriorityZone()
{
	if (!isMaximumVolumeValid())
		return false;
	if (pZonesMaxVolume.size() == 0 ||
		(pZonesMaxVolume.size() > 0 && pZonesMaxVolume.back() < maximumVolume)) {
		pZonesMaxVolume.push_back(maximumVolume);
		return true;
	}
	return false;
}

VectorOfPriorityZones Reservoir::getVolumeInPriorityZones()
{
	std::vector<int> p;
	std::vector<double> v;
	int count = 1;
	for (auto& i : pZonesMaxVolume) {
		p.push_back(count++);
		v.push_back(i);
	}

	PriorityUtils pUtils;
	return pUtils.zonesAvailableSupply(p ,v , minimumVolume, maximumVolume, currentVolume);
}

double Reservoir::getZoneMinVolume(int index)
{
	if (index == 0)
		return minimumVolume;
	return pZonesMaxVolume[index - 1];
}

bool Reservoir::isMinimumVolumeValid()
{
	if (minimumVolume >= maximumVolume)
		return false;
	if (minimumVolume < 0)
		return false;
	return true;
}

bool Reservoir::isMaximumVolumeValid()
{
	if (maximumVolume <= minimumVolume)
		return false;
	if (maximumVolume < currentVolume)
		return false;
	return true;
}

bool Reservoir::isCurrentVolumeValid()
{
	if (currentVolume > maximumVolume)
		return false;
	if (currentVolume < 0)
		return false;
	return true;
}

void Reservoir::saveReservoir(std::string path, std::string filename)
{
	std::ofstream file;
	file.open(path + "\\" + filename, std::ofstream::out);

	if (!file.is_open()) {
		return;
	}

	file << minimumVolume << "\n";
	file << maximumVolume << "\n";
	file << currentVolume << "\n";

	for (auto& i : pZonesMaxVolume) {
		file << i << "\n";
	}
	file.flush();
	file.close();

	currentPath = path;
	currentFileName = filename;
}

void Reservoir::loadReservoir(std::string path, std::string filename)
{
	std::ifstream file;
	file.open(path + "\\" + filename, std::ofstream::in);

	if (!file.is_open()) {
		return;
	}

	file >> minimumVolume;
	file >> maximumVolume;
	file >> currentVolume;

	while (file.good()) {
		double v;
		file >> v;
		if (file.eof())
			break;
		pZonesMaxVolume.push_back(v);
	}
	file.close();

	currentPath = path;
	currentFileName = filename;
}
