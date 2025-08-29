#include "raylib.h"
#include "balas.h"



Balas CrearBala()
{
	Balas nuevaentrada;
	nuevaentrada.position = Vector2{ -100,-100 };
	nuevaentrada.velocity = Vector2{1,.5};
	nuevaentrada.color = RED;
	nuevaentrada.isActive = false;
	//nuevaentrada.lifetime = 0;
	return nuevaentrada;

}