#include "Bonus.h"
#include "Game.h"

Bonus::Bonus()
{
	TheTextureManager::Instance()->load("../Assets/textures/bonus.png",
		"bonus", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("bonus");
	setWidth(size.x);
	setHeight(size.y);

	m_reset();
	setIsColliding(false);
	setType(GameObjectType::BONUS);
	setVelocity(glm::vec2(-3.0f, 0.0f));

	//TheSoundManager::Instance()->load("../Assets/audio/yay.ogg", "yay", SOUND_SFX);
}

Bonus::~Bonus()
{
}

void Bonus::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("bonus", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Bonus::update()
{
	m_move();
	m_checkBounds();
}

void Bonus::clean()
{
}

void Bonus::m_reset()
{
	const auto randomY = Util::RandomRange(100, Config::SCREEN_HEIGHT - 100);
	setPosition(glm::vec2(Config::SCREEN_WIDTH + getWidth(), randomY));
}

void Bonus::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Bonus::m_checkBounds()
{
	if (getPosition().x < -getWidth())
	{
		m_reset();
	}
}
