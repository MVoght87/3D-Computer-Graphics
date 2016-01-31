#pragma once
#include "Shape.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Circle: public Shape
{
public:
	Circle();
	Circle(double radius);
	Circle(float position[], double radius);
	~Circle();

	void draw();

	void setRadius(double radius);
	double getRadius();
private:
	double radius;
};

