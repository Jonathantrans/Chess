#pragma once
#ifndef GAME_SET_UP
#define GAME_SET_UP
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace sf;
using namespace std;

bool isWhiteChoosen;
bool isComputerTurn;
bool isMenuDraw = true;
bool isRulesDraw = false;
bool isCreditsDraw = false;
bool isTwoPlayersGameDraw = false;
bool isOnePlayerGameDraw = false;
bool isChooseColorDraw = false;
bool isFigureTake = false;
Texture pawnReachEndTextureBlack[4];
Texture pawnReachEndTextureWhite[4];

enum class FigureType
{
	king, queen, officer, horse, rook, pawn, pawnFirstMove
};

#endif // !GAME_SET_UP
