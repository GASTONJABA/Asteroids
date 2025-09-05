#pragma once

struct Enemigo

{
	Vector2 position;
	Vector2 velocity;
	Vector2 direction;
	float radius;
	bool isActive;


	Color color;


};
Enemigo CrearEnemigo(Vector2 direction);
