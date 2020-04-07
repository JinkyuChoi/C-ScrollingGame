//301024988 Jinkyu Choi
//2020-04-07
//Bullet
//This is for Bullet to move
//Referenced from Tom Tsiliopoulos

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