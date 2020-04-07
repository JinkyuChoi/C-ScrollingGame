//301024988 Jinkyu Choi
//2020-04-07
//Map
//This is for Map to scroll
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __MAP__
#define __MAP__

#include "DisplayObject.h"

class Map : public DisplayObject
{
public:
	Map();
	~Map();
	
	void draw() override;
	void update() override;
	void clean() override;
private:
	void m_move();
	void m_checkBounds();
	void m_reset();
};

#endif /* defined (__OCEAN__) */