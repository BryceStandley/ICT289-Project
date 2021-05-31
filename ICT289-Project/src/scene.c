#include "scene.h"

void DrawGroundPlane(float scaleX, float scaleZ)
{
	glDisable(GL_LIGHTING);
	glBegin(GL_QUADS);
	glVertex3f(-(1 * scaleX), 0.0f, -(1 * scaleZ));
	glVertex3f(-(1 * scaleX), 0.0f, (1 * scaleZ));
	glVertex3f((1 * scaleX), 0.0f, (1 * scaleZ));
	glVertex3f((1 * scaleX), 0.0f, -(1 * scaleZ));
	glEnd();
	glEnable(GL_LIGHTING);
}

void DrawCubeOnGround(float scale)
{
	glTranslatef(0.0f, (scale / 2.0f), 0.0f);
	glScalef(scale, scale, scale);

	glutSolidCube(1);
}


void DrawOffModels(GameObject* objects)
{
	for (int i = 0; i < MAX_SCENE_OBJECTS; i++)
	{
		DrawOffFile(&objects[i]);
	}
}
