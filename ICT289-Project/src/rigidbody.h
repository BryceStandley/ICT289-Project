/*****************************************************************//**
 * \file   rigidbody.h
 * \brief  Physics functions to be used to animate objects
 * 
 * \author Bryce Standley
 * \date   May 2021
 *********************************************************************/
#pragma once
#include "vector.h"
#include <stdbool.h>


#define RIGIDBODY_H

/**
 * \file rigidbody.h
 * \author Maea Havea
 * \brief enum of the different body types of a physics object
 * \date  June 2021
 */
typedef enum {DYNAMIC,KINEMATIC,STATIC} BODYTYPE;

/**
 * \brief Data structure of a physics rigidbody
 */
typedef struct Rigidbody
{
	float mass;
	float gravity;
	Vector3 velocity;
	float speed;
	Vector3 Acceleration;
	Vector3 Force;
	BODYTYPE type;
}Rigidbody;


/**
 * \brief Init a rigidbody with default values
 * \date  May 2021
 */
void InitRigidbody(Rigidbody* rb);


/**
 * \brief Calculate the velocity at a given time
 * \date  May 2021
 */
Vector3 VelocityAtTime(Vector3 InitVelocity, Vector3 Acceleration, float deltaTime);

/**
 * \brief Calculate the acceleration at a given time
 * \date  May 2021
 */
Vector3 Acceleration(Vector3 force, float mass);

/**
 * \brief Average of two velocities
 * \date  May 2021
 */
Vector3 AverageVelocity(Vector3 initVelocity, Vector3 finalVelocity);

/**
 * \brief Calculate the new displacement of a object at a given time
 * \date  May 2021
 */
Vector3 Displace(Vector3 position, Vector3 velocity, Vector3 Acceleration, float deltaTime);

/**
 * \brief Calculate a force of a object
 * \date  May 2021
 */
Vector3 Force(float mass, Vector3 Acceleration);

/**
 * \brief Calculate the force due to gravity
 * \date  May 2021
 */
Vector3 ForceDueToGravity(float mass, float gravity);
