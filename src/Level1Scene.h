#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Player.h"
#include "Island.h"
#include "Map.h"
#include "Cloud.h"
#include "Config.h"

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
	Island* m_pIsland;
	Map* m_pMap;
	Map* m_pMap2;

	int m_cloudNum = Config::CLOUD_NUM;
	std::vector<Cloud*> m_pClouds;
	void m_buildClouds();

	// private data member
	glm::vec2 m_mousePosition;
	
	
};

#endif /* defined (__LEVEL_1_SCENE__) */
