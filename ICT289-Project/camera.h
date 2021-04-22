#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include <GL/freeglut.h>
#include"vector.h"

typedef struct Camera
{
	Vector3 Position;
	Vector3 LookAt;
	Vector3 Up;
	Vector3 Rotation;
	Vector3 Forward;
}Camera;

void UpdateCameraLookAt(Camera* c);
void UpdateCamera(Camera* c);



#endif // !CAMERA_H

