#pragma once
#include "DisplayObject.h"
#include "Game.h"

class Bullet : public DisplayObject
{
public:
	Bullet();
	~Bullet();

	void draw() override;
	void update() override;
	void clean() override;

private:
	void m_move();
};