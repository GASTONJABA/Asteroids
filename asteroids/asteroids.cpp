#include "raylib.h"
#include "raymath.h"

//int main(void)
//{
//    Vector2 screen = { 1000, 600 };
//    InitWindow(screen.x, screen.y, "Ejemplo Raylib - Asteroids");
//
//    Vector2 playerPosition = { screen.x / 2, screen.y / 2 };
//    Vector2 direction = { 0, 0 };
//    Vector2 velocity = { 0, 0 };
//
//    float accelerationRate = 200.0f;    // Pixeles por segundo
//    float decelerationRate = 2.5f;      // Frenado por segundo
//    float maxSpeed = 300.0f;            // Pixeles por segundo
//
//    while (!WindowShouldClose())
//    {
//        float delta = GetFrameTime();
//
//        // Dirección hacia el cursor
//        direction = Vector2Subtract(GetMousePosition(), playerPosition);
//        Vector2 normalizedDir = Vector2Normalize(direction);
//
//        // Aceleración mientras se mantiene el botón derecho presionado
//        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
//        {
//            velocity.x += normalizedDir.x * accelerationRate * delta;
//            velocity.y += normalizedDir.y * accelerationRate * delta;
//        }
//        else
//        {
//            // Aplicar desaceleración multiplicada por delta para mantener independencia del framerate
//            velocity.x -= velocity.x * decelerationRate * delta;
//            velocity.y -= velocity.y * decelerationRate * delta;
//        }
//
//        // Limitar velocidad máxima
//        velocity = Vector2ClampValue(velocity, 0, maxSpeed);
//
//        // Mover al jugador con la velocidad escalada por delta
//        playerPosition.x += velocity.x * delta;
//        playerPosition.y += velocity.y * delta;
//
//        // Calcular ángulo para rotar el triángulo hacia el mouse
//        float angle = atan2(direction.y, direction.x);
//
//        BeginDrawing();
//        ClearBackground(BLACK);
//
//        // Dibujamos al player
//        DrawPoly(playerPosition, 3, 20, angle * RAD2DEG, GREEN);
//        DrawLineV(playerPosition, GetMousePosition(), RED);
//
//        EndDrawing();
//    }
//
//    CloseWindow();
//    return 0;
//}
