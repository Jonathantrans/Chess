#pragma once
#ifndef FIGURE_MOVE_DIRECTIONS
#define FIGURE_MOVE_DIRECTIONS
#include "ClassFigure.h"
#include "ClassChessBoard.h"

void ChessBoard::CheckForEnemyFigures(int i, Figure figure[16])
{
	for (int n = 0; n < 16; n++)
	{
		if (gridCells[i].getPosition().x == figure[n].GetRectangleShape().getPosition().x && gridCells[i].getPosition().y == figure[n].GetRectangleShape().getPosition().y)
		{
			gridCells[i].setOutlineColor(Color::Red);
			gridCells[i].setOutlineThickness(3);
			break;
		}
	}
}

void ChessBoard::CheckForFriendFigures(int i, Figure figure[16])
{
	gridCells[i].setOutlineColor(Color::Green);
	gridCells[i].setOutlineThickness(3);
	for (int n = 0; n < 16; n++)
	{
		if (gridCells[i].getPosition().x == figure[n].GetRectangleShape().getPosition().x && gridCells[i].getPosition().y == figure[n].GetRectangleShape().getPosition().y)
		{
			gridCells[i].setOutlineColor(Color::White);
			gridCells[i].setOutlineThickness(0);
			break;
		}
	}
}

void ChessBoard::SetUpNearestHorizontally(RectangleShape figure, Figure nearFigure, float &nearestRigth, float &nearestLeft)
{
	if (nearestRigth > nearFigure.GetRectangleShape().getPosition().x && nearFigure.GetRectangleShape().getPosition().x > figure.getPosition().x)
	{
		nearestRigth = nearFigure.GetRectangleShape().getPosition().x;
	}
	else if (nearestLeft < nearFigure.GetRectangleShape().getPosition().x && nearFigure.GetRectangleShape().getPosition().x < figure.getPosition().x)
	{
		nearestLeft = nearFigure.GetRectangleShape().getPosition().x;
	}
}

void ChessBoard::CheckForNearestHorizontally(RectangleShape figure, int i, Figure enemyFigure[16], Figure friendFigure[16], float &nearestRigth, float &nearestLeft)
{
	if (gridCells[i].getPosition().x > figure.getPosition().x && gridCells[i].getPosition().x <= nearestRigth)
	{
		CheckForFriendFigures(i, friendFigure);
		CheckForEnemyFigures(i, enemyFigure);
	}
	else if (gridCells[i].getPosition().x < figure.getPosition().x && gridCells[i].getPosition().x >= nearestLeft)
	{
		CheckForFriendFigures(i, friendFigure);
		CheckForEnemyFigures(i, enemyFigure);
	}
}

void ChessBoard::HorizontalDirection(RectangleShape figure, int i, Figure enemyFigure[16], Figure friendFigure[16], float &nearestRigth, float &nearestLeft)
{
	for (int n = 0; n < 16; n++)
	{
		if (gridCells[i].getPosition().y == figure.getPosition().y)
		{
			if(gridCells[i].getPosition().y == enemyFigure[n].GetRectangleShape().getPosition().y)
			{
				SetUpNearestHorizontally(figure, enemyFigure[n], nearestRigth, nearestLeft);
			}
			else if (gridCells[i].getPosition().y == friendFigure[n].GetRectangleShape().getPosition().y)
			{
				SetUpNearestHorizontally(figure, friendFigure[n], nearestRigth, nearestLeft);
			}
		}
	}

	if (gridCells[i].getPosition().y == figure.getPosition().y)
	{
		CheckForNearestHorizontally(figure, i, enemyFigure, friendFigure, nearestRigth, nearestLeft);
	}
}

void ChessBoard::SetUpNearestVertically(RectangleShape figure, Figure nearFigure,float &nearestDown, float &nearestUp)
{
	if (nearestDown > nearFigure.GetRectangleShape().getPosition().y && nearFigure.GetRectangleShape().getPosition().y > figure.getPosition().y)
	{
		nearestDown = nearFigure.GetRectangleShape().getPosition().y;
	}
	else if (nearestUp < nearFigure.GetRectangleShape().getPosition().y && nearFigure.GetRectangleShape().getPosition().y < figure.getPosition().y)
	{
		nearestUp = nearFigure.GetRectangleShape().getPosition().y;
	}
}

