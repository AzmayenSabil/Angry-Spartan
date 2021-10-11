#include "GameMode.h"

GameMode::GameMode(float width, float height)
{
	if (!gameModeBgTexture.loadFromFile("images/menubg.png")) {
		std::cout << "Cant load BG\n";
	}
	gameModeBgSprite.setTexture(gameModeBgTexture);
	gameModeBgSprite.setTextureRect(IntRect(0, 0, 1980, 1080));
	gameModeBgSprite.setScale(1 / 2.f, 1 / 2.f);

	if (!font.loadFromFile("Fonts/TYPEWR__.TTF"))
	{
		//handle error
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Black);
	menu[0].setString("Battle of Hot Gates");
	menu[0].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	this->sprite[0].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Valley of The Dead");
	menu[1].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Survival Mode");
	menu[2].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Horde Mode");
	menu[3].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));



}

GameMode::~GameMode()
{

}

void GameMode::moveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		std::cout << "Up pressed";
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void GameMode::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		std::cout << "Down pressed";
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void GameMode::update(RenderWindow& window, int* mode)
{
	//cout << this->menu[0].getLocalBounds().intersects(Mouse::getPosition()) << endl;

	/*cout << this->menu[0].getPosition().x + this->menu[0].getLocalBounds().width
		 << " "
		 << this->menu[0].getPosition().y + this->menu[0].getLocalBounds().width << endl;

	*/
	//cout << Mouse::getPosition().x << " " << Mouse::getPosition().y  << endl;

	if (menu[0].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		std::cout << "Hovered over button!" << std::endl;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			*mode = -2;
			std::cout << "Button pressed" << std::endl;
		}
	}


}

void GameMode::clear()
{
	//delete menu;
}

void GameMode::draw(RenderTarget & target)
{
	target.draw(gameModeBgSprite);
	for (int i = 0; i < 1; i++)
	{
		target.draw(menu[i]);
	}
}
