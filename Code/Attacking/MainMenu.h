#pragma once

#define MAX_NUMBER_OF_ITEMS 6

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
#include <SFML/Audio.hpp>


using namespace std;
using namespace sf;

class MainMenu
{
public:
	MainMenu(float width, float height);
	~MainMenu();

	void draw(RenderTarget& target);
	void moveUp();
	void moveDown();
	int GetPressedItem() { return selectedItemIndex; }

	void update(RenderWindow& window, int* level);

	void clear();

	void turnOffMusic();
private:
	int selectedItemIndex = 0;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Sprite sprite[MAX_NUMBER_OF_ITEMS];
	sf::Sprite menuBgSprite;
	sf::Texture menuBgTexture;

	SoundBuffer buffer;
	sf::Sound sound;
	//Music music;
	
	bool isMusic = true;
};

