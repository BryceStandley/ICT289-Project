#include "camera.h"


void UpdateCameraLookAt(Camera* c)
{
	Vector3 v, v2;
	v.x = (cos(c->transform.Rotation.x) * cos(c->transform.Rotation.y));
	v.y = sin(c->transform.Rotation.y);
	v.z = (sin(c->transform.Rotation.x) * cos(c->transform.Rotation.y));

	v2 = v;
	v2.x += c->transform.Position.x;
	v2.y += c->transform.Position.y;
	v2.z += c->transform.Position.z;
	c->LookAt = v2;
	c->Forward = v;
	
}


void MoveCamera(Camera* c, float incr)
{
	float lx = cos(c->transform.Rotation.x) * cos(c->transform.Rotation.y);
	//float ly = sin(c->transform.Rotation.y);
	float lz = sin(c->transform.Rotation.x) * cos(c->transform.Rotation.y);

	c->transform.Position.x += incr * lx;
	c->transform.Position.y = 1.0f;
	c->transform.Position.z += incr * lz;

	UpdateCamera(c);
}


void StrafeCamera(Camera* c, float incr)
{
	float strafeLx = cos(c->transform.Rotation.x - M_PI_2);
	float strafeLz = sin(c->transform.Rotation.x - M_PI_2);

	c->transform.Position.x += incr * strafeLx;
	c->transform.Position.z += incr * strafeLz;

	UpdateCamera(c);
}



void RotateCameraX(Camera* c, float angle)
{
	c->transform.Rotation.x += angle;
	
	float degree = 360 * M_PI / 180.0f;
	if (c->transform.Rotation.x > degree)
	{
		c->transform.Rotation.x = 0;
	}

	if (c->transform.Rotation.x < -degree)
	{
		c->transform.Rotation.x = 0;
	}
	
	UpdateCamera(c);
}


void RotateCameraY(Camera* c, float angle)
{
	float limit = 89.0f * M_PI / 180.0f;
	c->transform.Rotation.y += angle;
	
	if (c->transform.Rotation.y < -limit)
	{
		c->transform.Rotation.y = -limit;
	}

	if (c->transform.Rotation.y > limit)
	{
		c->transform.Rotation.y = limit;
	}
	
	UpdateCamera(c);
}


void UpdateCamera(Camera* c)
{
	UpdateCameraLookAt(c);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(c->transform.Position.x, c->transform.Position.y, c->transform.Position.z,
				c->LookAt.x, c->LookAt.y, c->LookAt.z,
					c->WorldUp.x, c->WorldUp.y, c->WorldUp.z);

	UpdateCameraMatrix(c);

	//Calculate related direction vectors based on the cameras position
	//c->Forward = Normalize3(DirectionVector3(Vector3Zero, c->LookAt));
	c->Up = (Vector3){ .x = 0, .y = 1, .z = 0 };
	c->Left = Normalize3(CrossProduct3(c->Up, c->Forward));
	c->Up = CrossProduct3(c->Forward, c->Left);
}

void UpdateCameraMatrix(Camera* c)
{
	Vector3 f = DirectionVector3(c->LookAt, c->transform.Position);
	Vector3 up = c->WorldUp;

	f = Normalize3(f);
	up = Normalize3(up);
	Vector3 s = CrossProduct3(f, up);
	s = Normalize3(s);
	Vector3 u = CrossProduct3(s, f);
	Mat4 m = Identity();
	m.x1 = s.x; m.y1 = s.y; m.z1 = s.z;
	m.x2 = u.x; m.y2 = u.y; m.z2 = u.z;
	m.x3 = -f.x; m.y3 = -f.y; m.z3 = -f.z;
	c->CameraLookAtMatrix = m;

}

void DisplayEndScreen(Camera* c)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* fov, aspect, near, far */
	gluPerspective(60, 1, 1, 10);
	gluLookAt(0, 0, -2, /* eye */
				0, 0, 2, /* center */
					0, 1, 0); /* WorldUp */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
