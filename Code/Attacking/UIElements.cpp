#include "UIElements.h"

UIElements::UIElements()
{
	this->pauseGameText();
	this->overText();
	this->showScore();
}

UIElements::~UIElements()
{

}

void UIElements::pauseGameText()
{
	pauseFont.loadFromFile("Fonts/TYPEWR__.TTF");
	pauseText.setFont(pauseFont);
	pauseText.setString("PAUSED");
	pauseText.setCharacterSize(32);
	pauseText.setFillColor(Color::Cyan);
	pauseText.setStyle(Text::Bold);
	pauseText.setPosition(350.f, 50.f);
}

void UIElements::overText()
{
	gameOverFont.loadFromFile("Fonts/TYPEWR__.TTF");
	gameOverText.setFont(gameOverFont);
	gameOverText.setString("GAME OVER");
	gameOverText.setCharacterSize(32);
	gameOverText.setFillColor(Color::Red);
	gameOverText.setStyle(Text::Bold);
	gameOverText.setPosition(300.f, 50.f);
}

void UIElements::updatePause()
{
	if (this->pauseOrPlay == 0) //pauseOrPlay == 0 means paused and pauseOrPlay == 1 means playing
	{
		this->isPaused = true;
		this->pauseOrPlay = 1;
	}

	else if (this->pauseOrPlay == 1)
	{
		this->isPaused = false;
		this->pauseOrPlay = 0;
	}
}

void UIElements::showScore()
{
	scoreFont.loadFromFile("Fonts/TYPEWR__.TTF");
	scoreText.setFont(scoreFont);
	scoreText.setString("Score : " + to_string(this->score));
	scoreText.setCharacterSize(22);
	scoreText.setFillColor(Color::Yellow);
	scoreText.setStyle(Text::Bold);
	scoreText.setPosition(5.f, 5.f);
}

void UIElements::updateHealthBar(int health, Sprite sprite)
{
	//healthBar.updateHealth(health, sprite);

	showHealthBar = true;
}

void UIElements::updateSpartanHealthBar(int health, int maxHealth, RenderTarget& target)
{
	healthBar.updateSpartanHealth(health, maxHealth, target);

	showHealthBar = true;
}

void UIElements::checkGameOVer(bool isDead)
{
	if (isDead) {
		this->isGameOver = true;
	}

}

void UIElements::render(RenderTarget & target, bool isMoreThanThreshold, Vector2f pos)
{
	//if (isMoreThanThreshold)
	//{
	pauseText.setPosition(pos.x - 50.f, pos.y - 200.f);
	gameOverText.setPosition(pos.x - 50.f, pos.y - 200.f);
	scoreText.setPosition(pos.x + 290.f, pos.y - 255.f);
	healthBar.frameSprite.setPosition(pos.x - 435.f, pos.y - 250.f);
	healthBar.fillSprite.setPosition(pos.x - 430.f, pos.y - 245.f);

	//}

	this->attributeComponents.draw(target, pos);

	target.draw(this->scoreText);

	if (this->isPaused)
	{
		target.draw(this->pauseText);
		this->pauseMenu.draw(target, pos);
	}


	if (this->isGameOver) {
		target.draw(this->gameOverText);
		this->gameOverMenu.draw(target, pos);
	}

	if (showHealthBar) {
		healthBar.Draw(target);
		//showHealthBar = false;
	}

}

void UIElements::updateScore(int score)
{
	this->score = score;
	this->showScore();
}

void UIElements::updateRage(int rage)
{
	//std::cout <<"RAGE : " << rage << endl;

	attributeComponents.updateRageBar(rage);
}

void UIElements::updateStamina(int stamina)
{
	attributeComponents.updateStaminaBar(stamina);
}

void UIElements::updatePauseMenu(RenderWindow& window, int *level)
{
	this->pauseMenu.update(window, &isPaused, level);
	cout << this->isPaused << endl;
}

void UIElements::updateGameOverMenu(RenderWindow & window, int * level)
{
	this->gameOverMenu.update(window, &isGameOver, level);
	cout << this->isGameOver << endl;
}
