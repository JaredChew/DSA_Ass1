#include "binaryTree.h"

template<class nodeType>
BinaryTree<nodeType>::BinaryTree() : rootNode(nullptr) { }

template<class nodeType>
BinaryTree<nodeType>::~BinaryTree() {

	delete rootNode;

}

template<class nodeType>
void BinaryTree<nodeType>::insertToBinarytree(Node<nodeType> *&node, const int &value) {

	if (node == nullptr) {

		node = new Node<nodeType>();

		node->setValue(value);

		std::cout << "Value set at node address: " << &node << std::endl;

	}
	else if (value < node->getValue()) {

		std::cout << "Moving down left Node" << "\n";

		insertToBinarytree(node->getLeftExtend(), value);

	}
	else {

		std::cout << "Moving down right Node" << "\n";

		insertToBinarytree(node->getRightExtend(), value);

	}

	std::cout << "\n";

}

template<class nodeType>
void BinaryTree<nodeType>::listBinaryTree(Node<nodeType> *&node) const {

	if (node == nullptr) {
		return;
	}

	listBinaryTree(node->getLeftExtend());

	std::cout << node->getValue() << " | ";

	listBinaryTree(node->getRightExtend());

}

template<class nodeType>
bool BinaryTree<nodeType>::searchBinaryTree(Node<nodeType> *&parent, const int &key) const {

	if (parent != nullptr) {

		if (parent->getValue() == key) {
			std::cout << "Searched value found at node address: " << &parent << std::endl;
			return true;
		}
		else if (parent->getValue() < key) {
			return searchBinaryTree((Node<nodeType>*&)*parent->getLeftExtend(), key);
		}
		else if (parent->getValue() > key) {
			return searchBinaryTree((Node<nodeType>*&)*parent->getRightExtend(), key);
		}

	}

	return false;

}

template<class nodeType>
void BinaryTree<nodeType>::insertValue(const int &value) {

	insertToBinarytree(rootNode, value);

}

template<class nodeType>
void BinaryTree<nodeType>::displayContent() {

	listBinaryTree(rootNode);

}

template<class nodeType>
void BinaryTree<nodeType>::searchValueNode(const int &value) {

	if (!searchBinaryTree(rootNode, value)) {
		std::cout << "Searched value not found in any node" << std::endl;
	}

}