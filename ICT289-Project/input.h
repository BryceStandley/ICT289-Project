#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <GL/freeglut.h>
#include "camera.h"
#include <stdbool.h>
#include <corecrt_math_defines.h>

extern Camera camera;
extern int viewportWidth;
extern int viewportHieght;


/**
* \brief Main Input function
* 
* \author Bryce Standley
* \date   April 2021
* \param key
* \param xVal
* \param yVal
*/
void PressNormalInput(unsigned char key, int xVal, int yVal);

void PressNormalInputUp(unsigned char key, int xVal, int yVal);

void MouseButtonInput(int button, int state, int x, int y);

void MouseMovementInput(int x, int y);

void InputTimer(int value);

#endif // !INPUT_H
