/*****************************************************************//**
 * \file   material.h
 * \brief  Data structures of all materials within the application
 * 
 * \author Bryce Standley
 * \date   May 2021
 *********************************************************************/

#pragma once
#include <GL/freeglut.h>

/**
 * \file material.h
 * \author Bryce Standley
 * \brief Material structure for holding all component data
 * \date  May 2021
 */
typedef struct Material
{
	GLfloat Ambient[4];
	GLfloat Diffuse[4];
	GLfloat Specular[4];
	GLfloat Shininess[1];
}Material;

//Define materials here


#define Brass  { {0.33f, 0.22f, 0.03f, 1.0f}, {0.78f, 0.57f, 0.11f, 1.0f}, {0.99f, 0.91f, 0.91f, 1.0f}, {27.8f} }

#define Red_Shiny_Plastic  { {0.3f, 0.0f, 0.0f, 1.0f}, {0.6f, 0.0f, 0.0f, 1.0f}, {0.8f, 0.6f, 0.6f, 1.0f}, {100.0f} }


/**
 * \file material.h
 * \author Bryce Standley
 * \fn SetMaterial
 * \brief Sets the material inside opengl for a given object
 * \date  May 2021
 * \param Material* material
 */
void SetMaterial(Material* material);

