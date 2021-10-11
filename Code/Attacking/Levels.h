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

class Levels
{
public:
	Levels(float width, float height);
	~Levels();

	void draw(RenderTarget& target);
	void moveUp();
	void moveDown();
	int GetPressedItem() { return selectedItemIndex; }

	void update(RenderWindow& window, int* level);

	void clear();

private:
	int selectedItemIndex = 0;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Sprite sprite[MAX_NUMBER_OF_ITEMS];
	sf::Sprite levelsBgSprite;
	sf::Texture levelsBgTexture;
};

