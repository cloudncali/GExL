#ifndef TEXTURE_HPP_INCLUDED
#define TEXTURE_HPP_INCLUDED
#include <SDL.h>
#include <string>
#include <GExL/utils/Math_types.hpp>
class Texture
{
public:
	Texture();
	bool LoadFromFile(std::string theFilename);
	void Render(GExL::Vector2f thePosition = GExL::Vector2f(), float theRotation = 0.0f, GExL::Vector2f theScale = GExL::Vector2f(1.0f, 1.0f), GExL::IntRect theClipRect = GExL::IntRect(), GExL::Vector2f theOrigin = GExL::Vector2f(), GExL::Color theColor = GExL::Color());
	static void RegisterRenderer(SDL_Renderer* theRenderer);
private:
	SDL_Texture* mTexture;
	static SDL_Renderer* sRenderer;
};

#endif