#ifndef ZOMBIEARENA_H
#define ZOMBIEARENA_H
#include <SFML/Graphics.hpp>
#include "zombie.h"
int createBackground(sf::VertexArray &rVA, sf::IntRect arena);
Zombie *zombieHorde(int numOfZombies, sf::IntRect arena);
#endif // ZOMBIEARENA_H
