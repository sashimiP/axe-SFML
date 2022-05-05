#pragma once

#include "Window.h"
#include "Player.h"
#include "Axe.h"
#include "Text.h"
#include<vector>

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	void RestartClock();
	void RenderSpawnZone(sf::RenderWindow& l_window);
	Window* GetWindow();


private:
	sf::RectangleShape spawnZone;
	Window m_window;
	sf::Clock m_clock;
	Player m_player;
	std::vector<Axe>m_axes;
	Text m_score;
	Text m_gameOver;
	Text m_winText;
	Text m_level;
	sf::Time dt;
	bool axeHit{ false };
	int numAxes{ 1 };
	
};
