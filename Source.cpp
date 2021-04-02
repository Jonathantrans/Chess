#include "GameMovementLogic.h"
#include "ChessBoardSetAndGetFunctions.h"
#include "FigureMoveDirections.h"
#include "PawnAndHorseMoveDirections.h"
#include "PawnReachEndOfBoardLogic.h"
#include "GameMenu.h"
#include "KingLogic.h"
#include "AILogic.h"
#include "OneAndTwoPlayersMode.h"

int main()
{
	RenderWindow window(VideoMode(665, 665), "Chess", Style::Titlebar | Style::Close);
	ChessBoard chessBoard;
	Figure whiteFigures[] =
	{
		Figure(4, "Images\\WhiteRook.png"), Figure(3, "Images\\WhiteHorse.png"), Figure(2, "Images\\WhiteOfficer.png"), Figure(0, "Images\\WhiteKing.png"),
		Figure(1, "Images\\WhiteQueen.png"), Figure(2, "Images\\WhiteOfficer.png"), Figure(3, "Images\\WhiteHorse.png"), Figure(4, "Images\\WhiteRook.png"),
		Figure(6, "Images\\WhitePawn.png"), Figure(6, "Images\\WhitePawn.png"), Figure(6, "Images\\WhitePawn.png"), Figure(6, "Images\\WhitePawn.png"),
		Figure(6, "Images\\WhitePawn.png"), Figure(6, "Images\\WhitePawn.png"), Figure(6, "Images\\WhitePawn.png"), Figure(6, "Images\\WhitePawn.png")
	};
	Figure blackFigures[] =
	{
		Figure(4, "Images\\BlackRook.png"), Figure(3, "Images\\BlackHorse.png"), Figure(2, "Images\\BlackOfficer.png"), Figure(0, "Images\\BlackKing.png"),
		Figure(1, "Images\\BlackQueen.png"), Figure(2, "Images\\BlackOfficer.png"), Figure(3, "Images\\BlackHorse.png"), Figure(4, "Images\\BlackRook.png"),
		Figure(6, "Images\\BlackPawn.png"), Figure(6, "Images\\BlackPawn.png"), Figure(6, "Images\\BlackPawn.png"), Figure(6, "Images\\BlackPawn.png"),
		Figure(6, "Images\\BlackPawn.png"), Figure(6, "Images\\BlackPawn.png"), Figure(6, "Images\\BlackPawn.png"), Figure(6, "Images\\BlackPawn.png")
	};

	chessBoard.SetFigurePositions(blackFigures, 0, 16, "up");
	chessBoard.SetFigurePositions(whiteFigures, 48, 64, "down");

	bool isGamePaused = false;
	double secondsLeft = 60;
	int minutesLeft = 2;
	Text seconds, minutes;
	Font font;
	font.loadFromFile("Fonts\\arial.ttf");
	seconds.setFont(font);
	seconds.setFillColor(Color::Red);
	seconds.setPosition(300, 0);
	minutes.setFont(font);
	minutes.setFillColor(Color::Red);
	minutes.setPosition(260, 0);

	while (window.isOpen())
	{
		while (true)
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
				}
			}

			if (isMenuDraw == true)
			{
				GameMenu(window);
			}
			else if (isRulesDraw == true)
			{
				GameRules(window);
			}
			else if (isCreditsDraw == true)
			{
				GameCredits(window);
			}
			else if (isOnePlayerGameDraw == true)
			{
				OnePlayerMode(window, chessBoard, blackFigures, whiteFigures, secondsLeft, minutesLeft, isGamePaused, seconds, minutes, font);
			}
			else if (isTwoPlayersGameDraw == true)
			{
				TwoPlayersMode(window, chessBoard, blackFigures, whiteFigures, secondsLeft, minutesLeft, isGamePaused, seconds, minutes, font);
			}
			else if (isChooseColorDraw == true)
			{
				ChooseColor(window);
			}
		}
	}

	return 0;
}