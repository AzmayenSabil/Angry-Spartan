#include "Game.h"


void Game::initWindow()
{
	this->window.create(VideoMode(windowX, windowY), "Refactoring Angry Spartan", Style::Close | Style::Resize);
	this->window.setFramerateLimit(60);
	this->view = sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(windowX, windowY));	//the ratio should always be 16:9
}

vector <Projectile> arrows; // Arrow container


/*void Game::initLevel()	//init all the levels here
{
	//all variables will be init here
	this->platforms.chooseLevel(this->currentLevel);
	this->enemies.chooseLevel(this->currentLevel);

}*/

void Game::changeLevel()	//if level changes, this will init the new level, delete the old one
{

	if (this->currentLevel == 0)
	{
		this->isMenu = true;
		this->menu = MainMenu(windowX, windowY);
	}
	
	else if (this->currentLevel == 1)
	{
		this->isMenu = false;
		this->spartan = Spartan();
		this->level.chooseLevel(currentLevel);
	}

	else if (this->currentLevel == 2)
	{
		this->isMenu = false;
		this->spartan = Spartan();
		this->level.chooseLevel(currentLevel);
	}

	else if (this->currentLevel == 3)
	{
		this->isMenu = false;
		this->spartan = Spartan();
		this->level.chooseLevel(currentLevel);
	}

	//this->currentLevel = 1; //put a value here to change
	this->selectLevel();
}

void Game::camera()
{

	if (spartan.GetPosition().x >= minCameraX)	//camera will only move if player crosses the threshold
	{
		view.setCenter(spartan.GetPosition());
		window.setView(view);
		this->isMoreThanThreshold = true;
	}
	else
		this->isMoreThanThreshold = false;


	//std::cout << spartan.GetPosition().y << endl;
}

void Game::selectLevel()
{
	
	if (this->currentLevel == -2)
	{
		this->isMenu = true;
		this->isGameMode = false;
		this->isChoosingLevels = true;
		this->level.chooseLevel(currentLevel);
	}

	else if (this->currentLevel == -1)
	{
		this->isMenu = true;
		this->isGameMode = true;
		this->level.chooseLevel(currentLevel);
	}

	else if (this->currentLevel == 0)
	{
		this->isMenu = true;
		this->level.chooseLevel(currentLevel);
	}

	else if (this->currentLevel == -100)
	{
		this->isMenu = false;
		this->isGameMode = false;
		this->isChoosingLevels = false;
		this->sv.getProgress();
		this->currentLevel = this->sv.getLevel();
		this->spartan.setHealth(this->sv.getHealth());
		this->spartan.setPosition(this->sv.getPosition());
		this->level.chooseLevel(this->sv.getLevel());

		//this->spartan = Spartan();
	}

	else if (this->currentLevel == 1)
	{
		this->isMenu = false;
		this->isGameMode = false;
		this->isChoosingLevels = false;
		this->level.chooseLevel(currentLevel);
		//this->spartan = Spartan();
	}

	else if (this->currentLevel == 2)
	{
		this->isMenu = false;
		this->isGameMode = false;
		this->isChoosingLevels = false;
		this->level.chooseLevel(currentLevel);
	}
	else if (this->currentLevel == 3)
	{
		this->isMenu = false;
		this->isGameMode = false;
		this->isChoosingLevels = false;
		this->level.chooseLevel(currentLevel);
	}
	

}

//only few things will be init here
Game::Game()
{
	this->initWindow();
	this->selectLevel();
}

Game::~Game()
{

}


