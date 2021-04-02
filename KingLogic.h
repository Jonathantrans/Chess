#pragma once
#ifndef KING_LOGIC
#define KING_LOGIC
#include "ClassFigure.h"
#include "ClassChessBoard.h"

void ChessBoard::KingDirection(RectangleShape figure, int i, Figure enemyFigure[16], Figure friendFigure[16])
{
	if (gridCells[i].getPosition().y == figure.getPosition().y)//horizontal
	{
		if (gridCells[i].getPosition().x == figure.getPosition().x - figure.getSize().x || gridCells[i].getPosition().x == figure.getPosition().x + figure.getSize().x)
		{
			CheckForFriendFigures(i, friendFigure);
			CheckForEnemyFigures(i, enemyFigure);
		}
	}
	else if (gridCells[i].getPosition().x == figure.getPosition().x)//vertical
	{
		if (gridCells[i].getPosition().y == figure.getPosition().y - figure.getSize().y || gridCells[i].getPosition().y == figure.getPosition().y + figure.getSize().y)
		{
			CheckForFriendFigures(i, friendFigure);
			CheckForEnemyFigures(i, enemyFigure);
		}
	}
	//diagonal
	else if (gridCells[i].getPosition().x == figure.getPosition().x + figure.getSize().x || gridCells[i].getPosition().x == figure.getPosition().x - figure.getSize().x)
	{
		if (gridCells[i].getPosition().y == figure.getPosition().y + figure.getSize().y || gridCells[i].getPosition().y == figure.getPosition().y - figure.getSize().y)
		{
			CheckForFriendFigures(i, friendFigure);
			CheckForEnemyFigures(i, enemyFigure);
		}
	}
}

void ChessBoard::GameEnd(RenderWindow &window, Figure blackFigure[16], Figure whiteFigure[16], bool &isGamePaused, Font font, int minutesLeft, double secondsLeft)
{
	Text text;
	text.setFont(font);
	text.setPosition(200, 300);
	text.setCharacterSize(60);
	text.setOutlineThickness(5);

	for (int i = 0; i < 16; i++)
	{
		if ((blackFigure[i].GetType() == FigureType::king && blackFigure[i].GetRectangleShape().getPosition().x == -66) || (secondsLeft <= 1 && minutesLeft <= 0 && figureColor == "black"))
		{
			isGamePaused = true;
			text.setString("White win!");
			text.setFillColor(Color::White);
			text.setOutlineColor(Color::Black);
			window.draw(text);
		}
		else if ((whiteFigure[i].GetType() == FigureType::king && whiteFigure[i].GetRectangleShape().getPosition().x == -66) || (secondsLeft <= 1 && minutesLeft <= 0 && figureColor == "white"))
		{
			isGamePaused = true;
			text.setString("Black win!");
			text.setFillColor(Color::Black);
			text.setOutlineColor(Color::White);
			window.draw(text);
		}
	}
}

#endif // !KING_LOGIC
