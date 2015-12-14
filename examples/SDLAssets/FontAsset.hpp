#ifndef   FONT_ASSET_HPP_INCLUDED
#define   FONT_ASSET_HPP_INCLUDED

#include <SDL_ttf.h>
#include <GExL/assets/TAsset.hpp>
#include <GExL/assets/AssetManager.hpp>
#include <GExL/GExL_types.hpp>
typedef TTF_Font* Font;
class FontAsset : public GExL::TAsset<Font>
{
public:


  FontAsset(GExL::AssetManager& theAssetManager);


  FontAsset(GExL::AssetManager& theAssetManager,
    const GExL::typeAssetID theAssetID,
    GExL::AssetLoadTime theLoadTime = GExL::AssetLoadLater,
    GExL::AssetLoadStyle theLoadStyle = GExL::AssetLoadFromFile,
    GExL::AssetDropTime theDropTime = GExL::AssetDropAtZero);

  virtual ~FontAsset();

protected:

private:
  // Variables
  ///////////////////////////////////////////////////////////////////////////
}; // class ImageAsset

#endif // CORE_IMAGE_ASSET_HPP_INCLUDED

/**
* @class GQE::ImageAsset
* @ingroup Core
* The ImageAsset class is a wrapper around the SFML Image class and is
* used by the AssetManager to keep track of and provide SFML Images to
* game states and other entities.
*
* Copyright (c) 2010-2011 Ryan Lindeman
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
