#pragma once


//include necesssary libraries/headers
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const int water = 0;
const int ship = 1;
const int hit = 2;
const int miss = 3;

class Ship
{
public:
	Ship(const int& newsize);
	Ship();
	~Ship();

	//functions
	bool is_sunk(void);

	void is_hit_update(string position);

private:
	//position trackers
	int mstart_x;
	int mend_x;

	char mstart_y;
	char mend_y;

	//size
	int msize;

	//tracks if a ship is sunk
	int msunk = 0;

	//array tracks hit positions
	int* mhits; //int* hits = (int*)calloc(size, sizeof(int));
};

