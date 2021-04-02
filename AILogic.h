#pragma once
#ifndef AI_LOGIC
#define AI_LOGIC
#include "ClassFigure.h"
#include "ClassChessBoard.h"
#include "ClassAI.h"

void AI::SwitchPawnWithFigure(RectangleShape Figures[4], FigureType &type, RectangleShape &figure, FigureType fType[4], RenderWindow &ChooseFigure, bool &isFigureChoosen, string color)
{
	int figuresIndex = rand() % 4;
	if (color == "Black")
	{
		figure.setTexture(&pawnReachEndTextureBlack[figuresIndex]);
	}
	else
	{
		figure.setTexture(&pawnReachEndTextureWhite[figuresIndex]);
	}
	type = FigureType(fType[figuresIndex]);
	ChooseFigure.close();
	isFigureChoosen = true;
}

void AI::PlaceFigure(vector<int> &countPossibleMoves, int &figureIndex, Figure figure[16], ChessBoard &chessBoard, Figure enemyFigure[16])
{
	int gridCellIndex = countPossibleMoves[rand() % countPossibleMoves.size()];
	figure[figureIndex].GetRectangleShape().setPosition(chessBoard.gridCells[gridCellIndex].getPosition().x, chessBoard.gridCells[gridCellIndex].getPosition().y);
	countPossibleMoves.erase(countPossibleMoves.begin(), countPossibleMoves.begin() + (countPossibleMoves.size() - 1));//reduce size to 0

	if (chessBoard.gridCells[gridCellIndex].getOutlineColor() == Color::Red)
	{
		for (int i = 0; i < 16; i++)
		{
			if (enemyFigure[i].GetRectangleShape().getPosition().x == chessBoard.gridCells[gridCellIndex].getPosition().x
				&& enemyFigure[i].GetRectangleShape().getPosition().y == chessBoard.gridCells[gridCellIndex].getPosition().y)
			{
				enemyFigure[i].GetRectangleShape().setPosition(-66, -66);
			}
		}
	}
	chessBoard.SetGridCellsOutline();
	isComputerTurn = false;
}

void AI::ChooseFigure(ChessBoard &chessBoard, RenderWindow &window, Figure figure[16], string position, Figure enemyFigure[16], Figure friendFigure[16], string color)
{
	if (isComputerTurn == true)
	{
		srand(time(0));
		int figureIndex = rand() % 16;
		chessBoard.FigureMovement(figure[figureIndex].GetType(), figure[figureIndex].GetRectangleShape(), position, enemyFigure, friendFigure);
		vector<int> countPossibleMoves;
		for (int i = 0; i < 64; i++)
		{
			if (chessBoard.gridCells[i].getOutlineColor() == Color::Green || chessBoard.gridCells[i].getOutlineColor() == Color::Red)
			{
				countPossibleMoves.push_back(i);
			}
		}

		if (countPossibleMoves.size() == 0)
		{
			ChooseFigure(chessBoard, window, figure, position, enemyFigure, friendFigure, color);
		}
		else
		{
			PlaceFigure(countPossibleMoves, figureIndex, figure, chessBoard, enemyFigure);
		}
	}
}

#endif // AI_LOGIC
