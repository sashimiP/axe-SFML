#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include<string>
#include<sstream>
#include<cstdlib>

class Text
{
public:
	Text();
	Text(int l_size, float positionX, float positionY, std::string message);
	~Text() {}
	void Setup(int l_size, float positionX, float positionY, std::string message);

	void Display(sf::RenderWindow& l_window);
	void SetMessage(Player& player);
	void SetEmptyMessage();
	void SetLevel(int level);

private:
	sf::Vector2f m_Position;
	sf::Text m_Text;
	sf::Font m_font;
	std::string textMessage;
};
