#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "node2D.hpp"
#include "binaryTree.hpp"
#include "utilities.h"

#define NODE_TYPE bool

enum questionState {

	domestication,
	movement,
	habitat,
	conception

};

enum animalWild {

	turtle,
	sea_otter,
	eal,
	seal,
	aligator,
	lion,
	cobra_snake, //Can't access
	rattle_snake,

};

enum animalTame {

	tortoise,
	seahorse,
	koi_fish,
	guppy_fish,
	parrot,
	dog,
	corn_snake, //Can't access
	none

};

class AnimalGuessing {

private:
	BinaryTree<NODE_TYPE> *answerTree;
	questionState currentState;

	bool animalGuessed;

	int animalType; // 1 - wild, 2 - tame

private:
	void saveAnswer(const int &answer);
	void switchState();

public:
	AnimalGuessing();
	~AnimalGuessing();

	void question();
	void answer();
	void result();

	bool getAnimalGuessed();

};