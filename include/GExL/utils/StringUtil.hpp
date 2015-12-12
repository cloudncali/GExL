/**
 * Provides several string parsing and manipulation methods used throughout
 * the GExL namespace.
 *
 * @file include/GExL/utils/StringUtil.hpp
 * @author Jacob Dix
 * @date 20151201 - Initial Release
 */
#ifndef STRING_UTIL_HPP_INCLUDED
#define STRING_UTIL_HPP_INCLUDED

#include <string>
#include <GExL/Config.hpp>

namespace GExL
{
 /** 
  * StringToLowercase will convert theString to all lowercase letters.
  * @param[in] theString is the string to change case.
  * @return theString with all lowercase.
  **/
  std::string GExL_API StringToLowercase(std::string theString);

  /** 
  * StringToUppercase will convert theString to all uppercase letters.
  * @param[in] theString is the string to change case.
  * @return theString with all uppercase.
  **/
  std::string GExL_API StringToUppercase(std::string theString);
  /**
  * GetDateString will generated a string with the current date.
  * @return A string containing todays date in MM/DD/YY format.
  **/
  std::string GetDateString();
  /**
  * GetDateString will generated a string with the current time.
  * @return A string containing current time in HH:MM:SS format.
  **/
  std::string GetTimeString();
} // namespace GExL

#endif // STRING_UTIL_HPP_INCLUDED
/**
 * @ingroup GExL
 * This file contains all the string manipulation methods that can
 * be used by any class in the GExL namespace. 
 *
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
