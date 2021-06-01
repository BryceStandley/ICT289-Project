#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include <GL/freeglut.h>
#include"vector.h"
#include <corecrt_math_defines.h>

/**
 * \file camera.h
 * \author Bryce Standley
 * \brief Adds the data structure and functions to control a OpenGL camera
 * \date  April 2021
 */


/*
* \brief Data structure of the camera
* \param transform - The transform data of the camera - position, rotation, scale
* \param LookAt - The direction the camera is looking at
* \param WorldUp - the up vector of the world to the camera
* \param Forward - the vector thats always forward from the cameras view (normalized)
* \param Up - Up vector in relation to the camera
* \param Left - the left vector to the camera
*/
typedef struct Camera
{
	Transform transform;
	Vector3 LookAt;
	Vector3 WorldUp;
	Vector3 Forward;
	Vector3 Up;
	Vector3 Left;
}Camera;

/*
* \fn void UpdateCameraLookAt(Camera* c)
* \brief Updates the direction the cameras looking towards
*/
void UpdateCameraLookAt(Camera* c);

/*
* \fn void UpdateCamera(Camera* c)
* \brief Updates the camera and the gluLookAt function
*/
void UpdateCamera(Camera* c);

/*
* \fn void MoveCamera(Camera* c, float incr)
* \brief moves the cameras position forwards and back
*/
void MoveCamera(Camera* c, float incr);

/*
* \fn void StrafeCamera(Camera* c, float incr)
* \brief Moves the cameras position left and right
*/
void StrafeCamera(Camera* c, float incr);

/*
* \fn void RotateCameraX(Camera* c, float incr)
* \brief Rotates the camera's yaw/x value
*/
void RotateCameraX(Camera* c, float incr);

/*
* \fn void RotateCameraY(Camera* c, float incr)
* \brief Rotates the camera's pitch/y value
*/
void RotateCameraY(Camera* c, float incr);

/**
 * \file camera.h
 * \author Bryce Standley
 * \brief Updates the cameras look at settings to correctly display the endscreen image
 * \date  May 2021
 */
void DisplayEndScreen(Camera* c);



#endif // !CAMERA_H

