#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Player.h"
#include "Island.h"
#include "Map.h"
#include "Cloud.h"
#include "Config.h"
#include "Enemy.h"
#include "Bullet.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects
	Player* m_pPlayer;
	
	Map* m_pMap;
	Map* m_pMap2;

	int m_EnemyNum = Config::ENEMY_NUM;
	std::vector<Enemy*> m_pEnemies;
	void m_buildEnemies();

	std::vector<Bullet*> m_pBullets;
	void m_buildBullets();


	// private data member
	glm::vec2 m_mousePosition;

	int m_xPosition;
	
	
};

#endif /* defined (__LEVEL_1_SCENE__) */
