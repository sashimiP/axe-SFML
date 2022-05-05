#include "Axe.h"

Axe::Axe() {}

Axe::Axe(float startX, float startY, float speed, sf::Color color)
{
	m_Position.x = startX;
	m_Position.y = startY;
	m_Speed = speed;
	m_Color = color;

	m_Shape.setSize(sf::Vector2f(50, 50));
	m_Shape.setPosition(m_Position);
	m_Shape.setFillColor(m_Color);
}
sf::FloatRect Axe::getPosition()
{
	return m_Shape.getGlobalBounds();
}
sf::RectangleShape Axe::getShape()
{
	return m_Shape;
}
void Axe::reboundTop()
{
	m_DirectionY = -m_DirectionY;
}
void Axe::reboundBottom()
{
	m_DirectionY = -m_DirectionY;
}
void Axe::Update(sf::Time dt)
{
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Shape.setPosition(m_Position);
}
void Axe::Render(sf::RenderWindow& l_window)
{
	axeOnScreen = true;
	l_window.draw(m_Shape);
}

bool Axe::isAxeOnScreen()
{
	return axeOnScreen;
}
