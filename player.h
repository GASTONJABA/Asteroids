#pragma once

struct Rectjugador
{
	Vector2  position;
	Vector2 velocity;
	Vector2 direction;
	float acelerationRate;
	float decelerationRate;
	float maxSpeed;
    Color  color;

};

Rectjugador CrearPlayer();