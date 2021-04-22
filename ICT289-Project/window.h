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
void init();

/**
* \brief Main Render function
* 
* \author Bryce Standley
* \date   April 2021
*/
void Render();

/**
* 
* \brief Lighting setup function
* \author Bryce Standley
* \date   April 2021
*/
void SetLighting();



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
void WindowInit(int argc, char** argv, int windowWidth, int windowHeight, char* title);



