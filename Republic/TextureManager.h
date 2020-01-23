#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "SFML/Graphics.hpp"
#include <string.h>

class TextureManager {
private:
	static TextureManager* instance;
	std::map<std::string, sf::Texture> textures;

	TextureManager();

public:
	~TextureManager();

	static TextureManager* getInstance() {
		if (!instance)
			instance = new TextureManager;
		return instance;
	}

	sf::Texture* getTexture(std::string filename);

};

#endif
