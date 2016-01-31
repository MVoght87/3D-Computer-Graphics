#pragma once
#include "Shape.h"


class Triangle: public Shape
{
public:
	Triangle();
	Triangle(double base, double height);
	Triangle(float position[], double base, double height);
	~Triangle();

	void draw();

	void setBase(double base);
	double getBase();
	void setHeight(double height);
	double getHeight();
private:
	double base;
	double height;
};

