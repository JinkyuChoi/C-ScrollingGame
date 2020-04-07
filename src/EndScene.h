//301024988 Jinkyu Choi
//2020-04-07
//EndScene
//This is for EndScene to restart or go back to menu
//Here is where Player checks the final score after game over
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __END_SCENE__
#define __END_SCENE__

#include "Scene.h"
#include "Label.h"
#include "RestartButton.h"
#include "MenuButton.h"

class Map;

class EndScene : public Scene
{
public:
	EndScene();
	~EndScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// getters
	glm::vec2 getMousePosition();
	
private:
	// Game Objects
	Label* m_pGameOverLabel{};
	Label* m_pFinalScoreLabel;
	RestartButton* m_pRestartButton{};
	MenuButton* m_pMenuButton{};
	Map* m_pMap{};

	// private data member
	glm::vec2 m_mousePosition;
};

#endif /* defined (__END_SCENE__) */