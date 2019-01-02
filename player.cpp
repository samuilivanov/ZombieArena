#include "player.h"

Player::Player()
{
    this->m_Speed = START_SPEED;
    this->m_Health = START_HEALTH;
    this->m_MaxHealth = START_HEALTH;

    // TODO:: chech if not loaded texture
    this->m_Texture.loadFromFile("/home/sambio/Documents/ZombieArena/ZombieArena/assets/graphics/player.png");
    this->m_Sprite.setTexture(this->m_Texture);
    this->m_Sprite.setOrigin(25, 25);
}

void Player::spawn(sf::IntRect arena, sf::Vector2f resolution,
                                            int32_t tileSize)
{
    this->m_Position.x = arena.width / 2;
    this->m_Position.y = arena.height / 2;
    //I can use reference not a copy
    this->m_Arena.left = arena.left;
    this->m_Arena.width = arena.width;
    this->m_Arena.top = arena.top;
    this->m_Arena.height = arena.height;

    this->m_TileSize = tileSize;

    this->m_Resolution.x = resolution.x;
    this->m_Resolution.y = resolution.y;
}

void Player::resetPlayerStats()
{
    this->m_Speed = START_SPEED;
    this->m_Health = START_HEALTH;
    this->m_MaxHealth = START_HEALTH;
}

sf::Time Player::getLastHitTime()
{
    return m_LastHit;
}

bool Player::hit(sf::Time timeHit)
{
    if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200) {
        this->m_LastHit = timeHit;
        this->m_Health -= 10;
        return true;
    } else {
        return false;
    }
}

sf::FloatRect Player::getPosition()
{
    return this->m_Sprite.getGlobalBounds();
}

sf::Vector2f Player::getCenter()
{
    return this->m_Position;
}

float Player::getRotation()
{
    return this->m_Sprite.getRotation();
}

sf::Sprite Player::getSprite()
{
    return this->m_Sprite;
}

int32_t Player::getHealth()
{
    return this->m_Health;
}

void Player::moveLeft()
{
    this->m_LeftPressed = true;
}

void Player::moveRight()
{
    this->m_RightPressed = true;
}

void Player::moveUp()
{
    this->m_UpPressed = true;
}

void Player::moveDown()
{
    this->m_DownPressed = true;
}

void Player::stopLeft()
{
    this->m_LeftPressed = false;
}

void Player::stopRight()
{
    this->m_RightPressed = false;
}

void Player::stopUp()
{
    this->m_UpPressed = false;
}

void Player::stopDown()
{
    this->m_DownPressed = false;
}

void Player::update(float elapsedTime, sf::Vector2i mousePosition)
{
    if (this->m_UpPressed) {
        this->m_Position.y -= this->m_Speed * elapsedTime;
    }
    if (this->m_DownPressed) {
        this->m_Position.y += this->m_Speed * elapsedTime;
    }
    if (this->m_RightPressed) {
        this->m_Position.x += this->m_Speed * elapsedTime;
    }
    if (this->m_LeftPressed) {
        this->m_Position.x -= this->m_Speed * elapsedTime;
    }

    this->m_Sprite.setPosition(m_Position);

    if (this->m_Position.x > this->m_Arena.width - this->m_TileSize) {
        this->m_Position.x = this->m_Arena.width - this->m_TileSize;
    }

    if (this->m_Position.x < this->m_Arena.left + this->m_TileSize) {
        this->m_Position.x = this->m_Arena.left + this->m_TileSize;
    }

    if (this->m_Position.y > this->m_Arena.height - this->m_TileSize) {
        this->m_Position.y = this->m_Arena.height - this->m_TileSize;
    }

    if (this->m_Position.y < this->m_Arena.top + this->m_TileSize) {
        this->m_Position.y = this->m_Arena.top + this->m_TileSize;
    }
    float angle = (atan2(mousePosition.y - this->m_Resolution.y / 2.0,
                         mousePosition.x - this->m_Resolution.x / 2.0) *
                                                        180.0) / 3.141;

    this->m_Sprite.setRotation(angle);
}

void Player::upgradeSpeed()
{
    this->m_Speed += (START_SPEED * 0.2f);
}

void Player::upgradeHealth()
{
    this->m_Health += (START_HEALTH * 0.2);
}

void Player::increaseHealthLevel(int32_t amount)
{
    this->m_Health += amount;
    if (this->m_Health > this->m_MaxHealth) {
        this->m_Health = this->m_MaxHealth;
    }
}
