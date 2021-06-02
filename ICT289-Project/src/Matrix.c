#include "Matrix.h"

GLfloat* Mat4ToGLMatrix(Mat4 m)
{
	GLfloat g[16];
	g[0] = m.x1; g[1] = m.y1; g[2] = m.z1; g[3] = m.w1;
	g[4] = m.x2; g[5] = m.y2; g[6] = m.z2; g[7] = m.w2;
	g[8] = m.x3; g[9] = m.y3; g[10] = m.z3; g[11] = m.w3;
	g[12] = m.x4; g[13] = m.y4; g[14] = m.z4; g[15] = m.w4;
	return &g;
}

Mat4 LookAt(Vector3 pos, Vector3 target)
{
	Vector3 forward = Normalize3(DirectionVector3(pos, target));

	Vector3 up = Vector3YUp;
	
	Vector3 left = Normalize3(CrossProduct3(up, forward));

	up = CrossProduct3(forward, left);

	Mat4 m;
	m = Identity();

	m.x1 = left.x; m.y1 = up.x; m.z1 = forward.x;
	m.x2 = left.y; m.y2 = up.y; m.z2 = forward.y;
	m.x3 = left.z; m.y3 = up.z; m.z3 = forward.z;


	m.x4 = -left.x * pos.x - left.y * pos.y - left.z * pos.z;
	m.y4 = -up.x * pos.x - up.y * pos.y - up.z * pos.z;
	m.z4 = -forward.x * pos.x - forward.y * pos.y - forward.z * pos.z;

	return m;
}

Mat4 Identity()
{
	Mat4 m;
	m.x1 = 1; m.y1 = 0; m.z1 = 0; m.w1 = 0;
	m.x2 = 0; m.y2 = 1; m.z2 = 0; m.w2 = 0;
	m.x3 = 0; m.y3 = 0; m.z3 = 1; m.w3 = 0;
	m.x4 = 0; m.y4 = 0; m.z4 = 0; m.w4 = 1;
	return m;
}

Mat4 GLMatrixToMat4(GLfloat* m)
{
	Mat4 i;
	i.x1 = m[0]; i.y1 = m[1]; i.z1 = m[2]; i.w1 = m[3];
	i.x2 = m[4]; i.y2 = m[5]; i.z2 = m[6]; i.w2 = m[7];
	i.x3 = m[8]; i.y3 = m[9]; i.z3 = m[10]; i.w3 = m[11];
	i.x4 = m[12]; i.y4 = m[13]; i.z4 = m[14]; i.w4 = m[15];
	return i;
}
