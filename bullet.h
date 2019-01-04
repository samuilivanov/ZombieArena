#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::Vector2f m_Position;
    sf::RectangleShape m_BulletShape;
    bool m_InFlight = false;
    float m_BulletSpeed = 1000;

    float m_BulletDistanceX;
    float m_BulletDistanceY;

    float m_MaxY;
    float m_MinY;
    float m_MaxX;
    float m_MinX;

public:
    Bullet();
    void stop();
    bool isInFlight();
    void shoot(float startX, float startY, float xTarget, float yTarget);
    sf::FloatRect getPosition();
    sf::RectangleShape getShape();
    void update(float elapsedTime);
};

#endif // BULLET_H
