#include <iostream>
#include <conio.h>

using namespace std;

/*
	Rule
	0 : Wall
	1 : Road
	2 : Start Point
	3 : End Point
*/

struct _tagPoint
{
	int x;
	int y;

};


typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

// 21 array to build a structure of the Maze
// Last one is for NULL
void SetMaze(char Maze[21][21], PPOINT pPlayerPos,PPOINT pStartPos, PPOINT pEndPos)
{
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	*pPlayerPos = *pStartPos;

	strcpy_s(Maze[0],  "21111111111111111111");
	strcpy_s(Maze[1],  "11111111010011100000");
	strcpy_s(Maze[2],  "00001111111111111111");
	strcpy_s(Maze[3],  "11111111111111111111");
	strcpy_s(Maze[4],  "00000111111111111000");
	strcpy_s(Maze[5],  "00000111111111111000");
	strcpy_s(Maze[6],  "01111110000000111110");
	strcpy_s(Maze[6],  "00000000011111111110");
	strcpy_s(Maze[7],  "00011111111111100000");
	strcpy_s(Maze[9],  "11111111111111111000");
	strcpy_s(Maze[10], "00000000001111000000");
	strcpy_s(Maze[11], "00000000000110001110");
	strcpy_s(Maze[12], "00000001100111111000");
	strcpy_s(Maze[13], "00111000111110100000");
	strcpy_s(Maze[14], "00011110001111111100");
	strcpy_s(Maze[15], "00000000111111110000");
	strcpy_s(Maze[16], "00011111111111110000");
	strcpy_s(Maze[17], "00111100011111110000");
	strcpy_s(Maze[18], "00000011100011111100");
	strcpy_s(Maze[19], "11111111111100011113");
	
}

void Output(char Maze[21][21], PPOINT pPlayerPos)
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (pPlayerPos->x == j && pPlayerPos->y == i)
			{
				cout << "и▄";
			}

			else if (Maze[i][j] == '0')
			{
				// 2 bytes	
				cout << "бс";
			}

			else if (Maze[i][j] == '1')
			{
				cout << "  ";
			}
				
			else if (Maze[i][j] == '2')
			{
				cout << "в╝";
			}
			else if (Maze[i][j] == '3')
			{
				cout << "бу";
			}

		}
		cout << endl;
	}
}

void MoveUp(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y - 1 >= 0)
	{
		//Check the wall
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0')
		{
			--pPlayerPos->y;
		}
	}
}

void MoveDown(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y + 1 < 20)
	{
		//Check the wall
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0')
		{
			++pPlayerPos->y;
		}
	}
}

void MoveRight(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x + 1 < 20)
	{
		//Check the wall
		if (Maze[pPlayerPos->y ][pPlayerPos->x + 1] != '0')
		{
			++pPlayerPos->x;
		}
	}
}

void MoveLeft(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x + 1 < 20)
	{
		//Check the wall
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0')
		{
			--pPlayerPos->x;
		}
	}
}

void MovePlayer(char Maze[21][21], PPOINT pPlayerPos, char cInput)
{
	switch (cInput)
	{
	case 'w':
	case 'W':

		MoveUp(Maze, pPlayerPos);

		break;
	case 's':
	case 'S':

		MoveDown(Maze, pPlayerPos);

		break;
	case 'a':
	case 'A':

		MoveLeft(Maze, pPlayerPos);

		break;
	case 'd':
	case 'D':

		MoveRight(Maze, pPlayerPos);

		break;

	}
}

int main()
{
	// 20 X 20 Board
	char strMaze[21][21] = {};

	/*
		Position for Player
		and Start and End Position
	*/
	POINT tPlayerPos;
	POINT tStartPos;
	POINT tEndPos;

	//Set the Maze
	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);

	while (true)
	{
		system("cls");
		//Print out the Maze
		Output(strMaze, &tPlayerPos);
		
		cout << "W : Up, S : Down, A : Left, D : Right, Q : EXIT ";
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
		{
			break;
		}

		MovePlayer(strMaze, &tPlayerPos, cInput);

	}
	

	return 0;
} 