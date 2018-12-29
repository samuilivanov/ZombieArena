#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <cstdint>
#include <cmath>

class Player
{
private:
    const uint32_t START_SPEED = 200;
    const int32_t START_HEALTH = 100;

    sf::Vector2f m_Position;
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;
    sf::Vector2f m_Resolution;
    sf::IntRect m_Arena;
    uint32_t m_TileSize;
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_LeftPressed;
    bool m_RightPressed;

    int32_t m_Health;
    int32_t m_MaxHealth;

    sf::Time m_LastHit;

    float m_Speed;
public:
    Player();
    void spawn(sf::IntRect arena, sf::Vector2f resolution, uint32_t tileSize);
    void resetPlayerStats();
    bool hit(sf::Time timeHit);
    sf::Time getLastHitTime();
    sf::FloatRect getPosition();
    sf::Vector2f getCenter();
    float getRotation();
    sf::Sprite getSprite();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();
    void update(float elapsedTime, sf::Vector2i mousePosition);
    void upgradeSpeed();
    void upgradeHealth();
    void increaseHealthLevel(uint32_t amount);
    int32_t getHealth();
};

#endif // PLAYER_H
