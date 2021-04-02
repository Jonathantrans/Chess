#pragma once
#ifndef CLASS_OPTION
#define CLASS_OPTION
#include "GameSetUp.h"

class Option
{
private:
	Text text;
	Font font;
	int textSize;
	enum class Options
	{
		onePlayer, twoPlayers, rules, credits, back, whiteFigures, blackFigures
	}option;
public:
	Option(string word, int x, int y, int n)
	{
		font.loadFromFile("Fonts\\arial.ttf");
		text.setFont(font);
		text.setString(word);
		text.setPosition(x, y);
		text.setCharacterSize(70);
		text.setFillColor(Color::Black);
		textSize = word.length();
		option = Options(n);
	}
	Text GetText();
	void ClickOnOption(RenderWindow &window);
};

Text Option::GetText()
{
	return text;
}

#endif //CLASS_OPTION