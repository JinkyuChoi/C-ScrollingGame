#include "Player.h"
#include "Game.h"

Player::Player() :m_maxSpeed(4.0f), m_isMoving(false)
{
	TheTextureManager::Instance()->load("../Assets/textures/player.png",
		"player", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("player");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.2f , Config::SCREEN_HEIGHT * 0.5f));
	setIsColliding(false);
	setType(GameObjectType::PLAYER);
	setVelocity(glm::vec2(0.0f, 0.0f));
	
}

Player::~Player()
{
}

void Player::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("player", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Player::update()
{
	
	auto currentPosition = getPosition();
	auto currentVelocity = getVelocity();

	setVelocity(glm::vec2(currentVelocity.x, currentVelocity.y));
	
	auto deltax = currentPosition.x + currentVelocity.x;
	auto deltay = currentPosition.y + currentVelocity.y;


	setPosition(glm::vec2(deltax, deltay));


	m_checkBounds();
}

void Player::clean()
{
}

void Player::move(Move newMove)
{
	auto currentVelocity = getVelocity();
	
	
	switch(newMove)
	{
	case RIGHT:
		setVelocity(glm::vec2(1.0f * m_maxSpeed, getVelocity().y));
		break;
	case LEFT:
		setVelocity(glm::vec2(-1.0f * m_maxSpeed, getVelocity().y));
		break;
	case UP:
		setVelocity(glm::vec2(getVelocity().x, -1.0f * m_maxSpeed));
		break;
	case DOWN:
		setVelocity(glm::vec2(getVelocity().x, 1.0f * m_maxSpeed));
		break;
	}
}

bool Player::getIsMoving()
{
	return m_isMoving;
}

void Player::setIsMoving(bool newState)
{
	m_isMoving = newState;
}

void Player::m_checkBounds()
{
	if (getPosition().x <= Config::SCREEN_WIDTH * 0.05f)
	{
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.05f, getPosition().y));
	}
	
	if (getPosition().x >= Config::SCREEN_WIDTH * 0.95f)
	{
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.95f, getPosition().y));
	}
	
	if (getPosition().y <= Config::SCREEN_HEIGHT * 0.10f)
	{
		setPosition(glm::vec2(getPosition().x, Config::SCREEN_HEIGHT * 0.10f));
	}
	
	if (getPosition().y >= Config::SCREEN_HEIGHT * 0.95f)
	{
		setPosition(glm::vec2(getPosition().x, Config::SCREEN_HEIGHT * 0.95f));
	}
}
