/*****************************************************************//**
 * \file   Quaternion.h
 * \brief  Quaternion functionality for openGL
 * 
 * \author Bryce Standley
 * \date   June 2021
 *********************************************************************/
#pragma once
#include "Vector.h"
#include "Matrix.h"
#include <math.h>
#include <corecrt_math_defines.h>
/**
 * \file Quaternion.h
 * \author Bryce Standley
 * \brief Structure of a quaternion
 * \date  June 2021
 */
typedef struct Quaternion
{
	float w, x, y, z;
} Quaternion;

/**
 * \file Quaternion.h
 * \author Bryce Standley
 * \brief Finds the magnatude of a quaternion
 * \date  June 2021
 */
float MagnitudeQuaternion(Quaternion q);

/**
 * \file Quaternion.h
 * \author Bryce Standley
 * \brief Used to normalise a quaternion between 0 and 1
 * \date  June 2021
 */
Quaternion NormaliseQuaternion(Quaternion q);

/**
 * \file Quaternion.h
 * \author Bryce Standley
 * \brief Multiply quaternion A by B. NOTE multiplying A by B is not the same as multiplying B by A.
 * \date  June 2021
 */
Quaternion MultiplyQuaternion(Quaternion a, Quaternion b);

/**
 * \file Quaternion.h
 * \author Bryce Standley
 * \brief Creates a new quaternion with given w, x, y, z components
 * \date  June 2021
 */
Quaternion NewQuaternion(float w, float x, float y, float z);

/**
 * \file Quaternion.h
 * \author Bryce Standley
 * \brief Creates a new local rotation quaternion with around axis and angle
 * \date  June 2021
 */
Quaternion LocalRotationQuaternion(Vector3 axis, float angle);

/**
 * \file Quaternion.h
 * \author Bryce Standley
 * \brief Converts a rotation quaternion to a 4 x 4 matrix
 * \date  June 2021
 */
Mat4 QuaternionToMat4(Quaternion q);

/**
 * \file Quaternion.h
 * \author Bryce Standley
 * \brief Converts starndard degree angles in a euler vector 3 to quaternion data
 * \date  June 2021
 */
Quaternion EulerToQuaternion(Vector3 euler);

/**
 * \file Quaternion.h
 * \author Bryce Standley
 * \brief Converts a rotation vector in radians to degrees / euler angles
 * \date  June 2021
 */
Vector3 RadiansToDegrees(Vector3 rad);

/**
 * \file Quaternion.h
 * \author Bryce Standley
 * \brief Converts a mat4 matrix back into a quaternion
 * \date  June 2021
 */
Quaternion Mat4ToQuaternion(Mat4 m);

/**
 * \file Quaternion.h
 * \author Bryce Standley
 * \brief Scales a quaternion by a set factor
 * \date  June 2021
 */
Quaternion ScaleQuaternion(Quaternion q, float scale);

/**
 * \file Quaternion.h
 * \author Bryce Standley
 * \brief Converts a euler angle vector into a quaternion
 * \date  June 2021
 */
Vector3 QuaternionToEuler(Quaternion q);

