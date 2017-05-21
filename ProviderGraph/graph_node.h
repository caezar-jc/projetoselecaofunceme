#pragma once
#include <vector>

using ConsumeFunc_ptr = std::add_pointer<void(float)>::type;

class GraphNode
{
public:
	int id;
	float value;
	std::vector<GraphNode*> children;

	static int idSpace;
public:
	GraphNode();
	virtual bool connect(GraphNode *child) = 0;
	virtual void next(float &toConsume) = 0;

	virtual void deleteChildren();
};

