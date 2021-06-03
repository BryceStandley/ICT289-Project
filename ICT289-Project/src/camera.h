/*****************************************************************//**
 * \file   camera.h
 * \brief  Adds the data structure and functions to control a OpenGL camera
 * 
 * \author Bryce Standley
 * \date   June 2021
 *********************************************************************/
#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include <GL/freeglut.h>
#include"vector.h"
#include <corecrt_math_defines.h>
#include "Transform.h"



/**
 * \brief Data structure of the camera
 */
typedef struct Camera
{
	Transform transform;
	Vector3 LookAt;
	Vector3 WorldUp;
	Vector3 Forward;
	Vector3 Up;
	Vector3 Left;
	Mat4 CameraLookAtMatrix;
}Camera;

/**
* \fn void UpdateCameraLookAt(Camera* c)
* \brief Updates the direction the cameras looking towards
*/
void UpdateCameraLookAt(Camera* c);

/**
* \fn void UpdateCamera(Camera* c)
* \brief Updates the camera and the gluLookAt function
*/
void UpdateCamera(Camera* c);

/**
 * \fn UpdateCameraMatrix(Camera* c)
 * \brief Updates the cameras look at matrix
 */
void UpdateCameraMatrix(Camera* c);

/**
* \fn void MoveCamera(Camera* c, float incr)
* \brief moves the cameras position forwards and back
*/
void MoveCamera(Camera* c, float incr);

/**
* \fn void StrafeCamera(Camera* c, float incr)
* \brief Moves the cameras position left and right
*/
void StrafeCamera(Camera* c, float incr);

/**
* \fn void RotateCameraX(Camera* c, float incr)
* \brief Rotates the camera's yaw/x value
*/
void RotateCameraX(Camera* c, float incr);

/**
* \fn void RotateCameraY(Camera* c, float incr)
* \brief Rotates the camera's pitch/y value
*/
void RotateCameraY(Camera* c, float incr);

/**
 * \fn DisplayEndScreen(Camera* c)
 * \brief Updates the cameras look at settings to correctly display the endscreen image
 */
void DisplayEndScreen(Camera* c);



#endif // !CAMERA_H

