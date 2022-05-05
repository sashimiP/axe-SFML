
#include "Game.h"
#include<iostream>
Game::Game() : m_window("Axe", sf::Vector2u(800, 450)),
m_player(0, 450 / 2),
	m_score(40, 180, 0, "Score:"),
m_gameOver(50, 800/2-100, 175, "Game Over!"),
m_winText(50, 800 / 2 - 100, 175, "You Win!"),
m_level(40,0,0,"Level:")
{
	spawnZone.setSize(sf::Vector2f(50, 50));
	spawnZone.setFillColor(sf::Color::Black);
	spawnZone.setPosition(800-50, static_cast<float>(450)/2);

	m_axes.push_back(Axe(400, 0, 30, sf::Color::Red));
	m_axes.push_back(Axe(400, 450, 30, sf::Color::Red));
	m_axes.push_back(Axe(200, 0, 30, sf::Color::Green));
	m_axes.push_back(Axe(200, 450, 30, sf::Color::Green));
	m_axes.push_back(Axe(600, 0, 30, sf::Color::Blue));
	m_axes.push_back(Axe(600, 450, 30, sf::Color::Blue));


	m_score.SetMessage(m_player);
	m_gameOver.SetEmptyMessage();
	m_winText.SetEmptyMessage();
	m_level.SetLevel(1);
}
Game::~Game() {}

Window* Game::GetWindow() { return &m_window; }

void Game::RestartClock() {
	dt = m_clock.restart();
}

void Game::HandleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_player.MoveLeft();
		
		if (m_player.GetVectorPosition().x < 1)
		{
			m_player.StopLeft();
		}
	}
	else
	{
		m_player.StopLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_player.MoveRight();
		
		
	}
	else
	{
		m_player.StopRight();
	}

}

void Game::Update()
{
	m_window.Update();
	for (int i = 0; i < m_axes.size(); i++)
	{
		if (m_axes[i].getPosition().top > m_window.GetWindowSize().y)
		{
			m_axes[i].reboundBottom();
		}
		if (m_axes[i].getPosition().top < 0)
		{
			m_axes[i].reboundTop();
		}
		if (m_player.getPosition().intersects(m_axes[i].getPosition()) && m_axes[i].isAxeOnScreen())
		{
			axeHit = true;
		}
		m_axes[i].Update(dt);
		
	}
	if (m_player.getPosition().intersects(spawnZone.getGlobalBounds()))
	{
		if (numAxes < m_axes.size())
		{
			numAxes++;
			m_level.SetLevel(numAxes);
		}
		m_player.addScore();
		m_score.SetMessage(m_player);
		m_player.SetPosition(sf::Vector2f(0, 450/2));
	}
	m_player.Update(dt);
	

	
}

void Game::Render()
{
	m_window.BeginDraw();
	RenderSpawnZone(*m_window.GetRenderWindow());
	if (m_player.getScore() > 5)
	{
		m_winText.Display(*m_window.GetRenderWindow());
	}
	else
	{
		if (axeHit)
		{
			m_gameOver.Display(*m_window.GetRenderWindow());
			m_score.Display(*m_window.GetRenderWindow());
			m_level.Display(*m_window.GetRenderWindow());
		}
		else
		{
			m_player.Render(*m_window.GetRenderWindow());
			for (int i = 0; i < numAxes; i++)
			{
				m_axes[i].Render(*m_window.GetRenderWindow());
			}
			m_score.Display(*m_window.GetRenderWindow());
			m_level.Display(*m_window.GetRenderWindow());
		}
	}
	
	m_window.EndDraw();
}

void Game::RenderSpawnZone(sf::RenderWindow& l_window)
{
	l_window.draw(spawnZone);
}

