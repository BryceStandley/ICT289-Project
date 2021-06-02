#pragma once
#ifndef MODEL_H
#define MODEL_H
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "vector.h"
#include "colours.h"
#include <GL/freeglut.h>
#include "material.h"
#include "rigidbody.h"
#include <corecrt_math_defines.h>
#include "Transform.h"

/**
 * \file model.h
 * \author Bryce Standley
 * \brief Used to load and manage models into the program
 * 
 * \date  April 2021
 */

/*
* \brief Structure of a 3D Model based arounf the OFF file type
*/
 
typedef struct GameObject
{
	char* name;
	int numFaces;
	int numPoints;
	int numEdges;
	Vector3* vertexPoints;
	Vector5* faceIndices;
	Transform transform;
	Rigidbody rigidbody;
	Vector3* normals;
	int TextureID;
	Material material;
} GameObject;

/*
* \brief Init's values in the object before loading in the file. Similar to a default constructor for the object
*/
void InitEmptyObject(GameObject* object);

/*
* \brief Loads in a given 3D model OFF file and returns true or false for a successful load
*/
int LoadOffFile(char* filePath, GameObject* object);

/*
* \brief Used to render a OFF file. Use this function within the glut render call
*/
void DrawOffFile(GameObject* object);

/**
 * \file model.h
 * \author Bryce Standley
 * \brief Translates the scene to a gameobjects position
 * \date  May 2021
 */
void TranslateToObjectPosition(GameObject* object);

/**
 * \file model.h
 * \author Bryce Standley
 * \brief Translates the scene to a given vec3
 * \date  June 2021
 */
void TranslateToVec3Position(Vector3 a);

/**
 * \file model.h
 * \author Bryce Standley
 * \brief Uses openGl rotatef to rotate around a give axis in radians
 * \date  June 2021
 */
void RotateAroundRad(Vector3 a);

/**
 * \file model.h
 * \author Bryce Standley
 * \brief Uses openGL rotatef to rotate a given axis in degrees
 * \date  June 2021
 */
void RotateAroundDeg(Vector3 a);

/**
 * \file model.h
 * \author Bryce Standley
 * \brief Updates a game object's information with a temp game object
 * \date  June 2021
 */
void UpdateGameObject(GameObject* gameObjectToUpdate, GameObject tempGameObject);



void SetName(GameObject* gameobject, char* name);


#endif // !MODEL_H


