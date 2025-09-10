#pragma once
#include "raylib.h"

class Player
{
protected:
	Rectangle rectangle;
	Color playercolor;
	Vector2 velocity;
	Vector2 direction;
    float acelerationRate;
	float decelerationRate;
	float maxSpeed;
	float angle;// = atan2(Player.direction.y, Player.direction.x);
	Color color;
	Vector2 screen = { 1000, 600 };
	float delta;
	Vector2 normalizedDir;// = Vector2Normalize(direction);
private:
	
public:
	Player(Vector2 position);
	void DrawPlayer();
	void Shoot();
	void Update();
	void Input();
	void CheckPlayerBoundries();
};






