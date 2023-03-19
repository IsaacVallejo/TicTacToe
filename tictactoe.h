#ifndef TICTACTOE_H
#define TICTACTOE_H

class tictactoe {

public:
	tictactoe();
	//default constructor initializes board and moves counter
	void displayBoard() const;
	//displays board through each iteration
	void getMove(char player);
	//ask the user for the next move 
	//once recieved checks if move is valid
	//and stores move in board for next iteration
	void playGame();
	//creates a loop in order to play the game

private:
	static const int BSIZE = 3; //board size
	static const int maxMoves = 9; //max moves possible in a game of ttt
	static const int minMovesToWin = 5; //min moves before checking for win

	char board[BSIZE][BSIZE]; //our board
	int totalMoves; //moves counter
	bool checkForWins(char player)const;
	//takes in the player sign
	//checks board (rows, colums and diagonals) to see if we have foudn a winner
	bool checkForDraw()const;
	//checks to see if max number of moves has been reached.
	// if so it's a tie
	void fill_board();
	//fills our 3*3 array of blank spaces
	char togglePlayer(char player);
	//changes the player sign at the end of the turn
};
#endif