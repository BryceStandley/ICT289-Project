/*****************************************************************//**
 * \file   window.h
 * \brief  Main window file that contains all functions related to the window and the program
 * 
 * \author Bryce Standley
 * \date   April 2021
 *********************************************************************/
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
 * \file window.h
 * \author Bryce Standley
 * \brief Target FPS define 
 * \date  June 2021
 */
#define TARGET_FPS 1000.0f/60.0f

/**
* \brief Aditional init function for unrelated items to glut
*/
void init(int w, int h);

/**
* \brief Main Render function
*/
void Render(void);

/**
* 
* \brief Lighting setup function
*/
void SetLighting();

/**
*
* \brief Main GLUT init functions
*/
void WindowInit(int argc, char** argv, int windowWidth, int windowHeight, char* title);

/**
* \brief Resize function for glut
*/
void WindowReSize(int w, int h);


/**
* \brief Init function to load all models into the program
*/
void LoadModels();

/**
 * \author Bryce Standley
 * \brief  Loads the endscreen image into opengl and creates a texture ID
 * \date  May 2021
 */
GLuint LoadEndScreen(const char* filename, int width, int height);

/**
 * \file window.h
 * \author Bryce Standley
 * \brief Draws the end screen image to a quad on the screen
 * \date  May 2021
 */
void DrawEndScreen();

/**
 * \file window.h
 * \author Bryce Standley
 * \brief Updates all objects with physics
 * \date  June 2021
 */
void UpdatePhysics(int k);

/**
 * \file window.h
 * \author Bryce Standley
 * \brief Draws the bow to the scene
 * \date  June 2021
 */
void DrawBow();

/**
 * \file window.h
 * \author Bryce Standley
 * \brief Draws the arrow to the scene
 * \date  June 2021
 */
void DrawArrow();


#endif // !WINDOW_H
