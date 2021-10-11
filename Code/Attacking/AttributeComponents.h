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

class AttributeComponents
{
public:

	AttributeComponents();
	~AttributeComponents();

	bool staminaFill = false;
	bool showRageFill = false;
	bool showSpearFill = false;
	int rageCount = 0;
	int spearCount = 3;

	int gap = 0;

	void updateStaminaBar(int stamina);
	void updateRageBar(int rage);
	void updateSpearBar(int spear);

	void draw(RenderTarget & target, Vector2f pos);

private:

	Texture staminaTexture;
	Sprite staminaSprite;

	Texture rageFrameTexture;
	Texture ragefillTexture;
	Sprite rageframeSprite;
	Sprite ragefillSprite;

	Texture spearTexture;
	Sprite spearSprite;

};

