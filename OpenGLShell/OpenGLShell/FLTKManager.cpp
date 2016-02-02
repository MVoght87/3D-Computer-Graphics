#include "FLTKManager.h"


FLTKManager::FLTKManager()
{
	window = new Fl_Window(308, 530, 800, 200);
	square = new Fl_Button(100, 20, 150, 50, "Square");
	triangle = new Fl_Button(325, 20, 150, 50, "Triangle");
	circle = new Fl_Button(550, 20, 150, 50, "Circle");
	clear = new Fl_Button(212, 100, 150, 50, "Clear All");
	quit = new Fl_Button(437, 100, 150, 50, "Quit");
	window->end();
}


FLTKManager::~FLTKManager()
{
}

void FLTKManager::initialize(int argc, char** argv) {
	window->show(argc, argv);
}