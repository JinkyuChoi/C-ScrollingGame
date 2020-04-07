#include "Bullet.h"
#include "Game.h"

Bullet::Bullet()
{
	TheTextureManager::Instance()->load("../Assets/textures/bullet.png",
		"bullet", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("bullet");
	setWidth(size.x);
	setHeight(size.y);

	m_reset();
	setIsColliding(false);
	setType(GameObjectType::ENEMY);

	//TheSoundManager::Instance()->load("../Assets/audio/yay.ogg", "yay", SOUND_SFX);
}

Bullet::~Bullet()
{
}

void Bullet::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("bullet", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Bullet::update()
{
	m_move();
	m_checkBounds();
}

void Bullet::clean()
{
}

void Bullet::m_reset()
{
	setPosition(glm::vec2(, ));
}

void Bullet::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Bullet::m_checkBounds()
{
	if (getPosition().y > Config::SCREEN_WIDTH + getWidth())
	{
		m_reset();
	}
}
