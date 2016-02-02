#pragma once
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <FL\Fl.H>
#include <FL\Fl_Button.H>
#include <FL\Fl_Window.H>
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"


class OpenGLManager
{
public:
	static bool drawCircle, drawSquare, drawTriangle;

	OpenGLManager();
	~OpenGLManager();

	void setWindowSize(int x, int y);
	void initialize(int argc, char** argv);
	void glLoop();
	static void drawScene();
	static void handleResize(int w, int h);

private:
	int windowSize[2];
	Fl_Window *window;
	Fl_Button *square;
	Fl_Button *circle;
	Fl_Button *triangle;
	Fl_Button *clear;
	Fl_Button *quit;

	void initRendering();

	static void square_button_cb(Fl_Widget* obj, void*);
	static void circle_button_cb(Fl_Widget* obj, void* b);
	static void triangle_button_cb(Fl_Widget* obj, void* b);
	static void clear_button_cb(Fl_Widget* obj, void* b);
	static void quit_button_cb(Fl_Widget* obj, void* b);
};

