//301024988 Jinkyu Choi
//2020-04-07
//LevelScene
//This is for LevelScene to control all player control and collider
//Here is where player plays the game
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __LEVEL_SCENE__
#define __LEVEL_SCENE__

#include "Scene.h"
#include "Player.h"
#include "Map.h"
#include "Game.h"
#include "Enemy.h"
#include "ScoreBoardManager.h"
#include "Wall.h"
#include "Bonus.h"

class LevelScene : public Scene
{
public:
	LevelScene();
	~LevelScene();
	
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

	Wall* m_pWall1;
	Wall* m_pWall2;

	Bonus* m_pBonus;
	
	// private data member
	glm::vec2 m_mousePosition;
};

#endif /* defined (__LEVEL_SCENE__) */
