#include "InstructionButton.h"
#include "Game.h"

InstructionButton::InstructionButton()
	:Button(
		"../Assets/textures/InstructionButton.png",
		"insturctionButton",
		INSTURCTION_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{
}

InstructionButton::~InstructionButton()
{
}

bool InstructionButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			Game::Instance()->changeSceneState(INSTURCTION_SCENE);
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
