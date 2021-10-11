#include "Pickup.h"

Pickup::Pickup()
{
}

Pickup::~Pickup()
{
}

void Pickup::render(RenderTarget & target)
{
	target.draw(sprite);
}
