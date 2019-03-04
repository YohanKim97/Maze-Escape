#include <iostream>

using namespace std;

/*
	Rule
	0 : Wall
	1 : Road
	2 : Start Point
	3 : End Point
*/

// 21 array to build a structure of the Maze
// Last one is for NULL
void SetMaze(char Maze[21][21])
{
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

void Output(char Maze[21][21])
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (Maze[i][j] == '0')
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

int main()
{
	// 20 X 20 Board
	char strMaze[21][21] = {};

	//Set the Maze
	SetMaze(strMaze);

	//Print out the Maze
	Output(strMaze);

	return 0;
} 