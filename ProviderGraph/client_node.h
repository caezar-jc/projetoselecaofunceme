#pragma once

#include "graph_node.h"
class ClientNode: public GraphNode
{
private:
	static int nameIdSpace;
	int nameId;
	
public:
	ClientNode(float demand);
	~ClientNode();

	virtual bool connect(GraphNode *child);
	virtual void next(float &toConsume);
};

