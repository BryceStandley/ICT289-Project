#include "window.h"

Vector3 cPosition;
GameObject targetModel;
GameObject bow;
GLint endScreenTextureID;
char* endScreenImagePath = "./res/images/endscreen.raw";
int endScreenWidth = 800;
int endScreenHeight = 600;
float deltaTime = 0;
float previousTime = 0;
float currentTime = 0;

//Maybe even store the objects in a hashmap of sorts, more intuitive than indexes still iterable
GameObject sceneObjects[MAX_SCENE_OBJECTS];
char fileNames[MAX_SCENE_OBJECTS][14] = { "apple.off", "arrow.off", "bow.off", "bone.off", "cube.off"};

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

	previousTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;

	glutTimerFunc(1, InputTimer, 0);
	//glutTimerFunc(1, UpdatePhysics, 1);

}

void SetLighting()
{
	//Lighting code used from labs
	GLfloat lightPos[] = {10.0f, 60.0f, 10.0f, 1.0f };
	GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat ambient[] = {0.2f, 0.2f, 0.2f, 1.0f };

	//Enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glShadeModel(GL_SMOOTH);

	// Define position of light source
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// Define lighting model
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
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

void UpdatePhysics(GameObject* gameobject)
{
	//All data models (gameobjects) are updated here..
	//The appropriate physical data is manipulated here
	//-such that Render(); will redraw these updated objects

	glutTimerFunc(1000/60, UpdatePhysics, 1);
	currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	deltaTime = currentTime - previousTime;
	if (gameobject->rigidbody.type != STATIC)
	{
		Transform newTransorm;
		newTransorm.Position = Displace(gameobject->transform.Position, gameobject->rigidbody.velocity, gameobject->rigidbody.Acceleration, deltaTime);

		Rigidbody newRigidbody = gameobject->rigidbody;
		newRigidbody.velocity = VelocityAtTime(gameobject->rigidbody.velocity, gameobject->rigidbody.Acceleration, deltaTime);


		/*if (newTransorm.Position.y <= gameobject->ballRadius)
		{
			newRigidbody.velocity = Invert3(Scale3(newRigidbody.velocity, 0.75));
			newTransorm.Position.y = ball->ballRadius;
		}*/

		gameobject->transform = newTransorm;
		gameobject->rigidbody = newRigidbody;
	}
	previousTime = currentTime;
	glutPostRedisplay();

}

void Render()
{
	//Clear the colours and transforms
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	UpdateCamera(&camera);
	//printf("Camera.Forward: %f, %f, %f\n", camera.Forward.x, camera.Forward.y, camera.Forward.z);
	sceneObjects[2].transform.Position = camera.transform.Position;

	glPushMatrix();
	TranslateToObjectPosition(&sceneObjects[2]);
	glRotatef(-camera.transform.Rotation.y * (180.0f / M_PI), 0.0f, 1.0f, 0.0f);
	glRotatef(camera.transform.Rotation.z * (180.0f / M_PI), 0.0f, 0.0f, 1.0f);


	glTranslatef(0.005f, 0.1f, 1.25f);
	glRotatef(105, 0, 1, 0);
	glScalef(sceneObjects[2].transform.Scale.x, sceneObjects[2].transform.Scale.y, sceneObjects[2].transform.Scale.z);
	DrawOffFile(&sceneObjects[2]);
	if (setArrow) 
	{
		//set the arrow to the same position as the bow, should be in the center
		//draw the arrow
	}
	glPopMatrix();

	glPushMatrix();
	if (fireArrow)
	{
		//set the arrows rb isStatic to false
		//update the arrows position
	}
	glPopMatrix();


	//Draw the ground plane
	glColor3f(DARK_GREEN);
	DrawGroundPlane(100, 100);


	//Draw a test cube
	glPushMatrix();
	glColor3f(WHITE);
	glTranslatef(10.0f, 0.0f, 0.0f);
	DrawCubeOnGround(1);
	glPopMatrix();

	//Draw a test cube
	glPushMatrix();
	glColor3f(RED);
	glTranslatef(5.0f, 0.0f, -10.0f);
	DrawCubeOnGround(1);
	glPopMatrix();

	//Drawing Off Files
	DrawOffFile(&sceneObjects[0]);



	if (endscreenDisplay)
	{
		DrawEndScreen();
	}


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

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLdouble fov = 80;		// degrees
	GLdouble aspect = 1;		// aspect ratio aspect = height/width
	GLdouble nearVal = 0.001f;
	GLdouble farVal = 1000;     // near and far clipping planes
	gluPerspective(fov, aspect, nearVal, farVal);

	UpdateCamera(&camera);

	LoadModels();

	endScreenTextureID = LoadEndScreen(endScreenImagePath, endScreenWidth, endScreenHeight);

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
		GameObject newOb;
		InitRigidbody(&sceneObjects[i].rigidbody);
		InitEmptyObject(&sceneObjects[i]);

		char concatTemp[50] = "./res/models/";
		strcpy(&newOb.name, &fileNames[i]);

		if (!LoadOffFile(strcat(&concatTemp, &fileNames[i]), &newOb)) printf("File at './res/models/bone.off' failed to load\n");
		//newOb = sceneObjects[i];

		sceneObjects[i] = newOb;
	}
}


GLuint LoadEndScreen(const char* filename, int width, int height)
{
	GLuint texture;
	unsigned char* data;
	FILE* file;
	file = fopen(filename, "rb");
	if (file == NULL) return 0;
	data = (unsigned char*)malloc(width * height * 4);
	fread(data, width * height * 4, 1, file);
	fclose(file);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_DECAL);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);

	free(data);

	return texture;
	
}

void DrawEndScreen()
{
	DisplayEndScreen(&camera);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2d(1, 1); glVertex3f(-1.0, -1.0, 0.0);
	glTexCoord2d(1, 0); glVertex3f(-1.0, 1.0, 0.0);
	glTexCoord2d(0, 0); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2d(0, 1); glVertex3f(1.0, -1.0, 0.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glPopAttrib();
}
