#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "balas.h"




int main(void)
{

	Vector2 screen = { 1000, 600 };
	InitWindow(screen.x, screen.y, "Ejemplo Raylib - Asteroids");

	// Vector2 playerPosition = { screen.x / 2, screen.y / 2 };
	 //Vector2 direction = { 0, 0 };
	 //Vector2 velocity = { 0, 0 };

	 //float accelerationRate = 200.0f;    // Pixeles por segundo
	 //float decelerationRate = .5f;      // Frenado por segundo
	 //float maxSpeed = 300.0f;            // Pixeles por segundo


	Rectjugador Player1 = CrearPlayer({ screen.x / 2, screen.y / 2 }, { 0,0 }, { 0,0 }, 200.0f, .5f, 300., RED);
	const int totalBalas = 20;
	Balas balasJugador[totalBalas];

	for (int i = 0; i < totalBalas; i++)
	{
		balasJugador[i] = CrearBala();
	}

	while (!WindowShouldClose())
	{
		float delta = GetFrameTime();

		// Dirección hacia el cursor
		Player1.direction = Vector2Subtract(GetMousePosition(), Player1.position);
		Vector2 normalizedDir = Vector2Normalize(Player1.direction);

		// Aceleración mientras se mantiene el botón derecho presionado
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			Player1.velocity.x += normalizedDir.x * Player1.decelerationRate * delta;
			Player1.velocity.y += normalizedDir.y * Player1.acelerationRate * delta;



		}
		else
		{
			// Aplicar desaceleración multiplicada por delta para mantener independencia del framerate
			Player1.velocity.x -= Player1.velocity.x * Player1.decelerationRate * delta;
			Player1.velocity.y -= Player1.velocity.y * Player1.decelerationRate * delta;
		}

		//NOTA: Agregar un delay entre disparo y disparo
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			for (int i = 0; i < totalBalas; i++)
			{
				if (!balasJugador[i].isActive)
				{
					balasJugador[i].position = Player1.position;
					balasJugador[i].isActive = true;
				}
			}
		}

		// Limitar velocidad máxima
		Player1.velocity = Vector2ClampValue(Player1.velocity, 0, Player1.maxSpeed);

		// Mover al jugador con la velocidad escalada por delta
		Player1.position.x += Player1.velocity.x * delta;
		Player1.position.y += Player1.velocity.y * delta;

		// Calcular ángulo para rotar el triángulo hacia el mouse
		float angle = atan2(Player1.direction.y, Player1.direction.x);

		BeginDrawing();
		ClearBackground(BLACK);

		// Dibujamos al player
		DrawPoly(Player1.position, 3, 20, angle * RAD2DEG, GREEN);
		DrawLineV(Player1.position, GetMousePosition(), RED);

		for (int i = 0; i < totalBalas; i++)
		{
			if (balasJugador[i].isActive)
			{
				DrawCircle(balasJugador[i].position.x, balasJugador[i].position.y, 5, balasJugador[i].color);
			}
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}













