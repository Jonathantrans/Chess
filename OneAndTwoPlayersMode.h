#pragma once
#ifndef ONE_AND_TWO_PLAYERS_MODE
#define ONE_AND_TWO_PLAYERS_MODE
#include "ClassFigure.h"
#include "ClassChessBoard.h"

void OnePlayerMode(RenderWindow &window, ChessBoard &chessBoard, Figure blackFigures[16], Figure whiteFigures[16], double &secondsLeft, int &minutesLeft, bool isGamePaused, Text &seconds, Text &minutes, Font font)
{
	if (isGamePaused == false)
	{
		if ((int)secondsLeft > 0)
		{
			secondsLeft -= 0.005;
		}
		if ((int)secondsLeft == 0 && minutesLeft > 0)
		{
			minutesLeft--;
			secondsLeft = 60;
		}
		string leftSeconds = to_string((int)secondsLeft), leftMinutes = to_string(minutesLeft) + " : ";
		seconds.setString(leftSeconds);
		minutes.setString(leftMinutes);

		if (isFigureTake == true)
		{
			if (chessBoard.figureColor == "white")
			{
				chessBoard.PlaceFigure(window, whiteFigures, blackFigures, minutesLeft, secondsLeft);
			}
			else
			{
				chessBoard.PlaceFigure(window, blackFigures, whiteFigures, minutesLeft, secondsLeft);
			}
		}
		else
		{
			for (int i = 0; i < 16; i++)
			{
				if (isWhiteChoosen == true)
				{
					chessBoard.TakeFigure(window, whiteFigures[i].GetRectangleShape(), whiteFigures[i].GetType(), "up", blackFigures, whiteFigures, i, "white");
				}
				else
				{
					chessBoard.TakeFigure(window, blackFigures[i].GetRectangleShape(), blackFigures[i].GetType(), "down", whiteFigures, blackFigures, i, "black");
				}
			}
		}

		if (isWhiteChoosen == true)
		{
			computer.ChooseFigure(chessBoard, window, blackFigures, "down", whiteFigures, blackFigures, "black");
		}
		else
		{
			computer.ChooseFigure(chessBoard, window, whiteFigures, "up", blackFigures, whiteFigures, "white");
		}

		window.clear();
		window.draw(chessBoard.GetRectangleShape());
		chessBoard.DrawGridCells(window);

		for (int i = 0; i < 16; i++)
		{
			window.draw(whiteFigures[i].GetRectangleShape());
		}

		for (int i = 0; i < 16; i++)
		{
			window.draw(blackFigures[i].GetRectangleShape());
		}
	}
	chessBoard.GameEnd(window, blackFigures, whiteFigures, isGamePaused, font, minutesLeft, secondsLeft);
	window.draw(seconds);
	window.draw(minutes);
	window.display();
}

void TwoPlayersMode(RenderWindow &window, ChessBoard &chessBoard, Figure blackFigures[16], Figure whiteFigures[16], double &secondsLeft, int &minutesLeft, bool &isGamePaused, Text &seconds, Text &minutes, Font font)
{
	if (isGamePaused == false)
	{
		if ((int)secondsLeft > 0)
		{
			secondsLeft -= 0.005;
		}
		if ((int)secondsLeft == 0 && minutesLeft > 0)
		{
			minutesLeft--;
			secondsLeft = 60;
		}
		string leftSeconds = to_string((int)secondsLeft), leftMinutes = to_string(minutesLeft) + " : ";
		seconds.setString(leftSeconds);
		minutes.setString(leftMinutes);

		if (isFigureTake == true)
		{
			if (chessBoard.figureColor == "white")
			{
				chessBoard.PlaceFigure(window, whiteFigures, blackFigures, minutesLeft, secondsLeft);
			}
			else
			{
				chessBoard.PlaceFigure(window, blackFigures, whiteFigures, minutesLeft, secondsLeft);
			}
		}
		else
		{
			for (int i = 0; i < 16; i++)
			{
				chessBoard.TakeFigure(window, whiteFigures[i].GetRectangleShape(), whiteFigures[i].GetType(), "up", blackFigures, whiteFigures, i, "white");
				chessBoard.TakeFigure(window, blackFigures[i].GetRectangleShape(), blackFigures[i].GetType(), "down", whiteFigures, blackFigures, i, "black");
			}
		}

		window.clear();
		window.draw(chessBoard.GetRectangleShape());
		chessBoard.DrawGridCells(window);

		for (int i = 0; i < 16; i++)
		{
			window.draw(whiteFigures[i].GetRectangleShape());
		}

		for (int i = 0; i < 16; i++)
		{
			window.draw(blackFigures[i].GetRectangleShape());
		}
	}
	chessBoard.GameEnd(window, blackFigures, whiteFigures, isGamePaused, font, minutesLeft, secondsLeft);
	window.draw(seconds);
	window.draw(minutes);
	window.display();
}

#endif // !ONE_AND_TWO_PLAYERS_MODE
