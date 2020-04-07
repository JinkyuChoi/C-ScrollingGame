#include "Wall.h"
#include "Game.h"

Wall::Wall()
{
	TheTextureManager::Instance()->load("../Assets/textures/wall.png",
		"wall", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("wall");
	setWidth(size.x);
	setHeight(size.y);
	
	
	m_reset();
	setIsColliding(false);
	setType(GameObjectType::ENEMY);
	setVelocity(glm::vec2(-3.0f, 0.0f));
}

Wall::~Wall()
= default;

void Wall::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("wall", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Wall::update()
{
	m_move();
	m_checkBounds();
}

void Wall::clean()
{
}

void Wall::m_reset()
{
	if(isTopWall == true)
	{
		const auto randomY = Util::RandomRange(0, getHeight() * 0.7);
		setPosition(glm::vec2(Config::SCREEN_WIDTH + getWidth(), randomY));
	}
	else
	{
		const auto randomY = Util::RandomRange(Config::SCREEN_HEIGHT - getHeight() * 0.7, Config::SCREEN_HEIGHT);
		setPosition(glm::vec2(Config::SCREEN_WIDTH + getWidth(), randomY));
	}
}

void Wall::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Wall::m_checkBounds()
{
	if (getPosition().x < -getWidth())
	{
		m_reset();
	}
}
