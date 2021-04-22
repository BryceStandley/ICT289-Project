#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <GL/freeglut.h>
#include "camera.h"

extern Camera camera;
extern float deltaAngle;
extern float deltaMove;

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

void PressCameraInput(unsigned char key, int xVal, int yVal);

void ReleaseCameraInput(unsigned char key, int xVal, int yVal);

void MouseButtonInput(int button, int state, int x, int y);

void MouseMovementInput(int x, int y);

#endif // !INPUT_H
