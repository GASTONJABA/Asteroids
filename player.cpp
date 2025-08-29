#include "raylib.h"
#include "player.h"
#include "raymath.h"

Vector2 screen = { 1000, 600 };
Rectjugador CrearPlayer( Vector2 direction)
{
	Rectjugador nuevaentrada;

	nuevaentrada.position = Vector2{ screen.x / 2, screen.y / 2 };
	nuevaentrada.velocity = Vector2 { 20,10 };
	nuevaentrada.direction = Vector2 { 50,10 };
	nuevaentrada.acelerationRate =  200.0f;
	nuevaentrada.decelerationRate = .5f;
	nuevaentrada.maxSpeed = 300.0f;
	nuevaentrada.color = RED;
	return nuevaentrada;
}