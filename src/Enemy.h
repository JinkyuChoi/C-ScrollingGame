#pragma once
#ifndef __ENEMY__
#define __ENEMY__
#include "DisplayObject.h"

class Enemy : public DisplayObject
{
public:
	Enemy();
	~Enemy();

	void draw() override;
	void update() override;
	void clean() override;

	double yPosition;
private:
	void m_reset();
	void m_move();
	void m_checkBounds();
};

#endif /* defined (__ENEMY__) */