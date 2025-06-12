/*
 * Author: Noah Pragin
 * Program description: NBA 3pt shooting contest simulation
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

/*
 * Function: promptPlayers
 * Description: Prompts for number of players, with bad input handling,
 *   returns the int value.
 * Returns:
 *   int numPlayers: The number of players entered by the user
 * Side Effects: 
 *   Prints "Enter number of players:" to console
 *   Handles bad values, must be a positive int
 *   Prints "Input must be a positive integer."
*/
int promptPlayers() {
	int numPlayers = 0;
	std::string numPlayersString;

	while (numPlayers < 1) {
		std::cout << "Enter number of players: ";
		std::cin >> numPlayersString;
		std::cout << std::endl;

		try { //Handles failed integer parse
			numPlayers = std::stoi(numPlayersString);

			if (numPlayers < 1) { //Verifies input is good
				std::cout << "Input must be a positive integer." << std::endl;
			}
		} catch(const std::exception& e) {
			std::cout << "Input must be a positive integer." << std::endl;
		}
	}

	return numPlayers;
}

/*
 * Function: promptMoneyball
 * Description: Prompts for money ball position, with bad input handling,
 * 	returns the int value representing rack number.
 * Returns:
 * 	int moneyballPosition: The money ball rack represented by rack number
 * Side Effects:
 * 	Prints "Where do you want to put your money-ball rack? Enter 1-5:"
 * 	Prints "Input must be an integer 1-5, inclusive."
 * 	Handles bad values, must be an integer [1, 5]
*/
int promptMoneyball() {
	int moneyballPosition = 0;
	std::string moneyballString;

	while (moneyballPosition < 1 || moneyballPosition > 5) {
		std::cout << "Where do you want to put your money-ball rack?"
			<< " Enter 1-5: ";
		std::cin >> moneyballString;
		std::cout << std::endl;

		try { //Handles failed integer parse
			moneyballPosition = std::stoi(moneyballString);

			if (moneyballPosition < 1 || moneyballPosition > 5) { //Verifies input is good
				std::cout << "Input must be an integer 1-5, inclusive."
					<< std::endl;
			}
		} catch(const std::exception& e) {
			std::cout << "Input must be an integer 1-5, inclusive."
				<< std::endl;
		}
	}

	return moneyballPosition;
}

/*
 * Function: promptPlayAgain
 * Description: Prompts user whether they will play again using 1 and 0
 * Returns:
 * 	int playAgain: whether they will play again. 1 indicates yes, 0 indicates no.
 * Side Effects:
 * 	Prints "Do you want to play again? (1-yes, 0-no): "
 * 	Prints "Input must be 0 or 1."
 * 	Handles bad values, must be 0 or 1
*/
int promptPlayAgain() {
	int playAgain = -1;
	std::string playAgainString;

	while (!(playAgain == 1 || playAgain == 0)) {
		std::cout << "Do you want to play again? (1-yes, 0-no): ";
		std::cin >> playAgainString;
		std::cout << std::endl;

		try { //Handles failed integer parse
			playAgain = std::stoi(playAgainString);

			if (!(playAgain == 1 || playAgain == 0)) { //Verifies input is good
				std::cout << "Input must be 0 or 1." << std::endl;
			}
		} catch(const std::exception& e) {
			std::cout << "Input must be 0 or 1." << std::endl;
		}
	}

	return playAgain;
}

