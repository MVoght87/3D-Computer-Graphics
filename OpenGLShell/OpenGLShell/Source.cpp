#include <iostream>
#include "OpenGLManager.h"

using namespace std;


int main(int argc, char** argv) {
	OpenGLManager *GL = new OpenGLManager();
	GL->setWindowSize(800, 600);
	GL->initialize(argc, argv);
	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(GL->drawScene);
	glutReshapeFunc(GL->handleResize);
	glutMainLoop(); //Start the main loop
	return 0;
}