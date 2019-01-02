#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureHolder
{
private:
    std::map<std::string, sf::Texture> mTextures;
    static TextureHolder *MSInstance;

public:
    TextureHolder();
    static sf::Texture &GetTexture(std::string const &filename);
};

#endif // TEXTUREHOLDER_H
