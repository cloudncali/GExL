#include "TextureHandler.hpp"
#include <SDL_image.h>
#include <iostream>
TextureHandler::TextureHandler(SDL_Renderer* theRenderer) :
GExL::TAssetHandler<Texture>()
{
	Texture::RegisterRenderer(theRenderer);
}
TextureHandler::~TextureHandler()
{

}
bool TextureHandler::LoadFromFile(const GExL::typeAssetID theAssetID, Texture& theAsset)
{
  bool anResult = false;
  std::string anFilname = GetFilename(theAssetID);
  if (anFilname.length() > 0)
  {
	  theAsset = Texture();
	  anResult = theAsset.LoadFromFile(anFilname);
  }
  else
  {
    ELOG() << "TextureHandler::LoadFromFile(" << theAssetID
      << ") No filename provided!" << std::endl;
  }
  return anResult;
}
bool TextureHandler::LoadFromMemory(const GExL::typeAssetID theAssetID, Texture& theAsset)
{
  return false;
}

bool TextureHandler::LoadFromNetwork(const GExL::typeAssetID theAssetID, Texture& theAsset)
{
  return false;
}