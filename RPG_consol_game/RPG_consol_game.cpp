#include "Game.h"

int main()
{
	srand(time(NULL));
	Game game;
	game.init_game();
	while (game.get_playing())
	{
		game.main_menu();
	}

}

