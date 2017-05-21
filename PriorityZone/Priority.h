#pragma once

#ifndef __PRIORITY_UTILS__
#define __PRIORITY_UTILS__

#include <vector>

#include "PriorityZone.h"

class PriorityUtils
{
public:
	/** @brief
	* Retorna o volume de �gua dispon�vel em cada zona de prioridade
	* @param pArray � um vetor contendo as prioridades de cada zona
	* @param vArray � o limite superior de cada zona
	* @param minimumVolume � o volume m�nimo do reservat�rio
	* @param maximumVolume � o volume m�ximo do reservat�rio
	* @param currentVolume � o volume atual do reservat�rio
	*/
	/** Crie aqui o m�todo zonesAvailableSupply segundo as especifica��es logo acima **/
	VectorOfPriorityZones zonesAvailableSupply(std::vector<int> pArray,
		std::vector<double> vArray, double minimumVolume, double maximumVolume, double currentVolume);
};

#endif /** __PRIORITY_UTILS__ **/