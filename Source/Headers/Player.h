#pragma once
#include <SFML/Graphics.hpp>


class Player
{
private:
	sf::Vector2f m_Position;

	sf::CircleShape m_Shape;

	float m_Speed{ 500.0f };
	bool m_MovingRight{ false };
	bool m_MovingLeft{ false };
	float m_Score{ 0 };

public:
	Player(float startX, float startY);
	~Player() {}

	sf::FloatRect getPosition();

	sf::CircleShape getShape();

	int getScore();

	void setScore(float score);

	void addScore();

	void MoveRight();

	void MoveLeft();

	void StopRight();

	void StopLeft();

	void Update(sf::Time dt);

	void Render(sf::RenderWindow& l_window);

	sf::Vector2f GetVectorPosition();

	void SetPosition(sf::Vector2f newPosition);
};
