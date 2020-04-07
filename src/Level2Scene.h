#pragma once
#ifndef __LEVEL_2_SCENE__
#define __LEVEL_2_SCENE__

#include "Scene.h"
#include "Player.h"
#include "Map.h"
#include "Game.h"
#include "Enemy.h"

class Level2Scene : public Scene
{
public:
	Level2Scene();
	~Level2Scene();

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


	// private data member
	glm::vec2 m_mousePosition;
};

#endif /* defined (__LEVEL_2_SCENE__) */