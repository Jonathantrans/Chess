#pragma once
#ifndef PAWN_AND_HORSE_MOVE_DIRECTIONS
#define PAWN_AND_HORSE_MOVE_DIRECTIONS
#include "ClassFigure.h"
#include "ClassChessBoard.h"

void ChessBoard::PawnFirstMove(RectangleShape figure, int i, string position, Figure enemyFigure[16], Figure friendFigure[16])
{
	if (position == "down")
	{
		if (gridCells[i].getPosition().x == figure.getPosition().x)
		{
			if (gridCells[i].getPosition().y == figure.getPosition().y + figure.getSize().y || gridCells[i].getPosition().y == figure.getPosition().y + figure.getSize().y * 2)
			{
				CheckForFriendFigures(i, friendFigure);
				CheckForFriendFigures(i, enemyFigure);
			}
		}
	}
	else
	{
		if (gridCells[i].getPosition().x == figure.getPosition().x)
		{
			if (gridCells[i].getPosition().y == figure.getPosition().y - figure.getSize().y || gridCells[i].getPosition().y == figure.getPosition().y - figure.getSize().y * 2)
			{
				CheckForFriendFigures(i, friendFigure);
				CheckForFriendFigures(i, enemyFigure);
			}
		}
	}
}

void ChessBoard::PawnDirection(RectangleShape figure, int i, string position, Figure enemyFigure[16], Figure friendFigure[16])
{
	if (position == "down")
	{
		if (gridCells[i].getPosition().x == figure.getPosition().x  && gridCells[i].getPosition().y == figure.getPosition().y + figure.getSize().y)
		{
			CheckForFriendFigures(i, friendFigure);
			CheckForFriendFigures(i, enemyFigure);
		}
		else if (gridCells[i].getPosition().y == figure.getPosition().y + figure.getSize().y)
		{
			if (gridCells[i].getPosition().x == figure.getPosition().x + figure.getSize().x || gridCells[i].getPosition().x == figure.getPosition().x - figure.getSize().x)
			{
				CheckForEnemyFigures(i, enemyFigure);
			}
		}
	}
	else
	{
		if (gridCells[i].getPosition().x == figure.getPosition().x && gridCells[i].getPosition().y == figure.getPosition().y - figure.getSize().y)
		{
			CheckForFriendFigures(i, friendFigure);
			CheckForFriendFigures(i, enemyFigure);
		}
		else if (gridCells[i].getPosition().y == figure.getPosition().y - figure.getSize().y)
		{
			if (gridCells[i].getPosition().x == figure.getPosition().x + figure.getSize().x || gridCells[i].getPosition().x == figure.getPosition().x - figure.getSize().x)
			{
				CheckForEnemyFigures(i, enemyFigure);
			}
		}
	}
}

void ChessBoard::HorseDirection(RectangleShape figure, int i, Figure enemyFigure[16], Figure friendFigure[16])
{
	if (gridCells[i].getPosition().x == figure.getPosition().x + figure.getSize().x * 2 || gridCells[i].getPosition().x == figure.getPosition().x - figure.getSize().x * 2)
	{
		if (gridCells[i].getPosition().y == figure.getPosition().y - figure.getSize().y || gridCells[i].getPosition().y == figure.getPosition().y + figure.getSize().y)
		{
			CheckForFriendFigures(i, friendFigure);
			CheckForEnemyFigures(i, enemyFigure);
		}
	}
	else if (gridCells[i].getPosition().y == figure.getPosition().y + figure.getSize().y * 2 || gridCells[i].getPosition().y == figure.getPosition().y - figure.getSize().y * 2)
	{
		if (gridCells[i].getPosition().x == figure.getPosition().x - figure.getSize().x || gridCells[i].getPosition().x == figure.getPosition().x + figure.getSize().x)
		{
			CheckForFriendFigures(i, friendFigure);
			CheckForEnemyFigures(i, enemyFigure);
		}
	}
}

#endif // !PAWN_AND_HORSE_MOVE_DIRECTIONS
