#pragma once
#ifndef SCENE_H
#define SCENE_H
#define MAX_SCENE_OBJECTS 4

#include <GL/freeglut.h>
#include "vector.h"
#include "model.h"
#include "gameobject.h"
/**
 * \file scene.h
 * \author Bryce Standley
 * \brief Functions to render objects within the scene
 * 
 * \date  April 2021
 */


/*
* \brief Draws a flat ground plane
*/
void DrawGroundPlane(float scaleX, float scaleZ);

/*
* \brief Draws a cube fixed on the ground plane
*/
void DrawCubeOnGround(float scale);

/*
* \brief Used to draw multiple OFF models to the scene
* \todo Fix memory alloc and param passing for rendering
*/
void DrawOffModels(Object3D* objects);

#endif // !SCENE_H

