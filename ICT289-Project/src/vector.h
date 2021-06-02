#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <math.h>
#include <corecrt_math_defines.h>
/**
 * \file vector.h
 * \author Bryce Standley
 * \brief Vector Math fucntions file
 * \date  April 2021
 */

/**
 * \brief Vector data structure with 2 components
 * create a vector2 by using a compund literal
 * ie Vector2 v = (Vector2){.x = 0.0f, .y = 0.0f};
 */
typedef struct Vector2 { float x, y; }Vector2;

/**
 * \brief Vector data structure with 3 components
 * create a vector3 by using a compund literal
 * ie Vector3 v = (Vector3){.x = 0.0f, .y = 0.0f, .z = 0.0f};
 */
typedef struct Vector3 { float x, y, z; } Vector3;

/**
 * \brief Vector data structure with 4 components
 * create a vector4 by using a compund literal
 * ie Vector4 v = (Vector4){.x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f};
 */
typedef struct Vector4 { float x, y, z, w; } Vector4;

/**
 * \brief Vector data structure with 5 components
 * create a vector5 by using a compund literal
 * ie Vector5 v = (Vector5){.x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f, .u = 0.0f};
 */
typedef struct Vector5 { float x, y, z, w, u; } Vector5;


/** 
* \brief Eazy define for creating a vector3 with all components at zero
*/
#define Vector3Zero (Vector3){.x = 0.0f, .y = 0.0f, .z = 0.0f}

/**
* \brief Eazy define for creating a vector3 with all components at one
*/
#define Vector3One (Vector3){.x = 1.0f, .y = 1.0f, .z = 1.0f}

/**
* \brief Eazy define for creating a vector3 y up vector
*/
#define Vector3YUp (Vector3){.x = 0.0f, .y = 1.0f, .z = 0.0f}

/**
 * \brief Find the magnatude of a Vector2
 * \param Vector2 a
 */
float Magnatude2(Vector2 a);

/**
 * \brief Find the magnatude of a Vector3
 * \param Vector3 a
 */
float Magnatude3(Vector3 a);

/**
 * \brief Find the magnatude of a Vector4
 * \param Vector4 a
 */
float Magnatude4(Vector4 a);

/**
 * \brief Finds the distance between two Vector2's
 * \param Vector2 a
 * \param Vector2 b
 */
float Distance2(Vector2 a, Vector2 b);

/**
 * \brief Finds the distance between two Vector3's
 * \param Vector3 a
 * \param Vector3 b
 */
float Distance3(Vector3 a, Vector3 b);

/**
 * \brief Finds the distance between two Vector4's
 * \param Vector4 a
 * \param Vector4 b
 */
float Distance4(Vector4 a, Vector4 b);

/**
 * \brief Finds a directional vector between two Vector2's
 * \param Vector2 a
 * \param Vector2 b
 */
Vector2 DirectionVector2(Vector2 a, Vector2 b);

/**
 * \brief Finds a directional vector between two Vector3's
 * \param Vector3 a
 * \param Vector3 b
 */
Vector3 DirectionVector3(Vector3 a, Vector3 b);

/**
 * \brief Finds a directional vector between two Vector4's
 * \param Vector4 a
 * \param Vector4 b
 */
Vector4 DirectionVector4(Vector4 a, Vector4 b);

/**
 * \brief Adds two Vector2's together
 * \param Vector2 a
 * \param Vector2 b
 */
Vector2 Add2(Vector2 a, Vector2 b);

/**
 * \brief Adds two Vector3's together
 * \param Vector3 a
 * \param Vector3 b
 */
Vector3 Add3(Vector3 a, Vector3 b);

/**
 * \brief Adds two Vector4's together
 * \param Vector4 a
 * \param Vector4 b
 */
Vector4 Add4(Vector4 a, Vector4 b);

/**
 * \brief subtracts two Vector2's
 * \param Vector2 a
 * \param Vector2 b
 */
Vector2 Subtract2(Vector2 a, Vector2 b);

/**
 * \brief subtracts two Vector3's
 * \param Vector3 a
 * \param Vector3 b
 */
Vector3 Subtract3(Vector3 a, Vector3 b);

/**
 * \brief subtracts two Vector4's
 * \param Vector4 a
 * \param Vector4 b
 */
Vector4 Subtract4(Vector4 a, Vector4 b);

