#pragma once
#ifndef SCENE_H
#define SCENE_H
#include <GL/freeglut.h>
#include "vector.h"
/**
 * scene.h
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

#endif // !SCENE_H

