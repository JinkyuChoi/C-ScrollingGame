#include "BulletManager.h"

BulletManager* BulletManager::m_pInstance = nullptr;

BulletManager::BulletManager()
{
	m_buildBullets();
}

BulletManager::~BulletManager()
{
}

void BulletManager::clean()
{
}

Bullet* BulletManager::getBullet()
{
	Bullet* bullet = m_pBullets.front();
	m_pBullets.pop_front();
	m_pBullets.push_back(bullet);
	return bullet;
}

std::list<Bullet*> BulletManager::getBullets()
{
	return m_pBullets;
}


void BulletManager::update()
{
	for (auto bullet : m_pBullets)
	{
		bullet->update();
	}
}

void BulletManager::draw()
{
	for (auto bullet : m_pBullets)
	{
		bullet->draw();
	}
}

void BulletManager::m_buildBullets()
{
	for (auto i = 0; i < Config::BULLET_NUM; i++)
	{
		auto bullet = new Bullet();

		m_pBullets.push_back(bullet);
	}
}

