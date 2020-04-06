#include "Map.h"
#include "Game.h"

Map::Map()
{
	TheTextureManager::Instance()->load("../Assets/textures/map.png",
		"map", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("map");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setType(MAP);
	setVelocity(glm::vec2(-5.0f, 0.0f));

}

Map::~Map()
{
}

void Map::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("map", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, false);
}

void Map::update()
{
	m_move();
	m_checkBounds();
}

void Map::clean()
{
}

void Map::m_move()
{
	setPosition(getPosition() + getVelocity());
}

void Map::m_checkBounds()
{
	if(getPosition().x <= -1005.0f)
	{
		m_reset();
	}
}

void Map::m_reset()
{
	setPosition(glm::vec2(995.0f, 0.0f));
}
