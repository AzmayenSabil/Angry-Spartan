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

#include "Enemies.h"

using namespace std;
using namespace sf;

class SpartanAttack
{
public:
	SpartanAttack();
	~SpartanAttack();

	void HeavyAttack(Vector2f location);

private:

	void dealDamage(Vector2f location, Enemies* enemies, int damage);
};
