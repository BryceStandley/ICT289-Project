#pragma once
#include <GL/freeglut.h>
/**
* \brief Main Input function
* 
* \author Bryce Standley
* \date   April 2021
* \param key
* \param xVal
* \param yVal
*/
void Input(unsigned char key, int xVal, int yVal)
{
	switch (key)
	{
		case 'Q':
		case 'q':
			exit(0);
			break;
		default:
			break;
	}

	glutPostRedisplay();
}
