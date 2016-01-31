#include "Triangle.h"


Triangle::Triangle()
{
	Triangle(0, 0);
}

Triangle::Triangle(double base, double height)
{
	float position[] = { 0, 0, 0 };
	Triangle(position, base, height);
}

Triangle::Triangle(float position[], double base, double height)
{
	this->base = base;
	this->height = height;
	Shape::setPosition(position);
}

Triangle::~Triangle()
{
}

void Triangle::draw()
{
	float* position = Shape::getPosition();

	glBegin(GL_TRIANGLES); //Begin triangle coordinates
	//Triangle
	glVertex3f((position[0] - 0.5f), (position[1] - 0.5f), (position[2] - 5.0f));
	glVertex3f((position[0] + 0.5f), (position[1] - 0.5f), (position[2] - 5.0f));
	glVertex3f(position[0], (position[1] + 0.5f), (position[2] - 5.0f));
	glEnd(); //End triangle coordinates
}

void Triangle::setBase(double base)
{
	this->base = base;
}

double Triangle::getBase()
{
	return this->base;
}

void Triangle::setHeight(double height)
{
	this->height = height;
}

double Triangle::getHeight()
{
	return this->height;
}