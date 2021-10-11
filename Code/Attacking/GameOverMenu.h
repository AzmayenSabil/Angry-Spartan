#pragma once

#define MAX_NUMBER_OF_ITEMS 3

#include <iostream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>
#include <sstream> 
#include <fstream>

#include <SFML/system.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>


using namespace std;
using namespace sf;

class GameOverMenu
{

public:
	GameOverMenu(float width, float height);
	~GameOverMenu();

	void draw(RenderTarget& target, Vector2f pos);
	void moveUp();
	void moveDown();
	int GetPressedItem() { return selectedItemIndex; }

	void update(RenderWindow& window, bool * isGameOver, int *level);

	void clear();

private:
	int selectedItemIndex = 0;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Sprite sprite[MAX_NUMBER_OF_ITEMS];
	sf::Sprite gameOverBgSprite;
	sf::Texture gameOverBgTexture;


};

