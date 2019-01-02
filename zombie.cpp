#include "zombie.h"
#include "textureholder.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

void Zombie::spawn(float startX, float startY, int type, int seed)
{
    switch (type) {
    case 0:
        m_Sprite = sf::Sprite(TextureHolder::GetTexture("/home/sambio/Documents/ZombieArena/ZombieArena/assets/graphics/bloater.png"));
        m_Speed = 40;
        m_Health = 5;
        break;
    case 1:
        m_Sprite = sf::Sprite(TextureHolder::GetTexture("/home/sambio/Documents/ZombieArena/ZombieArena/assets/graphics/chaser.png"));
        m_Speed = 70;
        m_Health = 1;
        break;
    case 2:
        m_Sprite = sf::Sprite(TextureHolder::GetTexture("/home/sambio/Documents/ZombieArena/ZombieArena/assets/graphics/crawler.png"));
        m_Speed = 20;
        m_Health = 3;
        break;
    }
    srand((int)time(0) * seed);
    float modifier = (rand() % MAX_VARRIALNCE) + OFFSET;
    modifier /= 100;
    m_Speed *= modifier;
    m_Position.x = startX;
    m_Position.y = startY;
    m_Sprite.setOrigin(25, 25);
    m_Sprite.setPosition(m_Position);
}

bool Zombie::hit()
{
    m_Health--;
    if (m_Health < 0)
    {
        m_Active = false;
        m_Sprite.setTexture(TextureHolder::GetTexture("/home/sambio/Documents/ZombieArena/ZombieArena/assets/graphics/blood.png"));
        return true;
    }
    return false;
}

bool Zombie::isAvlive()
{
    return m_Active;
}

sf:: FloatRect Zombie::getPosition()
{
    return m_Sprite.getGlobalBounds();
}

sf::Sprite Zombie::getSprite()
{
    return m_Sprite;
}

void Zombie::update(float elapsedTime, sf::Vector2f playerLocation)
{
    float playerX = playerLocation.x;
    float playerY = playerLocation.y;

    if (playerX > m_Position.x) {
        m_Position.x = m_Position.x + m_Speed * elapsedTime;
    }

    if (playerY > m_Position.y) {
        m_Position.y = m_Position.y + m_Speed * elapsedTime;
    }

    if (playerX < m_Position.x) {
        m_Position.x = m_Position.x - m_Speed * elapsedTime;
    }

    if (playerY < m_Position.y) {
        m_Position.y = m_Position.y - m_Speed * elapsedTime;
    }

    m_Sprite.setPosition(m_Position);
    float angle = (atan2(playerY - m_Position.y, playerX - m_Position.x) * 180 / 3.14);
    m_Sprite.setRotation(angle);
}
