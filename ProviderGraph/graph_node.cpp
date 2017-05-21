#include "stdafx.h"
#include "graph_node.h"

int GraphNode::idSpace = 0;

GraphNode::GraphNode()
{
	id = idSpace++;
}

inline void GraphNode::deleteChildren() {
	for (auto& i : children) {
		i->deleteChildren();
		delete i;
	}
}
