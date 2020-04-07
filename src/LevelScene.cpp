#include "LevelScene.h"
#include <iostream>
#include "BulletManager.h"


LevelScene::LevelScene()
{
	start();
}

LevelScene::~LevelScene()
{
}

void LevelScene::draw()
{
	m_pMap->draw();
	m_pMap2->draw();

	BulletManager::Instance()->draw();
	
	m_pPlayer->draw();

	for (auto enemy : m_pEnemies)
	{
		enemy->draw();
	}

	m_pBonus->draw();

	m_pWall1->draw();
	m_pWall2->draw();
	
	ScoreBoardManager::Instance()->Draw();
}

void LevelScene::update()
{
	m_pMap->update();
	m_pMap2->update();
	
	BulletManager::Instance()->update();
	for(auto bullet: BulletManager::Instance()->getBullets())
	{
		for (auto enemy : m_pEnemies)
		{
			if (CollisionManager::squaredRadiusCheck(bullet, enemy))
			{
				TheSoundManager::Instance()->load("../Assets/audio/kill.ogg", "kill", SOUND_SFX);
				TheSoundManager::Instance()->playSound("kill", 0);
				enemy->setPosition(glm::vec2(Config::SCREEN_WIDTH + 30, enemy->getPosition().y));
				bullet->setPosition(glm::vec2(0, -50));
			};
		}
	}
	
	m_pPlayer->update();

	for (auto enemy : m_pEnemies)
	{
		enemy->update();
		if(CollisionManager::squaredRadiusCheck(m_pPlayer, enemy))
		{
			TheSoundManager::Instance()->load("../Assets/audio/damage.ogg", "damage", SOUND_SFX);
			TheSoundManager::Instance()->playSound("damage", 0);
			ScoreBoardManager::Instance()->setLives(ScoreBoardManager::Instance()->getLives() - 1);
			enemy->setPosition(glm::vec2(Config::SCREEN_WIDTH + 30, enemy->getPosition().y));
		};
	}
	
	m_pBonus->update();
	if(CollisionManager::squaredRadiusCheck(m_pPlayer, m_pBonus))
	{
		TheSoundManager::Instance()->load("../Assets/audio/bonus.ogg", "bonus", SOUND_SFX);
		TheSoundManager::Instance()->playSound("bonus", 0);
		ScoreBoardManager::Instance()->setScore(ScoreBoardManager::Instance()->getScore() + 100);
		const auto randomY = Util::RandomRange( 100, Config::SCREEN_HEIGHT - 100);
		m_pBonus->setPosition(glm::vec2(Config::SCREEN_WIDTH + getWidth(), randomY));
	};
	
	m_pWall1->update();
	CollisionManager::squaredRadiusCheck(m_pPlayer, m_pWall1);
	m_pWall2->update();
	CollisionManager::squaredRadiusCheck(m_pPlayer, m_pWall2);
}

void LevelScene::clean()
{
}

void LevelScene::handleEvents()
{
	auto wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
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
			switch(event.button.button)
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
			case SDLK_SPACE:
				m_pPlayer->attack();
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

void LevelScene::start()
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

	m_pWall1 = new Wall();
	m_pWall1->setPosition(glm::vec2(Config::SCREEN_WIDTH + 50, 0));
	m_pWall1->isTopWall = true;
	addChild(m_pWall1);

	m_pWall2 = new Wall();
	m_pWall2->setPosition(glm::vec2(Config::SCREEN_WIDTH + 50, Config::SCREEN_HEIGHT));
	m_pWall2->isTopWall = false;
	addChild(m_pWall2);

	m_pBonus = new Bonus();
	addChild(m_pBonus);
	
	m_buildEnemies();

	ScoreBoardManager::Instance()->Start();
}

glm::vec2 LevelScene::getMousePosition()
{
	return m_mousePosition;
}

void LevelScene::m_buildEnemies()
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

