#include <iostream>

#include "animalGuessing.h"

bool playAgain(char &playGame) {

	while (true) {

		std::cout << "\nWould you like to play again? (y/n): ";

		std::cin.clear();
		std::cin.ignore();

		std::cin >> playGame;

		switch (playGame) {

			case 'Y':
			case 'y':
				return true;
				break;

			case 'n':
			case 'N':
				return false;
				break;

			default:
				std::cout << "\nSelection not recognised" << std::endl;


		}

	}

}

int main() {

	AnimalGuessing *game = new AnimalGuessing();

	bool gameLoop = true;

	char playGame = ' ';

	std::cout << "##################################################\n";
	std::cout << "\n\tXBGT1024 DSA Assignment 2\n";
	std::wcout << "\nName:Jared Chew\nStudent #: 0128085\n";
	std::cout << "\n##################################################" << std::endl;

	std::cout << "\n\nWelcome to the animal guesing game\n";

	std::cout << "\nWould you like to play? (y/n)";

	std::cout << "\nChoice: ";
	std::cin >> playGame;

	while (gameLoop) {

		switch (playGame) {

			case 'Y':
			case 'y':

				while (!game->getAnimalGuessed()) {
					game->question();
					game->answer();
				}

				game->result();

				if (!playAgain(playGame)) {
					gameLoop = false;
					std::cout << "\nThank you for playing!" << std::endl;
					break;
				}

				std::cout << "\n\n#####################################\n" << std::endl;

				delete game;
				game = new AnimalGuessing();

				break;

			case 'N':
			case 'n':

				gameLoop = false;

				break;

			default:
				std::cout << "\nSelection not recognised\n" << std::endl;

				std::cin.clear();
				std::cin.ignore();

		}

	}

	delete game;

	std::cout << "\nPress ENTER to exit the program." << std::endl;

	std::cin.clear();
	std::cin.ignore();

	std::cin.get();

	return 0;

}