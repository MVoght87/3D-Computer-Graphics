#include "Circle.h"


Circle::Circle()
{
}

Circle::Circle(double radius)
{
	float position[] = { 0, 0, 0 };
	Circle(position, radius);	
}

Circle::Circle(float position[], double radius)
{
	this->radius = radius;
	Shape::setPosition(position);
}

Circle::~Circle()
{
}

void Circle::draw()
{

	int triangleAmount = 30;
	float* position = Shape::getPosition();
	float twicePi = 2.0f * (float)M_PI;

	glBegin(GL_TRIANGLE_FAN); //Begin circle coordinates
	glVertex3d(position[0], position[1], (position[2] - 5.0f));
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex3d(position[0] + (this->radius * cos(i * twicePi / triangleAmount)),
			position[1] + (this->radius * sin(i * twicePi / triangleAmount)),
			position[2] - 5.0f
			);
	}

	glEnd(); // end circle coordinates
}

void Circle::setRadius(double radius)
{
	this->radius = radius;
}

double Circle::getRadius()
{
	return radius;
}