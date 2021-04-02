#pragma once
#ifndef GAME_MENU
#define GAME_MENU
#include "ClassOption.h"

void Option::ClickOnOption(RenderWindow &window)
{
	Vector2i mousePosition = Mouse::getPosition(window);
	if (mousePosition.x >= text.getPosition().x && mousePosition.x <= text.getPosition().x + text.getCharacterSize() * (textSize / 2) &&
		mousePosition.y >= text.getPosition().y && mousePosition.y <= text.getPosition().y + text.getCharacterSize())
	{
		text.setFillColor(Color::Blue);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			switch (option)
			{
			case Options::onePlayer:
				isMenuDraw = false;
				isChooseColorDraw = true;
				break;
			case Options::twoPlayers:
				isMenuDraw = false;
				isTwoPlayersGameDraw = true;
				break;
			case Options::rules:
				isMenuDraw = false;
				isRulesDraw = true;
				break;
			case Options::credits:
				isMenuDraw = false;
				isCreditsDraw = true;
				break;
			case Options::back:
				isMenuDraw = true;
				break;
			case Options::whiteFigures:
				isOnePlayerGameDraw = true;
				isWhiteChoosen = true;
				isComputerTurn = false;
				break;
			case Options::blackFigures:
				isOnePlayerGameDraw = true;
				isWhiteChoosen = false;
				isComputerTurn = true;
				break;
			}
		}
	}
	else
	{
		text.setFillColor(Color::Black);
	}
}

void GameMenu(RenderWindow &window)
{
	isCreditsDraw = false;
	isRulesDraw = false;
	RectangleShape background; 
	Texture backgroundTexture;
	backgroundTexture.loadFromFile("Images\\GameMenuBackground.jpg");
	background.setPosition(5, 5);
	background.setSize(Vector2f(650, 650));
	background.setTexture(&backgroundTexture);

	Option onePlayer("1 Player", 200, 120, 0);
	Option twoPlayers("2 Players", 190, 220, 1);
	Option rules("Rules", 240, 340, 2);
	Option credits("Credits", 210, 450, 3);

	onePlayer.ClickOnOption(window);
	twoPlayers.ClickOnOption(window);
	rules.ClickOnOption(window);
	credits.ClickOnOption(window);

	window.clear();
	window.draw(background);
	window.draw(onePlayer.GetText());
	window.draw(twoPlayers.GetText());
	window.draw(rules.GetText());
	window.draw(credits.GetText());
	window.display();
}

void GameRules(RenderWindow &window)
{
	RectangleShape background;
	Texture backgroundTexture, takeTexture, placeTexture;
	backgroundTexture.loadFromFile("Images\\GameMenuBackground.jpg");
	background.setPosition(5, 5);
	background.setSize(Vector2f(650, 650));
	background.setTexture(&backgroundTexture);

	takeTexture.loadFromFile("Images\\Take.png");
	placeTexture.loadFromFile("Images\\Place.png");
	Sprite take(takeTexture), place(placeTexture);
	take.setPosition(66, 66);
	take.setScale(0.8F, 0.8F);
	place.setPosition(66, 330);
	place.setScale(0.8F, 0.8F);

	Option back("Back to Menu", 120, 520, 4);
	back.ClickOnOption(window);

	window.clear();
	window.draw(background);
	window.draw(take);
	window.draw(place);
	window.draw(back.GetText());
	window.display();
}


void GameCredits(RenderWindow &window)
{
	RectangleShape background;
	Texture backgroundTexture;
	backgroundTexture.loadFromFile("Images\\GameMenuBackground.jpg");
	background.setPosition(5, 5);
	background.setSize(Vector2f(650, 650));
	background.setTexture(&backgroundTexture);

	Text text;
	Font font;
	font.loadFromFile("Fonts\\arial.ttf");
	text.setFont(font);
	text.setString("Created by : borislavvv");
	text.setPosition(170, 295);
	text.setFillColor(Color::Black);

	Option back("Back to Menu", 120, 520, 4);
	back.ClickOnOption(window);

	window.clear();
	window.draw(background);
	window.draw(back.GetText());
	window.draw(text);
	window.display();
}

void ChooseColor(RenderWindow &window)
{
	RectangleShape background;
	Texture backgroundTexture, blackTexture, whiteTexture;
	backgroundTexture.loadFromFile("Images\\GameMenuBackground.jpg");
	background.setPosition(5, 5);
	background.setSize(Vector2f(650, 650));
	background.setTexture(&backgroundTexture);

	blackTexture.loadFromFile("Images\\BlackKing.png");
	whiteTexture.loadFromFile("Images\\WhiteKing.png");

	Sprite white(whiteTexture), black (blackTexture);
	white.setPosition(270, 70);
	white.setScale(0.5F, 0.5F);
	black.setPosition(270, 270);
	black.setScale(0.5F, 0.5F);

	Option whiteFigures("White Figures", 120, 200, 5);
	Option blackFigures("Black Figures", 120, 400, 6);
	Option back("Back to Menu", 120, 520, 4);

	whiteFigures.ClickOnOption(window);
	blackFigures.ClickOnOption(window);
	back.ClickOnOption(window);

	window.clear();
	window.draw(background);
	window.draw(back.GetText());
	window.draw(white);
	window.draw(black);
	window.draw(whiteFigures.GetText());
	window.draw(blackFigures.GetText());
	window.display();
}

#endif // !GAME_MENU
