#pragma once

#define NUM 3

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

class SaveFile
{
public:

	SaveFile();
	~SaveFile();

	int* getProgress();
	
	int getHealth() { return this->list[2]; }
	int getPosition() { return this->list[1]; }
	int getLevel() { return this->list[0]; }

private:
	int list[NUM];
};

