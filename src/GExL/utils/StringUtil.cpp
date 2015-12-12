/**
* Provides several string parsing and manipulation methods used throughout
* the GExL namespace.
*
* @file include/GExL/utils/StringUtil.hpp
* @author Jacob Dix
* @date 20151201 - Initial Release
*/

#include <sstream>
#include <algorithm>
#include <GExL/utils/StringUtil.hpp>
#include <time.h>
namespace GExL
{
  std::string StringToLowercase(std::string theString)
  {
    std::string anLowerString=theString;
    std::transform(anLowerString.begin(), anLowerString.end(), anLowerString.begin(), ::tolower);
    return anLowerString;
  }

  std::string StringToUppercase(std::string theString)
  {
    std::string anUpperString=theString;
    std::transform(anUpperString.begin(), anUpperString.end(), anUpperString.begin(), ::toupper);
    return anUpperString;
  }

  std::string GetDateString()
  {
    time_t anRawTime;
    struct tm * anTimeInfo;
    char anBuffer[80];

    time(&anRawTime);
    anTimeInfo = localtime(&anRawTime);
    strftime(anBuffer, 80, "%D", anTimeInfo);

    return std::string(anBuffer);
  }
  std::string GetTimeString()
  {
    time_t anRawTime;
    struct tm * anTimeInfo;
    char anBuffer[80];

    time(&anRawTime);
    anTimeInfo = localtime(&anRawTime);
    strftime(anBuffer, 80, "%T", anTimeInfo);

    return std::string(anBuffer);
  }
} // namespace GExL

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
