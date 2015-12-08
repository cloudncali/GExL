/**
 * Provides the TAsset template class for managing a single Asset and is used
 * by the IAssetHandler in the GExL namespace which is responsible for providing
 * the Asset management facilities for each asset type.
 *
 * @file include/GExL/Core/templates/TAsset.hpp
 * @author Ryan Lindeman
 * @date 20140912 - Initial Release
*/
#ifndef   CORE_TASSET_HPP_INCLUDED
#define   CORE_TASSET_HPP_INCLUDED

#include <string>
#include <GExL/GExL_types.hpp>
#include <GExL/assets/AssetManager.hpp>
#include <GExL/assets/TAssetHandler.hpp>

namespace GExL
{
  /// Provides base template class for all game assets
  template<class TYPE>
  class TAsset
  {
    public:
      /**
       * TAsset constructor that should be used most frequently since it
       * allows theAssetManager to provide the asset at construction time.
       * @param[in] theAssetManager reference to the assetmanager this asset should use
       * @param[in] theAssetID to use for this asset
       * @param[in] theLoadTime (Now, Later) of when to load this asset
       * @param[in] theLoadStyle (File, Mem, Network) to use when loading this asset
       * @param[in] theDropTime at (Zero, Exit) for when to unload this asset
       */
      TAsset(AssetManager& theAssetManager, const typeAssetID theAssetID,
        AssetLoadTime theLoadTime = AssetLoadLater,
        AssetLoadStyle theLoadStyle = AssetLoadFromFile,
        AssetDropTime theDropTime = AssetDropAtZero):
        mAssetHandler(theAssetManager.GetHandler<TYPE>()),
        mAsset(mAssetHandler.GetReference(theAssetID, theLoadTime, theLoadStyle, theDropTime)),
        mAssetID(theAssetID)
      {
      }

      /**
       * TAsset default constructor that can be used if there is no way that
       * theAssetID can be provided at construction time. You will need to call
       * the SetID method before calling the GetAsset method if you use this
       * constructor.
       * @param[in] theAssetManager reference to the assetmanager this asset should use
       */
      TAsset(AssetManager& theAssetManager):
        mAssetHandler(theAssetManager.GetHandler<TYPE>()),
        mAsset(mAssetHandler.GetReference())
      {
      }

      /**
       * TAsset copy constructor will allow for copying of assets by
       * incrementing the reference counter for this asset through the
       * Asset Handler provided at construction time.
       * @param[in] theCopy reference construct a copy of
       */
      TAsset(const TAsset<TYPE>& theCopy) :
        mAssetHandler(theCopy.mAssetHandler),
        mAssetID(theCopy.mAssetID)
      {
        // Increment reference count to this asset
        mAsset = mAssetHandler.GetReference(mAssetID);
      }
      

      /**
       * TAsset deconstructor
       */
      virtual ~TAsset()
      {
        // Drop reference to this asset
        mAssetHandler.DropReference(mAssetID);
      }

      /**
       * IsLoaded will return true if the Asset has been loaded.
       * @return true if loaded, false otherwise
       */
      bool IsLoaded(void) const
      {
        return mAssetHandler.IsLoaded(mAssetID);
      }

      /**
       * GetID will return the ID being used for this asset.
       * @return the Asset ID assigned to this asset
       */
      const typeAssetID GetID(void) const
      {
        return mAssetID;
      }

      /**
       * SetID will set the ID for this asset and get a reference to the
       * asset.
       * @param[in] theAssetID to use for this asset
       * @param[in] theLoadTime (Now, Later) of when to load this asset
       * @param[in] theLoadStyle (File, Mem, Network) to use when loading this asset
       * @param[in] theDropTime at (Zero, Exit) for when to unload this asset
       */
      void SetID(const typeAssetID theAssetID,
        AssetLoadTime theLoadTime = AssetLoadLater,
        AssetLoadStyle theLoadStyle = AssetLoadFromFile,
        AssetDropTime theDropTime = AssetDropAtZero)
      {
        // Make note of the new Asset ID
        mAssetID = theAssetID;

        // Try to obtain a reference to the new Asset from Handler
        mAsset = mAssetHandler.GetReference(mAssetID, theLoadTime, theLoadStyle, theDropTime);
      }

      /**
       * GetAsset will return the Asset if it is available.
       * @return pointer to the Asset or NULL if not available yet.
       */
      TYPE& GetAsset(void)
      {
        // Is asset not yet loaded, then try to load it immediately
        if(false == mAssetHandler.IsLoaded(mAssetID))
        {
          // Load the asset immediately
          bool anLoaded = mAssetHandler.LoadAsset(mAssetID);

          // If the asset was loaded, get a reference to it now
          if(anLoaded)
          {
            // Get reference to the asset immediately
            mAsset = mAssetHandler.GetReference(mAssetID);
          }
        }

        // Return reference to dummy asset or loaded asset
        return *mAsset;
      }

