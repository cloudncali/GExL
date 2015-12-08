/**
 * Provides the StringLogger class that provides logging support to a string for
 * all GExL classes in the GExL namespace in the GExL core library.
 *
 * @file include/GExL/logger/StringLogger.hpp
 * @author Ryan Lindeman
 * @date 20140912 - Initial Release
 */
#ifndef   CORE_STRING_LOGGER_HPP_INCLUDED
#define   CORE_STRING_LOGGER_HPP_INCLUDED
#ifndef GExL_ANDROID
#include <sstream>
#include <string>
#include <GExL/GExL_types.hpp>
#include <GExL/logger/ILogger.hpp>

namespace GExL
{
  /// Provides a class for logging to a large string in memory
  class GExL_API StringLogger : public ILogger
  {
    public:

      /**
       * StringLogger constructor
       * @param[in] theDefault flag indicating this should be the default logger
       * @param[in] theExitCode value to use when FatalShutdown is called
       */
      StringLogger(bool theDefault = false, int theExitCode = StatusError);

      /**
       * StringLogger deconstructor
       */
      virtual ~StringLogger();

      /**
       * GetString is responsible for returning the ostream in string form and
       * is most often used by classes that inherit from StringLogger.
       * @return the string version of the ostream
       */
      std::string GetString(void);

      /**
       * GetStream is responsible for returning the ostream necessary to log the
       * custom message that will follow without a prefix.
       * @return the ostream to use for logging the message
       */
      virtual std::ostream& GetStream(void);

      /**
       * GetStream is responsible for returning the ostream necessary to log the
       * custom message that will follow and prefix the custom message with an
       * appropriate timestamp and File:Line tag.
       * @param[in] theSeverity for this message to be logged
       * @param[in] theSourceFile where the Log macro was called from
       * @param[in] theSourceLine number where the Log macro was called from
       * @param[in] theExitCode value to use when FatalShutdown is called
       * @return the ostream to use for logging the message
       */
      virtual std::ostream& GetStream(SeverityType theSeverity,
          const char* theSourceFile, int theSourceLine, int theExitCode = StatusError);

      /**
       * LogMessage is responsible for logging the message provided using an
       * appropriate timestamp and File:Line tag in front.
       * @param[in] theMessage to log
       */
      virtual void LogMessage(const char* theMessage);

      /**
       * LogMessage is responsible for logging the message provided using an
       * appropriate timestamp and File:Line tag in front.
       * @param[in] theSeverity for this message to be logged
       * @param[in] theSourceFile where the Log macro was called from
       * @param[in] theSourceLine number where the Log macro was called from
       * @param[in] theMessage to log
       */
      virtual void LogMessage(SeverityType theSeverity,
          const char* theSourceFile, int theSourceLine,
          const char* theMessage);

    protected:      

    private:
      /// Output Logger file
      std::ostringstream mStringStream;

      /**
       * Copy constructor is private because we do not allow copies of
       * our Singleton class
       */
      StringLogger(const StringLogger&);             // Intentionally undefined

      /**
       * Our assignment operator is private because we do not allow copies
       * of our Singleton class
       */
      StringLogger& operator=(const StringLogger&);  // Intentionally undefined
  }; // class StringLogger
} // namespace GExL
#endif
#endif // CORE_STRING_LOGGER_HPP_INCLUDED
/**
 * @class GExL::StringLogger
 * @ingroup Core
 * The StringLogger class provides a useful string logging facility for any game
 * engine that needs string logging for debug purposes.
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
