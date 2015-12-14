#ifndef TEXTURE_HANDLER_HPP_INCLUDED
#define TEXTURE_HANDLER_HPP_INCLUDED
#include <GExL/assets/TAssetHandler.hpp>
#include "Texture.hpp"
class TextureHandler : public GExL::TAssetHandler < Texture >
{
public:
	TextureHandler(SDL_Renderer* theRenderer);
	/// Provides the ImageHandler class for managing sf::Image assets

	/**
	* ImageHandler deconstructor
	*/
	virtual ~TextureHandler();

protected:
	/**
	* LoadFromFile is responsible for loading theAsset from a file and must
	* be defined by the derived class since the interface for TYPE is
	* unknown at this stage.
	* @param[in] theAssetID of the asset to be loaded
	* @param[in] theAsset pointer to load
	* @return true if the asset was successfully loaded, false otherwise
	*/
	virtual bool LoadFromFile(const GExL::typeAssetID theAssetID, Texture& theAsset);
	/**
	* LoadFromMemory is responsible for loading theAsset from memory and
	* must be defined by the derived class since the interface for TYPE is
	* unknown at this stage.
	* @param[in] theAssetID of the asset to be loaded
	* @param[in] theAsset pointer to load
	* @return true if the asset was successfully loaded, false otherwise
	*/
	virtual bool LoadFromMemory(const GExL::typeAssetID theAssetID, Texture& theAsset);
	/**
	* LoadFromNetwork is responsible for loading theAsset from network and
	* must be defined by the derived class since the interface for TYPE is
	* unknown at this stage.
	* @param[in] theAssetID of the asset to be loaded
	* @param[in] theAsset pointer to load
	* @return true if the asset was successfully loaded, false otherwise
	*/
	virtual bool LoadFromNetwork(const GExL::typeAssetID theAssetID, Texture& theAsset);
private:
}; // class TextureHandler

#endif