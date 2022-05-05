#include "Text.h"

Text::Text()
{
	Setup(40, 20, 20, " ");
}
Text::Text(int l_size, float positionX, float positionY, std::string message)
{
	Setup(l_size, positionX, positionY, message);
}
void Text::Setup(int l_size, float positionX, float positionY, std::string message)
{
	m_Position.x = positionX;
	m_Position.y = positionY;
	textMessage = message;
	m_font.loadFromFile("font/DS-DIGI.ttf");
	m_Text.setFont(m_font);
	m_Text.setCharacterSize(l_size);
	m_Text.setFillColor(sf::Color::White);
	m_Text.setPosition(m_Position);
	
}
void Text::SetMessage(Player& player)
{
	std::stringstream m_message;
	m_message << textMessage << player.getScore();
	m_Text.setString(m_message.str());
}
void Text::SetEmptyMessage()
{
	
	std::stringstream m_message;
	m_message << textMessage;
	m_Text.setString(m_message.str());
}
void Text::SetLevel(int level)
{
	std::stringstream m_message;
	m_message << textMessage<<level;
	m_Text.setString(m_message.str());
}

void Text::Display(sf::RenderWindow& l_window)
{
	l_window.draw(m_Text);
}
