#include "window.h"

Vector3 cPosition;


void WindowInit(int argc, char** argv, int windowWidth, int windowHeight, char* title)
{
	init();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(title);

	glutReshapeFunc(WindowReSize);
	glutDisplayFunc(Render);
	glutIdleFunc(Render);


	
	
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(PressNormalInput);
	glutSpecialFunc(PressCameraInput);
	glutSpecialUpFunc(ReleaseCameraInput);

	glutMouseFunc(MouseButtonInput);
	glutMotionFunc(MouseMovementInput);

	glEnable(GL_DEPTH_TEST);

	SetLighting();

}

void SetLighting()
{
	//Put Any lighting code here

}

void Render()
{
	//Clear the colours and transforms
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if (deltaMove) ComputePosition(deltaMove);

	UpdateCamera(&camera);

	//Draw the ground plane
	glColor3f(FORREST_GREEN);
	DrawGroundPlane(100, 100);


	//Draw a test cube
	glColor3f(WHITE);
	glTranslatef(10.0f, 0.0f, 0.0f);
	DrawCubeOnGround(1);
	glPopMatrix();
	//Draw a test cube
	glColor3f(RED);
	glTranslatef(5.0f, 0.0f, -10.0f);
	DrawCubeOnGround(1);



	//Swap the buffers
	glutSwapBuffers();
}

void init()
{
	//Put opening init calls here
	glClearColor(BLACK, 1.0f);

	//Camera init to default values
	cPosition = (Vector3){ .x = 0.0f, .y = 1.0f, .z = 0.0f };
	camera.Position = cPosition;
	camera.LookAt = (Vector3){ .x = 5.0f, .y = 0.0f, .z = -10.0f };;
	camera.Up = (Vector3){ .x = 0.0f, .y = 1.0f, .z = 0.0f };;
	camera.Rotation = (Vector3){ .x = 0.0f, .y = 0.0f, .z = 0.0f };
	camera.Forward = (Vector3){ .x = 0.0f, .y = 0.0f, .z = -1.0f };

	UpdateCamera(&camera);
}

void WindowReSize(int w, int h)
{
	if (h == 0) h = 1;
	float ratio = 1.0 * w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void ComputePosition(float d)
{
	camera.Position.x += d * camera.Forward.x * 0.1f;
	camera.Position.z += d * camera.Forward.z * 0.1f;
}

void ComputeDirection(float d)
{
	camera.Rotation.y += d;
	camera.Forward.x = sin(camera.Rotation.y);
	camera.Forward.z = -cos(camera.Rotation.y);
}
