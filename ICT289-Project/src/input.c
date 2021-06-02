#include "input.h"

Camera camera;
int viewportWidth;
int viewportHieght;
const float cameraTranslationSpeed = 0.01f;
const float cameraRotationSpeed = 0.01f;//M_PI / 180 * 0.2f;
bool keys[256];
bool endscreenDisplay = false;
bool setArrow = false;
bool fireArrow = false;
bool inAir = false;

void PressNormalInput(unsigned char key, int xVal, int yVal)
{

	switch (key)
	{
	case 27:
		endscreenDisplay = !endscreenDisplay;
		break;
	default:
		break;
	}

	keys[key] = true;
}


void PressNormalInputUp(unsigned char key, int xVal, int yVal)
{
	keys[key] = false;
}

void MouseButtonInput(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (endscreenDisplay)
		{
			exit(1);
		}
		else
		{
			//draw bow
			setArrow = true;
			fireArrow = false;
			inAir = false;
		}
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		//fire bow
		fireArrow = true;
		setArrow = false;
		inAir = false;
	}
}

void MouseMovementInput(int x, int y)
{
	if (!endscreenDisplay)
	{
		static bool warpedPointer = false;

		if (warpedPointer)
		{
			warpedPointer = false;
			return;
		}

		int dx = x - viewportWidth / 2;
		int dy = y - viewportHieght / 2;
		if (dx)
		{
			RotateCameraX(&camera, cameraRotationSpeed * dx);
		}
		if (dy)
		{
			RotateCameraY(&camera, -cameraRotationSpeed * dy);
		}

		glutWarpPointer(viewportWidth / 2, viewportHieght / 2);
		warpedPointer = true;
	}

}

void InputTimer(int value)
{
	if (!endscreenDisplay)
	{
		if (keys['w'] || keys['W'])
		{
			//camera.transform.Position.x += camera.LookAt.x * cameraTranslationSpeed;
			//camera.transform.Position.z += camera.LookAt.z * cameraTranslationSpeed;
			MoveCamera(&camera, cameraTranslationSpeed);


		}
		if (keys['s'] || keys['S'])
		{
			//camera.transform.Position.x -= camera.LookAt.x * cameraTranslationSpeed;
			//camera.transform.Position.z -= camera.LookAt.z * cameraTranslationSpeed;
			MoveCamera(&camera, -cameraTranslationSpeed);
		}
		if (keys['a'] || keys['A'])
		{
			//camera.transform.Position.x += camera.LookAt.z * cameraTranslationSpeed;
			//camera.transform.Position.z -= camera.LookAt.x * cameraTranslationSpeed;
			StrafeCamera(&camera, cameraTranslationSpeed);
		}
		if (keys['d'] || keys['D'])
		{
			//camera.transform.Position.x -= camera.LookAt.z * cameraTranslationSpeed;
			//camera.transform.Position.z += camera.LookAt.x * cameraTranslationSpeed;
			StrafeCamera(&camera, -cameraTranslationSpeed);
		}
	}
	glutTimerFunc(1, InputTimer, 0);
}