      /**
       * GetFilename is responsible for retrieving the filename to use when
       * loading this asset.
       * @return the filename to use when loading this asset
       */
      const std::string GetFilename(void)
      {
        return mAssetHandler.GetFilename(mAssetID);
      }

      /**
       * SetFilename is responsible for setting the filename to use when
       * loading this asset.
       * @param[in] theFilename to use for loading asset
       */
      void SetFilename(std::string theFilename)
      {
        // Set the filename to use for this asset
        mAssetHandler.SetFilename(mAssetID, theFilename);
      }

      /**
       * GetLoadStyle will attempt to retrieve the loading style to use when
       * loading this asset. If the asset ID isn't found then
       * AssetLoadFromUnknown will be returned.
       * @return the loading style to use or AssetLoadFromUnknown otherwise
       */
      AssetLoadStyle GetLoadStyle(void) const
      {
        return mAssetHandler.GetLoadStyle(mAssetID);
      }

      /**
       * SetLoadStyle will set the loading style for this asset to theLoadStyle
       * specified.
       * @param[in] theLoadStyle (File, Mem, Network) to use when loading this asset
       */
      void SetLoadTime(AssetLoadStyle theLoadStyle)
      {
        mAssetHandler.SetLoadStyle(mAssetID, theLoadStyle);
      }

      /**
       * GetLoadTime will attempt to retrieve the loading time of when this
       * asset will be loaded.  If the asset ID isn't found then AssetLoadLater
       * will be returned.
       * @return the loading time or AssetLoadLater otherwise
       */
      AssetLoadTime GetLoadTime(void) const
      {
        return mAssetHandler.GetLoadTime(mAssetID);
      }

      /**
       * SetLoadTime will set the load time for this asset to theLoadTime
       * specified.
       * @param[in] theLoadTime (Now, Later) of when to load this asset
       */
      void SetLoadTime(AssetLoadTime theLoadTime)
      {
        mAssetHandler.SetLoadTime(mAssetID, theLoadTime);
      }

      /**
       * GetDropTime will attempt to retrieve the drop time of when this asset
       * will be unloaded.  If the asset ID isn't found then
       * AssetDropUnspecified will be returned.
       * @return the loading time or AssetDropUnspecified otherwise
       */
      AssetDropTime GetDropTime(void) const
      {
        return mAssetHandler.GetDropTime(mAssetID);
      }

      /**
       * SetDropTime will set the drop time for this asset to theDropTime
       * specified.
       * @param[in] theDropTime at (Zero, Exit) for when to unload this asset
       */
      void SetDropTime(AssetDropTime theDropTime)
      {
        mAssetHandler.SetDropTime(mAssetID, theDropTime);
      }

      /**
       * TAsset assignment operator will allow for copying of assets by
       * incrementing the reference count for this asset.
       * @param[in] theRight hand side of the = operation
       * @return the left hand side of the = operator
       */
      TAsset<TYPE>& operator=(TAsset<TYPE> theRight)
      {
        // Now swap my local copy with theRight copy made during the call to this method
        swap(*this, theRight);

        // Increment the reference count to this Asset
        mAssetHandler.GetReference(mAssetID);

        // Return my pointer
        return *this;
      }

      /**
       * swap was created according to the copy-and-swap idiom necessary for
       * correctly handling the assignment operator and copy constructor for a
       * resource holding class like TAsset. This allows us to perform
       * reference counting correctly for our TAsset resources.
       * @param[inout] first item to swap
       * @param[inout] second item to swap
       */
      friend void swap(TAsset& first, TAsset& second)
      {
        // enable ADL
        using std::swap;

        // Swap our asset pointer and ID
        swap(first.mAsset, second.mAsset);
        swap(first.mAssetID, second.mAssetID);
        // The mAssetHandler is already handled at construction time
      }
    protected:
      // Variables
      ///////////////////////////////////////////////////////////////////////////
      /// Asset Handler class that will manage this asset
      TAssetHandler<TYPE>& mAssetHandler;
      /// Pointer to the loaded asset
      TYPE*                mAsset;
      /// Asset ID specified for this asset
      typeAssetID          mAssetID;
  }; // class TAsset
} // namespace GExL

#endif // CORE_TASSET_HPP_INCLUDED

/**
 * @class GExL::TAsset
 * @ingroup Core
 * The TAsset template class is the template used to create a new asset type
 * reference.  It provides indirect reference counting and dummy asset
 * references if no Asset ID is provided (see IAssetHandler).
 *
 * Copyright (c) 2010-2012 Ryan Lindeman
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
