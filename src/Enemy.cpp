#include "Enemy.h"
#include "Game.h"
#include "ScoreBoardManager.h"

Enemy::Enemy()
{
	TheTextureManager::Instance()->load("../Assets/textures/enemy.png",
		"enemy", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("enemy");
	setWidth(size.x);
	setHeight(size.y);
	
	m_reset();
	setIsColliding(false);
	setType(GameObjectType::ENEMY);

	//TheSoundManager::Instance()->load("../Assets/audio/yay.ogg", "yay", SOUND_SFX);
}

Enemy::~Enemy()
= default;

void Enemy::draw()
{	
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("enemy", xComponent, yPosition,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Enemy::update()
{
	m_move();
	m_checkBounds();
}

void Enemy::clean()
{
}

void Enemy::m_reset()
{
	const auto randomVelocity = Util::RandomRange(-7, -4);
	setVelocity(glm::vec2(randomVelocity, 0));

	setPosition(glm::vec2(Config::SCREEN_WIDTH + getWidth(), yPosition));

	ScoreBoardManager::Instance()->setScore(ScoreBoardManager::Instance()->getScore() + 10);
}

void Enemy::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Enemy::m_checkBounds()
{
	if (getPosition().x < -getWidth())
	{
		m_reset();
	}
}
