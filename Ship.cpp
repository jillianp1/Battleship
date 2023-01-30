//include necesssary libraries/headers
#include "Ship.h"

Ship::Ship()
{
	int mstart_x = 0;
	int mend_x = 0;

	char mstart_y = 'Z';
	char mend_y = 'Z';
}
Ship::Ship(const int& newsize)
{
	this->mhits = (int*)calloc(newsize, sizeof(int));
	this->msize = newsize;
}

Ship::~Ship()
{
	delete this->mhits;
}

//functions
bool Ship::is_sunk(void)
{
	int i = 0, temp = 0, is_sunk = 1;
	for (i = 0; i < msize; i++)
	{
		if (this->mhits[i] == 0)
		{
			is_sunk = 0;
			return false;
		}
	}
	if (is_sunk == 1)
	{
		return true;
	}

}

void Ship::is_hit_update(string position)
{
	//get position from string
	char y_pos = 'Z';
	char temp = 'Z';
	int x_pos;
	position[0] = temp; //x is an integer
	x_pos = (int)temp - 48;
	position[1] = y_pos;

	//check if position overlaps with ship position
	//first find if its horizontal or vertical
	if (mstart_x == mend_x) //vertical
	{
		if (mstart_x == x_pos) //first check if it's even in the same column
		{
			char guess = mstart_y; //start position is always less than end
			int i = 0, hit = 0;
			while (i < msize && hit == 0)
			{
				if (guess + i == y_pos)
				{
					hit = 1;
				}
				else
				{
					i++;
				}
			}
			if (hit == 0)
			{
				mhits[i] = 1;
			}
		}

	}
	else if (mstart_y == mend_y) //horizontal
	{
		if (mstart_y == y_pos) //first check if it's even in the same row
		{
			char guess = mstart_x;//start position is always less than end
			int i = 0, hit = 0;
			while (i < msize && hit == 0)
			{
				if (guess + i == x_pos)
				{
					hit = 1;
				}
				else
				{
					i++;
				}
			}
			if (hit == 0)
			{
				mhits[i] = 1;
			}
		}
	}
}