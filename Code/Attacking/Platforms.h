#pragma once

#include "Platform.h"

#include "Collider.h"

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


class Platforms
{
public:
	Platforms();
	~Platforms();

	vector <Platform> platformList; // platform container

	void chooseLevel(int level);

	void render(RenderTarget & target);

	void clearPlatforms();


private:
	float groundWidth = 1024, sizeX = 3 / 1.25f;
	float defLength = groundWidth * sizeX;
	Vector2f defWallSize = Vector2f(1.1 / 1.25f, 3 / 2.5f);
	Vector2f defPlatformSize = Vector2f(1 / 1.f, 1 / 1.f);

	Texture texture;
	Texture texture2;

	sf::Vector2f direction;

	void addNewScene(float startFrom, float length, float height);
	void addPlatform(float startFrom, Vector2f size, float height);
	void addWall(float startFrom, Vector2f size, float height);
	void addCave(float startFrom, float length, float height);

	void initLevel1Platforms();
	void initLevel2Platforms();
	void initLevel3Platforms();
};

