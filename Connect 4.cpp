// Connect 4

#include <iostream>
#include <conio.h>


//gamepieces X & O's =  control w/arrow keys - if statement?

char box[4] = "[ ]";
char Player1[4] = "[O]";
char Player2[4] = "[X]";
char* checkerboard[6][7];

void PlayerInput(int& position) 
{

	bool StopLoop = false;

	const int KEY_ARROW_CHAR1 = 224;
	const int KEY_ARROW_UP = 72;
	const int KEY_ARROW_DOWN = 80;
	const int KEY_ARROW_LEFT = 75;
	const int KEY_ARROW_RIGHT = 77;
	const int ENTER = 13;
	
	while (StopLoop != true )
	{
		unsigned char ch1 = _getch();
		if (ch1 == KEY_ARROW_CHAR1)
		{
			// Some Arrow key was pressed, determine which?
			unsigned char ch2 = _getch();
			switch (ch2)
			{
			case KEY_ARROW_LEFT:
				// code for arrow right
				position = position - 4;
				StopLoop = true;
				break;
			case KEY_ARROW_RIGHT:
				// code for arrow left
				position = position + 4;
				StopLoop = true;
				break;
			}
		}
		else
		{
			switch (ch1)
			{
				// Process other key presses if required.
			case ENTER:
				//replace address of box with player1
				checkerboard[0][0] = Player1;
				StopLoop = true;
				break;
			}
		}
	}
}


void Player_Movement(int NumberOfSpaces) 
{
	char space = ' ';

	for (int i = 0; i < NumberOfSpaces; i++)
	{
		std::cout << space;
	}

}

void Init_CheckerBoard()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			checkerboard[i][j] = box;
			std::cout << checkerboard[i][j] << ' ';
		}
		std::cout << "\n";
	}
}

void Print_CheckerBoard()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			std::cout << checkerboard[i][j] << ' ';
		}
		std::cout << "\n";
	}
}



int main()
{
	//intializing and printing checkerboard
	Init_CheckerBoard();
	std::cout << " O";

	int position = 0;
	while (true)
	{
		//Player input bounds preventing runoff from board
		if (position > 23 || position < 0)
		{
			position = 0;
		}
		PlayerInput(position);
		system("cls");
		
		//Update display after console clear
		Print_CheckerBoard();
		Player_Movement(position);

		std::cout <<  " O";
	}
 }



