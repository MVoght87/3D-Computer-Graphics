#pragma once
#include <GL\glew.h>
#include <GL\glut.h>

class Shape
{
public:
	bool drawShape;

	Shape();
	Shape(float position []);
	~Shape();

	virtual void draw();

	void setPosition(float position[]);
	float* getPosition();
private:
	float position [3];
};

