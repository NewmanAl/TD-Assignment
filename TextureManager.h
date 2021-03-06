#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class TextureManager{
public:
	enum TEXTURE{ENV,SPRITE,UI};


	TextureManager();
	~TextureManager();

	sf::Texture& getTexture(TEXTURE tex) const;

private:
	sf::Texture* textures;

	const static string ENV_TEX_LOC;
	const static string SPRITE_TEX_LOC;
	const static string UI_TEX_LOC;


};
#endif