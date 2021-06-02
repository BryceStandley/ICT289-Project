/*****************************************************************//**
 * \file   Matrix.h
 * \brief  All functions and structures of a Matrix
 * 
 * \author Bryce Standley
 * \date   June 2021
 *********************************************************************/
#pragma once
#include <GL/freeglut.h>
#include "vector.h"
/**
 * \file Matrix.h
 * \author Bryce Standley
 * \brief Structure of a 4 x 4 matrix
 * \date  June 2021
 */
typedef struct Mat4
{
	float x1, y1, z1, w1;
	float x2, y2, z2, w2;
	float x3, y3, z3, w3;
	float x4, y4, z4, w4;
} Mat4;

/**
 * \file Matrix.h
 * \author Bryce Standley
 * \brief Converts a mat4 into a GLfloat array for opengl to process
 * \date  June 2021
 */
GLfloat* Mat4ToGLMatrix(Mat4 m);

/**
 * \file Matrix.h
 * \author Bryce Standley
 * \brief Converts a Glfloat matrix into a mat4
 * \date  June 2021
 */
Mat4 GLMatrixToMat4(GLfloat* m);

/**
 * \file Matrix.h
 * \author Bryce Standley
 * \brief creates a rotation mat4 from the position to the target
 * \date  June 2021
 */
Mat4 LookAt(Vector3 pos, Vector3 target);

/**
 * \file Matrix.h
 * \author Bryce Standley
 * \brief returns a mat4 with a identity matrix
 * \date  June 2021
 */
Mat4 Identity();
