#include "gameobject.h"


void SetName(Gameobject *gameobject, char* name) 
{
	strcpy(&gameobject->name, &name);
}

void SetObject3D(Gameobject* gameobject, Object3D obj3D) 
{
	gameobject->object3D = obj3D;
}