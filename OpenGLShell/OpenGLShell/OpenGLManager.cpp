#include "OpenGLManager.h"


OpenGLManager::OpenGLManager()
{
	this->windowSize[0] = 600;
	this->windowSize[1] = 400;
}


OpenGLManager::~OpenGLManager()
{
}

void OpenGLManager::setWindowSize(int x, int y)
{
	this->windowSize[0] = x;
	this->windowSize[1] = y;
}

void OpenGLManager::initialize(int argc, char** argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(this->windowSize[0], this->windowSize[1]); //Set the window size
	//Create the window
	glutCreateWindow("Basic Shapes");
	initRendering(); //Initialize rendering
}

void OpenGLManager::glLoop()
{
	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(this->drawScene);
	glutReshapeFunc(this->handleResize);
	glutMainLoop(); //Start the main loop
}

void OpenGLManager::drawScene()
{
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	float pos1[] = { 0, 1, 0 };
	float pos2[] = { -1.5, 1, 0 };
	float pos3[] = { 1.5, 1, 0 };

	Square *sq = new Square(pos1, 0);
	sq->draw();

	Triangle *tr = new Triangle(pos2, 0, 0);
	tr->draw();

	Circle *cr = new Circle(pos3, 0.5);
	cr->draw();

	glutSwapBuffers(); //Send the 3D scene to the screen
}

void OpenGLManager::handleResize(int w, int h)
{
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
		(double)w / (double)h, //The width-to-height ratio
		1.0,                   //The near z clipping coordinate
		200.0);                //The far z clipping coordinate
}

void OpenGLManager::initRendering()
{
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
}
