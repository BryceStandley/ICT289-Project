#include "window.h"

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

void SetLighting()
{
	//Put Any lighting code here

}

void Render()
{
	//Put Render code here

}

void init()
{
	//Put opening init calls here
}