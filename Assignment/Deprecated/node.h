#pragma once

template <typename custom>
class Node {

private:
	custom value;

	Node *leftExtend;
	Node *rightExtend;

public:
	Node();
	~Node();

	void setValue(const custom &value);
	void setLeftExtend(Node *&leftExtend);
	void setRightExtend(Node *&leftExtend);

	custom getValue() const;

	Node*& getLeftExtend();
	Node*& getRightExtend();

};