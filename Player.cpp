#include "Player.h"

Player::Player(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setRadius(25);
	m_Shape.setFillColor(sf::Color::Blue);
	m_Shape.setPosition(m_Position);

}
sf::FloatRect Player::getPosition()
{
	return m_Shape.getGlobalBounds();
}
sf::CircleShape Player::getShape()
{
	return m_Shape;
}
void Player::MoveRight()
{
	m_MovingRight = true;
}
void Player::StopRight()
{
	m_MovingRight = false;
}
void Player::MoveLeft()
{
	m_MovingLeft = true;
}
void Player::StopLeft()
{
	m_MovingLeft = false;
}
void Player::Update(sf::Time dt)
{
	if (m_MovingRight)
	{
		m_Position.x += m_Speed * dt.asSeconds();
	}
	if (m_MovingLeft)
	{
		m_Position.x -= m_Speed * dt.asSeconds();
	}
	m_Shape.setPosition(m_Position);
}

int Player::getScore() { return m_Score; }

void Player::setScore(float score) { m_Score = score; }

void Player::addScore()
{
	m_Score += 1;
}

void Player::Render(sf::RenderWindow& l_window)
{
	l_window.draw(m_Shape);
}

sf::Vector2f Player::GetVectorPosition()
{
	return m_Position;
}

void Player::SetPosition(sf::Vector2f newPosition)
{
	m_Position = newPosition;
}
