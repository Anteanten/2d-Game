#include "TextureManager.h"

TextureManager* TextureManager::instance;

TextureManager::TextureManager() {

}

TextureManager::~TextureManager()
{
	for (int i = 0; i < textures.size();) {
		textures.erase(textures.begin());
	}
}

sf::Texture* TextureManager::getTexture(std::string filename)
{
	auto tex = textures.find(filename);
	if (tex == textures.end()) {
		sf::Texture temp;
		temp.loadFromFile(filename);
		textures.insert(std::pair<std::string, sf::Texture>(filename, temp));

		return &textures.rbegin()->second;
	}
	else {
		return &tex->second;
	}
}
