#pragma once

#ifndef __PRIORITY_UTILS__
#define __PRIORITY_UTILS__

#include <vector>

#include "priorityZone.h"

using VectorOfPriorityZones = std::vector<PriorityZone>;

class PriorityUtils
{
public:
	/** @brief
	* Retorna o volume de água disponível em cada zona de prioridade
	* @param pArray é um vetor contendo as prioridades de cada zona
	* @param vArray é o limite superior de cada zona
	* @param minimumVolume é o volume mínimo do reservatório
	* @param maximumVolume é o volume máximo do reservatório
	* @param currentVolume é o volume atual do reservatório
	*/
	/** Crie aqui o método zonesAvailableSupply segundo as especificações logo acima **/
	VectorOfPriorityZones zonesAvailableSupply(std::vector<int> pArray,
		std::vector<float> vArray, float minimumVolume, float maximumVolume, float currentVolume);
};

#endif /** __PRIORITY_UTILS__ **/