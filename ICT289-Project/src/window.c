#include "window.h"

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
	glutTimerFunc(TARGET_FPS, UpdatePhysics, 1);

	setArrow = false;
	fireArrow = false;
	inAir = false;

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

void UpdatePhysics(int k)
{
	//All data models (gameobjects) are updated here..
	//The appropriate physical data is manipulated here
	//-such that Render(); will redraw these updated objects

	glutTimerFunc(TARGET_FPS, UpdatePhysics, 1);
	currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	deltaTime = currentTime - previousTime;

		for (int i = 0; i < MAX_SCENE_OBJECTS; i++)
		{
			//Loop though all scene objects and check if their static or not
			if (sceneObjects[i].rigidbody.type != STATIC)
			{
				//If the object isnt static, update their physics
				Transform newTransorm;
				newTransorm.Position = Displace(sceneObjects[i].transform.Position, sceneObjects[i].rigidbody.velocity, sceneObjects[i].rigidbody.Acceleration, deltaTime);

				Rigidbody newRigidbody = sceneObjects[i].rigidbody;
				newRigidbody.velocity = VelocityAtTime(sceneObjects[i].rigidbody.velocity, sceneObjects[i].rigidbody.Acceleration, deltaTime);

				sceneObjects[i].transform = newTransorm;
				sceneObjects[i].rigidbody = newRigidbody;
			}

			if (sceneObjects[i].transform.Position.y < 0)
			{
				// object on the floor
				Vector3 currPos = sceneObjects[i].transform.Position;
				currPos.y = 0;
				sceneObjects[i].transform.Position = currPos;
				sceneObjects[i].rigidbody.type = STATIC;

			}
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

	if (!setArrow && !fireArrow)
	{
		glPushMatrix();
		RotateAroundRad(sceneObjects[1].transform.Rotation);
		TranslateToObjectPosition(&sceneObjects[1]);
		DrawOffFile(&sceneObjects[1]);
		glPopMatrix();
	}
	/*
	glLoadIdentity();
	UpdateCamera(&camera);

	sceneObjects[2].transform.Position = camera.transform.Position;
	sceneObjects[2].transform.Position.y = 1.0f;
	TranslateToVec3Position(sceneObjects[2].transform.Position);

	glRotatef(-camera.transform.Rotation.y * (180.0f / M_PI), 0.0f, 0.0f, 1.0f);
	float a1 = DotProduct3(sceneObjects[2].transform.Position, camera.Forward);
	float magPos = Magnatude3(sceneObjects[2].transform.Position);
	float magFwd = Magnatude3(camera.Forward);
	float thetaX = (a1 / (magPos * magFwd)) * (180.0f / M_PI);
	glRotatef(camera.transform.Rotation.x * (180.0f / M_PI), 0.0f, 1.0f, 0.0f);
	TranslateToVec3Position((Vector3) {.x = 0.0f, .y = 0.0f, .z = -1.25f});
	glRotatef(-70, 0, 1, 0);
	*/
	glPushMatrix();
	glPushMatrix();
	Vector3 c = camera.LookAt;
	c.y = 1;
	TranslateToVec3Position(Vector3Zero);
	glRotatef(-camera.transform.Rotation.y, 0, 1, 0);
	TranslateToVec3Position(c);
	
	//glRotatef(-camera.transform.Rotation.x, 1, 0, 1);
	
	DrawOffFile(&sceneObjects[2]);
	glPopMatrix();
	glPopMatrix();

	if (setArrow && !fireArrow && !inAir)
	{
		glLoadIdentity();
		UpdateCamera(&camera);

		sceneObjects[1].transform = camera.transform;
		TranslateToVec3Position(sceneObjects[1].transform.Position);
		glRotatef(-camera.transform.Rotation.y * (180.0f / M_PI), 0.0f, 0.0f, 1.0f);
		float a1 = DotProduct3(sceneObjects[1].transform.Position, camera.Forward);
		float magPos = Magnatude3(sceneObjects[1].transform.Position);
		float magFwd = Magnatude3(camera.Forward);
		float thetaX = (a1 / (magPos * magFwd)) * (180.0f / M_PI);
		glRotatef(camera.transform.Rotation.x* (180.0f / M_PI), 0.0f, 1.0f, 0.0f);
		TranslateToVec3Position((Vector3) { .x = 0.0f, .y = 0.0f, .z = -1.25f });
		glRotatef(-70, 0, 1, 0);
		DrawOffFile(&sceneObjects[1]);
		glPopMatrix();

	}
	else if (fireArrow && !setArrow && !inAir)
	{
		sceneObjects[1].rigidbody.type = DYNAMIC;
		sceneObjects[1].rigidbody.velocity = Scale3(Multiply3(camera.Up, camera.Forward), 10.5f);
		fireArrow = false;
		inAir = true;
	}



	if (endscreenDisplay)
	{
		DrawEndScreen();
	}


	//Swap the buffers
	glFlush();
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
	camera.transform.Position = (Vector3){ .x = 0.0f, .y = 1.0f, .z = 0.0f };
	camera.LookAt = (Vector3){ .x = 5.0f, .y = 0.0f, .z = -10.0f };;
	camera.WorldUp = (Vector3){ .x = 0.0f, .y = 1.0f, .z = 0.0f };;
	camera.transform.Rotation = (Vector3){ .x = 0.0f, .y = 0.0f, .z = 0.0f };

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLdouble fov = 80;		// degrees
	GLdouble aspect = 1;		// aspect ratio aspect = height/width
	GLdouble nearVal = 0.000001f;
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

		if (!LoadOffFile(strcat(&concatTemp, &fileNames[i]), &newOb)) printf("File at '%s' failed to load\n", &fileNames[i]);
		Material plastic = Red_Shiny_Plastic;
		newOb.material = plastic;

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
