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
	m_pKeyLabel1->draw();
	m_pKeyLabel2->draw();
	m_pKeyLabel3->draw();
	m_pGoalLabel1->draw();
	m_pGoalLabel2->draw();
	m_pGoalLabel3->draw();
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
	m_pKeyLabel1 = new Label("KEY SETTINGS", "PressStart2P-Regular", 20, white,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.25f));
	m_pKeyLabel1->setParent(this);
	addChild(m_pKeyLabel1);

	m_pKeyLabel2 = new Label("MOVEMENT - W A S D", "PressStart2P-Regular", 20, white,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.3f));
	m_pKeyLabel2->setParent(this);
	addChild(m_pKeyLabel2);

	m_pKeyLabel3 = new Label("ATTACK - SPACE BAR", "PressStart2P-Regular", 20, white,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.35f));
	m_pKeyLabel3->setParent(this);
	addChild(m_pKeyLabel3);

	m_pGoalLabel1 = new Label("POINT TABLE", "PressStart2P-Regular", 20, white,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.45f));
	m_pGoalLabel1->setParent(this);
	addChild(m_pGoalLabel1);

	m_pGoalLabel2 = new Label("DODGE ENEMY - 10 point", "PressStart2P-Regular", 20, white,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	m_pGoalLabel2->setParent(this);
	addChild(m_pGoalLabel2);

	m_pGoalLabel3 = new Label("COLLECT BONUS - 100 point", "PressStart2P-Regular", 20, white,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.55f));
	m_pGoalLabel3->setParent(this);
	addChild(m_pGoalLabel3);

	m_pMenuButton = new MenuButton();
	m_pMenuButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.8f));
	addChild(m_pMenuButton);

}

glm::vec2 InstructionScene::getMousePosition()
{
	return m_mousePosition;
}