/*
 * Function: generateShots
 * Description: Randomly decides if a shot makes or misses, populates shots
 * 	array with value of the shot if it made, 0 if missed.
 * Parameters:
 * 	int *shots: Pointer to integer array which will store shot value, must be
 * 	  size of at least 27
 *  int moneyballPosition: Rack number of money ball rack
 * Side Effects:
 * 	Manipulates shots array.
*/
void generateShots(int *shots, int moneyballPosition) {
	int rand;

	for (int i = 0; i < 27; i++) {
		rand = std::rand() % 2; //Get 50% chance result

		if (rand == 1) { //Basket made

			if (i == 25 || i == 26) { //Starry balls
				shots[i] = 3;
			} else if (i / 5 == moneyballPosition - 1 || i % 5 == 4) {
				//Money balls
				// i / 5 represents rack, compare to moneyball position
				// i % 5 == 4 is the last ball of the rack, also money ball

				shots[i] = 2;
			} else { //Regular shot
				shots[i] = 1;
			}

		} else { //Basket missed
			shots[i] = 0;
		}
	}
}

/*
 * Function: printShots
 * Description: Prints player's results using required visualization.
 * Parameters:
 * 	int *shots: Pointer to integer[27] array of 0, 1, 2, and 3.
 * Returns:
 * 	int totalScore: Total score of the player.
*/
int printShots(int *shots) {
	int totalScore = 0;
	int rackScore;

	for (int i = 0; i < 5; i++) { //Iterates each rack
		rackScore = 0;
		std::cout << "Rack " << i + 1 << ": ";

		for (int j = 0; j < 5; j++) { //Iterates each shot
			switch (shots[i * 5 + j]) {
				case 1: //Regular shot
					std::cout << "O ";
					break;
				case 2: //Money ball
					std::cout << "M ";
					break;
				case 3: //Starry ball
					std::cout << "S ";
					break;
				default: //Miss
					std::cout << "_ ";
					break;
			}
			
			rackScore += shots[i * 5 + j]; //Add shot score to rack score
		}

		totalScore += rackScore; //Add rack score to total score
		std::cout << "| " << rackScore << " pts" << std::endl;

		if (i == 1 || i == 2) { //Printing Starry balls
			std::cout << "Starry: ";
			if (shots[24 + i] == 3) { //24 + i because starry balls are last
				std::cout << "S         | 3 pts" << std::endl;
				totalScore += 3;
			} else {
				std::cout << "_         | 0 pts" << std::endl;
			}
		}
	}

	std::cout << std::endl << "Total: " << totalScore << " pts" << std::endl << std::endl;

	return totalScore;
}

/*
 * Function: printWinner
 * Description: Prints the winner or if there was a tie
 * Parameters:
 * 	int *scores: Array holding total scores of all players
 *  int scoreSize: Size of scores array
*/
void printWinner(int *scores, int scoreSize) {
	int maximum = -1;
	int winner = -1;
	bool tie = false;

	for (int i = 0; i < scoreSize; i++) { //Find high score
		if (scores[i] > maximum) {
			maximum = scores[i];
			winner = i + 1;
			tie = false; //If new high score, no more tie
		} else if (scores[i] == maximum) { //Finds ties
			tie = true;
		}
	}

	if (tie) { //Tie handling
		std::cout << "There was a tie at " << maximum << " points."
			<< std::endl << std::endl;
	} else {
		std::cout << "Player " << winner << " is the winner with " << maximum
			<< " points!!" << std::endl << std::endl;
	}
}

int main() {

	srand(time(nullptr));
	bool playAgain = true;

	while (playAgain) {

		std::cout << "Welcome to the basketball shooting contest!" << std::endl
			<< std::endl;

		int numPlayers = promptPlayers();
		int* scores = new int[numPlayers]; //Instantiate dynamic array

		//Iterating over each player's turn
		for (int i = 1; i <= numPlayers; i++) {
			std::cout << "Player " << i << ":" << std::endl;

			int moneyballPosition = promptMoneyball();

			int shots[27]; //Used to store shot data, manipulated using pointer
			generateShots(&shots[0], moneyballPosition);

			//printShots returns the total score, stored in the dynamic array
			scores[i - 1] = printShots(&shots[0]);
		}

		printWinner(&scores[0], numPlayers);

		playAgain = promptPlayAgain() == 1;

		delete[] scores; //Release dynamic allocated memory
	}

	return 0;

}
