#pragma once
#include "maze.h"


using namespace std;

void MoveUp(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y - 1 >= 0)
	{
		//Check the wall
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0' &&
			Maze[pPlayerPos->y - 1][pPlayerPos->x] != '4')
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
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0' &&
			Maze[pPlayerPos->y + 1][pPlayerPos->x] != '4')
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
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0' &&
			Maze[pPlayerPos->y][pPlayerPos->x + 1] != '4')
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
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0' &&
			Maze[pPlayerPos->y][pPlayerPos->x - 1] != '4')
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