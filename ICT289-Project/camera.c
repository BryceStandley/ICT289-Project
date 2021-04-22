#include "camera.h"

void UpdateCameraLookAt(Camera* c)
{
	Vector3 v;
	v.x = c->Position.x + c->Forward.x;
	v.y = c->Position.y;
	v.z = c->Position.z + c->Forward.z;
	c->LookAt = v;
}

void UpdateCamera(Camera* c, Vector3 p, Vector3 l, Vector3 u)
{
	UpdateCameraLookAt(c);

	gluLookAt(c->Position.x, c->Position.y, c->Position.z,
				c->LookAt.x, c->LookAt.y, c->LookAt.z,
					c->Up.x, c->Up.y, c->Up.z);
}
