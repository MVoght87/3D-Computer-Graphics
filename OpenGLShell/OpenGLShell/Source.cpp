#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

//Initializes 3D rendering
void initRendering() {
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
}
//Called when the window is resized
void handleResize(int w, int h) {
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

void drawSquare(float x, float y, float z){
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	//Trapezoid
	glVertex3f((x - 0.5f), (y - 0.5f), (z - 5.0f));
	glVertex3f((x + 0.5f), (y - 0.5f), (z - 5.0f));
	glVertex3f((x + 0.5f), (y + 0.5f), (z - 5.0f));
	glVertex3f((x - 0.5f), (y + 0.5f), (z - 5.0f));
	glEnd(); //End quadrilateral coordinates
}

void drawTriangle(float x, float y, float z){

	glBegin(GL_TRIANGLES); //Begin triangle coordinates
	//Triangle
	glVertex3f((x - 0.5f), (y - 0.5f), (z - 5.0f));
	glVertex3f((x + 0.5f), (y - 0.5f), (z - 5.0f));
	glVertex3f(x, (y + 0.5f), (z - 5.0f));
	glEnd(); //End triangle coordinates
}

void drawCircle(float x, float y, float z, float r) {
	int triangleAmount = 30;

	float twicePi = 2.0f * (float)M_PI;
	glBegin(GL_TRIANGLE_FAN); //Begin circle coordinates
	glVertex3d(x, y, (z - 5.0f));
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex3d(	x + (r * cos(i * twicePi / triangleAmount)),
					y + (r * sin(i * twicePi / triangleAmount)),
					z - 5.0f
		);
	}

	glEnd(); // end circle coordinates

}
//Draws the 3D scene
void drawScene() {
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	drawSquare(0, 1, 0);
	drawTriangle(-1.5, 1, 0);
	drawCircle(1.5, 1, 0, 0.55);
	glutSwapBuffers(); //Send the 3D scene to the screen
}
int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600); //Set the window size
	//Create the window
	glutCreateWindow("Basic Shapes - programming-technique.blogspot.com");
	initRendering(); //Initialize rendering
	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);
	glutMainLoop(); //Start the main loop
	return 0;
}