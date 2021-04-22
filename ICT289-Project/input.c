#include "input.h"

Camera camera;

float deltaAngle = 0.0f;
float deltaMove = 0.0f;
int xOrigin = -1;

void PressNormalInput(unsigned char key, int xVal, int yVal)
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

void PressCameraInput(unsigned char key, int xVal, int yVal)
{
	float fraction = 0.1f;
	float angle = 0.0f;

	switch (key)
	{
	case 'W'://Move forward
	case 'w':
		deltaMove = 0.5f;
		break;

	case 'S'://Move backwards
	case 's':
		deltaMove = -0.5f;
		break;

	case 'Q':
	case 'q':
		exit(0);
		break;
	default:
		break;
	}

	glutPostRedisplay();
}

void ReleaseCameraInput(unsigned char key, int xVal, int yVal)
{
	switch (key)
	{
	case 'W'://Move forward and back
	case 'w':
	case 'S':
	case 's':
		deltaMove = 0.0f;
		break;
	default:
		break;
	}
}

void MouseButtonInput(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_UP)
		{
			camera.Rotation.y += deltaAngle;
			xOrigin = -1;
		}
		else
		{
			xOrigin = x;
		}
	}
}

void MouseMovementInput(int x, int y)
{
	if (xOrigin >= 0)
	{
		deltaAngle = (x - xOrigin) * 0.001f;
		camera.Forward.x = sin(camera.Rotation.y + deltaAngle);
		camera.Forward.z = -cos(camera.Rotation.y + deltaAngle);
	}

}