void ChessBoard::CheckForNearestVertically(RectangleShape figure, int i, Figure enemyFigure[16], Figure friendFigure[16], float &nearestDown, float &nearestUp)
{
	if (gridCells[i].getPosition().y > figure.getPosition().y && gridCells[i].getPosition().y <= nearestDown)
	{
		CheckForFriendFigures(i, friendFigure);
		CheckForEnemyFigures(i, enemyFigure);
	}
	else if (gridCells[i].getPosition().y < figure.getPosition().y && gridCells[i].getPosition().y >= nearestUp)
	{
		CheckForFriendFigures(i, friendFigure);
		CheckForEnemyFigures(i, enemyFigure);
	}
}

void ChessBoard::VerticalDirection(RectangleShape figure, int i, Figure enemyFigure[16], Figure friendFigure[16], float &nearestDown, float &nearestUp)
{
	for (int n = 0; n < 16; n++)
	{
		if (gridCells[i].getPosition().x == figure.getPosition().x)
		{
			if (gridCells[i].getPosition().x == enemyFigure[n].GetRectangleShape().getPosition().x)
			{
				SetUpNearestVertically (figure, enemyFigure[n], nearestDown, nearestUp);
			}
			else if (gridCells[i].getPosition().x == friendFigure[n].GetRectangleShape().getPosition().x)
			{
				SetUpNearestVertically(figure, friendFigure[n], nearestDown, nearestUp);
			}
		}
	}

	if (gridCells[i].getPosition().x == figure.getPosition().x)
	{
		CheckForNearestVertically(figure, i, enemyFigure, friendFigure, nearestDown, nearestUp);
	}
}

void ChessBoard::DiagonalDirection(RectangleShape figure, int i, Figure enemyFigure[16], Figure friendFigure[16], float &nearestDown, float &nearestUp)
{
	for (int n = 0; n < 16; n++)
	{
		if (figure.getPosition().x - figure.getPosition().y == gridCells[i].getPosition().x - gridCells[i].getPosition().y)
		{
			if (enemyFigure[n].GetRectangleShape().getPosition().x - enemyFigure[n].GetRectangleShape().getPosition().y == gridCells[i].getPosition().x - gridCells[i].getPosition().y)
			{
				SetUpNearestVertically(figure, enemyFigure[n], nearestDown, nearestUp);
			}
			else if(friendFigure[n].GetRectangleShape().getPosition().x - friendFigure[n].GetRectangleShape().getPosition().y == gridCells[i].getPosition().x - gridCells[i].getPosition().y)
			{
				SetUpNearestVertically(figure, friendFigure[n], nearestDown, nearestUp);
			}
		}
		else if (figure.getPosition().x + figure.getPosition().y == gridCells[i].getPosition().x + gridCells[i].getPosition().y)
		{
			if (enemyFigure[n].GetRectangleShape().getPosition().x + enemyFigure[n].GetRectangleShape().getPosition().y == gridCells[i].getPosition().x + gridCells[i].getPosition().y)
			{
				SetUpNearestVertically(figure, enemyFigure[n], nearestDown, nearestUp);
			}
			else if (friendFigure[n].GetRectangleShape().getPosition().x + friendFigure[n].GetRectangleShape().getPosition().y == gridCells[i].getPosition().x + gridCells[i].getPosition().y)
			{
				SetUpNearestVertically(figure, friendFigure[n], nearestDown, nearestUp);
			}
		}
	}

	if (figure.getPosition().x - figure.getPosition().y == gridCells[i].getPosition().x - gridCells[i].getPosition().y)
	{
		CheckForNearestVertically(figure, i, enemyFigure, friendFigure, nearestDown, nearestUp);
	}
	else if (figure.getPosition().x + figure.getPosition().y == gridCells[i].getPosition().x + gridCells[i].getPosition().y)
	{
		CheckForNearestVertically(figure, i, enemyFigure, friendFigure, nearestDown, nearestUp);
	}
}

#endif // !FIGURE_MOVE_DIRECTIONS
