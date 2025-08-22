#include "raylib.h"
#include "player.h"



Rectjugador CrearPlayer(Vector2 position, Vector2 velocity, Vector2 direction, float acelerationRate, float decelerationRate, float maxSpeed, Color color)
{
	Rectjugador nuevaentrada;

	nuevaentrada.position = position;
    nuevaentrada.velocity = velocity;
	nuevaentrada.direction = direction;
	nuevaentrada.acelerationRate = acelerationRate;
	nuevaentrada.decelerationRate = decelerationRate;
	nuevaentrada.maxSpeed = maxSpeed;



	nuevaentrada.color = color;
	return nuevaentrada;
}