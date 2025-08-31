#include "raylib.h"
#include "player.h"
#include "CheckPlayerBoundries.h"





void CheckPlayerBoundries(Rectjugador& player, Vector2 screen)
{
	if (player.position.x < 0)
	{
		player.position.x = screen.x - 0;//player.position.y
	}
	if (player.position.x > screen.x)
	{
		player.position.x = 0 + 0;//player.position.y
	}

	if (player.position.y < 0)
	{
		player.position.y = screen.y - 0;//player.position.x
	}
	if (player.position.y > screen.y)
	{
		player.position.y = 0 + 0;// player.position.x
	}
}
