//301024988 Jinkyu Choi
//2020-04-07
//InstructionScene
//This is for InstructionScene to show labels and button to go back to menu
//Here is where Player checks the key settings and goal for the game
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __INSTRUCTION_SCENE__
#define __INSTRUCTION_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Map.h"
#include "MenuButton.h"

class InstructionScene : public Scene
{
public:
	// constructor
	InstructionScene();
	// destructor
	~InstructionScene();

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
	Label* m_pKeyLabel1;
	Label* m_pKeyLabel2;
	Label* m_pKeyLabel3;
	Label* m_pGoalLabel1;
	Label* m_pGoalLabel2;
	Label* m_pGoalLabel3;

	MenuButton* m_pMenuButton;
	
	Map* m_pMap;

	// private data member
	glm::vec2 m_mousePosition;

};

#endif /* defined (__INSTRUCTION_SCENE__) */
