#include "OpenGLManager.h"


OpenGLManager::OpenGLManager()
{
	this->windowSize[0] = 600;
	this->windowSize[1] = 400;

	drawCircle = drawSquare = drawTriangle = false;
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
	glutInitWindowPosition(300, 100);
	//Create the window
	glutCreateWindow("Basic Shapes");
	initRendering(); //Initialize rendering

	window->begin();
	window = new Fl_Window(308, 530, 800, 200);
	square = new Fl_Button(100, 20, 150, 50, "Square");
	triangle = new Fl_Button(325, 20, 150, 50, "Triangle");
	circle = new Fl_Button(550, 20, 150, 50, "Circle");
	clear = new Fl_Button(212, 100, 150, 50, "Clear All");
	quit = new Fl_Button(437, 100, 150, 50, "Quit");

	square->callback((Fl_Callback*)square_button_cb, this);
	circle->callback((Fl_Callback*)circle_button_cb, this);
	triangle->callback((Fl_Callback*)triangle_button_cb, this);
	clear->callback((Fl_Callback*)clear_button_cb, this);
	quit->callback((Fl_Callback*)quit_button_cb, this);

	window->show(argc, argv);
	window->end();
}

void OpenGLManager::glLoop(int argc, char** argv)
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

	float pos3[] = { 1.5, 1, 0 };
	Circle *cr = new Circle(pos3, 0.5);
	cr->draw();
			
	float pos1[] = { 0, 1, 0 };
	Square *sq = new Square(pos1, 0);
	sq->draw();
	
	float pos2[] = { -1.5, 1, 0 };
	Triangle *tr = new Triangle(pos2, 0, 0);
	tr->draw();

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

void OpenGLManager::square_button_cb(Fl_Widget* obj, void* b){
	drawSquare = true;
}

void OpenGLManager::circle_button_cb(Fl_Widget* obj, void* b){
	drawCircle = true;
}

void OpenGLManager::triangle_button_cb(Fl_Widget* obj, void* b){
	drawTriangle = true;
}

void OpenGLManager::clear_button_cb(Fl_Widget* obj, void* b){
	drawCircle = drawSquare = drawTriangle = false;
}

void OpenGLManager::quit_button_cb(Fl_Widget* obj, void* b){

}