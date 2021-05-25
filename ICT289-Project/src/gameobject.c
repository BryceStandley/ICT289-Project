#include "gameobject.h"


void SetName(Gameobject *gameobject, char* name) 
{
	strcpy(&gameobject->name, &name);
}

void SetObject3D(Gameobject* gameobject, Object3D obj3D) 
{
	gameobject->object3D = obj3D;
}

void UpdatePhysics()
{
	//All data models (gameobjects) are updated here..
	//The appropriate physical data is manipulated here
	//-such that Render(); will redraw these updated objects
	glutTimerFunc(1, UpdatePhysics, 1);
}