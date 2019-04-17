#include "node.h"

template <typename custom>
Node<custom>::Node() :leftExtend(nullptr), rightExtend(nullptr) {

	value = 0;

}

template <typename custom>
Node<custom>::~Node() {

	if (!leftExtend) {
		delete leftExtend;
	}

	if (!rightExtend) {
		delete rightExtend;
	}

}

template <typename custom>
void Node<custom>::setValue(const custom &value) {
	this->value = value;
}

template <typename custom>
void Node<custom>::setLeftExtend(Node *&leftExtend) {
	this->leftExtend = leftExtend;
}

template <typename custom>
void Node<custom>::setRightExtend(Node *&rightExtend) {
	this->rightExtend = rightExtend;
}

template <typename custom>
custom Node<custom>::getValue() const {
	return value;
}

template <typename custom>
Node<custom>*& Node<custom>::getLeftExtend() {
	return leftExtend;
}

template <typename custom>
Node<custom>*& Node<custom>::getRightExtend() {
	return rightExtend;
}