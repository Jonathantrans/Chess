#pragma once
#ifndef GAME_LOGIC
#define GAME_LOGIC
#include "ClassFigure.h"
#include "ClassChessBoard.h"
#include "ClassAI.h"

void ChessBoard::ChooseFigure(string color, FigureType &type, RectangleShape &figure)
{
	RenderWindow ChooseFigure(VideoMode(264, 66), "Choose Figure", Style::Titlebar | Style::Close);
	RectangleShape Figures[4], background;
	background.setFillColor(Color::White);
	background.setSize(Vector2f(ChooseFigure.getSize().x, ChooseFigure.getSize().y));

	FigureType fType[4];
	fType[0] = FigureType(4);
	fType[1] = FigureType(3);
	fType[2] = FigureType(2);
	fType[3] = FigureType(1);

	pawnReachEndTextureBlack[0].loadFromFile("Images\\BlackRook.png");
	pawnReachEndTextureBlack[1].loadFromFile("Images\\BlackHorse.png");
	pawnReachEndTextureBlack[2].loadFromFile("Images\\BlackOfficer.png");
	pawnReachEndTextureBlack[3].loadFromFile("Images\\BlackQueen.png");

	pawnReachEndTextureWhite[0].loadFromFile("Images\\WhiteRook.png");
	pawnReachEndTextureWhite[1].loadFromFile("Images\\WhiteHorse.png");
	pawnReachEndTextureWhite[2].loadFromFile("Images\\WhiteOfficer.png");
	pawnReachEndTextureWhite[3].loadFromFile("Images\\WhiteQueen.png");

	for (int i = 0; i < 4; i++)
	{
		Figures[i].setSize(Vector2f(66, 66));
		Figures[i].setPosition(0.0F + i * 66.0F, 0.0F);
		if (color == "Black")
		{
			Figures[i].setTexture(&pawnReachEndTextureBlack[i]);
		}
		else
		{
			Figures[i].setTexture(&pawnReachEndTextureWhite[i]);
		}

	}

	while (ChooseFigure.isOpen())
	{
		while (true)
		{
			Event event;
			while (ChooseFigure.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					ChooseFigure.close();
				}
			}

			for (int i = 0; i < 4; i++)
			{
				Vector2i mousePosition = Mouse::getPosition(ChooseFigure);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					if (mousePosition.x >= Figures[i].getPosition().x && mousePosition.x <= Figures[i].getPosition().x + Figures[i].getSize().x &&
						mousePosition.y >= Figures[i].getPosition().y && mousePosition.y <= Figures[i].getPosition().y + Figures[i].getSize().y)
					{
						if (color == "Black")
						{
							figure.setTexture(&pawnReachEndTextureBlack[i]);
						}
						else
						{
							figure.setTexture(&pawnReachEndTextureWhite[i]);
						}
						
						type = FigureType(fType[i]);
						ChooseFigure.close();
						isFigureChoosen = true;
					}
				}
			}

			if (isOnePlayerGameDraw == true && isComputerTurn == true)
			{
				computer.SwitchPawnWithFigure(Figures, type, figure, fType, ChooseFigure, isFigureChoosen, color);
			}

			if (isFigureChoosen == true)
			{
				break;
			}

			ChooseFigure.clear();
			ChooseFigure.draw(background);
			for (int i = 0; i < 4; i++)
			{
				ChooseFigure.draw(Figures[i]);
			}
			ChooseFigure.display();
		}
	}
}

void ChessBoard::PawnReachEndOfBoard(FigureType &type, RectangleShape &figure, string position)
{
	isFigureChoosen = false;
	if (position == "down")
	{
		if (figure.getPosition().y >= 528)
		{
			ChooseFigure("Black", type, figure);
		}
	}
	else
	{
		if (figure.getPosition().y <= 66)
		{
			ChooseFigure("White", type, figure);
		}
	}
}

#endif // !GAME_LOGIC
