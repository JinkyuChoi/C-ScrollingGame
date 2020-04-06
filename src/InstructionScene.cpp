#include "InstructionScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

InstructionScene::InstructionScene()
{
	InstructionScene::start();
}

InstructionScene::~InstructionScene()
{
}

void InstructionScene::draw()
{
	m_pMap->draw();
	m_pKeyLabel->draw();
	m_pGoalLabel->draw();
	m_pMenuButton->draw();
}

void InstructionScene::update()
{
	m_pMenuButton->setMousePosition(m_mousePosition);
	m_pMenuButton->ButtonClick();
}

void InstructionScene::clean()
{
	removeAllChildren();
}

void InstructionScene::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pMenuButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pMenuButton->setMouseButtonClicked(false);
				break;
			}
			break;

		default:
			break;
		}
	}
}

void InstructionScene::start()
{
	m_pMap = new Map();
	addChild(m_pMap);


	SDL_Color white = { 255, 255, 255, 255 };
	m_pKeyLabel = new Label("Movement - W A S D", "Dock51", 20, white,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.3f));
	m_pKeyLabel->setParent(this);
	addChild(m_pKeyLabel);

	m_pGoalLabel = new Label("Dodge Enemies and Obstacles and reach the goal", "Dock51", 20, white,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.4f));
	m_pGoalLabel->setParent(this);
	addChild(m_pGoalLabel);

	m_pMenuButton = new MenuButton();
	m_pMenuButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.8f));
	addChild(m_pMenuButton);

}

glm::vec2 InstructionScene::getMousePosition()
{
	return m_mousePosition;
}
