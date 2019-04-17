#pragma once

#include <iostream>
#include <sstream>

#include "node2d.hpp"

#define DEBUG true

#if DEBUG
#define Log(lambda) lambda()
#else
#define Log(null)
#endif // DEBUG

template<typename nodeType>
class BinaryTree {

	private:

		Node2D<nodeType> *rootNode;

	private:

		void listBinaryTree(Node2D<nodeType> *&node) const {

			if (node == nullptr) {
				return;
			}

			listBinaryTree(node->getLeftExtend());

			std::cout << node->getValue() << " | ";

			listBinaryTree(node->getRightExtend());

		}

		void insertToBinarytree(Node2D<nodeType> *&node, const nodeType &value) {

			if (node == nullptr) {

				node = new Node2D<nodeType>();

				node->setValue(value);

				Log([&]() { std::cout << "Value [" << value << "] set at node address: " << &node << std::endl; });

			}
			else if (value < node->getValue()) {

				Log([]() { std::cout << "Moving down left Node" << "\n"; });

				insertToBinarytree(node->getLeftExtend(), value);

			}
			else {

				Log([]() { std::cout << "Moving down right Node" << "\n"; });

				insertToBinarytree(node->getRightExtend(), value);

			}

		}

		bool searchBinaryTree(Node2D<nodeType> *&parent, const nodeType &value) const {

			if (parent != nullptr) {

				if (parent->getValue() == value) {
					Log([&parent]() { std::cout << "Searched value found at node address: " << &parent << std::endl; });
					return true;
				}
				else if (parent->getValue() < value) {
					return searchBinaryTree((Node2D<nodeType>*&) *parent->getLeftExtend(), value);
				}
				else {
					return searchBinaryTree((Node2D<nodeType>*&) *parent->getRightExtend(), value);
				}

			}

			return false;

		}

		void preOrder(Node2D<nodeType> *&node, std::stringstream &nodeValue) {

			if (node == nullptr) {
				return;
			}

			nodeValue << node->getValue();

			preOrder(node->getLeftExtend(), nodeValue);
			preOrder(node->getRightExtend(), nodeValue);

		}

		void inOrder(Node2D<nodeType> *&node, std::stringstream &nodeValue) {

			if (node == nullptr) {
				return;
			}

			inOrder(node->getLeftExtend(), nodeValue);

			nodeValue << node->getValue();

			inOrder(node->getRightExtend(), nodeValue);

		}

		void postOrder(Node2D<nodeType> *&node, std::stringstream &nodeValue) {

			if (node == nullptr) {
				return;
			}

			postOrder(node->getLeftExtend(), nodeValue);
			postOrder(node->getRightExtend(), nodeValue);

			nodeValue << node->getValue();


		}

	public:

		BinaryTree() : rootNode(nullptr) { }

		~BinaryTree() {

			delete rootNode;

		}

		void displayContent() {

			listBinaryTree(rootNode);

		}

		void insertValue(const nodeType &value) {

			insertToBinarytree(rootNode, value);

		}

		void searchValueNode(const nodeType &value) {

			if (!searchBinaryTree(rootNode, value)) {
				Log([]() { std::cout << "Searched value not found in any node" << std::endl; });
			}

		}

		std::stringstream getNodeValuePreOrder() {

			Log([]() { std::cout << "BinaryTree search by pre-order" << std::endl; });

			std::stringstream nodeValue;

			preOrder(rootNode, nodeValue);

			return nodeValue;

		}

		std::stringstream getNodeValueInOrder() {

			Log([]() { std::cout << "BinaryTree search by in-order" << std::endl; });

			std::stringstream nodeValue;

			inOrder(rootNode, nodeValue);

			return nodeValue;

		}

		std::stringstream getNodeValuePostOrder() {

			Log([]() { std::cout << "BinaryTree search by post-order" << std::endl; });

			std::stringstream nodeValue;

			postOrder(rootNode, nodeValue);

			return nodeValue;

		}

};