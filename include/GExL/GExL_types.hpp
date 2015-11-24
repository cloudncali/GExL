/**
 * Provides the GExL typedef's and forward class declarations.
 *
 * @file include/GExL/GExL_types.hpp
 * @author Ryan Lindeman
 * @date 20140912 - Initial Release
 */
#ifndef   GExL_TYPES_HPP_INCLUDED
#define   GExL_TYPES_HPP_INCLUDED

#include <list>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <GExL/Config.hpp>
#define INFO_LEVEL   0  ///< Defines the value for GExL::SeverityInfo
#define WARN_LEVEL   1  ///< Defines the value for GExL::SeverityWarning
#define ERROR_LEVEL  2  ///< Defines the value for GExL::SeverityError
#define FATAL_LEVEL  3  ///< Defines the value for GExL::Severity
#define NO_LOG_LEVEL 4  ///< Defines the value for no logging

namespace GExL
{
  /// Status Enumeration for Status Return values
  enum StatusType
  {
    // Values from -99 to 99 are common Error and Good status responses
    StatusAppMissingAsset = -4,  ///< Application failed due to missing asset file
    StatusAppStackEmpty = -3,  ///< Application States stack is empty
    StatusAppInitFailed = -2,  ///< Application initialization failed
    StatusError = -1,  ///< General error status response
    StatusAppOK = 0,  ///< Application quit without error
    StatusNoError = 0,  ///< General no error status response
    StatusFalse = 0,  ///< False status response
    StatusTrue = 1,  ///< True status response
    StatusOK = 1   ///< OK status response

    // Values from +-100 to +-199 are reserved for File status responses
  };

  /// Enumeration of all Logging severity types
  enum SeverityType
  {
    // Logger severity types range from 0 to 4
    SeverityInfo = INFO_LEVEL,   ///< Informational severity type
    SeverityWarning = WARN_LEVEL,   ///< Warning severity type
    SeverityError = ERROR_LEVEL,  ///< Error severity type
    SeverityFatal = FATAL_LEVEL   ///< Fatal severity type
  };
  /* ///<TODO> IMPLEMENT ASSETSYSTEM
  /// Enumeration of AssetLoadTime
  enum AssetLoadTime
  {
    AssetLoadNow = 0, ///< Load the asset now
    AssetLoadLater = 1  ///< Load the asset later
  };

  /// Enumeration of AssetDropTime
  enum AssetDropTime
  {
    AssetDropUnspecified = 0, ///< Drop/unload time unspecified, use default AtZero
    AssetDropAtZero = 1, ///< Drop/unload when count reaches 0
    AssetDropAtExit = 2  ///< Drop/unload when program exits (deconstructor)
  };

  /// Enumeration of all Asset loading techniques
  enum AssetLoadStyle
  {
    AssetLoadFromUnknown = 0, ///< Error condition returned by GetLoadStyle
    AssetLoadFromFile = 1, ///< Load the asset from a file
    AssetLoadFromMemory = 2, ///< Load the asset from memory
    AssetLoadFromNetwork = 3  ///< Load the asset from the network
  };


  /// Declare NameValue typedef which is used for config section maps
  typedef std::map<const std::string, const std::string> typeNameValue;

  /// Declare NameValueIter typedef which is used for name,value pair maps
  typedef std::map<const std::string, const std::string>::iterator typeNameValueIter;

  /// Declare Asset ID typedef which is used for identifying Asset objects
  typedef std::string typeAssetID;
  typedef std::string typeStateID;

  /// Declare Asset Handler ID typedef which is used for identifying Asset Handler objects
  typedef std::string typeAssetHandlerID;
*/
} // namespace GExL
#endif // GExL_TYPES_HPP_INCLUDED

/**
 * Copyright (c) 2014-2015 Jacob Dix
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