/**
 * \brief Scales a Vector2 by a scale value
 * \param Vector2 a
 * \param float scale
 */
Vector2 Scale2(Vector2 a, float scale);

/**
 * \brief Scales a Vector3 by a scale value
 * \param Vector3 a
 * \param float scale
 */
Vector3 Scale3(Vector3 a, float scale);

/**
 * \brief Scales a Vector4 by a scale value
 * \param Vector4 a
 * \param float scale
 */
Vector4 Scale4(Vector4 a, float scale);

/**
 * \brief divides a Vector2 by a divide value
 * \param Vector2 a
 * \param float divide
 */
Vector2 Divide2(Vector2 a, float divide);

/**
 * \brief divides a Vector3 by a divide value
 * \param Vector3 a
 * \param float divide
 */
Vector3 Divide3(Vector3 a, float divide);

/**
 * \brief divides a Vector4 by a divide value
 * \param Vector4 a
 * \param float divide
 */
Vector4 Divide4(Vector4 a, float divide);

/**
 * \brief returs the result of a vector2 to the power of
 * \param Vector2 a
 * \param float powerOf
 */
Vector2 Pow2(Vector2 a, float powerOf);

/**
 * \brief returs the result of a vector3 to the power of
 * \param Vector3 a
 * \param float powerOf
 */
Vector3 Pow3(Vector3 a, float powerOf);

/**
 * \brief returs the result of a vector4 to the power of
 * \param Vector4 a
 * \param float powerOf
 */
Vector4 Pow4(Vector4 a, float powerOf);

/**
 * \brief multiplies a vector2 of a and b together
 * \param Vector2 a
 * \param Vector2 b
 */
Vector2 Multiply2(Vector2 a, Vector2 b);

/**
 * \brief multiplies a vector3 of a and b together
 * \param Vector3 a
 * \param Vector3 b
 */
Vector3 Multiply3(Vector3 a, Vector3 b);

/**
 * \brief multiplies a vector4 of a and b together
 * \param Vector4 a
 * \param Vector4 b
 */
Vector4 Multiply4(Vector4 a, Vector4 b);

/**
 * \brief Finds the dot product between two Vector2's
 * \param Vector2 a
 * \param Vector2 b
 */
float DotProduct2(Vector2 a, Vector2 b);

/**
 * \brief Finds the dot product between two Vector3's
 * \param Vector3 a
 * \param Vector3 b
 */
float DotProduct3(Vector3 a, Vector3 b);

/**
 * \brief Finds the cross product between two Vector3's
 * \param Vector3 a
 * \param Vector3 b
 */
Vector3 CrossProduct3(Vector3 a, Vector3 b);

/**
 * \brief Finds the angle between two Direction Vector2's in degrees
 * \param Two directional vectors of type Vector2
 */
float Angle2(Vector2 a, Vector2 b);

/**
 * \brief Finds the angle between two Direction Vector3's in Degrees
 * \param Two directional vectors of type Vector3
 */
float Angle3(Vector3 a, Vector3 b);

/**
 * \brief Finds the area of a triangle of three Vector3's
 * \param Vector3 a
 * \param Vector3 b
 * \param Vector3 c
 */
float Area3(Vector3 a, Vector3 b, Vector3 c);

/**
 * \brief Finds the area of a triangle using the base and height
 * \param float base
 * \param float height
 */
float TriangleArea(float base, float height);

/**
 * \brief Normalizes a Vector2
 * \param Vector2 a
 */
Vector2 Normalize2(Vector2 a);

/**
 * \brief Normalizes a Vector3
 * \param Vector3 a
 */
Vector3 Normalize3(Vector3 a);

/**
 * \brief Normalizes a Vector4
 * \param Vector4 a
 */
Vector4 Normalize4(Vector4 a);

/**
 * \brief Inverts a vector 2
 * \param Vector2 a
 */
Vector2 Invert2(Vector2 a);

/**
 * \brief Inverts a vector 3
 * \param Vector3 a
 */
Vector3 Invert3(Vector3 a);

/**
 * \brief Inverts a vector 4
 * \param Vector4 a
 */
Vector4 Invert4(Vector4 a);

/**
 * \file vector.h
 * \author Bryce Standley
 * \brief Creates a new vector3 out of xyz components and returns it
 * \date  June 2021
 */
Vector3 NewVector3(float x, float y, float z);

#endif // !VECTOR_H

