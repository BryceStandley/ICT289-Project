#include "input.h"

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

