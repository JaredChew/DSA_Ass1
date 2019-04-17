#pragma once

#include <vector>

template <typename custom>
class Node2D {

	private:

		custom value;

		Node2D *leftExtend;
		Node2D *rightExtend;

	public:

		Node2D() :leftExtend(nullptr), rightExtend(nullptr) {

			value = NULL;


		}

		~Node2D() {
			
			if (!leftExtend) {
				delete leftExtend;
			}

			if (!rightExtend) {
				delete rightExtend;
			}
			
		}

		void setValue(const custom &value) {
			this->value = value;
		}

		void setLeftExtend(Node2D *&leftExtend) {
			this->leftExtend = leftExtend;
		}

		void setRightExtend(Node2D *&leftExtend) {
			this->rightExtend = rightExtend;
		}
		
		custom getValue() const {
			return value;
		}
		
		Node2D*& getLeftExtend() {
			return leftExtend;
		}

		Node2D*& getRightExtend() {
			return rightExtend;
		}
		
};