#include "Board.h"

Board::Board()
{
	
}

//one dimenstional array attempt
// not used in program right now
void Board::initializeBoard()
{
	int level1[] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	cout << "  1 2 3 4 5 6 7 8 9 10" << endl;
	char letter = 'A';
	for (int i = 0; i < 10; i++)
	{
		cout << letter << ' ';
		for (int i = 0; i < 10; i++)
		{
			cout << level1[i] << ' ';
		}
		cout << "\n";
		letter++;
	}
	/*int gameBoard[10][10];
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			gameBoard[x][y] = 0;
		}
	}*/
}

//converts the char (y) entered to an int
int Board::convertY(char y)
{
	int ypos = 0;
	//hard code to convert y
	if (y == 'A')
	{
		ypos = 0;
	}
	else if (y == 'B')
	{
		ypos = 1;
	}
	else if (y == 'C')
	{
		ypos = 2;
	}
	else if (y == 'D')
	{
		ypos = 3;
	}
	else if (y == 'E')
	{
		ypos = 4;
	}
	else if (y == 'F')
	{
		ypos = 5;
	}
	else if (y == 'G')
	{
		ypos = 6;
	}
	else if (y == 'H')
	{
		ypos = 7;
	}
	else if (y == 'I')
	{
		ypos = 8;
	}
	else if (y == 'J')
	{
		ypos = 9;
	}

	return ypos;
}

//marks a ship on board
// need to figure out how to do multiple and how to keep updating board/array
void Board::markShips()
{
	int x;
	char y;
	int ypos = 0;
	int xpos;
	int water = 0;
	initialize2D();
	cout << "Lets place your battleship- 5 spaces" << endl;
	for (int n = 1; n < 6; n++)
	{
		cout << "Enter x coordinate for ship to place int" << endl;
		cin >> x;
		cout << "Enter y coordinate for ship to place (captial letter A-J)" << endl;
		cin >> y;
		//convert y char to int
		int ypos = convertY(y);
		//change x to be for array
		xpos = x - 1;
		//set to one meaning ship in array 
		board2D[ypos][xpos] = 1;
		
		//print board
		char letter = 'A';
		cout << "   1  2  3  4  5  6  7  8  9  10" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << letter;
			for (int j = 0; j < 10; j++)
			{
				board2D[i][j];
				board2D[ypos][xpos] = 1;
				cout << "  " << board2D[i][j];
			}
			cout << "\n";
			letter++;
		}
		bool hit = checkHit(board2D);
		// if they hit they can guess again
		if (hit == true)
		{
			checkHit(board2D);
		}
	}
}

void Board::printBoard(int board2D[10][10])
{
	//print board
	char letter = 'A';
	cout << "   1  2  3  4  5  6  7  8  9  10" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << letter;
		for (int j = 0; j < 10; j++)
		{
			board2D[i][j] = 0;
			board2D[ypos][xpos] = 1;
			cout << "  " << board2D[i][j];
		}
		cout << "\n";
		letter++;
	}
}

// makes starting 2D array game board and prints it to screen
void Board::initialize2D()
{
	//print starting board to screen 
	int board2D[10][10];
	//int count = 1;
	char letter = 'A';
	cout << "   1  2  3  4  5  6  7  8  9  10" << endl;
	for (int i = 0; i< 10; i++)
	{
		cout << letter;
		for (int j = 0; j < 10; j++)
		{
			board2D[i][j] = 0;
			cout << "  " <<board2D[i][j] ;
		}
		cout << "\n";
		letter++;
	}
}

//pass it array 
//checks to see if user entered coordinate is a hit
bool Board::checkHit(int board2D[10][10])
{
	int guessX = 0;
	char y;
	int guessY;
	int x;

	cout << "Enter x coordinate to check for a hit" << endl;
	cin >> x;
	cout << "Enter y to check for a hit" << endl;
	cin >> y;
	guessX = x - 1;
	guessY = convertY(y);

	//go through array to check for hit
	if (board2D[guessY][guessX] == 1)
	{			
		//set element of array to 2 for hit
		board2D[guessY][guessX] = 2;
		// if they get a hit they can guess again
		return true;
	}
	else if (board2D[guessY][guessX] == 0)
	{
		//set to 3 for miss
		board2D[guessY][guessX] = 3;
		return false;
	}
}

// function to play and start game
void Board::playGame()
{
	markShips();


}