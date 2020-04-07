#include "EndScene.h"
#include "Game.h"
#include <ctime>
#include "glm/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

EndScene::EndScene()
{
	EndScene::start();
}

EndScene::~EndScene()
= default;

void EndScene::draw()
{
	m_pMap->draw();
	m_pGameOverLabel->draw();
	m_pFinalScoreLabel->draw();
	m_pRestartButton->draw();
	m_pMenuButton->draw();
}

void EndScene::update()
{
	m_pRestartButton->setMousePosition(m_mousePosition);
	m_pRestartButton->ButtonClick();

	m_pMenuButton->setMousePosition(m_mousePosition);
	m_pMenuButton->ButtonClick();
}

void EndScene::clean()
{
	removeAllChildren();
}

void EndScene::handleEvents()
{
	auto wheel = 0;
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
				m_pRestartButton->setMouseButtonClicked(true);
				m_pMenuButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRestartButton->setMouseButtonClicked(false);
				m_pMenuButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;

		default:
			break;
		}
	}
}

void EndScene::start()
{
	m_pMap = new Map();
	addChild(m_pMap);
	
	const SDL_Color green = { 0, 255, 0, 255 };
	m_pGameOverLabel = new Label("Game Over", "PressStart2P-Regular", 60, green, glm::vec2(Config::SCREEN_WIDTH * 0.5f, 100.0f));
	m_pGameOverLabel->setParent(this);
	addChild(m_pGameOverLabel);

	m_pFinalScoreLabel = new Label("Score : " + std::to_string(ScoreBoardManager::Instance()->getScore()), "PressStart2P-Regular", 30, green, glm::vec2(Config::SCREEN_WIDTH * 0.5f, 200.0f));
	m_pFinalScoreLabel->setParent(this);
	addChild(m_pFinalScoreLabel);

	m_pRestartButton = new RestartButton();
	m_pRestartButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	addChild(m_pRestartButton);

	m_pMenuButton = new MenuButton();
	m_pMenuButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.7f));
	addChild(m_pMenuButton);
}
