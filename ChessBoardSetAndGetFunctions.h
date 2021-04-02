#pragma once
#ifndef CHESS_BOARD_SET_AND_GET_FUNCTIONS
#define CHESS_BOARD_SET_AND_GET_FUNCTIONS
#include "ClassChessBoard.h"
#include "ClassFigure.h"

void ChessBoard::SetFigurePositions(Figure figure[16], int start, int end, string position)
{
	if (position == "up")
	{
		int n = 0;
		for (int i = start; i < end; i++, n++)
		{
			figure[n].SetPosition(gridCells[i].getPosition().x, gridCells[i].getPosition().y);
		}
	}
	else
	{
		int n = 15;
		for (int i = start; i < end; i++)
		{
			figure[n].SetPosition(gridCells[i].getPosition().x, gridCells[i].getPosition().y);
			if (n > 8)
			{
				n--;
			}
			else if (n == 8)
			{
				n = 0;
			}
			else
			{
				n++;
			}
		}
	}
}

void ChessBoard::SetGridCellsPositions()
{
	int n = 0;//next cell position (horizontal)
	int multiply = 1;//go to next row
	for (int i = 0; i < 64; i++, n++)
	{
		gridCells[i].setPosition(66.0F * (n + 1), 66.0F * multiply);
		if (n == 7)
		{
			multiply++;
			n = -1;
		}
	}
}

void ChessBoard::SetGridCellsOutline()
{
	for (int i = 0; i < 64; i++)
	{
		gridCells[i].setOutlineColor(Color::White);
		gridCells[i].setOutlineThickness(0);
	}
}

RectangleShape ChessBoard::GetRectangleShape()
{
	return board;
}

#endif // !CHESS_BOARD_SET_AND_GET_FUNCTIONS
