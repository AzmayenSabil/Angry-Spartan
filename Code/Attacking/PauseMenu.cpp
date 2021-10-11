#include "PauseMenu.h"

PauseMenu::PauseMenu(float width, float height)
{
	if (!pauseMenuBgTexture.loadFromFile("images/menubg.png")) {
		std::cout << "Cant load BG\n";
	}
	pauseMenuBgSprite.setTexture(pauseMenuBgTexture);
	pauseMenuBgSprite.setTextureRect(IntRect(0, 0, 1980, 1080));
	pauseMenuBgSprite.setScale(1 / 2.f, 1 / 2.f);

	if (!font.loadFromFile("Fonts/TYPEWR__.TTF"))
	{
		//handle error
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Black);
	menu[0].setString("Resume");
	menu[0].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	//menu[0].setPosition(pos.x - 100.f, pos.y - 100.f);
	this->sprite[0].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Last Checkpoint");
	menu[1].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Restart Level");
	menu[2].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Main Menu");
	menu[3].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));



}

PauseMenu::~PauseMenu()
{

}

void PauseMenu::moveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		std::cout << "Up pressed";
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void PauseMenu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		std::cout << "Down pressed";
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void PauseMenu::update(RenderWindow& window, bool* isPaused, int *level)
{
	if (menu[0].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		std::cout << "Hovered over button! 0" << std::endl;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			*isPaused = false;
			std::cout << "Button pressed" << std::endl;
		}
	}

	if (menu[1].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		std::cout << "Hovered over button!" << std::endl;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			*level = 0;
			std::cout << "Button pressed" << std::endl;
		}
	}



}

void PauseMenu::clear()
{
	//delete menu;
}

void PauseMenu::draw(RenderTarget & target, Vector2f pos)
{
	//target.draw(pauseMenuBgSprite);
	/*for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		menu[i].setPosition(pos.x, pos.y);
		target.draw(menu[i]);
	}*/

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Black);
	menu[0].setString("Resume");
	menu[0].setPosition(pos.x - 100.f, pos.y - 100.f);
	target.draw(menu[0]);

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Last Checkpoint");
	menu[1].setPosition(pos.x - 100.f, pos.y - 50.f);
	target.draw(menu[1]);

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Restart Level");
	menu[2].setPosition(pos.x - 100.f, pos.y);
	target.draw(menu[2]);

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Main Menu");
	menu[3].setPosition(pos.x - 100.f, pos.y + 50.f);
	target.draw(menu[3]);
}

