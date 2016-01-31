#pragma once
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"

class OpenGLManager
{
public:
	OpenGLManager();
	~OpenGLManager();

	void setWindowSize(int x, int y);
	void initialize(int argc, char** argv);
	void glLoop();

private:
	int windowSize[2];

	static void drawScene();
	static void handleResize(int w, int h);
	void initRendering();
};

