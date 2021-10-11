#pragma once

#include "Spartan.h"

#include "Enemies.h" // from Enemies.cpp we call the spawn.cpp class
#include "Enemy.h"

#include "Xerxes.h"
#include "Leonidas.h"

#include "Platforms.h"

#include "UIElements.h"
#include "Combat.h"
#include "Projectile.h"
#include "LevelObjects.h"
#include "MainMenu.h"
#include "PauseMenu.h"
#include "TextChannel.h"


#include "Swordsman.h"

#include "Checkpoints.h"
#include "SaveFile.h"

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

class Game
{
public:

	Game();
	~Game();

	Event ev; //to handle all the events

	sf::View view;
	float windowX = 910.222f;
	float windowY = 512.f;

	float minCameraX = 457.865f;	//min threshold to move the camera

	void update(float deltaTime);
	void render();

	const RenderWindow& getWindow() const;

	void func(int x);


private:

	

	RenderWindow window; // main-window 
	void initWindow();

	/*/------------DO WE NEED THIS ?---------------------//

	//PAUSE
	bool isPaused = false;
	int pauseOrPlay = 0;
	Font pauseFont;
	Text pauseText;

	//GAME OVER
	bool isGameOver = false;
	Font gameOverFont;
	Text gameOverText;

	//PLATFORM TEXTURE
	Texture texture;
	Texture texture2;

	//--------------------------------------------------/*/
	bool isMoreThanThreshold = false;
	bool isMenu = true;
	int currentLevel = 0; // '0' to see main menu

	bool isGameMode = false;
	bool isChoosingLevels = false;

	float defaultY = 260.f;
	
	LevelObjects level = LevelObjects(currentLevel, 260.f);

	//Platforms platforms = this->level.platforms;

	//PLAYER
	Spartan  spartan = Spartan();
	Xerxes xerxes = Xerxes(Vector2f(40.f, 260.f));
	Leonidas leonidas = Leonidas(Vector2f(200.f, 280.f));

	//ENEMY SPAWNER
	//Enemies enemies = this->level.enemies;


	MainMenu menu = MainMenu(windowX, windowY);

	UIElements ui = UIElements();

	TextChannel textChannel = TextChannel();

	Combat combat = Combat();

	//Levels
	//void initLevel();
	void changeLevel();
	void selectLevel();


	//functions
	void camera();

	SaveFile sv = SaveFile();

	PauseMenu pauseMenu = PauseMenu(windowX, windowY);
	bool isPaused = false;

};

// ok 