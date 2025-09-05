#include "raylib.h"
#include "balas.h"



Balas CrearBala(Vector2 direction)
{
	Balas nuevaentrada;
	nuevaentrada.radius = 10;
	nuevaentrada.position = Vector2{ -100,-100 };
	nuevaentrada.velocity = Vector2{21,10};
	nuevaentrada.direction = Vector2{ 50,10 };
	nuevaentrada.color = RED;
	nuevaentrada.isActive = false;

	return nuevaentrada;

}