#pragma once
#include<SFML/Graphics.hpp>
#include<string>


class Axe
{
private:
	sf::Vector2f m_Position;
	sf::RectangleShape m_Shape;

	float m_Speed{ 0 };
	float m_DirectionY{ 10 };
	sf::Color m_Color;
	bool axeOnScreen{ false };
	

public:
	Axe();
	Axe(float startX, float starty, float speed, sf::Color color);
	~Axe() {}
	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

	void reboundTop();

	void reboundBottom();

	void Update(sf::Time dt);

	void Render(sf::RenderWindow& l_window);

	bool isAxeOnScreen();
	
};
