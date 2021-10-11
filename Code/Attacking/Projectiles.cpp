#include "Projectiles.h"

Projectiles::Projectiles()
{
}

Projectiles::~Projectiles()
{
}

void Projectiles::hit(Sprite target)
{
	Vector2f arrowDirection;
	for (int i = 0; i < list.size(); i++) {  // checking collision between spartan and arrow
		if (list[i].sprite.getGlobalBounds().intersects(target.getGlobalBounds()))
		{
			list.erase(list.begin() + i);
		}
	}
}
