#include "rigidbody.h"

void InitRigidbody(Rigidbody* rb)
{
	rb->gravity = -9.8f;
	rb->mass = 1;
	rb->velocity = (Vector3){.x = 0, .y = 0, .z = 0};
	rb->speed = 0;
	rb->Acceleration = (Vector3){ .x = 0, .y = rb->gravity, .z = 0 };
	rb->Force = (Vector3){ .x = 0, .y = 0, .z = 0 };
	rb->type = STATIC;
}

Vector3 VelocityAtTime(Vector3 InitVelocity, Vector3 Acceleration, float deltaTime)
{
	// velocity at time T = initial velocity +   acceleration * time
	Vector3 result = Add3(InitVelocity, Scale3(Acceleration, deltaTime));
	return result;
}

Vector3 Acceleration(Vector3 force, float mass)
{
	return Divide3(force, mass);
}

Vector3 AverageVelocity(Vector3 initVelocity, Vector3 finalVelocity)
{
	return Divide3(Add3(initVelocity, finalVelocity), 2.0f);
}

Vector3 Displace(Vector3 position, Vector3 velocity, Vector3 Acceleration, float deltaTime)
{
	Vector3 result = Add3(Add3(position, Scale3(velocity, deltaTime)), Scale3(Acceleration, deltaTime * deltaTime / 2.0f));
	return result;
}

Vector3 FinalVelocity(Vector3 initVelocity, Vector3 Acceleration, Vector3 Displacement)
{
	Vector3 result = Add3(Pow3(initVelocity, 2), Multiply3(Scale3(Acceleration, 2), Displacement));
	return result;
}

Vector3 Force(float mass, Vector3 Acceleration)
{
	// force = mass * acceleration
	Vector3 result = Scale3(Acceleration, mass);
	return result;
}



Vector3 ForceDueToGravity(float mass, float gravity)
{
	Vector3 result = Vector3Zero;
	return result;
}


