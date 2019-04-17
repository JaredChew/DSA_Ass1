#include "animalGuessing.h"

AnimalGuessing::AnimalGuessing() {

	answerTree = new BinaryTree<NODE_TYPE>();

	//answerTree->insertValue(0);

	currentState = questionState::domestication;

	animalGuessed = false;

	animalType = 0;

}

AnimalGuessing::~AnimalGuessing() {

	delete answerTree;

}

void AnimalGuessing::saveAnswer(const int &answer) {

	answerTree->insertValue(answer - 1);

}

void AnimalGuessing::switchState() {

	switch (currentState) {

		case questionState::domestication:
			currentState = questionState::habitat;
			break;

		case questionState::habitat:
			currentState = questionState::movement;
			break;

		case questionState::movement:
			currentState = questionState::conception;
			break;

		case questionState::conception:
			animalGuessed = true;
			break;

	}

}

void AnimalGuessing::question() {

	switch (currentState) {

		case questionState::domestication:
			std::cout << "\nIs the animal [wild (1)] or [tame (2)]?" << std::endl;
			break;

		case questionState::habitat:
			std::cout << "\nDoes the animal live in [water (1)] or on [land (2)]?" << std::endl;
			break;

		case questionState::movement:
			std::cout << "\nDoes the animal have a body part dedicated to moving? [yes (1)] [no (2)]" << std::endl;
			break;

		case questionState::conception:
			std::cout << "\nDoes the animal [lay eggs (1)] or [give birth (2)]?" << std::endl;
			break;

	}

}

void AnimalGuessing::answer() {

	int answer = 0;

	while (true) {

		std::cout << "\nSelect an answer of either 1 or 2 based on the question\n";

		std::cout << "Answer: ";

		std::cin.clear();
		std::cin.ignore();

		std::cin >> answer;

		if (std::cin.fail()) {
			std::cout << "\n\nPlease answer using numbers" << std::endl;
		}
		else if (answer == 1 || answer == 2) {
			break;
		}
		else {
			std::cout << "\n\nPlease answer within the given options" << std::endl;
		}

	}

	if (currentState == questionState::domestication) {
		animalType = answer;
	}
	else {
		saveAnswer(answer);
	}

	switchState();

}

void animalWildResult(const int &binaryData) {

	switch (utilites::binaryToDenary(binaryData)) {

	case animalWild::turtle:
		std::cout << "\nThe animal is a turtle" << std::endl;
		break;

	case animalWild::sea_otter:
		std::cout << "\nThe animal is a sea otter" << std::endl;
		break;

	case animalWild::eal:
		std::cout << "\nThe animal is an eal" << std::endl;
		break;

	case animalWild::seal:
		std::cout << "\nThe animal is a seal" << std::endl;
		break;

	case animalWild::aligator:
		std::cout << "\nThe animal is an aligator" << std::endl;
		break;

	case animalWild::lion:
		std::cout << "\nThe animal is a lion" << std::endl;
		break;

	case animalWild::cobra_snake:
		std::cout << "\nThe animal is a cobra snake" << std::endl;
		break;

	case animalWild::rattle_snake:
		std::cout << "\nThe animal is a rattle snake" << std::endl;
		break;

	}

}

void const animalTameResult(const int &binaryData) {

	switch (utilites::binaryToDenary(binaryData)) {

	case animalTame::tortoise:
		std::cout << "\nThe animal is a tortoise" << std::endl;
		break;

	case animalTame::seahorse:
		std::cout << "\nThe animal is a seahorse" << std::endl;
		break;

	case animalTame::koi_fish:
		std::cout << "\nThe animal is a koi fish" << std::endl;
		break;

	case animalTame::guppy_fish:
		std::cout << "\nThe animal is a guppy fish" << std::endl;
		break;

	case animalTame::parrot:
		std::cout << "\nThe animal is a parrot" << std::endl;
		break;

	case animalTame::dog:
		std::cout << "\nThe animal is a dog" << std::endl;
		break;

	case animalTame::corn_snake:
		std::cout << "\nThe animal is a corn snake" << std::endl;
		break;

	case animalTame::none:
		std::cout << "\nThe animal of chosen criteria does not exist" << std::endl;
		break;

	}

}

void AnimalGuessing::result() {

	std::stringstream nodeData;

	int searchType = 0;
	int binaryData = 0;

	char answer = ' ';

	do {

		searchType++;

		switch (searchType) {

			case 1:
				nodeData = answerTree->getNodeValuePreOrder();
				break;

			case 2:
				nodeData = answerTree->getNodeValueInOrder();
				break;

			case 3:
				nodeData = answerTree->getNodeValuePostOrder();
				break;

			default:
				std::cout << "\nUnable to guess animal" << std::endl;
				return;

		}

		std::cout << "\nAttempt " << searchType << "/3\n";

		nodeData >> binaryData;

		switch (animalType) {

			case 1:
				animalWildResult(binaryData);
				break;

			case 2:
				animalTameResult(binaryData);
				break;

		}

		std::cout << "\nDoes the guessed animal fit the selection from the questions? (y/n): ";
		std::cin >> answer;

	} while (answer != 'y');

}

bool AnimalGuessing::getAnimalGuessed() {

	return animalGuessed;

}