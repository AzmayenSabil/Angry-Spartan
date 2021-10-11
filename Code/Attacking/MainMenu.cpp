#include "MainMenu.h"
Music music;
MainMenu::MainMenu(float width, float height)
{
	if (!menuBgTexture.loadFromFile("images/menubg.png")) {
		std::cout << "Cant load BG\n";
	}
	menuBgSprite.setTexture(menuBgTexture);
	menuBgSprite.setTextureRect(IntRect(0, 0, 1980, 1080));
	menuBgSprite.setScale(1 / 2.f, 1 / 2.f);

	if (!font.loadFromFile("Fonts/TYPEWR__.TTF"))
	{
		//handle error
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Black);
	menu[0].setString("Continue");
	menu[0].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	this->sprite[0].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Play");
	menu[1].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Options");
	menu[2].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("High Scores");
	menu[3].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	menu[4].setFont(font);
	menu[4].setFillColor(sf::Color::White);
	menu[4].setString("Tutorial");
	menu[4].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));

	menu[5].setFont(font);
	menu[5].setFillColor(sf::Color::White);
	menu[5].setString("Exit");
	menu[5].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 6));

	
	if (!music.openFromFile("sounds/Grant Newman - Last March Of Heroes.wav"))
	{
		cout << "Error" << endl;
	}



	//music.setPosition(0, 1, 10); // change its 3D position
	music.setPitch(2);           // increase the pitch
	music.setVolume(10);         // reduce the volume
	music.setLoop(true);         // make it loop
	// Play it
	music.play();

	if (!buffer.loadFromFile("sounds/Grant Newman - Last March Of Heroes.ogg"))
	{
		cout << "Error" << endl;
	}
	sound.setBuffer(buffer);
}

MainMenu::~MainMenu()
{

}

void MainMenu::moveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		std::cout << "Up pressed";
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void MainMenu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		std::cout << "Down pressed";
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void MainMenu::update(RenderWindow& window, int* level)
{
	//cout << this->menu[0].getLocalBounds().intersects(Mouse::getPosition()) << endl;

	/*cout << this->menu[0].getPosition().x + this->menu[0].getLocalBounds().width
		 << " "
		 << this->menu[0].getPosition().y + this->menu[0].getLocalBounds().width << endl;

	*/
	//cout << Mouse::getPosition().x << " " << Mouse::getPosition().y  << endl;
	
	
	//music.play();
	
	//sound.play();
	
	
	//Music music;
	//if (!music.openFromFile("sounds/Grant Newman - Last March Of Heroes.wav"))
	//{
	//	cout << "Error" << endl;
	//}
	//	

	//
	//	//music.setPosition(0, 1, 10); // change its 3D position
	//	music.setPitch(2);           // increase the pitch
	//	music.setVolume(50);         // reduce the volume
	//	music.setLoop(true);         // make it loop
	//	// Play it
	//	music.play();

	if (menu[0].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		std::cout << "Hovered over button! 0" << std::endl;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			*level = -100;
			std::cout << "Button pressed" << std::endl;
		}
	}

	if (menu[1].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		std::cout << "Hovered over button!" << std::endl;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			*level = -1;
			std::cout << "Button pressed" << std::endl;
		}
	}

	if (menu[5].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		std::cout << "Hovered over button!" << std::endl;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			exit(0);
			std::cout << "Button pressed" << std::endl;
		}
	}

}

void MainMenu::clear()
{
	//delete menu;
}

void MainMenu::turnOffMusic()
{
	music.stop();
}

void MainMenu::draw(RenderTarget & target)
{
	target.draw(menuBgSprite);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		target.draw(menu[i]);
	}
}
