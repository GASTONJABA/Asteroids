#include "raylib.h"
#include "balas.h"



Balas CrearBala()
{
	Balas nuevaentrada;
	nuevaentrada.position = Vector2{ -100,-100 };
	nuevaentrada.velocity = Vector2{30,30};
	nuevaentrada.color = RED;
	nuevaentrada.isActive = false;

	return nuevaentrada;

}