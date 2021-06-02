/*****************************************************************//**
 * \file   Transform.h
 * \brief  Basic structure and functions of a transform
 * 
 * \author Bryce Standley
 * \date   June 2021
 *********************************************************************/
#pragma once
#include "vector.h"
#include "Quaternion.h"

/**
* \brief Transform struct that can hold 3 vector3 data structures and a quaternion for rotation
*  A transform can be initialized by using compound literals
* ie, Transform.Position = (Vector3){.x = 0.0f, .y = 0.0f, .z = 0.0f};
* Quaternion rotation is calculated by Euler angles on the Vector3 rotation data
*/
typedef struct Transform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
	Quaternion QuatRotation;
} Transform;

