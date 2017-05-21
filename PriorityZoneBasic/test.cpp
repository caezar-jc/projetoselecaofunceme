#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Priority.h"

int main(int args, char* argv[]) {

	PriorityUtils pUtils;
	VectorOfPriorityZones p = pUtils.zonesAvailableSupply({3,1,2}, {8000.0f, 1000.0f, 2500.0f}, 500.0f, 8000.0f, 2650.0f);

	for (auto& i : p) {
		std::cout << i.getPriority() << ", " << i.getAvailableVolume() << std::endl;
	}
	system("pause");
}