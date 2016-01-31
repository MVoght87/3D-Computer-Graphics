#pragma once
#include "Shape.h"


class Square: public Shape
{
public:
	Square();
	Square(double length);
	Square(float position[], double length);
	~Square();

	void draw();

	void setLength(double length);
	double getLength();

private:
	double length;
};

