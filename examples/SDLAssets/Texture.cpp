#include <SDL_image.h>
#include <GExL/logger/Log_macros.hpp>

#include "Texture.hpp"
SDL_Renderer* Texture::sRenderer = NULL;
void Texture::RegisterRenderer(SDL_Renderer* theRenderer)
{
	if (theRenderer != NULL)
	{
		sRenderer = theRenderer;
	}
	else
		FLOG(GExL::StatusAppInitFailed) << "Null Renderer pointer passed to Texture::RegisterRenderer()" << std::endl;
}



Texture::Texture() : mTexture(NULL){}

bool Texture::LoadFromFile(std::string theFilename)
{
	bool anResult = false;
	if (theFilename.length() > 0)
	{
		SDL_Texture* anTexture = NULL;
		SDL_Surface* anLoadedSurface = IMG_Load(theFilename.c_str());
		if (anLoadedSurface != NULL)
		{
			//Color key image
			SDL_SetColorKey(anLoadedSurface, SDL_TRUE, SDL_MapRGB(anLoadedSurface->format, 0xFF, 0, 0xFF));
			anTexture = SDL_CreateTextureFromSurface(Texture::sRenderer, anLoadedSurface);
			if (anTexture != NULL)
			{
				mTexture = anTexture;
				SDL_FreeSurface(anLoadedSurface);
				anResult = true;
			}
		}
	}
	return anResult;
}

void Texture::Render(GExL::Vector2f thePosition, float theRotation, GExL::Vector2f theScale, GExL::IntRect theClipRect, GExL::Vector2f theOrigin, GExL::Color theColor)
{
	SDL_Rect anSrcRect, anDstRect;
	if (mTexture != NULL)
	{
		anSrcRect.x = theClipRect.x;
		anSrcRect.y = theClipRect.y;

		anDstRect.x = (GExL::Int32)thePosition.x;
		anDstRect.y = (GExL::Int32)thePosition.y;
		if (theClipRect.w == 0 || theClipRect.h == 0)
		{
			SDL_QueryTexture(mTexture, NULL, NULL, &anDstRect.w, &anDstRect.h);
		}
		else
		{
			anDstRect.w = theClipRect.w;
			anDstRect.h = theClipRect.h;
		}
		anSrcRect.w = anDstRect.w;
		anSrcRect.h = anDstRect.h;
		anDstRect.w *= theScale.x;
		anDstRect.h *= theScale.y;
		anDstRect.x -= (anDstRect.w*(GExL::Int32)theOrigin.x);
		anDstRect.y -= (anDstRect.h*(GExL::Int32)theOrigin.y);
		SDL_SetTextureColorMod(mTexture, theColor.r, theColor.g, theColor.b);
		SDL_RenderCopy(sRenderer, mTexture, &anSrcRect, &anDstRect);
	}
}
