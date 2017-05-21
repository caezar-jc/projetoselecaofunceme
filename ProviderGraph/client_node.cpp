#include "stdafx.h"
#include "client_node.h"
#include <iostream>

int ClientNode::nameIdSpace = 0;

ClientNode::ClientNode(float demand)
{
	value = demand;
	nameId = nameIdSpace++;
}


ClientNode::~ClientNode()
{
}

bool ClientNode::connect(GraphNode * child)
{
	std::cout << "conexao nao permitida." << std::endl;
	return false;
}

void ClientNode::next(float & toConsume)
{
	if (toConsume < value) {
		std::cout << "F nao consegue mais liberar para C" << nameId << std::endl;
		return;
	}
	toConsume -= value;
	std::cout << "F libera " << value << " para C" << nameId << std::endl;
}