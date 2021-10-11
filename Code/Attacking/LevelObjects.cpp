#include "LevelObjects.h"

LevelObjects::LevelObjects(int level, float defaultY)
{
	this->level = level;
	this->defaultY = defaultY;
	this->enemies.setDefaultY(defaultY);
	this->chooseLevel(level);
}

LevelObjects::~LevelObjects()
{
}

void LevelObjects::chooseLevel(int level)
{
	if (this->level == level)
		return;

	if (level == 0)
	{
		this->level = level;
		this->initLevel0Objects();
	}
	else if (level == 1)
	{
		this->level = level;
		this->initLevel1Objects();
	}
	else if (level == 2)
	{
		this->level = level;
		this->initLevel2Objects();
	}
	else if (level == 3)
	{
		this->level = level;
		this->initLevel3Objects();
	}
}

Enemies LevelObjects::getEnemies()
{
	return this->enemies;
}

Platforms LevelObjects::getPlatforms()
{
	return this->platforms;
}

void LevelObjects::renderObjects(RenderTarget & target)
{
	target.draw(this->bgSprite);
	this->platforms.render(target);
	this->enemies.updateHealthBars();
	this->enemies.render(target);
	//this->wall1.draw(target);
	this->pickups.render(target);
}

void LevelObjects::initLevel0Objects() // MENU 
{
	this->platforms.clearPlatforms();
	this->enemies.clearEnemies();
	this->checkpoints.clear();
	bgTexture.loadFromFile("images/menubg.png");
	this->initBackground(IntRect(0, 0, 0, 0), Vector2f(0.f, 0.f), Vector2f(0.0f, 0.0f));
	
}

void LevelObjects::initLevel1Objects()
{
	cout << "this is level 1" << endl;
	this->platforms.clearPlatforms();
	this->enemies.clearEnemies();
	this->checkpoints.clear();
	/*bgTexture.loadFromFile("images/MORNING.png");
	bgTexture.setRepeated(true);
	this->initBackground(IntRect(0, 0, 2404, 320), Vector2f(0.f, -323.f), Vector2f(2.045f, 2.5f));*/
	//bgTexture.loadFromFile("images/MORNING.png");
	bgTexture.loadFromFile("images/morningBG.jpeg");
	bgTexture.setRepeated(true);
	//this->initBackground(IntRect(0, 0, 2404, 320), Vector2f(0.f, -323.f), Vector2f(2.045f, 2.5f));
	this->initBackground(IntRect(0, 0, 4800, 320), Vector2f(0.f, -323.f), Vector2f(2.045f, 2.5f));
	this->platforms.chooseLevel(1);
	this->enemies.chooseLevel(1);
	this->checkpoints.chooseLevel(1);
	this->pickups.chooseLevel(1);
}

void LevelObjects::initLevel2Objects()
{
	this->platforms.clearPlatforms();
	this->enemies.clearEnemies();
	this->checkpoints.clear();
	bgTexture.loadFromFile("images/DUSK.png");
	bgTexture.setRepeated(true); // to make repeation 
	this->initBackground(IntRect(0, 0, 4800, 320), Vector2f(0.f, -323.f), Vector2f(2.045f, 2.5f));
	this->platforms.chooseLevel(2);
	this->enemies.chooseLevel(2);
	this->checkpoints.chooseLevel(2);
	//this->pickups.chooseLevel(2);
}

void LevelObjects::initLevel3Objects()
{
	this->platforms.clearPlatforms();
	this->enemies.clearEnemies();
	this->checkpoints.clear();
	bgTexture.loadFromFile("images/morningBG.jpeg");
	bgTexture.setRepeated(true); // to make repeation 
	this->initBackground(IntRect(0, 0, 4800, 320), Vector2f(0.f, -323.f), Vector2f(2.045f, 2.5f));
	this->platforms.chooseLevel(3);
	this->enemies.chooseLevel(3);
	this->checkpoints.chooseLevel(3);
	//this->pickups.chooseLevel(2);

}

void LevelObjects::update(Spartan spartan)
{
	this->pickups.update(spartan);
}

void LevelObjects::addPickups(Vector2f location)
{
	this->pickups.add(location);
}


void LevelObjects::initBackground( IntRect rect, Vector2f pos, Vector2f resize)
{
	bgSprite.setTexture(bgTexture);
	bgSprite.setTextureRect(rect);
	bgSprite.setPosition(pos);
	bgSprite.setScale(resize);
}


