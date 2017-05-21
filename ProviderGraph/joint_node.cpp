#include "stdafx.h"
#include "joint_node.h"
#include "provider_node.h"
#include <iostream>
#include <typeinfo>

JointNode::JointNode()
{
}

JointNode::~JointNode()
{
}

bool JointNode::connect(GraphNode * child)
{
	if (typeid(*child) == typeid(ProviderNode)) {
		std::cout << "conexao nao permitida." << std::endl;
		return false;
	}
	if (typeid(*child) == typeid(JointNode)) {
		std::cout << "conexao nao permitida." << std::endl;
		return false;
	}
	children.push_back(child);
	return true;
}

void JointNode::next(float & toConsume)
{
	for (auto& i : children) {
		i->next(toConsume);
	}
}
