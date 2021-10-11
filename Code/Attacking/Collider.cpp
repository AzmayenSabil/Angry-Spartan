#include "Collider.h"

Collider::Collider(sf::Sprite& body) :
	body(body)
{
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider& other, sf::Vector2f & direction, float push)
{
	sf::Vector2f otherPosition = other.body.getPosition();                           // swapper "other" with "other.body"
	otherPosition.x = otherPosition.x + other.body.getGlobalBounds().width / 2.0f;
	otherPosition.y = otherPosition.y + other.body.getGlobalBounds().height / 2.0f;

	sf::Vector2f otherHalfSize /*= other.GetHalfSize()*/;
	otherHalfSize.x = other.body.getGlobalBounds().width / 2.0f;
	otherHalfSize.y = other.body.getGlobalBounds().height / 2.0f;

	/*/--------------to check (player)----------------------------------//
	cout << "other's information :" << endl;
	cout << otherPosition.x << " " << otherPosition.y << endl;
	cout << otherHalfSize.x << " " << otherHalfSize.y << endl;
	//-------------------------------------------------------/*/

	sf::Vector2f thisPosition = body.getPosition();
	thisPosition.x = thisPosition.x + body.getGlobalBounds().width / 2.0f;
	thisPosition.y = thisPosition.y + body.getGlobalBounds().height / 2.0f;

	sf::Vector2f thisHalfSize /*= GetHalfSize()*/;
	thisHalfSize.x = body.getGlobalBounds().width / 2.0f;
	thisHalfSize.y = body.getGlobalBounds().height / 2.0f;

	/*/--------------to check (platform)----------------------------------//
	cout << "body's information :" << endl;
	cout << thisPosition.x << " " << thisPosition.y << endl;
	cout << thisHalfSize.x << " " << thisHalfSize.y << endl;
	//-------------------------------------------------------/*/

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				Move(intersectX * (1.0f - push), 0.0f);
				other.body.move(-intersectX * push, 0.0f);

				direction.x = 1.0f;
				direction.y = 0.0f;

				//cout << "1st if if" << endl;
			}
			else
			{
				Move(-intersectX * (1.0f - push), 0.0f);
				other.body.move(intersectX * push, 0.0f);

				direction.x = -1.0f;
				direction.y = 0.0f;

				//cout << "1st if else" << endl;
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				Move(0.0f, intersectY * (1.0f - push));
				other.body.move(0.0f, -intersectY * push);

				direction.x = 0.0f;
				direction.y = 1.0f;

				//cout << "2n else if" << endl;
			}
			else
			{
				Move(0.0f, -intersectY * (1.0f - push));
				other.body.move(0.0f, intersectY * push);

				direction.x = 0.0f;
				direction.y = -1.0f;

				//cout << "2nd else else" << endl;
			}
		}


		return true;
	}

	return false;
}

bool Collider::CheckCollision2(Collider other, sf::Vector2f& direction, float push)
{
	sf::Vector2f otherPosition = other.body.getPosition();                           // swapper "other" with "other.body"
	otherPosition.x = otherPosition.x + other.body.getGlobalBounds().width / 2.0f;
	otherPosition.y = otherPosition.y + other.body.getGlobalBounds().height / 2.0f;

	sf::Vector2f otherHalfSize /*= other.GetHalfSize()*/;
	otherHalfSize.x = other.body.getGlobalBounds().width / 2.0f;
	otherHalfSize.y = other.body.getGlobalBounds().height / 2.0f;

	/*/--------------to check (player)----------------------------------//
	cout << "other's information :" << endl;
	cout << otherPosition.x << " " << otherPosition.y << endl;
	cout << otherHalfSize.x << " " << otherHalfSize.y << endl;
	//-------------------------------------------------------/*/

	sf::Vector2f thisPosition = body.getPosition();
	thisPosition.x = thisPosition.x + body.getGlobalBounds().width / 2.0f;
	thisPosition.y = thisPosition.y + body.getGlobalBounds().height / 2.0f;

	sf::Vector2f thisHalfSize /*= GetHalfSize()*/;
	thisHalfSize.x = body.getGlobalBounds().width / 2.0f;
	thisHalfSize.y = body.getGlobalBounds().height / 2.0f;

	/*/--------------to check (platform)----------------------------------//
	cout << "body's information :" << endl;
	cout << thisPosition.x << " " << thisPosition.y << endl;
	cout << thisHalfSize.x << " " << thisHalfSize.y << endl;
	//-------------------------------------------------------/*/

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				Move(intersectX * (1.0f - push), 0.0f);
				other.body.move(-intersectX * push, 0.0f);

				direction.x = 1.0f;
				direction.y = 0.0f;

				//cout << "1st if if" << endl;
			}
			else
			{
				Move(-intersectX * (1.0f - push), 0.0f);
				other.body.move(intersectX * push, 0.0f);

				direction.x = -1.0f;
				direction.y = 0.0f;

				//cout << "1st if else" << endl;
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				Move(0.0f, intersectY * (1.0f - push));
				other.body.move(0.0f, -intersectY * push);

				direction.x = 0.0f;
				direction.y = 1.0f;

				//cout << "2n else if" << endl;
			}
			else
			{
				Move(0.0f, -intersectY * (1.0f - push));
				other.body.move(0.0f, intersectY * push);

				direction.x = 0.0f;
				direction.y = -1.0f;

				//cout << "2nd else else" << endl;
			}
		}


		return true;
	}

	return false;
}
