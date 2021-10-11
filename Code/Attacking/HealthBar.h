#pragma once


#include <iostream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>

#include <SFML/system.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

using namespace std;
using namespace sf;

class HealthBar
{
public:

	HealthBar();

	~HealthBar();

	/** Renders the bar at the specified x and y location. */
	void Draw(sf::RenderTarget & target);

	/** Scales the fillSprite based on the health parameter. */
	void updateHealth(int health, int maxHealth, Sprite sprite);
	void updateSpartanHealth(int health, int maxHealth, RenderTarget& target);

	Sprite frameSprite;
	Sprite fillSprite;

private:

	Texture frameTexture;
	Texture fillTexture;

	/** Stores the maximum possible health value of the player. */
	int MAX_HEALTH;

	/** Determines whether or not the fillSprite variable is rendered. */
	bool showFill;

};

