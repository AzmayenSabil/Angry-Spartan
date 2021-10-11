#pragma once

#include "Enemy.h"
#include "Spawner.h"
#include "ScoreSystem.h"
#include "HealthBar.h"
#include "AttributeComponents.h"
#include "PauseMenu.h"
#include "GameOverMenu.h"

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



class UIElements
{
public:
	UIElements();
	~UIElements();

	bool isPaused = false;
	int pauseOrPlay = 0;
	Font pauseFont;
	Text pauseText;

	bool isGameOver = false;
	Font gameOverFont;
	Text gameOverText;

	void pauseGameText();
	void overText();

	void updatePause();

	int score = 0;
	void showScore();

	bool showHealthBar = false;
	void updateHealthBar(int health, Sprite sprite);
	void updateSpartanHealthBar(int health, int maxHealth, RenderTarget& target);

	void checkGameOVer(bool isDead);

	void render(RenderTarget & target, bool isMoreThanThreshold, Vector2f pos);

	HealthBar healthBar = HealthBar();
	ScoreSystem scoreSystem = ScoreSystem();
	AttributeComponents attributeComponents = AttributeComponents();

	Font scoreFont;
	Text scoreText;

	void updateScore(int score);
	void updateRage(int rage);
	void updateStamina(int stamina);
	float windowX = 910.222f;
	float windowY = 512.f;

	PauseMenu pauseMenu = PauseMenu(windowX, windowY);
	GameOverMenu gameOverMenu = GameOverMenu(windowX, windowY);

	void updatePauseMenu(RenderWindow& window, int *level);
	void updateGameOverMenu(RenderWindow& window, int *level);

private:
};

