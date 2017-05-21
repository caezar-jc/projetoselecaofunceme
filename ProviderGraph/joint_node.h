#pragma once
#include "graph_node.h"

class JointNode : public GraphNode
{
public:
	JointNode();
	~JointNode();

	virtual bool connect(GraphNode *child);
	virtual void next(float &toConsume);
};

