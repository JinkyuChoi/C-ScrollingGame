#include "StartScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
{
}

void StartScene::draw()
{
	m_pMap->draw();
	m_pStartLabel->draw();
	m_pStartButton->draw();
	m_pInstructionButton->draw();
	m_pExitButton->draw();
}

void StartScene::update()
{
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();

	m_pInstructionButton->setMousePosition(m_mousePosition);
	m_pInstructionButton->ButtonClick();

	m_pExitButton->setMousePosition(m_mousePosition);
	m_pExitButton->ButtonClick();
}

void StartScene::clean()
{
	delete m_pStartLabel;
	
	removeAllChildren();
}

void StartScene::handleEvents()
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
				m_pStartButton->setMouseButtonClicked(true);
				m_pInstructionButton->setMouseButtonClicked(true);
				m_pExitButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
				m_pInstructionButton->setMouseButtonClicked(false);
				m_pExitButton->setMouseButtonClicked(false);
				break;
			}
			break;

		default:
			break;
		}
	}
}

// this function is used for initialization
void StartScene::start()
{
	TheSoundManager::Instance()->load("../Assets/audio/background.ogg", "background", SOUND_MUSIC);
	TheSoundManager::Instance()->playMusic("background", 999);
	
	m_pMap = new Map();
	addChild(m_pMap);

	
	SDL_Color green = { 0, 255, 0, 255 };
	m_pStartLabel = new Label("Digital Space", "PressStart2P-Regular", 60, green, 
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, 100.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pStartButton = new StartButton();
	m_pStartButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.4f));
	addChild(m_pStartButton);

	m_pInstructionButton = new InstructionButton();
	m_pInstructionButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.6f));
	addChild(m_pInstructionButton);

	m_pExitButton = new ExitButton();
	m_pExitButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.8f));
	addChild(m_pExitButton);
	
}

glm::vec2 StartScene::getMousePosition()
{
	return m_mousePosition;
}
