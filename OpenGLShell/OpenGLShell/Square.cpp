#include "Square.h"


Square::Square()
{
}

Square::Square(double length)
{
	float position[] = { 0, 0, 0 };
	Square(position, length);
}

Square::Square(float position[], double length)
{
	this->length = length;
	Shape::setPosition(position);
}

Square::~Square()
{
}

void Square::draw()
{
	float* position = Shape::getPosition();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	//Trapezoid
	glVertex3f((position[0] - 0.5f), (position[1] - 0.5f), (position[2] - 5.0f));
	glVertex3f((position[0] + 0.5f), (position[1] - 0.5f), (position[2] - 5.0f));
	glVertex3f((position[0] + 0.5f), (position[1] + 0.5f), (position[2] - 5.0f));
	glVertex3f((position[0] - 0.5f), (position[1] + 0.5f), (position[2] - 5.0f));
	glEnd(); //End quadrilateral coordinates
}

void Square::setLength(double length)
{
	this->length = length;
}

double Square::getLength()
{
	return this->length;
}