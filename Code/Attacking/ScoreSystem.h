#pragma once

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

class ScoreSystem
{
public:

	ScoreSystem();
	~ScoreSystem();

	Font scoreFont;
	Text scoreText;

	void updateScore(string enemyType);
	void updateScoreFile();

	int getScore();

private:

	int score;

};

