#include "textureholder.h"
#include <assert.h>

TextureHolder *TextureHolder::MSInstance = nullptr;

TextureHolder::TextureHolder()
{
    assert(MSInstance == nullptr);
    MSInstance = this;
}

sf::Texture &TextureHolder::GetTexture(const std::string &filename)
{
    auto &m = MSInstance->mTextures;
    auto keyValuePair = m.find(filename);
    if (keyValuePair != m.end()) {
        return keyValuePair->second;
    } else {
        auto &texture = m[filename];
        texture.loadFromFile(filename);
        return texture;
    }
}
