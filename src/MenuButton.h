//301024988 Jinkyu Choi
//2020-04-07
//MenuButton
//This is for MenuButton to go to back to Menu
//Referenced from Tom Tsiliopoulos



#pragma once
#ifndef __MENU_BUTTON__
#define __MENU_BUTTON__
#include "Button.h"

class MenuButton : public Button
{
public:
	MenuButton();
	~MenuButton();

	bool ButtonClick() override;
private:
	bool m_isClicked;
};
#endif /* defined (__MENU_BUTTON__) */