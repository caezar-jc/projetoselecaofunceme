#pragma once
#include "graph_node.h"

class ProviderNode : public GraphNode
{
private :
	static int timeStepCounter;
	int timeStep;
public:
	ProviderNode(float initialStock);
	~ProviderNode();

	void distribute();

	virtual bool connect(GraphNode *child);
	virtual void next(float &toConsume);
};

