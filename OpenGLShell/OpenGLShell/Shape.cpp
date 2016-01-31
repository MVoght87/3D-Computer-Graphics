#include "Shape.h"


Shape::Shape()
{
	this->position[0] = 0;
	this->position[1] = 0;
	this->position[2] = 0;
}

Shape::Shape(float position[])
{
	this->position[0] = position[0];
	this->position[1] = position[1];
	this->position[2] = position[2];
}

Shape::~Shape()
{
}

void Shape::draw()
{

}

void Shape::setPosition(float position[])
{
	this->position[0] = position[0];
	this->position[1] = position[1];
	this->position[2] = position[2];
}

float* Shape::getPosition()
{
	return this->position;
}