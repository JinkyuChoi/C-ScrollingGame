#pragma once
#include "DisplayObject.h"

class Bullet : public DisplayObject
{
public:
	Bullet();
	~Bullet();
	
	void draw() override;
	void update() override;
	void clean() override;

private:
	void m_reset();
	void m_move();
	void m_checkBounds();
};

