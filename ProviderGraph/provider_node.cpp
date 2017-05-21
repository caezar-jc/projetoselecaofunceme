#include "stdafx.h"
#include "provider_node.h"
#include <typeinfo>
#include <iostream>

int ProviderNode::timeStepCounter = 1;

ProviderNode::ProviderNode(float initialStock)
{
	value = initialStock;
}

ProviderNode::~ProviderNode()
{
}

bool ProviderNode::connect(GraphNode * child)
{
	if (typeid(*child) == typeid(ProviderNode)) {
		std::cout << "conexao nao permitida." << std::endl;
		return false;
	}
	children.push_back(child);
	return true;
}

void ProviderNode::next(float &toConsume)
{	
	for (auto& i : children) {
		i->next(toConsume);
	}
}

void t(float test) {}
void ProviderNode::distribute()
{
	std::cout << "Passo " << timeStep << std::endl;
	std::cout << "=======" << std::endl;
	std::cout << "F(" << timeStep << ") = " << value << std::endl;
	timeStep = timeStepCounter++;
	next(value);
}

