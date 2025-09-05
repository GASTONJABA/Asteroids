#include "raylib.h"
#include "Enemigos.h"



Enemigo CrearEnemigo(Vector2 direction)
{
	Enemigo nuevaentrada;
	nuevaentrada.radius = 50;
	nuevaentrada.position = Vector2{ 100,100 };
	nuevaentrada.velocity = Vector2{ 1,1 };
	nuevaentrada.direction = Vector2{ 50,10 };
	nuevaentrada.color = VIOLET;
	nuevaentrada.isActive = false;

	return nuevaentrada;

}