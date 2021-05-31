#include "window.h"

Vector3 cPosition;
Object3D boneModel;
Object3D* models;

//Maybe even store the objects in a hashmap of sorts, more intuitive than indexes still iterable
Gameobject sceneObjects[MAX_SCENE_OBJECTS];
char fileNames[MAX_SCENE_OBJECTS][14] = { "apple.off", "arrow.off", "bone.off", "cube.off"};

void WindowInit(int argc, char** argv, int windowWidth, int windowHeight, char* title)
{
	

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
	glutKeyboardUpFunc(PressNormalInputUp);

	glutMouseFunc(MouseButtonInput);
	glutMotionFunc(MouseMovementInput);
	glutPassiveMotionFunc(MouseMovementInput);

	init(windowWidth, windowHeight);

	SetLighting();

	printf("Program lanuched successfully!");

	glutTimerFunc(1, InputTimer, 0);
	glutTimerFunc(1, UpdatePhysics, 1);

}

void SetLighting()
{
	//Put Any lighting code here
	//Lighting code used from labs
	GLfloat lightPos[] = {1.0f, 1.0f, 1.0f, 0.0f };
	GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat ambient[] = {0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat shininess[] = { 50.0f };
	glShadeModel(GL_SMOOTH);

	// Define position of light source
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// Define lighting model
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

	// Define material properties
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,specular);

	glEnable(GL_COLOR_MATERIAL);

	//Enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

//I forsee a problem with this
// are the callbacks run simutaneously?
// because the data model may run Updated(), apply gravity
// While the player halfway through the application of gravity, applies the
// arrow projectile, and renders the arrows first falling, then having applied the 
// velocity being shot, which may make it look choppy

//inputs?
void DrawBow() 
{
	//Animates the drawing of the bow, uses timer to pull string back, until a maximum value
	//Maximum value yields maximum velocity
}

//might move to inputs?
void Shoot() 
{
	// Will make the arrow object collidable, visible
	//rotate it to the camera angle such that the point faces away
	//Applies velocity to data model of given arrow object
	//
}

void UpdatePhysics(Gameobject* gameobject)
{
	//All data models (gameobjects) are updated here..
	//The appropriate physical data is manipulated here
	//-such that Render(); will redraw these updated objects

	float deltaTime = 0;

	Vector3 displacement = Displace(gameobject->rigidbody.Position, gameobject->rigidbody.velocity, gameobject->rigidbody.Acceleration, deltaTime);
	float disAbs = sqrt(pow(displacement.x, 2) + pow(displacement.y, 2) + pow(displacement.z, 2));

	gameobject->rigidbody.speed = disAbs / deltaTime;

	glutTimerFunc(1, UpdatePhysics, 1);
}

void Render()
{
	//Clear the colours and transforms
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	UpdateCamera(&camera);
	SetLighting();

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

	//Drawing Off Files
	glPopMatrix();

	glTranslatef(10.0f, 3.0f, 5.0f);
	DrawOffFile(&sceneObjects[0].object3D);

	glTranslatef(5.0f, 3.0f, -5.0f);
	DrawOffFile(&sceneObjects[3].object3D);



	//Swap the buffers
	glutSwapBuffers();
}

void init(int w, int h)
{
	viewportWidth = w;
	viewportHieght = h;

	//Put opening init calls here
	glClearColor(BLACK, 1.0f);

	//disable the cursor and move it to the center of the window
	glutSetCursor(GLUT_CURSOR_NONE);
	glutWarpPointer(viewportWidth / 2, viewportHieght / 2);

	//Camera init to default values
	cPosition = (Vector3){ .x = 0.0f, .y = 1.0f, .z = 0.0f };
	camera.transform.Position = cPosition;
	camera.LookAt = (Vector3){ .x = 5.0f, .y = 0.0f, .z = -10.0f };;
	camera.Up = (Vector3){ .x = 0.0f, .y = 1.0f, .z = 0.0f };;
	camera.transform.Rotation = (Vector3){ .x = 0.0f, .y = 0.0f, .z = 0.0f };
	camera.Forward = (Vector3){ .x = 0.0f, .y = 0.0f, .z = -1.0f };

	UpdateCamera(&camera);

	LoadModels();

}

void WindowReSize(int w, int h)
{
	if (h == 0) h = 1;
	float ratio = (float) 1.0 * w / h;
	viewportWidth = w;
	viewportHieght = h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void LoadModels()
{	
	
	
	//This can be better implemented, just wanna see it WORK :')
	for (int i = 0; i < MAX_SCENE_OBJECTS; i++)
	{
		Gameobject newOb;
		InitRigidbody(&sceneObjects[i].rigidbody);
		InitEmptyObject(&sceneObjects[i].object3D);

		char concatTemp[50] = "./res/models/";
		strcpy(&newOb.name,&fileNames[i]);

		if (!LoadOffFile(strcat(&concatTemp, &fileNames[i]), &sceneObjects[i].object3D)) printf("File at './res/models/bone.off' failed to load\n");
		newOb.object3D = sceneObjects[i].object3D;

		sceneObjects[i] = newOb;
	}
}
