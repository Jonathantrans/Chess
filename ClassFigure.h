#pragma once
#ifndef CLASS_FIGURE
#define CLASS_FIGURE
#include "GameSetUp.h"

class Figure
{
private:
	RectangleShape figure;
	Texture texture;
	FigureType type;
public:
	Figure(int Type, string path)
	{
		texture.loadFromFile(path);
		figure.setTexture(&texture);
		figure.setSize(Vector2f(66, 66));
		type = FigureType(Type);
	}
	RectangleShape& GetRectangleShape();
	FigureType& GetType();
	void SetPosition(float x, float y);
};

void Figure::SetPosition(float x, float y)
{
	figure.setPosition(x, y);
}

RectangleShape& Figure::GetRectangleShape()
{
	return figure;
}

FigureType& Figure::GetType()
{
	return type;
}

#endif // !CLASS_FIGURE
