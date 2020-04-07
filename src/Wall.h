//301024988 Jinkyu Choi
//2020-04-07
//Wall
//This is for Wall to move
//Referenced from Tom Tsiliopoulos

#pragma once
#ifndef __WALL__
#define __WALL__
#include "DisplayObject.h"

class Wall : public DisplayObject
{
public:
	Wall();
	~Wall();

	void draw() override;
	void update() override;
	void clean() override;

	bool isTopWall;
private:
	void m_reset();
	void m_move();
	void m_checkBounds();
};

#endif /* defined (__WALL__) */