/**
 * Provides a template for converting from numaric types to strings or vise versa.
 *
 * @file include/GExL/utils/TParser.hpp
 * @author Jacob Dix
 * @date 20151202 - Initial Release
*/
#ifndef TPARSER_HPP_INCLUDED
#define TPARSER_HPP_INCLUDED
#include <GExL/utils/StringUtil.hpp>
#include <string>
#include <sstream>
#include <algorithm>

namespace GExL
{
  /** Defines the TParser template class for converting TYPE into strings and
   * from strings which is typically used in reading/writing configuration
   * files or network streams.
   */
  template<typename TYPE>
  class TParser
  {
  public:
    /** Converts theValue provided into a string using the default insertion
     * operator << to perform the work. The insertion operator << must be
     * defined for this to work.
     * @param theValue to convert to a string
     * @return std::string after the conversion
     */
    static std::string ToString(TYPE theValue)
    {
      // Use StringStream class to convert theValue to a string
      std::stringstream anResult;

      // Add theDouble to the stringstream
      anResult << theValue;

      // Return the string result created by stringstream
      return anResult.str();
    }

    /** Converts theString provided into a value using the extraction operator
     * >> or returns theDefault value provided if the extraction operator fails
     * to convert theString into a value. The extraction operator >> must be
     * defined for the TYPE provided for this method to work.
     * @param theString to convert to a string
     * @param theDefault value to use if theString can't be converted
     * @return TYPE value as converted from theString
     */
    static TYPE ToValue(std::string theString, TYPE theDefault)
    {
      TYPE anResult = theDefault;
      std::istringstream iss(theString);

      // Convert the string to a floating point number
      iss >> anResult;

      // Return the result found or theDefault assigned above
      return anResult;
    }
  };

  /** Defines the boolean special case of the TParser template implementation.
   */
  template<>
  class TParser<bool>
  {
  public:
    /** Converts theValue (which is a boolean) provided into either a "true"
     * or "false" string value.
     * @param theValue to convert to a string
     * @return std::string after the conversion
     */
    static std::string ToString(const bool theValue)
    {
      // Use StringStream class to convert theBoolean to a string
      std::stringstream anResult;

      // Add theBoolean to the stringstream
      if (theValue)
      {
        anResult << "true";
      }
      else
      {
        anResult << "false";
      }

      // Return the string result created by stringstream
      return anResult.str();
    }

    /** Converts theString provided into a true boolean value if it matches one
     * of the following strings "1", "true", "on" or a false boolean value if
     * it matches one of the following strings "0", "false", "off". If theString
     * doesn't match any of the above strings then theDefault value is returned.
     * @param theString to convert to a boolean value
     * @param theDefault value to use if theString can't be converted
     * @return TYPE value as converted from theString
     */
    static bool ToValue(std::string theString, const bool theDefault = false)
    {
      bool anResult = theDefault;

      // First convert theValue provided into lower case
      theString = StringToLowercase(theString);

        // Look for true/1/on results
      if (theString == "true" || theString == "1" || theString == "on")
      {
        anResult = true;
      }

      // Look for false results
      if (theString == "false" || theString == "0" || theString == "off")
      {
        anResult = false;
      }

      // Return the result found or theDefault assigned above
      return anResult;
    }
  };

}
#endif
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
