#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "balas.h"




int main(void)
{

	Vector2 screen = { 1000, 600 };
	InitWindow(screen.x, screen.y, "Ejemplo Raylib - Asteroids");
	//Rectjugador Player1 = CrearPlayer();
	// playerPosition = { screen.x / 2, screen.y / 2 };
	//Vector2 direction = { 0, 0 };
	// Vector2 velocity = { 0, 0 };

	 //float accelerationRate = 200.0f;    // Pixeles por segundo
	 //float decelerationRate = .5f;      // Frenado por segundo
	 //float maxSpeed = 300.0f;            // Pixeles por segundo



	const int totalBalas = 20;
	float balasduracion = GetTime();
	Balas balasJugador[totalBalas];

	for (int i = 0; i < totalBalas; i++)
	{
		balasJugador[i] = CrearBala();
	}


	while (!WindowShouldClose())
	{
		float delta = GetFrameTime();
		Rectjugador Player = CrearPlayer();
		// Dirección hacia el cursor
		Player.direction = Vector2Subtract(GetMousePosition(), Player.position);
		Vector2 normalizedDir = Vector2Normalize(Player.direction );

		// Aceleración mientras se mantiene el botón derecho presionado
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			Player.velocity.x += normalizedDir.x * Player.acelerationRate * delta;
			Player.velocity.y += normalizedDir.y * Player.acelerationRate * delta;



		}
		else
		{
			// Aplicar desaceleración multiplicada por delta para mantener independencia del framerate
			Player.velocity.x -= Player.velocity.x * Player.decelerationRate * delta;
			Player.velocity.y -= Player.velocity.y * Player.decelerationRate * delta;
		}

		//NOTA: Agregar un delay entre disparo y disparo
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			for (int i = 0; i < totalBalas; i++)
			{
				if (!balasJugador[i].isActive)
				{
					balasJugador[i].position = Player.position;
					//balasJugador[i].velocity *= 21; //*GetFrameTime();
					balasJugador[i].isActive = true;

					//balasJugador[i].velocity.x += .10f * delta;
					//balasJugador[i].velocity.y -= .050 * delta;


					break;
				}


				///for (int i = 0; i < totalBalas; i++)
					//if ((GetTime() - balasduracion) >= 5.f)
					//{
						// Missile dissapears
						//balasJugador[i].isActive = false;
				//	}
			}


		}

		// Limitar velocidad máxima
		Player.velocity = Vector2ClampValue(Player.velocity, 0, Player.maxSpeed);

		// Mover al jugador con la velocidad escalada por delta
		Player.position.x += Player.velocity.x * delta;
		Player.position.y += Player.velocity.y * delta;

		// Calcular ángulo para rotar el triángulo hacia el mouse
		float angle = atan2(Player.direction.y, Player.direction.x);

		BeginDrawing();
		ClearBackground(BLACK);

		// Dibujamos al player
		DrawPoly(Player.position, 3, 20, angle * RAD2DEG, Player.color);
		DrawLineV(Player.position, GetMousePosition(), RED);

		for (int i = 0; i < totalBalas; i++)
		{
			if (balasJugador[i].isActive)
			{
				DrawCircle(balasJugador[i].position.x, balasJugador[i].position.y, 5, balasJugador[i].color);
				// Movement
				balasJugador[i].position.x += balasJugador[i].velocity.x;//gracias a estoy se mueven
				balasJugador[i].position.y -= balasJugador[i].velocity.y;

			}
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}













