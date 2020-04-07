#include "Bullet.h"

Bullet::Bullet()
{
	TheTextureManager::Instance()->load("../Assets/textures/bullet.png",
		"bullet", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("bullet");
	setWidth(size.x);
	setHeight(size.y);

	setIsColliding(false);
	setType(GameObjectType::BULLET);
	setPosition(glm::vec2(0.0f, -50.0f));
	setVelocity(glm::vec2(15.0f, 0.0f));

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
}

void Bullet::clean()
{
}


void Bullet::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}
