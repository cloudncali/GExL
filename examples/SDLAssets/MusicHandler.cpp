#include "MusicHandler.hpp"
#include <SDL_image.h>
#include <iostream>
MusicHandler::MusicHandler() :
GExL::TAssetHandler<Music>()
{

}
MusicHandler::~MusicHandler()
{

}
bool MusicHandler::LoadFromFile(const GExL::typeAssetID theAssetID, Music& theAsset)
{
  bool anResult = false;
  std::string anFilname = GetFilename(theAssetID);
  if (anFilname.length() > 0)
  {
    //Load music
    theAsset = Mix_LoadMUS(anFilname.c_str());
    if (theAsset == NULL)
    {
      ELOG() << "ImageHandler::LoadFromFile(" << theAssetID
        << ") Mix_Error: " << Mix_GetError() << std::endl;
    }
    else
      anResult = true;
  }
  else
  {
    ELOG() << "ImageHandler::LoadFromFile(" << theAssetID
      << ") No filename provided!" << std::endl;
  }
  return anResult;
}
bool MusicHandler::LoadFromMemory(const GExL::typeAssetID theAssetID, Music& theAsset)
{
  return false;
}

bool MusicHandler::LoadFromNetwork(const GExL::typeAssetID theAssetID, Music& theAsset)
{
  return false;
}