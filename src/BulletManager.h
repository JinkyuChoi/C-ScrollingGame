//301024988 Jinkyu Choi
//2020-04-07
//Bullet Manager
//All the bullets are managed here
//Referenced from Tom Tsiliopoulos, and Hyungseok Lee

#pragma once
#ifndef __BULLET_MANAGER__
#define __BULLET_MANAGER__
#include <list>
#include "Bullet.h"


class BulletManager
{
public:
	static BulletManager* Instance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new BulletManager();
			return m_pInstance;
		}
		return m_pInstance;
	}
	void clean();

	Bullet* getBullet();
	std::list<Bullet*> getBullets();

	void update();
	void draw();
	void m_buildBullets();
private:
	BulletManager();
	~BulletManager();

	static BulletManager* m_pInstance;

	std::list<Bullet*> m_pBullets;
};
#endif /* defined( __BULLET_MANAGER__ ) */