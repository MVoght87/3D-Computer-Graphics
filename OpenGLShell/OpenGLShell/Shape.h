#pragma once
#include <GL\glew.h>
#include <GL\freeglut.h>

class Shape
{
public:
	Shape();
	Shape(float position []);
	~Shape();

	virtual void draw();

	void setPosition(float position[]);
	float* getPosition();
private:
	float position [3];
};

