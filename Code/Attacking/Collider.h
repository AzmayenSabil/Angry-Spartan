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

class Collider
{
public:
	Collider(sf::Sprite& body);
	~Collider();

	void Move(float dx, float dy) { body.move(dx, dy); }

	bool CheckCollision(Collider &other, sf::Vector2f& direction, float push);
	bool CheckCollision2(Collider other, sf::Vector2f& direction, float push);
	sf::Vector2f GetPosition() { return body.getPosition(); }



private:
	sf::Sprite& body;
};




