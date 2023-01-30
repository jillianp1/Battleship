#pragma once
#include "Ship.h"

class Board
{
public:
	Board();
	void initializeBoard();

	void printBoard();

	void markShips();

	void initialize2D();

	void printBoard(int board2D[10][10]);

	int convertY(char y);

	bool checkHit(int board2D[10][10]);

	void playGame();
	
private:
	//game board
	int board2D[10][10];
	int ypos;
	int xpos;

};