void Game::update(float deltaTime)
{
	if (ui.isPaused)
		ui.updatePauseMenu(this->window, &currentLevel);

	if (isMenu)
	{
		this->menu.update(this->window, &this->currentLevel);
	}
	else 
		this->menu.turnOffMusic();
		

	if (isGameMode)
		this->level.gameMode.update(this->window, &this->currentLevel);

	if (isChoosingLevels)
		this->level.levels.update(this->window, &this->currentLevel);
	
	this->selectLevel();

	//cout << this->currentLevel << endl;

	while (this->window.pollEvent(this->ev)) {

		if (this->ev.type == Event::Closed) { // to close the window
			this->ui.scoreSystem.updateScoreFile();
			this->window.close();
		}

		else if (this->ev.type == Event::KeyPressed && this->ev.key.code == Keyboard::Escape) {
			this->isPaused = true;
			this->ui.updatePause();
		}

	}

	if (!this->ui.isGameOver) {

		if (!this->ui.isPaused && !this->isMenu) {

			if (this->level.enemies.enemyList.size() == 0)
			{
				if (this->currentLevel != 3)
				{
					this->currentLevel += 1;
					this->selectLevel();
				}
			}

			this->level.update(spartan);
			this->level.checkpoints.update(spartan.getPosition().x, this->currentLevel, this->spartan.getHealth());
			this->sv.getProgress();

			thread t4(&Spartan::update, &spartan, deltaTime);
			
			
			//this->spartan.update(deltaTime);

			thread t3(&Combat::update, &this->combat, &spartan, &this->level.enemies, ref(arrows), deltaTime, &this->ui.score);
			t3.detach();
			t4.detach();
			//this->combat.update(&spartan, &this->level.enemies, arrows, deltaTime, &this->ui.score);

			//-----------ENEMIES---------------------//
			thread t1(&Enemies::updateMovements, this->level.enemies, this->spartan.spartanSprite, deltaTime);
			//this->level.enemies.updateMovements(this->spartan.spartanSprite, deltaTime);
			//thread t2(&Combat::attack, this->combat, &spartan, &this->level.enemies, ref(arrows), deltaTime); //use ref() for vectors
			//this->combat.attack(&spartan, &this->level.enemies, arrows, deltaTime);
			//t2.join();

			//------projectiles class---------
			if (arrows.size() > 0) {
				for (int i = 0; i < arrows.size(); i++) {
					arrows[i].move();
				}
			}
			
			//this->combat.hitWithProjectile(arrows, this->spartan);

			//---------end of projectile class------

			
			this->ui.checkGameOVer(this->spartan.checkIfDead());


			//-----------SPARTAN---------------------//
			
			//this->spartan.updateMovement(deltaTime);
			//this->spartan.updateAnimation(deltaTime);
			//this->combat.spartanAttack(&spartan, &this->level.enemies, arrows, deltaTime, &this->ui.score);

			while (this->combat.getPickupsNum() != 0)
			{
				this->level.addPickups(this->combat.dropPickup());
				this->combat.pickupLocations.pop_back();

			}
		
			this->level.enemies.updateHealthBars(); // to update enemies health bar 
			this->ui.updateScore(spartan.getScore());
			this->ui.updateSpartanHealthBar(spartan.getHealth(), spartan.MAX_HEALTH, this->window); // health bar 
			this->ui.updateRage(spartan.getRage()); // ragebar
			this->ui.updateStamina(spartan.getStamina()); // stamina
			//--------------------------------------//

			//---------------------------COLLISION BETWEEN SPARTAN AND PLATFORM-----------------------------------------------------//
			sf::Vector2f direction;

			for (Platform& platform : this->level.platforms.platformList) {
				if (platform.GetCollider().CheckCollision2(spartan.GetCollider(), direction, 1.0f)) {
					//cout << direction.x << " " << direction.y << endl;
					spartan.onCollision(direction);
					textChannel.updateText("Collided with pf");
				}
			}

			for (Platform& platform : this->level.platforms.platformList) {
				for (int i = 0; i < this->level.enemies.enemyList.size(); i++)
				{
					AbstractEnemy* enemy = this->level.enemies.enemyList[i];
					if (platform.GetCollider().CheckCollision2(enemy->GetCollider(), direction, 1.0f)) {
						//cout << direction.x << " " << direction.y << endl;
						enemy->onCollision(direction);
					}
				}
				
			}
			
			//----------------------------------------------------------------------------------------//
			
			t1.join();
			//t3.join();
			//t4.join();
			
		}

	}


	if (this->ui.isGameOver) {
		//this->ui.overText(isGameOver);
		this->ui.updateGameOverMenu(this->window, &currentLevel);
		// here i can save my latest score to the file but only if it's game over
		this->ui.scoreSystem.updateScoreFile();
	}
	
	textChannel.updateText("LEVEL " + to_string(currentLevel));
}

void Game::render()
{
	this->window.clear();

	this->level.renderObjects(this->window);
	//this->xerxes.render(this->window);
	//this->leonidas.render(this->window);
	if (this->isMoreThanThreshold) {
		textChannel.draw(window, this->view.getCenter(), -50.f, 200.f);
		textChannel.updateText("");
	}

	if (isMenu)
		this->menu.draw(this->window);

	if (isGameMode)
		this->level.gameMode.draw(this->window);

	if (isChoosingLevels)
		this->level.levels.draw(this->window);

	if (!isMenu)
	{
		this->spartan.render(this->window);

		if (arrows.size() > 0) {
			for (int i = 0; i < arrows.size(); i++) { // DRAWING ARROW  // ekhaneo  error dey
				arrows[i].draw(this->window);
			}
		}

	}

	this->camera();

	//cout << this->isMoreThanThreshold << endl;

	if(!isMenu)
		this->ui.render(this->window, isMoreThanThreshold, this->view.getCenter());

	//cout <<"Spartant health: "<< spartan.getHealth() << endl;
	
	this->window.display();
}

const RenderWindow & Game::getWindow() const
{
	return this->window;
}

void Game::func(int x)
{
	//cout << "This is " << x << endl;
}


