/**
* Provides the FileLogger class that provides logging support to a file for
* all GExL classes in the GExL namespace in the GExL core library.
*
* @file src/GExL/logger/FileLogger.cpp
* @author Ryan Lindeman
* @date 20120912 - Initial Release
*/
#include <GExL/Config.hpp>
#ifndef GExL_ANDROID
#include <GExL/logger/FileLogger.hpp>

namespace GExL
{
  FileLogger::FileLogger(const char* theFilename, bool theDefault) :
    ILogger(theDefault)
  {
    mFileStream.open(theFilename);
    if(mFileStream.is_open())
    {
      LogMessage(SeverityInfo, __FILE__, __LINE__, "FileLogger::ctor()");
    }
  }

  FileLogger::~FileLogger()
  {
    if(mFileStream.is_open())
    {
      LogMessage(SeverityInfo, __FILE__, __LINE__, "FileLogger::dtor()");
      mFileStream.close();
    }
  }

  std::ostream& FileLogger::GetStream(void)
  {
    std::ostream* anResult = &gNullStream;
    if(mFileStream.is_open() && IsActive())
    {
      anResult = &mFileStream;
    }
    return *anResult;
  }

  std::ostream& FileLogger::GetStream(SeverityType theSeverity,
      const char* theSourceFile, int theSourceLine, int theExitCode)
  {
    std::ostream* anResult = &gNullStream;
    if(mFileStream.is_open() && IsActive())
    {
      anResult = &mFileStream;
      WriteTag(mFileStream, theSeverity, theSourceFile, theSourceLine);
    }
    return *anResult;
  }

  void FileLogger::LogMessage(const char* theMessage)
  {
    if(mFileStream.is_open() && IsActive())
    {
      mFileStream << theMessage << std::endl;
    }
  }

  void FileLogger::LogMessage(SeverityType theSeverity,
      const char* theSourceFile, int theSourceLine,
      const char* theMessage)
  {
    if(mFileStream.is_open() && IsActive())
    {
      WriteTag(mFileStream, theSeverity, theSourceFile, theSourceLine);
      mFileStream << theMessage << std::endl;
    }
  }

} // namespace GExL
#endif
/**
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
