#include <iostream>
#include "OpenGLManager.h"

using namespace std;


int main(int argc, char** argv) {
	OpenGLManager *GL = new OpenGLManager();
	GL->setWindowSize(800, 600);
	GL->initialize(argc, argv);
	GL->glLoop(argc, argv);
	return 0;
}