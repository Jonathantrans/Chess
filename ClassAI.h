#pragma once
#ifndef CLASS_AI
#define CLASS_AI
#include "GameSetUp.h"

class AI
{
private:
	void PlaceFigure(vector<int> &countPossibleMoves, int &figureIndex, Figure figure[16], ChessBoard &chessBoard, Figure enemyFigure[16]);
public:
	void ChooseFigure(ChessBoard &chessBoard, RenderWindow &window, Figure figure[16], string position, Figure enemyFigure[16], Figure friendFigure[16], string color);
	void SwitchPawnWithFigure(RectangleShape Figures[4], FigureType &type, RectangleShape &figure, FigureType fType[4], RenderWindow &ChooseFigure, bool &isFigureChoosen, string color);
	friend class ChessBoard;
}computer;

#endif // !CLASS_AI
