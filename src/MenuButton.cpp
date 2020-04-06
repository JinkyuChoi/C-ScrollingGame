#include "MenuButton.h"
#include "Game.h"

MenuButton::MenuButton()
	:Button(
		"../Assets/textures/restartButton.png",
		"menuButton",
		MENU_BUTTON, glm::vec2(320.0f, 400.0f)), m_isClicked(false)
{
}

MenuButton::~MenuButton()
{
}

bool MenuButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			Game::Instance()->changeSceneState(START_SCENE);
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
