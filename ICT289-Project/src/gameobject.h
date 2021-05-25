#include "rigidbody.h"
#include "model.h"

#define GAMEOBJECT_H

typedef struct Gameobject {
	char* name;
	Rigidbody rigidbody;
	Object3D object3D;


} Gameobject;

void SetName(Gameobject* gameobject, char *name);

void SetObject3D(Gameobject* gameobject, Object3D *object3D);

void UpdatePhysics();

void TranslateGameObject(Gameobject gameobject, float x, float y, float z);