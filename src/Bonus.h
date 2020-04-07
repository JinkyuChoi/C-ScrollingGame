//301024988 Jinkyu Choi
//2020-04-07
//Bonus
//This is for Bonus to move
//Referenced from Tom Tsiliopoulos


#pragma once
#include "DisplayObject.h"
class Bonus : public DisplayObject
{
public:
	Bonus();
	~Bonus();
	
	void draw() override;
	void update() override;
	void clean() override;
	
private:
	void m_reset();
	void m_move();
	void m_checkBounds();
};

