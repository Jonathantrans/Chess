#pragma once
#ifndef CLASS_CHESS_BOARD
#define CLASS_CHESS_BOARD
#include "GameSetUp.h"

class ChessBoard
{
private:
	RectangleShape board, gridCells[64];
	Texture boardTexture, gridCellTexture;
	bool isFigureChoosen = false, isNextPlayerTurn = true;

	void CheckForFriendFigures(int i, Figure figure[16]);
	void CheckForEnemyFigures(int i, Figure figure[16]);

	void DiagonalDirection(RectangleShape figure, int i, Figure enemyFigure[16], Figure friendFigure[16], float &nearestDown, float &nearestUp);

	void SetUpNearestHorizontally(RectangleShape figure, Figure nearFigure, float &nearestRigth, float &nearestLeft);
	void CheckForNearestHorizontally(RectangleShape figure, int i, Figure enemyFigure[16], Figure friendFigure[16], float &nearestRigth, float &nearestLeft);
	void HorizontalDirection(RectangleShape figure, int i, Figure enemyFigure[16], Figure friendFigure[16], float &nearestRigth, float &nearestLeft);

	void SetUpNearestVertically(RectangleShape figure, Figure nearFigure, float &nearestDown, float &nearestUp);
	void CheckForNearestVertically(RectangleShape figure, int i, Figure enemyFigure[16], Figure friendFigure[16], float &nearestDown, float &nearestUp);
	void VerticalDirection(RectangleShape figure, int i, Figure enemyFigure[16], Figure friendFigure[16], float &nearestDown, float &nearestUp);

	void PawnDirection(RectangleShape figure, int i, string position, Figure enemyFigure[16], Figure friendFigure[16]);
	void PawnFirstMove(RectangleShape figure, int i, string position, Figure enemyFigure[16], Figure friendFigure[16]);
	void ChooseFigure(string color, FigureType &type, RectangleShape &figure);//switches pawn with (queen, officer, horse or rook)
	void PawnReachEndOfBoard(FigureType &type, RectangleShape &figure, string position);

	void HorseDirection(RectangleShape figure, int i, Figure enemyFigure[16], Figure friendFigure[16]);
	void KingDirection(RectangleShape figure, int i, Figure enemyFigure[16], Figure friendFigure[16]);

	void FigureMovement(FigureType &type, RectangleShape &figure, string position, Figure enemyFigure[16], Figure friendFigure[16]);

	void SetGridCellsPositions();
	void SetGridCellsOutline();
public:
	int *figureIndex;// I use pointer to be sure that I use the given figure (not the previous one)
	string figureColor;
	ChessBoard()
	{
		figureColor = "black";

		boardTexture.loadFromFile("Images\\ChessBoard.jpg");
		board.setSize(Vector2f(650, 650));
		board.setPosition(5, 5);
		board.setTexture(&boardTexture);

		gridCellTexture.loadFromFile("Images\\GridCell.png");
		SetGridCellsPositions();
		for (int i = 0; i < 64; i++)
		{
			gridCells[i].setSize(Vector2f(66, 66));
			gridCells[i].setTexture(&gridCellTexture);
		}
	}
	~ChessBoard()
	{
		delete figureIndex;
	}
	RectangleShape GetRectangleShape();
	void TakeFigure(RenderWindow &window, RectangleShape &figure, FigureType &type, string position, Figure enemyFigure[16], Figure friendFigure[16], int i, string color);
	void PlaceFigure(RenderWindow &window, Figure figure[16], Figure enemyFigure[16], int &minutesLeft, double &secondsLeft);
	void DrawGridCells(RenderWindow &window);
	void SetFigurePositions(Figure figure[16], int start, int end, string position);
	void GameEnd(RenderWindow &window, Figure blackFigure[16], Figure whiteFigure[16], bool &isTimePaused, Font font, int minutesLeft, double secondsLeft);
	friend class AI;
};

void ChessBoard::DrawGridCells(RenderWindow &window)
{
	for (int i = 0; i < 64; i++)
	{
		window.draw(gridCells[i]);
	}
}

#endif // !CLASS_CHESS_BOARD
