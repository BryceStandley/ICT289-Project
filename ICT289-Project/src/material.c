#include "material.h"


void SetMaterial(Material* material)
{
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_AMBIENT, material->Ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material->Diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material->Specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, material->Shininess);
}
