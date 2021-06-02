#include "Quaternion.h"

float MagnitudeQuaternion(Quaternion q)
{
	float mag;
	mag = sqrt(pow(q.w, 2) + pow(q.x, 2) + pow(q.y, 2) + pow(q.z, 2));
	return mag;
}


Quaternion NormaliseQuaternion(Quaternion q)
{
	Quaternion a;
	float mag = MagnitudeQuaternion(q);
	a.w = q.w / mag;
	a.x = q.x / mag;
	a.y = q.y / mag;
	a.z = q.z / mag;
	return a;
}

Quaternion MultiplyQuaternion(Quaternion a, Quaternion b)
{
	Quaternion q;
	q.w = (a.w * b.w) - (a.x * b.x) - (a.y * b.y) - (a.z * b.z);
	q.x = (a.w * b.x) + (a.x * b.w) + (a.y * b.z) + (a.z * b.y);
	q.y = (a.w * b.y) - (a.x * b.z) - (a.y * b.w) - (a.z * b.x);
	q.z = (a.w * b.z) + (a.x * b.y) + (a.y * b.x) + (a.z * b.w);
	return q;
}

Quaternion ScaleQuaternion(Quaternion q, float scale)
{
	q.w *= scale;
	q.x *= scale;
	q.y *= scale;
	q.z *= scale;
	return q;
}

Quaternion NewQuaternion(float w, float x, float y, float z)
{
	Quaternion q = (Quaternion){ .w = w, .x = x, .y = y, .z = z };
	return q;
}


Quaternion LocalRotationQuaternion(Vector3 axis, float angle)
{
	Quaternion q;
	float a = angle / 2.0f;
	q.w = cosf(a);
	q.x = axis.x * sinf(a);
	q.y = axis.y * sinf(a);
	q.z = axis.z * sinf(a);
	return q;
}


Mat4 QuaternionToMat4(Quaternion q)
{
	Mat4 m;
	//Row 1
	m.x1 = (1 - (2 * pow(q.y, 2)) - (2 * pow(q.z, 2)));
	m.y1 = (2 * (q.x * q.y) - (2 * (q.w * q.z)));
	m.z1 = (2 * (q.x * q.z) + (2 * (q.w * q.y)));
	m.w1 = 0;

	// Row 2
	m.x2 = (2 * (q.x * q.y)) + (2 * (q.w * q.z));
	m.y2 = 1 - (2 * pow(q.x, 2)) - (2 * (pow(q.z, 2)));
	m.z2 = (2 * (q.y * q.z)) + (2 * (q.w * q.x));
	m.w2 = 0;

	// Row 3
	m.x3 = (2 * (q.x * q.z)) - (2 * (q.w * q.y));
	m.y3 = (2 * (q.y * q.z)) - (2 * (q.w * q.x));
	m.z3 = 1 - (2 * pow(q.x, 2)) - (2 * pow(q.y, 2));
	m.w3 = 0;

	//Row 4
	m.x4 = 0;
	m.y4 = 0;
	m.z4 = 0;
	m.w4 = 1;

	return m;
}

Quaternion EulerToQuaternion(Vector3 euler)
{
	Vector3 e = Scale3(euler, 0.5f);

	float cz = cos(e.z);
	float sz = sin(e.z);
	float cy = cos(e.y);
	float sy = sin(e.y);
	float cx = cos(e.x);
	float sx = sin(e.x);

	Quaternion q;
	q.w = cx * cy * cz + sx * sy * sz;
	q.x = sx * cy * cz - cx * sy * sz;
	q.y = cx * sy * cz + sx * cy * sz;
	q.z = cx * cy * sz - sx * sy * cz;

	return q;
}

Vector3 RadiansToDegrees(Vector3 rad)
{
	rad.x *= 180.0f * M_PI;
	rad.y *= 180.0f * M_PI;
	rad.z *= 180.0f * M_PI;
	return rad;
}

Quaternion Mat4ToQuaternion(Mat4 m)
{
	float t;
	Quaternion q;
	if (m.z3 < 0) 
	{ 
		if (m.x1 > m.y2) 
		{ 
			t = 1 + m.x1 - m.y2 - m.z3;
			q  = NewQuaternion(t, m.y1 + m.x2, m.x3 + m.z1, m.z2 - m.y3); 
		} 
		else 
		{ 
			t = 1 - m.x1 + m.y2 - m.z3;
			q = NewQuaternion(m.y1 + m.x2, t, m.z2 + m.y3, m.x3 - m.z1);
		} 
	}
	else 
	{ 
		if (m.x1 < -m.y2)
		{ 
			t = 1 - m.x1 - m.y2 + m.z3;
			q = NewQuaternion(m.x3 + m.z1, m.z2 + m.y3, t, m.y1 - m.x2);
		}
		else
		{
			t = 1 + m.x1 + m.y2 + m.z3;
			q = NewQuaternion(m.z2 - m.y3, m.x3 - m.z1, m.y1 - m.x2, t);
		}
	}
	return q = ScaleQuaternion(q, 0.5f / sqrt(t));
}

Vector3 QuaternionToEuler(Quaternion q)
{
	Vector3 r;
	
	// roll (x-axis rotation)
	double sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
	double cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
	r.x = atan2(sinr_cosp, cosr_cosp);

	// pitch (y-axis rotation)
	double sinp = 2 * (q.w * q.y - q.z * q.x);
	if (abs(sinp) >= 1)
		r.y = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
	else
		r.y = asin(sinp);

	// yaw (z-axis rotation)
	double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
	double cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
	r.z = atan2(siny_cosp, cosy_cosp);

	return r;
}
