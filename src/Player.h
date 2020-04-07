//301024988 Jinkyu Choi
//2020-04-07
//Player
//This is for Main Player to move and attack
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __PLAYER__
#define __PLAYER__
#include "DisplayObject.h"
#include "Move.h"

class Player : public DisplayObject
{
public:
	Player();
	~Player();
	
	void draw() override;
	void update() override;
	void clean() override;

	void move(Move newMove);
	void attack();

	//getters and setters
	bool getIsMoving();
	void setIsMoving(bool newState);
	
private:
	float m_maxSpeed;

	bool m_isMoving;

	
	void m_checkBounds();
};

#endif /* defined (__PLAYER__) */