#include <iostream>
#include <string>
#include "tictactoe.h"

//class tic tac toe

tictactoe::tictactoe() {
	totalMoves = 0;
	fill_board();
}

void tictactoe::fill_board() {
	for (int row = 0; row < BSIZE; row++) {
		for (int col = 0; col < BSIZE; col++) {
			board[row][col] = ' ';
		}
	}
}

void tictactoe::displayBoard()const {
	std::cout << " --------------\n";
	for (int row = 0; row < BSIZE; row++) {
		std::cout << " | ";
		for (int col = 0; col < BSIZE; col++) {
			std::cout << board[row][col] << "  |";
		}
		std::cout << "\t\n---------------\n";
	}
}

void tictactoe::getMove(char player) {
	std::string input;
	char char_entered;
	int num_entered, row, col, index;

	while (true) {
		std::cout << player << "Where do you want to play? Select a number (1-9): " << std::endl;
		getline(std::cin, input);
		if (input != "") {
			//Since we are checking for a correct move
			//we convert string into a cstring for easier comparison.

			char_entered = input.c_str()[0]; // convert the given string to an array of chars
			if (char_entered >= '1' && char_entered <= '9') {
				//If the input is between the desired range, convert it into an int.
				num_entered = char_entered - '0';
				//ASCII code is '0' = 48 - minus the values of 1 - 9
				index = num_entered - 1;
				// this will store the num into the index wthinin the board
				//i.e if the value is 1 then after this statement the index will be 0 on the board

				row = index / 3;
				col = index % 3;
				//we can use division and the remainder, in order to find the correct row and column. 

				//check if the position on the board is empty (correct move), else it's wrong move.
				char b_pos = board[row][col];
				if (b_pos != 'X' && b_pos != 'O') {
					board[row][col] = player;
					totalMoves++;
					break;
				}
				else
					std::cout << " invalid. position is already taken. Try Again" << std::endl;
			}
			else
				std::cout << "you must enter a number between 1-9. try again \n";
		}
		else
			std::cout << "You must enter something!!" << std::endl;

	}
	std::cout << "Total moves: " << totalMoves <<  std::endl;
}

char tictactoe::togglePlayer(char player) {

	player = player == 'X' ? 'O' : 'X';
	return (player);
}

bool tictactoe::checkForWins(char player)const {

	//only check for a winner once the min moves to win has been reached.
	if (totalMoves >= minMovesToWin) {
		//check rows for winner
		if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
			return true;
		}
		if (board[1][0] == player && board[1][1] == player && board[1][2] == player)
		{
			return true;
		}
		if (board[2][0] == player && board[2][1] == player && board[2][2] == player)
		{
			return true;
		}
		//columns 
		if (board[0][0] == player && board[1][0] == player && board[2][0] == player)
		{
			return true;
		}
		if (board[0][1] == player && board[1][1] == player && board[2][1] == player)
		{
			return true;
		}
		if (board[0][2] == player && board[1][2] == player && board[2][2] == player)
		{
			return true;
		}
		//Accross
		if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
		{
			return true;
		}
		if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
		{
			return true;
		}

	}
	return false;

}

bool tictactoe::checkForDraw()const {
	return totalMoves == maxMoves;
}

void tictactoe::playGame() {
	char player = 'X'; //initialize the player.
	bool gameOver = false;
	//single game iteration
	do {
		displayBoard();
		getMove(player);
		if (checkForWins(player)) {
			std::cout << "\n *********** WE HAVE A WINNER!! ***********" << std::endl
				<< player << "WINS!!";
			gameOver = true;
		}
		else if (checkForDraw()) {
			std::cout << "IT'S A DRAW! Play again!" << std::endl;
			gameOver = true;
		}
		player = togglePlayer(player);
	} while (!gameOver);

	displayBoard();
}