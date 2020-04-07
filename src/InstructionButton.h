//301024988 Jinkyu Choi
//2020-04-07
//InstructionButton
//This is for InstructionButton to go to InstructionScene
//Referenced from Tom Tsiliopoulos



#pragma once
#ifndef __INSTRUCTION_BUTTON__
#define __INSTRUCTION_BUTTON__

#include "Button.h"

class InstructionButton : public Button
{
public:
	InstructionButton();
	~InstructionButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__INSTRUCTION_BUTTON__) */