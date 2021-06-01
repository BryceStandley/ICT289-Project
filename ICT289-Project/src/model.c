#include "model.h"

int LoadOffFile(char* filePath, GameObject* object)
{
	InitEmptyObject(object);
	char off[10];
	FILE* file;

	if (fopen_s(&file, filePath, "r") != 0) return 0;

	if (fscanf_s(file, "%s %d %d %d", off, (unsigned int)sizeof(off), &object->numPoints, &object->numFaces, &object->numEdges) == 0) return 0;


	object->vertexPoints = (Vector3*)malloc(object->numPoints * sizeof(Vector3));

	for (int i = 0; i < object->numPoints; i++)
	{

		float x = 0.0f, y = 0.0f, z = 0.0f;
		if (fscanf_s(file, "%f %f %f", &x, &y, &z) == 0) return 0;
		object->vertexPoints[i].x = x;
		object->vertexPoints[i].y = y;
		object->vertexPoints[i].z = z;

	}

	object->faceIndices = (Vector5*)malloc(object->numFaces * sizeof(Vector5));

	for (int i = 0; i < object->numFaces; i++)
	{
		int a = 0, b = 0, c = 0, d = 0, e = 0;
		if (fscanf_s(file, "%d %d %d %d", &a, &b, &c, &d) == 0) return 0;
		//ignore the value at a because its just defining how many vertex points make up the face
		object->faceIndices[i].x = (float)b;
		object->faceIndices[i].y = (float)c;
		object->faceIndices[i].z = (float)d;

	}

	fclose(file);

	//Allocate one normal for every face indice
	object->normals = (Vector3*)malloc(object->numFaces * sizeof(Vector3));

	// Calculate a normal for all faces, disregard if the face is a quad or a triangle
	for (int i = 0; i < object->numFaces; i++)
	{
		Vector3 f;
		f.x = object->faceIndices[i].x;
		f.y = object->faceIndices[i].y;
		f.z = object->faceIndices[i].z;
		Vector3 p1 = object->vertexPoints[(int)f.x];
		Vector3 p2 = object->vertexPoints[(int)f.y];
		Vector3 p3 = object->vertexPoints[(int)f.z];

		Vector3 u = DirectionVector3(p1, p2);
		Vector3 v = DirectionVector3(p2, p3);
		object->normals[i] = CrossProduct3(u, v);
	}



	object->transform.Position = Vector3Zero;
	object->transform.Rotation = Vector3Zero;
	object->transform.Scale = Vector3One;
	InitRigidbody(&object->rigidbody);
	return 1;
}

void InitEmptyObject(GameObject* object)
{
	object->numPoints = 0;
	object->numFaces = 0;
	object->numEdges = 0;
	object->transform.Position = Vector3Zero;
	object->transform.Rotation = Vector3Zero;
	object->transform.Scale = Vector3One;
}

void DrawOffFile(GameObject* object)
{
	for (int i = 0; i < object->numFaces; i++)
	{
		Vector3 f;
		f.x = object->faceIndices[i].x;
		f.y = object->faceIndices[i].y;
		f.z = object->faceIndices[i].z;
		Vector3 p1 = (Vector3){ .x = object->vertexPoints[(int)f.x].x, .y = object->vertexPoints[(int)f.x].y, .z = object->vertexPoints[(int)f.x].z };
		Vector3 p2 = (Vector3){ .x = object->vertexPoints[(int)f.y].x, .y = object->vertexPoints[(int)f.y].y, .z = object->vertexPoints[(int)f.y].z };
		Vector3 p3 = (Vector3){ .x = object->vertexPoints[(int)f.z].x, .y = object->vertexPoints[(int)f.z].y, .z = object->vertexPoints[(int)f.z].z };
		Vector3 n = (Vector3){ .x = object->normals[i].x, .y = object->normals[i].y, .z = object->normals[i].z };

		glEnable(GL_NORMALIZE);
		glBegin(GL_TRIANGLES);
		SetMaterial(&object->material);
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(p1.x, p1.y, p1.z);
		glVertex3f(p2.x, p2.y, p2.z);
		glVertex3f(p3.x, p3.y, p3.z);
		glEnd();
		glDisable(GL_COLOR_MATERIAL | GL_NORMALIZE | GL_LIGHTING);
	}
}

void TranslateToObjectPosition(GameObject* object)
{
	glTranslatef(object->transform.Position.x, object->transform.Position.y, object->transform.Position.z);
}

void TranslateToVec3Position(Vector3 a)
{
	glTranslatef(a.x, a.y, a.z);
}

void RotateAroundRad(Vector3 a)
{
	glRotatef(a.x * (180.0f / M_PI), 1.0f, 0.0f, 0.0f);
	glRotatef(a.y * (180.0f / M_PI), 0.0f, 1.0f, 0.0f);
	glRotatef(a.z * (180.0f / M_PI), 0.0f, 0.0f, 1.0f);
}

void RotateAroundDeg(Vector3 a)
{
	glRotatef(a.x, 1.0f, 0.0f, 0.0f);
	glRotatef(a.y, 0.0f, 1.0f, 0.0f);
	glRotatef(a.z, 0.0f, 0.0f, 1.0f);
}

void SetName(GameObject* gameobject, char* name)
{
	strcpy(&gameobject->name, &name);
}
