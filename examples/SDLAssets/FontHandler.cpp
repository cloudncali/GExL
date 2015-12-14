#include "FontHandler.hpp"
#include <SDL_ttf.h>
#include <iostream>
FontHandler::FontHandler(GExL::Uint32 theFontSize) :
GExL::TAssetHandler<Font>(),
mFontSize(theFontSize)
{

}
FontHandler::~FontHandler()
{

}
bool FontHandler::LoadFromFile(const GExL::typeAssetID theAssetID, Font& theAsset)
{
  bool anResult = false;
  std::string anFilname = GetFilename(theAssetID);
  if (anFilname.length() > 0)
  {
    theAsset = TTF_OpenFont(anFilname.c_str(), mFontSize);
    if (theAsset != NULL)
    {
      anResult = true;
    }
  }
  else
  {
    ELOG() << "ImageHandler::LoadFromFile(" << theAssetID
      << ") No filename provided!" << std::endl;
  }
  return anResult;
}
bool FontHandler::LoadFromMemory(const GExL::typeAssetID theAssetID, Font& theAsset)
{
  return false;
}

bool FontHandler::LoadFromNetwork(const GExL::typeAssetID theAssetID, Font& theAsset)
{
  return false;
}