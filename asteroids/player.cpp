#include "player.h"
#include "raylib.h"
#include "raymath.h"


Player::Player(Vector2 position)
{

	 normalizedDir = Vector2 (direction);
	screen = { 1000, 600 };
	velocity = Vector2{ 20,10 };
	direction = Vector2{ 50,10 };
	acelerationRate = 200.0f;
	decelerationRate = .5f;
    delta = GetFrameTime();
	angle = atan2(direction.y, direction.x);
	maxSpeed = 300.0f;
	color = RED;
	rectangle.x = position.x;
	rectangle.y = position.y;
	rectangle.width = 200;
	rectangle.height = 200;

}
void Player::DrawPlayer()
{
	 DrawPoly(screen, 3, 20, angle * RAD2DEG, color);

}

void Player::Shoot()
{
}

void Player::Update()
{
}

void Player::Input()
{

	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		velocity.x += normalizedDir.x * acelerationRate * delta;
		velocity.y += normalizedDir.y * acelerationRate * delta;



	}
	else
	{
		// Aplicar desaceleraci?n multiplicada por delta para mantener independencia del framerate
		velocity.x -= velocity.x * decelerationRate * delta;
		velocity.y -= velocity.y * decelerationRate * delta;
	}

	//NOTA: Agregar un delay entre disparo y disparo
	//if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	//{
		////for (int i = 0; i < totalBalas; i++)
		//{
			//if (!balasJugador[i].isActive)
			//{
				//balasJugador[i].position = Player.position;
				//balasJugador[i].direction = Vector2Subtract(GetMousePosition(), balasJugador[i].position);
				//Vector2 normalizedDir = Vector2Normalize(balasJugador[i].direction);
				//balasJugador[i].velocity *= 21; //*GetFrameTime();
				//balasJugador[i].isActive = true;
				//balasJugador[i].velocity.x += .10f * delta;
				//balasJugador[i].velocity.y -= .050 * delta;
			///	//break;
			//}
			///for (int i = 0; i < totalBalas; i++)
			//if ((GetTime() - balasduracion) >= 5.f)
			//{
				// Missile dissapears
				//balasJugador[i].isActive = false;
		//	}
		//}
	
	// Limitar velocidad m?xima
	velocity = Vector2ClampValue(velocity, 0, maxSpeed);
}

void Player::CheckPlayerBoundries()

{
	if (rectangle.x < 0)
	{
		rectangle.width = screen.x - 0;//player.position.y
	}
	if (rectangle.x > screen.x)
	{
		rectangle.width = 0 + 0;//player.position.y
	}

	if (rectangle.y < 0)
	{
		rectangle.height = screen.y - 0;//player.position.x
	}
	if (rectangle.y > screen.y)
	{
		rectangle.width = 0 + 0;// player.position.x
	}
}

