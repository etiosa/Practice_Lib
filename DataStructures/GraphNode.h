//
// Created by Etiosa Obasuyi on 2019-01-08.
//
//
#ifndef PRACTICE_LIB_GRAPHNODE_H
#define PRACTICE_LIB_GRAPHNODE_H
#include<memory>

class GraphNode {
private:
	std::shared_ptr<GraphNode> leftChild;
	std::shared_ptr<GraphNode>rightChild;
	std::shared_ptr<GraphNode>parent;
	int data;
	int size;
public:
	GraphNode(int);
	~GraphNode();
};


#endif //PRACTICE_LIB_GRAPHNODE_H
