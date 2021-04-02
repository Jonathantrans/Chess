#pragma once
#ifndef GAME_MOVEMENT_LOGIC
#define GAME_MOVEMENT_LOGIC
#include "ClassFigure.h"
#include "ClassChessBoard.h"

void ChessBoard::FigureMovement(FigureType &type, RectangleShape &figure, string position, Figure enemyFigure[16], Figure friendFigure[16])
{
	float nearestLeft = 66, nearestRigth = 600;
	float nearestUp = 66, nearestDown = 600;
	float nearestBefore = 66, nearestAfter = 600;
	switch (type)
	{
	case FigureType::king:
		for (int i = 0; i < 64; i++)
		{
			KingDirection(figure, i, enemyFigure, friendFigure);
		}
		break;
	case FigureType::queen:
		for (int i = 0; i < 64; i++)
		{
			DiagonalDirection(figure, i, enemyFigure, friendFigure, nearestAfter, nearestBefore);
			HorizontalDirection(figure, i, enemyFigure, friendFigure, nearestRigth, nearestLeft);
			VerticalDirection(figure, i, enemyFigure, friendFigure, nearestDown, nearestUp);
		}
		break;
	case FigureType::officer:
		for (int i = 0; i < 64; i++)
		{
			DiagonalDirection(figure, i, enemyFigure, friendFigure, nearestAfter, nearestBefore);
		}
		break;
	case FigureType::horse:
		for (int i = 0; i < 64; i++)
		{
			HorseDirection(figure, i, enemyFigure, friendFigure);
		}
		break;
	case FigureType::rook:
		for (int i = 0; i < 64; i++)
		{
			HorizontalDirection(figure, i, enemyFigure, friendFigure, nearestRigth, nearestLeft);
			VerticalDirection(figure, i, enemyFigure, friendFigure, nearestDown, nearestUp);
		}
		break;
	case FigureType::pawn:
		for (int i = 0; i < 64; i++)
		{
			PawnDirection(figure, i, position, enemyFigure, friendFigure);
		}
		PawnReachEndOfBoard(type, figure, position);
		break;
	case FigureType::pawnFirstMove:
		for (int i = 0; i < 64; i++)
		{
			PawnFirstMove(figure, i, position, enemyFigure, friendFigure);
		}
		type = FigureType(5);
		break;
	}
}

void ChessBoard::TakeFigure(RenderWindow &window, RectangleShape &figure, FigureType &type, string position, Figure enemyFigure[16], Figure friendFigure[16], int i, string color)
{
	Vector2i mousePosition = Mouse::getPosition(window);
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (mousePosition.x >= figure.getPosition().x && mousePosition.x <= figure.getPosition().x + figure.getSize().x &&
			mousePosition.y >= figure.getPosition().y && mousePosition.y <= figure.getPosition().y + figure.getSize().y)
		{
			if (figureColor == color)
			{
				isNextPlayerTurn = false;
			}
			else 
			{
				isNextPlayerTurn = true;
			}

			if ((isNextPlayerTurn == true && isTwoPlayersGameDraw == true) || (isComputerTurn == false && isOnePlayerGameDraw == true))
			{
				FigureMovement(type, figure, position, enemyFigure, friendFigure);
				isFigureTake = true;
				delete figureIndex;
				figureIndex = new int;
				*figureIndex = i;
				figureColor = color;
			}

			if (isOnePlayerGameDraw == true)
			{
				isComputerTurn = false;
			}
		}
	}
}

void ChessBoard::PlaceFigure(RenderWindow &window, Figure figure[16], Figure enemyFigure[16], int &minutesLeft, double &secondsLeft)
{
	Vector2i mousePosition = Mouse::getPosition(window);
	if (Mouse::isButtonPressed(Mouse::Right))
	{
		for (int i = 0; i < 64; i++)
		{
			if (mousePosition.x >= gridCells[i].getPosition().x && mousePosition.x <= gridCells[i].getPosition().x + gridCells[i].getSize().x &&
				mousePosition.y >= gridCells[i].getPosition().y && mousePosition.y <= gridCells[i].getPosition().y + gridCells[i].getSize().y)
			{
				if (gridCells[i].getOutlineColor() != Color::White)
				{
					figure[*figureIndex].SetPosition(gridCells[i].getPosition().x, gridCells[i].getPosition().y);

					if (gridCells[i].getOutlineColor() == Color::Red)
					{
						for (int n = 0; n < 16; n++)
						{
							if (gridCells[i].getPosition().x == enemyFigure[n].GetRectangleShape().getPosition().x && gridCells[i].getPosition().y == enemyFigure[n].GetRectangleShape().getPosition().y)
							{
								enemyFigure[n].SetPosition(-66, -66);
								enemyFigure[n].GetRectangleShape().setSize(Vector2f(0, 0));
							}
						}
					}

					SetGridCellsOutline();
					isFigureTake = false;
					secondsLeft = 60;
					minutesLeft = 2;
				}
				else
				{
					SetGridCellsOutline();
					isFigureTake = false;
					if (isOnePlayerGameDraw == false)
					{
						if (figureColor == "black")
						{
							figureColor = "white";
						}
						else
						{
							figureColor = "black";
						}
					}
				}
			}
		}

		if (isOnePlayerGameDraw == true)
		{
			isComputerTurn = true;
		}
	}
}

#endif // !GAME_MOVEMENT_LOGIC
