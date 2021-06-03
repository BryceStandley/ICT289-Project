/*****************************************************************//**
 * \file   scene.h
 * \brief  Functions to render objects within the scene
 * 
 * \author Bryce Standley
 * \date   April 2021
 *********************************************************************/
#pragma once
#ifndef SCENE_H
#define SCENE_H
#define MAX_SCENE_OBJECTS 5

#include <GL/freeglut.h>
#include "vector.h"
#include "model.h"


/**
* \brief Draws a flat ground plane
*/
void DrawGroundPlane(float scaleX, float scaleZ);

/**
* \brief Draws a cube fixed on the ground plane
*/
void DrawCubeOnGround(float scale);

/**
* \brief Used to draw multiple OFF models to the scene
* \todo Fix memory alloc and param passing for rendering
*/
void DrawOffModels(GameObject* objects);

#endif // !SCENE_H

