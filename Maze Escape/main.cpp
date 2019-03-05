#include <iostream>
#include <conio.h>
#include "maze.h"
#include "mazeMovement.h"

using namespace std;

/*
	Rule
	0 : Wall
	1 : Road
	2 : Start Point
	3 : End Point
*/

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
		
		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y)
		{
			cout << " Escaped !!!!!! " << endl;
			break;
		}

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