#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "balas.h"
#include "CheckPlayerBoundries.h"
#include "Enemigos.h"

void CheckPlayerBoundries(Rectjugador& player, Vector2 screen);

int main(void)
{

	Vector2 screen = { 1000, 600 };
	InitWindow(screen.x, screen.y, "Ejemplo Raylib - Asteroids");
	//Rectjugador Player1 = CrearPlayer();
	// playerPosition = { screen.x / 2, screen.y / 2 };
	//Vector2 direction = { 0, 0 };
	// Vector2 velocity = { 0, 0 };
	Texture2D bala1 = LoadTexture("res/bala1.png");

	const int frameWidth = bala1.width;                // Ancho de cada frame en el spritesheet
	const int frameHeight = bala1.height;
	Rectangle frameRec = { 0.0f, 0.0f, (float)frameWidth, (float)frameHeight }; // Rectángulo que define el frame actual para dibujar
	Vector2 bala1Pos = { 200.0f, 150.0f };                         // Posición donde se dibuja el logo
	float bala1Rotation = 0.0f;
	//float accelerationRate = 200.0f;    // Pixeles por segundo
	 //float decelerationRate = .5f;      // Frenado por segundo
	 //float maxSpeed = 300.0f;            // Pixeles por segundo
	const int totalenemigos = 10;
	Enemigo  Cantidadenemigos[totalenemigos];

	
	static int spawnTimerEnemigo = 0;
	if (spawnTimerEnemigo >= 120)
	{
		for (int i = 0; i < totalenemigos; i++)
		{
			// La bala enemiga debe tener una velocidad Y positiva
			 Cantidadenemigos[i] = CrearEnemigo(Vector2{0,0});
			 DrawCircle(Cantidadenemigos[i].position.x, Cantidadenemigos[i].position.y, Cantidadenemigos[i].radius, Cantidadenemigos[i].color);
		}

	}


	const int totalBalas = 20;
	float balasduracion = GetTime();
	Balas balasJugador[totalBalas];

	for (int i = 0; i < totalBalas; i++)
	{
		balasJugador[i] = CrearBala({ 50,10 });//50,10
	}
	Rectjugador Player = CrearPlayer(Vector2{ 0,0 });
	//Enemigo enemigo1 = CrearEnemigo(Vector2{ 0,0 });
	while (!WindowShouldClose())
	{
		float delta = GetFrameTime();
		//Rectjugador Player = CrearPlayer(Vector2{0,0});
		// Direcci�n hacia el cursor
		Player.direction = Vector2Subtract(GetMousePosition(), Player.position);
		Vector2 normalizedDir = Vector2Normalize(Player.direction);
		//balasJugador.direction = Vector2Subtract(GetMousePosition(), balasJugador.position);
		//Vector2 normalizedDir = Vector2Normalize(balasJugador.direction);
		CheckPlayerBoundries(Player, screen);
		// Aceleraci�n mientras se mantiene el bot�n derecho presionado
		if (delta >= 1.0)
		{

			//CrearEnemigo({ 50,10 });
			//DrawCircle(enemigo1.position.x, enemigo1.position.y, enemigo1.radius, enemigo1.color);
		}

		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			Player.velocity.x += normalizedDir.x * Player.acelerationRate * delta;
			Player.velocity.y += normalizedDir.y * Player.acelerationRate * delta;



		}
		else
		{
			// Aplicar desaceleraci�n multiplicada por delta para mantener independencia del framerate
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
					balasJugador[i].direction = Vector2Subtract(GetMousePosition(), balasJugador[i].position);
					Vector2 normalizedDir = Vector2Normalize(balasJugador[i].direction);
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
		// Limitar velocidad m�xima
		Player.velocity = Vector2ClampValue(Player.velocity, 0, Player.maxSpeed);
		static int spawnTimerEnemigo = 0;
		if (spawnTimerEnemigo >= 120)
		{
			for (int i = 0; i < totalenemigos; i++)
			{
				// La bala enemiga debe tener una velocidad Y positiva
				Cantidadenemigos[i] = CrearEnemigo(Vector2{ 0,0 });
				DrawCircle(Cantidadenemigos[i].position.x, Cantidadenemigos[i].position.y, Cantidadenemigos[i].radius, Cantidadenemigos[i].color);
			}

		}
		// Mover al jugador con la velocidad escalada por delta
		Player.position.x += Player.velocity.x * delta;
		Player.position.y += Player.velocity.y * delta;

		// Calcular �ngulo para rotar el tri�ngulo hacia el mouse
		float angle = atan2(Player.direction.y, Player.direction.x);

		BeginDrawing();
		ClearBackground(BLACK);

		// Dibujamos al player
		DrawPoly(Player.position, 3, 20, angle * RAD2DEG, Player.color);
		DrawLineV(Player.position, GetMousePosition(), RED);
		//DrawCircle(enemigo1.position.x, enemigo1.position.y, enemigo1.radius, enemigo1.color);
		for (int i = 0; i < totalBalas; i++)
		{
			if (balasJugador[i].isActive)
			{
				DrawTexturePro(bala1, { 0,0, (float)bala1.width,(float)bala1.height },
					{ balasJugador[i].position.x,
					balasJugador[i].position.y,balasJugador[i].radius ,balasJugador[i].radius  },
					{ balasJugador[i].radius, balasJugador[i].radius }
				, bala1Rotation, WHITE);

				//{ balasJugador[i].radius, balasJugador[i].radius }.


					//(float)bala1.width / 2, (float)bala1.height / 2



					//DrawCircle(balasJugador[i].position.x, balasJugador[i].position.y, balasJugador[i].radius, balasJugador[i].color);
				// Movement
				balasJugador[i].position.x += balasJugador[i].direction.x * balasJugador[i].velocity.x * delta;
				balasJugador[i].position.y += balasJugador[i].direction.y * balasJugador[i].velocity.y * delta;
				
				//balasJugador[i].position.x += balasJugador[i].velocity.x;//gracias a estoy se mueven
				//balasJugador[i].position.y -= balasJugador[i].velocity.y;
				balasJugador[i].direction = Vector2Subtract(GetMousePosition(), Player.position);//Borrar esto sino la bala vuelve
				//Vector2 normalizedDir2 = Vector2Normalize(balasJugador[i].direction);
				//balasJugador[i].position.x += normalizedDir2.x * balasJugador[i].velocity.x * delta;
				//balasJugador[i].position.y += normalizedDir2.y * balasJugador[i].velocity.y * delta;



			}
		}

		EndDrawing();
	}
	UnloadTexture(bala1);
	CloseWindow();
	return 0;
}












