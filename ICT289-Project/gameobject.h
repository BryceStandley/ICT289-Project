#include "src/rigidbody.h"
#include "src/model.h"

#define GAMEOBJECT_H

typedef struct Gameobject {
	char* name;
	Rigidbody rigidbody;
	Object3D object3D;
	//Collider


} Gameobject;

