#include "Level2Scene.h"
#include <iostream>
#include "ScoreBoardManager.h"

Level2Scene::Level2Scene()
{
	start();
}

Level2Scene::~Level2Scene()
{
}

void Level2Scene::draw()
{
	m_pMap->draw();
	m_pMap2->draw();

	//m_pEnemy->draw();

	m_pPlayer->draw();

	for (auto enemy : m_pEnemies)
	{
		enemy->draw();
	}

	ScoreBoardManager::Instance()->Draw();
}

void Level2Scene::update()
{
	m_pMap->update();
	m_pMap2->update();

	m_pPlayer->update();

	for (auto enemy : m_pEnemies)
	{
		enemy->update();
		CollisionManager::squaredRadiusCheck(m_pPlayer, enemy);
	}

}

void Level2Scene::clean()
{
}

void Level2Scene::handleEvents()
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

				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:

				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;


				/************************************************************************/
			case SDLK_w:
				m_pPlayer->move(UP);
				break;
			case SDLK_s:
				m_pPlayer->move(DOWN);
				break;
			case SDLK_a:
				m_pPlayer->move(LEFT);
				break;
			case SDLK_d:
				m_pPlayer->move(RIGHT);
				break;
			}

			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				m_pPlayer->setIsMoving(false);
				break;

			case SDLK_s:
				m_pPlayer->setIsMoving(false);
				break;

			case SDLK_a:
				m_pPlayer->setIsMoving(false);
				break;
			case SDLK_d:
				m_pPlayer->setIsMoving(false);
				break;
			}

			break;
		default:
			break;
		}
	}
}

void Level2Scene::start()
{
	m_pMap = new Map();
	addChild(m_pMap);
	m_pMap->setPosition(glm::vec2(0, 0));
	;
	m_pMap2 = new Map();
	addChild(m_pMap2);
	m_pMap2->setPosition(glm::vec2(1000, 0));

	m_pPlayer = new Player();
	addChild(m_pPlayer);

	m_buildEnemies();

	ScoreBoardManager::Instance()->Start();
}

glm::vec2 Level2Scene::getMousePosition()
{
	return m_mousePosition;
}

void Level2Scene::m_buildEnemies()
{
	for (auto i = 0; i < m_EnemyNum; i++)
	{
		auto enemy = new Enemy();
		switch (i)
		{
		case 0:
			enemy->yPosition = Config::SCREEN_HEIGHT * 0.15;
			break;
		case 1:
			enemy->yPosition = Config::SCREEN_HEIGHT * 0.30;
			break;
		case 2:
			enemy->yPosition = Config::SCREEN_HEIGHT * 0.45;
			break;
		case 3:
			enemy->yPosition = Config::SCREEN_HEIGHT * 0.60;
			break;
		case 4:
			enemy->yPosition = Config::SCREEN_HEIGHT * 0.75;
			break;
		case 5:
			enemy->yPosition = Config::SCREEN_HEIGHT * 0.90;
			break;
		}

		m_pEnemies.push_back(enemy);
		addChild(enemy);
	}
}

