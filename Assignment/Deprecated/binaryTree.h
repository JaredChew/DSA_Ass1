#pragma once

#include <iostream>

#include "node.h"

template<typename nodeType>
class BinaryTree {

private:
	Node<nodeType> *rootNode;

private:
	void listBinaryTree(Node<nodeType> *&node) const;
	void insertToBinarytree(Node<nodeType> *&node, const int &value);

	bool searchBinaryTree(Node<nodeType> *&parent, const int &key) const;

public:
	BinaryTree();
	~BinaryTree();

	void displayContent();
	void insertValue(const int &value);
	void searchValueNode(const int &value);

};