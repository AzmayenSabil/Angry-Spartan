
#include "SpartanAttack.h"

SpartanAttack::SpartanAttack()
{
}

SpartanAttack::~SpartanAttack()
{
}

void SpartanAttack::HeavyAttack(Vector2f location)
{
	cout << "Attack landed on area: " << location.x << " to " << location.x + 200 << endl;
}

void SpartanAttack::dealDamage(Vector2f location, Enemies * enemies, int damage)
{

}
