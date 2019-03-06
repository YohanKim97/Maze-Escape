#pragma once

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
void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos)
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
	strcpy_s(Maze[9],  "11111111111111111111");
	strcpy_s(Maze[10], "00000000000111111000");
	strcpy_s(Maze[11], "00000000000110001110");
	strcpy_s(Maze[12], "01111111111111111111");
	strcpy_s(Maze[13], "00111000111110100000");
	strcpy_s(Maze[14], "00011110001111111100");
	strcpy_s(Maze[15], "00011111111111111110");
	strcpy_s(Maze[16], "00011111111111111110");
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
			if (Maze[i][j] == '4')
			{
				cout << "¢Í";
			}

			else if (pPlayerPos->x == j && pPlayerPos->y == i)
			{
				cout << "¨Ü";
			}

			else if (Maze[i][j] == '0')
			{
				// 2 bytes	
				cout << "¡á";
			}

			else if (Maze[i][j] == '1')
			{
				cout << "  ";
			}

			else if (Maze[i][j] == '2')
			{
				cout << "¢¼";
			}

			else if (Maze[i][j] == '3')
			{
				cout << "¡ã";
			}

		}
		cout << endl;
	}
}

void CreateBomb(char Maze[21][21], const PPOINT pPlayer, PPOINT pBombArr, int* pBombCount)
{
	if (*pBombCount == 5)
	{
		return;
	}

	for (int i = 0; i < *pBombCount; ++i)
	{
		if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y)
		{
			return;
		}
	}

	pBombArr[*pBombCount] = *pPlayer;
	++(*pBombCount);

	Maze[pPlayer->y][pPlayer->x] = '4';
}

void FireBomb(char Maze[21][21], PPOINT pPlayer, PPOINT pBombArr, int* pBombCount)
{
	for (int i = 0; i < *pBombCount; ++i)
	{	

		Maze[pBombArr[i].y][pBombArr[i].x] = '1';
		
			// If Player striked by bomb
			// return player to start point
		if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y - 1)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}

		if (pBombArr[i].y - 1 >= 0)
		{
			if (Maze[pBombArr[i].y - 1][pBombArr[i].x] == '0')
			{
				Maze[pBombArr[i].y - 1][pBombArr[i].x] = '1';
			}
			// If Player striked by bomb
			// return player to start point
			if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y - 1)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}

		if (pBombArr[i].y - 1 >= 0)
		{
			if (Maze[pBombArr[i].y + 1][pBombArr[i].x] == '0')
			{
				Maze[pBombArr[i].y + 1][pBombArr[i].x] = '1';
			}

			// If Player striked by bomb
			// return player to start point
			if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y + 1)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}

		}

		//Left
		if (pBombArr[i].x + 1 < 20)
		{
			if (Maze[pBombArr[i].y][pBombArr[i].x + 1] == '0')
			{
				Maze[pBombArr[i].y][pBombArr[i].x + 1] = '1';
			}

			// If Player striked by bomb
			// return player to start point
			if (pPlayer->x == pBombArr[i].x + 1 && pPlayer->y == pBombArr[i].y)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}

		}
		
		//Right
		if (pBombArr[i].x - 1 < 20)
		{
			if (Maze[pBombArr[i].y][pBombArr[i].x - 1] == '0')
			{
				Maze[pBombArr[i].y][pBombArr[i].x - 1] = '1';
			}
		}

		// If Player striked by bomb
		// return player to start point
		if (pPlayer->x == pBombArr[i].x - 1 && pPlayer->y == pBombArr[i].y)
		{
			pPlayer->x = 0;
			pPlayer->y = 0;
		}
	}
	*pBombCount = 0;
}
