// ProviderGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "provider_node.h"
#include "joint_node.h"
#include "client_node.h"

//Ilustração do grafo criado como exemplo
/**
[F]-->--[J]-->--[C1]
|
v
|
[J]
|
v
|
[C2]
**/

int main()
{
	ProviderNode provider(15);
	JointNode *j;
	provider.connect(j = new JointNode());
	j->connect(new ClientNode(2));
	j->connect(new JointNode());
	provider.connect(j = new JointNode());
	j->connect(new ClientNode(3));
	provider.distribute();
	provider.distribute();
	provider.distribute();
	provider.distribute();
	provider.deleteChildren();
	system("pause");
    return 0;
}

