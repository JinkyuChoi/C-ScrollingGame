//301024988 Jinkyu Choi
//2020-04-07
//StartScene
//This is for StartScene to control Buttons for start, instruction, and exit
//Here is where Player decide to start the game, read instruction, or exit
//Referenced from Tom Tsiliopoulos



#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "StartButton.h"
#include "Map.h"
#include "ExitButton.h"
#include "InstructionButton.h"

class StartScene : public Scene
{
public:
	// constructor
	StartScene();
	// destructor
	~StartScene();

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
	Label* m_pStartLabel;
	
	StartButton* m_pStartButton;
	ExitButton* m_pExitButton;
	InstructionButton* m_pInstructionButton;

	
	Map* m_pMap;

	// private data member
	glm::vec2 m_mousePosition;
	
};

#endif /* defined (__START_SCENE__) */