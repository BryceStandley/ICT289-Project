#pragma once
#ifndef WINDOW_H
#define WINDOW_H
#include<GL\freeglut.h>
#include "input.h"
#include "scene.h"
#include "camera.h"
#include "colours.h"
#include "model.h"

/**
* \brief Aditional init function for unrelated items to glut
* 
* \author Bryce Standley
* \date   April 2021
*/
void init(int w, int h);

/**
* \brief Main Render function
* 
* \author Bryce Standley
* \date   April 2021
*/
void Render(void);

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

/*
* \brief Resize function for glut
*/
void WindowReSize(int w, int h);


/*
* \brief Init function to load all models into the program
*/
void LoadModels();


#endif // !WINDOW_H
