#include "Levels.h"

Levels::Levels(float width, float height)
{
	if (!levelsBgTexture.loadFromFile("images/menubg.png")) {
		std::cout << "Cant load BG\n";
	}
	levelsBgSprite.setTexture(levelsBgTexture);
	levelsBgSprite.setTextureRect(IntRect(0, 0, 1980, 1080));
	levelsBgSprite.setScale(1 / 2.f, 1 / 2.f);

	if (!font.loadFromFile("Fonts/TYPEWR__.TTF"))
	{
		//handle error
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Black);
	menu[0].setString("LEVEL 1");
	menu[0].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	this->sprite[0].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("LEVEL 2");
	menu[1].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("LEVEL 3");
	menu[2].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));




}

Levels::~Levels()
{

}

void Levels::moveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		std::cout << "Up pressed";
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Levels::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		std::cout << "Down pressed";
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Levels::update(RenderWindow& window, int* level)
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
			*level = 1;
			std::cout << "Button pressed" << std::endl;
		}
	}

	if (menu[1].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		std::cout << "Hovered over button!" << std::endl;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			*level = 2;
			std::cout << "Button pressed" << std::endl;
		}
	}

	if (menu[2].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		std::cout << "Hovered over button!" << std::endl;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			*level = 3;
			std::cout << "Button pressed" << std::endl;
		}
	}


}

void Levels::clear()
{
	//delete menu;
}

void Levels::draw(RenderTarget & target)
{
	target.draw(levelsBgSprite);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		target.draw(menu[i]);
	}
}

