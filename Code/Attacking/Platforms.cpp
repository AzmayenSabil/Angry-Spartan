#include "Platforms.h"

Platforms::Platforms()
{
	texture.loadFromFile("images/background.png");
	texture2.loadFromFile("images/platform.png");
}

Platforms::~Platforms()
{
}

void Platforms::chooseLevel(int level)
{
	if (level == 1)
	{
		this->initLevel1Platforms();
	}
	else if (level == 2)
	{
		this->initLevel2Platforms();
	}
	else if (level == 3)
	{
		this->initLevel3Platforms();
	}
}



void Platforms::render(RenderTarget & target)
{
	for (auto i = 0; i < platformList.size(); i++)
	{
		this->platformList[i].draw(target);
	}

}

void Platforms::clearPlatforms()
{
	platformList.clear();
}





void Platforms::addNewScene(float startFrom, float length, float height)
{
	Platform ground = Platform(&texture, IntRect(0, 0, this->groundWidth, 462), Vector2f(startFrom, height), Vector2f(this->sizeX, 1 / 2.5f)); // Main platform
	platformList.push_back(ground);
}

void Platforms::addPlatform(float startFrom, Vector2f size, float height)
{
	Platform platform = Platform(&texture2, IntRect(0, 0, 90, 20), Vector2f(startFrom, height), Vector2f(size));
	platformList.push_back(platform);
}

void Platforms::addWall(float startFrom, Vector2f size, float height)
{
	Platform wall = Platform(&texture2, IntRect(0, 0, 90, 20), Vector2f(startFrom, height), Vector2f(size));
	wall.bodySprite.setRotation(90);
	platformList.push_back(wall);
}

void Platforms::initLevel1Platforms()
{
	
	platformList.clear();

	texture.loadFromFile("images/background.png");

	float platformWidth = 1024, sizeX = 3 / 1.25f;
	float finalLimit = platformWidth * sizeX;
	float perSceneSpace = finalLimit;

	
	this->addNewScene(0, defLength, 327.f);


	this->addNewScene(finalLimit, defLength, 327.f);

	finalLimit += perSceneSpace;
	this->addWall(finalLimit + 9, this->defWallSize, 327.f);

	this->addNewScene(finalLimit, defLength, 450);

	this->addPlatform(finalLimit - 100, this->defPlatformSize, 290);

	this->addNewScene(finalLimit, defLength, 200.f);

	Platform ground3 = Platform(&texture, IntRect(0, 0, platformWidth, 462), Vector2f(finalLimit, 200.f), Vector2f(sizeX, 1 / 2.5f)); // Main platform
	platformList.push_back(ground3);

	finalLimit += perSceneSpace;
	cout << "Final limit is: " << finalLimit << endl;
	texture2.loadFromFile("images/platform.png");

	this->addPlatform(1000.f, this->defPlatformSize, 210.f);
	this->addPlatform(800.f, this->defPlatformSize, 120.f);
	this->addPlatform(1200.f, this->defPlatformSize, 180.f);

	this->addNewScene(finalLimit, defLength, 350);

	finalLimit += perSceneSpace;



	Platform startWall = Platform(&texture2, IntRect(0, 0, 0, 500), Vector2f(-0.0f, 100.f), Vector2f(0 / 1.25f, 500 / 2.5f));
	platformList.push_back(startWall);

	Platform endWall = Platform(&texture2, IntRect(0, 0, 0, 500), Vector2f(finalLimit, 100.f), Vector2f(0 / 1.25f, 500 / 2.5f));
	platformList.push_back(endWall);
}

void Platforms::initLevel2Platforms()
{
	
	platformList.clear();

	texture.loadFromFile("images/background.png");

	float platformWidth = 1024, sizeX = 3 / 1.25f;
	float finalLimit = platformWidth * sizeX;
	float perSceneSpace = finalLimit;

	
	this->addNewScene(0, defLength, 327.f);


	this->addNewScene(finalLimit, defLength, 327.f);

	finalLimit += perSceneSpace;
	this->addWall(finalLimit + 9, this->defWallSize, 327.f);

	this->addNewScene(finalLimit, defLength, 450);

	this->addPlatform(finalLimit - 100, this->defPlatformSize, 290);

	this->addNewScene(finalLimit, defLength, 200.f);

	Platform ground3 = Platform(&texture, IntRect(0, 0, platformWidth, 462), Vector2f(finalLimit, 200.f), Vector2f(sizeX, 1 / 2.5f)); // Main platform
	platformList.push_back(ground3);

	finalLimit += perSceneSpace;
	cout << "Final limit is: " << finalLimit << endl;
	texture2.loadFromFile("images/platform.png");

	this->addPlatform(1000.f, this->defPlatformSize, 210.f);
	this->addPlatform(800.f, this->defPlatformSize, 120.f);
	this->addPlatform(1200.f, this->defPlatformSize, 180.f);

	this->addNewScene(finalLimit, defLength, 350);

	finalLimit += perSceneSpace;


	Platform startWall = Platform(&texture2, IntRect(0, 0, 0, 500), Vector2f(-0.0f, 100.f), Vector2f(0 / 1.25f, 500 / 2.5f));
	platformList.push_back(startWall);

	Platform endWall = Platform(&texture2, IntRect(0, 0, 0, 500), Vector2f(finalLimit, 100.f), Vector2f(0 / 1.25f, 500 / 2.5f));
	platformList.push_back(endWall);

}

void Platforms::initLevel3Platforms()
{
	
	platformList.clear();

	texture.loadFromFile("images/background.png");

	float platformWidth = 1024, sizeX = 3 / 1.25f;
	float finalLimit = platformWidth * sizeX;
	float perSceneSpace = finalLimit;
	this->addNewScene(0, defLength, 327.f);



	this->addNewScene(finalLimit, defLength, 327.f);

	finalLimit += perSceneSpace;
	this->addWall(finalLimit + 9, this->defWallSize, 327.f);

	this->addNewScene(finalLimit, defLength, 450);

	this->addPlatform(finalLimit - 100, this->defPlatformSize, 290);

	this->addNewScene(finalLimit, defLength, 200.f);

	Platform ground3 = Platform(&texture, IntRect(0, 0, platformWidth, 462), Vector2f(finalLimit, 200.f), Vector2f(sizeX, 1 / 2.5f)); // Main platform
	platformList.push_back(ground3);

	finalLimit += perSceneSpace;
	cout << "Final limit is: " << finalLimit << endl;
	texture2.loadFromFile("images/platform.png");

	this->addPlatform(1000.f, this->defPlatformSize, 210.f);
	this->addPlatform(800.f, this->defPlatformSize, 120.f);
	this->addPlatform(1200.f, this->defPlatformSize, 180.f);

	this->addNewScene(finalLimit, defLength, 350);

	finalLimit += perSceneSpace;


	Platform startWall = Platform(&texture2, IntRect(0, 0, 0, 500), Vector2f(-0.0f, 100.f), Vector2f(0 / 1.25f, 500 / 2.5f));
	platformList.push_back(startWall);

	Platform endWall = Platform(&texture2, IntRect(0, 0, 0, 500), Vector2f(finalLimit, 100.f), Vector2f(0 / 1.25f, 500 / 2.5f));
	platformList.push_back(endWall);
}
