#pragma once
#include<GL\freeglut.h>
#include "input.h"

#define BLACK 0.0, 0.0, 0.0, 1.0
#define WHITE 1.0, 1.0, 1.0, 1.0
#define RED 1.0, 0.0, 0.0, 1.0
#define GREEN 0.0, 1.0, 0.0, 1.0
#define BLUE 0.0, 0.0, 1.0, 1.0

/**
* \brief Aditional init function for unrelated items to glut
* 
* \author Bryce Standley
* \date   April 2021
*/
void init()
{
	//Put opening init calls here
}

/**
* \brief Main Render function
* 
* \author Bryce Standley
* \date   April 2021
*/
void Render()
{
	//Put Render code here

}

/**
* 
* \brief Lighting setup function
* \author Bryce Standley
* \date   April 2021
*/
void SetLighting()
{
	//Put Any lighting code here

}



/**
*
* \brief Main GLUT init functions
* \author Bryce Standley
* \date   April 2021
* \param argc
* \param argv
* \param windowWidth
* \param windowHeight
* \param title
*/
void WindowInit(int argc, char** argv, int windowWidth, int windowHeight, char* title)
{
	init();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(title);

	glutDisplayFunc(Render);
	glutKeyboardFunc(Input);

	SetLighting();

	glClearColor(BLACK);

	glutMainLoop();
}



