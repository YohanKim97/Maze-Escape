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
	4 : Bomb
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

	int iBombCount = 0;


	POINT tBombPos[5];

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

		cout << " Bomb Count : " << CreateBomb << endl;
		cout << "G : Install Bomb, L : Burst Bomb" << endl << endl;
		cout << "W : Up, S : Down, A : Left, D : Right, Q : EXIT ";

		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
		{
			break;
		}

		else if (cInput == 'g' || cInput == 'G')
		{
			CreateBomb(strMaze, &tPlayerPos, tBombPos, &iBombCount);
		}

		else if (cInput == 'l' || cInput == 'L')
		{
			FireBomb(strMaze, &tPlayerPos, tBombPos, &iBombCount);
		}

		else
		{
			MovePlayer(strMaze, &tPlayerPos, cInput);
		}

		MovePlayer(strMaze, &tPlayerPos, cInput);

	}
	

	return 0;
} 