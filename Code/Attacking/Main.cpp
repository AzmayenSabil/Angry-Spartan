#include "Game.h"

int main()
{
	Game game;

	//------deltaTime-------//
	float deltaTime = 0.0f;
	sf::Clock clock;
	//---------------------//

	while (game.getWindow().isOpen()) {

		deltaTime = clock.restart().asSeconds();
		
		if (deltaTime > 1.0f / 30.0f)
			deltaTime = 1.0f / 30.0f;

		game.update(deltaTime);
		game.render();

	}

	return 0;
}


// ok 

 