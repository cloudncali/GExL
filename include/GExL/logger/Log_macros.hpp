/**
 * Provides several macros for logging information to the global logger (see
 * GExL::gLogger) and is by several GExL Core modules.
 *
 * @file include/GExL/logger/Log_macros.hpp
 * @author Ryan Lindeman
 * @date 20110610 - Initial Release
 * @date 20120426 - Change to ILogger::GetLogger call instead of gLogger
 */
#ifndef   GExL_LOG_MACROS_HPP_INCLUDED
#define   GExL_LOG_MACROS_HPP_INCLUDED
#include <GExL/GExL_types.hpp>
#ifndef GExL_ANDROID
#include <GExL/logger/FatalLogger.hpp>
#include <GExL/logger/ScopeLogger.hpp>

/**
 * Define GExL_STRIP_LOG to the minimum log level you wish to include when
 * compiling the GExL Libraries or GExL based game engines, all others will be
 * stripped by the compiler and not included in the library or executable.
 */
#ifndef GExL_STRIP_LOG
#define GExL_STRIP_LOG INFO_LEVEL
#endif

/////////////////////////////////////////////////////////////////////////////
// Logger Macros
/////////////////////////////////////////////////////////////////////////////
/**
 * LOG_ON macro will enable all logging facilities for the severity level
 * that is compiled into the code (see GExL_STRIP_LOG)
 */
#if GExL_STRIP_LOG <= FATAL_LEVEL
#define LOG_ON() \
  do { \
    if(GExL::ILogger::GetLogger()) { \
      GExL::ILogger::GetLogger()->SetActive(true); \
    } \
  } while(false)
#else
#define LOG_ON() do {} while(false)
#endif

/**
 * LOG_OFF macro will disable all logging facilities for all severity levels
 * compiled into the code.
 */
#if GExL_STRIP_LOG <= FATAL_LEVEL
#define LOG_OFF() \
  do { \
    if(GExL::ILogger::GetLogger()) { \
      GExL::ILogger::GetLogger()->SetActive(false); \
    } \
  } while(false)
#else
#define LOG_OFF() do {} while(false)
#endif

#if GExL_STRIP_LOG == INFO_LEVEL
/**
 * ILOGM macro defines a simple macro that will log theMessage provided at the
 * GExL::SeverityInfo level to the global Logger (see GExL::gLogger).
 * @param[in] theMessage to be logged as a const char* string.
 */
#define ILOGM(theMessage) \
  do { \
    if(GExL::ILogger::GetLogger()) { \
      GExL::ILogger::GetLogger()->LogMessage(GExL::SeverityInfo, __FILE__, __LINE__, \
          theMessage); \
    } \
  } while(false)
/**
 * ILOG macro defines a simple macro that will log any << following the macro
 * at the GExL::SeverityInfo level to the global Logger (see GExL::gLogger).
 */
#define ILOG() \
  if(!GExL::ILogger::GetLogger()) { \
    /* Empty */ \
  } else \
    GExL::ILogger::GetLogger()->GetStream(GExL::SeverityInfo, __FILE__, __LINE__)
/**
 * ILOGM_IF macro defines a simple macro that will log theMessage provided if
 * theCondition is met at the GExL::SeverityInfo level to the global Logger
 * (see GExL::gLogger).
 * @param[in] theMessage to be logged as a const char* string
 * @param[in] theCondition to be used to determine if theMessage is logged
 */
#define ILOGM_IF(theMessage, theCondition) \
  !(theCondition) ? (void) 0 : ILOGM(theMessage)
/**
 * ILOG_IF macro defines a simple macro that will log any << following this
 * macro if theCondition is met at the GExL::SeverityInfo level to the global
 * Logger (see GExL::gLogger).
 * @param[in] theCondition to be used to determine if theMessage is logged
 */
#define ILOG_IF(theCondition) \
  !(theCondition) ? (void) 0 : ILOG()
#else
#define ILOGM(theMessage) do {} while(false)
#define ILOG() if(true) { /* Empty */ } else GExL::ILogger::gNullStream
#define ILOGM_IF(theMessage, theCondition) \
  !(theCondition) ? (void) 0 : ILOGM(theMessage)
#define ILOG_IF(condition) \
  !(theCondition) ? (void) 0 : ILOG()
#endif

#if GExL_STRIP_LOG <= WARN_LEVEL
/**
 * WLOGM macro defines a simple macro that will log theMessage provided at the
 * GExL::SeverityWarn level to the global Logger (see GExL::gLogger).
 * @param[in] theMessage to be logged as a const char* string.
 */
#define WLOGM(theMessage) \
  do { \
    if(GExL::ILogger::GetLogger()) { \
      GExL::ILogger::GetLogger()->LogMessage(GExL::SeverityWarning, __FILE__, __LINE__, \
          theMessage); \
    } \
  } while(false)

/**
 * WLOG macro defines a simple macro that will log any << following the macro
 * at the GExL::SeverityWarn level to the global Logger (see GExL::gLogger).
 */
#define WLOG() \
  if(!GExL::ILogger::GetLogger()) { \
    /* Empty */ \
  } else \
    GExL::ILogger::GetLogger()->GetStream(GExL::SeverityWarning, __FILE__, __LINE__)

/**
 * WLOGM_IF macro defines a simple macro that will log theMessage provided if
 * theCondition is met at the GExL::SeverityWarn level to the global Logger
 * (see GExL::gLogger).
 * @param[in] theMessage to be logged as a const char* string
 * @param[in] theCondition to be used to determine if theMessage is logged
 */
#define WLOGM_IF(theMessage, theCondition) \
  !(theCondition) ? (void) 0 : WLOGM(theMessage)

/**
 * WLOG_IF macro defines a simple macro that will log any << following this
 * macro if theCondition is met at the GExL::SeverityWarn level to the global
 * Logger (see GExL::gLogger).
 * @param[in] theCondition to be used to determine if theMessage is logged
 */
#define WLOG_IF(theCondition) \
  !(theCondition) ? (void) 0 : WLOG()

#else
#define WLOGM(theMessage) do {} while(false)
#define WLOG() if(true) { /* Empty */ } else GExL::ILogger::gNullStream
#define WLOGM_IF(theMessage, theCondition) \
  !(theCondition) ? (void) 0 : WLOGM(theMessage)
#define WLOG_IF(condition) \
  !(theCondition) ? (void) 0 : WLOG()
#endif

#if GExL_STRIP_LOG <= ERROR_LEVEL
/**
 * ELOGM macro defines a simple macro that will log theMessage provided at the
 * GExL::SeverityError level to the global Logger (see GExL::gLogger).
 * @param[in] theMessage to be logged as a const char* string.
 */
#define ELOGM(theMessage) \
  do { \
    if(GExL::ILogger::GetLogger()) { \
      GExL::ILogger::GetLogger()->LogMessage(GExL::SeverityError, __FILE__, __LINE__, \
          theMessage); \
    } \
  } while(false)

/**
 * ELOG macro defines a simple macro that will log any << following the macro
 * at the GExL::SeverityError level to the global Logger (see GExL::gLogger).
 */
#define ELOG() \
  if(!GExL::ILogger::GetLogger()) { \
    /* Empty */ \
  } else \
    GExL::ILogger::GetLogger()->GetStream(GExL::SeverityError, __FILE__, __LINE__)

/**
 * ELOGM_IF macro defines a simple macro that will log theMessage provided if
 * theCondition is met at the GExL::SeverityError level to the global Logger
 * (see GExL::gLogger).
 * @param[in] theMessage to be logged as a const char* string
 * @param[in] theCondition to be used to determine if theMessage is logged
 */
#define ELOGM_IF(theMessage, theCondition) \
  !(theCondition) ? (void) 0 : ELOGM(theMessage)

/**
 * ELOG_IF macro defines a simple macro that will log any << following this
 * macro if theCondition is met at the GExL::SeverityError level to the global
 * Logger (see GExL::gLogger).
 * @param[in] theCondition to be used to determine if theMessage is logged
 */
#define ELOG_IF(theCondition) \
  !(theCondition) ? (void) 0 : ELOG()

#else
#define ELOGM(theMessage) do {} while(false)
#define ELOG() if(true) { /* Empty */ } else GExL::ILogger::gNullStream
#define ELOGM_IF(theMessage, theCondition) \
  !(theCondition) ? (void) 0 : ELOGM(theMessage)
#define ELOG_IF(condition) \
  !(theCondition) ? (void) 0 : ELOG()
#endif

#if GExL_STRIP_LOG <= FATAL_LEVEL
/**
 * FLOGM macro defines a simple macro that will log theMessage provided at the
 * GExL::SeverityFatal level to the global Logger (see GExL::gLogger).  After
 * logging theMessage it will either call the Quit method using the global App
 * (see GExL::gApp) pointer or call exit if the global App pointer is NULL (see
 * ILogger::FatalShutdown).
 * @param[in] theMessage to be logged as a const char* string.
 * @param[in] theExitCode value to use when exiting the application
 */
#define FLOGM(theMessage, theExitCode) \
  do { \
    GExL::FatalLogger(GExL::SeverityFatal, __FILE__, __LINE__, theExitCode) \
      .LogMessage(theMessage); \
  } while(false)

/**
 * FLOG macro defines a simple macro that will log any << following the macro
 * at the GExL::SeverityFatal level to the global Logger (see GExL::gLogger).
 * After logging theMessage it will either call the Quit method using the
 * global App (see GExL::gApp) pointer or call exit if the global App pointer is
 * NULL (see ILogger::FatalShutdown).
 * @param[in] theExitCode value to use when exiting the application
 */
#define FLOG(theExitCode) \
  if(!GExL::ILogger::GetLogger()) { \
    /* Empty */ \
  } else \
    GExL::FatalLogger(GExL::SeverityFatal, __FILE__, __LINE__, theExitCode) \
      .GetStream()

/**
 * FLOGM_IF macro defines a simple macro that will log theMessage provided if
 * theCondition is met at the GExL::SeverityFatal level to the global Logger
 * (see GExL::gLogger).  After logging theMessage it will either call the Quit
 * method using the global App (see GExL::gApp) pointer or call exit if the
 * global App pointer is NULL (see ILogger::FatalShutdown).
 * @param[in] theMessage to be logged as a const char* string
 * @param[in] theCondition to be used to determine if theMessage is logged
 * @param[in] theExitCode value to use when exiting the application
 */
#define FLOGM_IF(theMessage, theCondition, theExitCode) \
  !(theCondition) ? (void) 0 : FLOGM(theMessage, theExitCode)

/**
 * FLOG_IF macro defines a simple macro that will log any << following this
 * macro if theCondition is met at the GExL::SeverityFatal level to the global
 * Logger (see GExL::gLogger).  After logging theMessage it will either call the
 * Quit method using the global App (see GExL::gApp) pointer or call exit if the
 * global App pointer is NULL (see ILogger::FatalShutdown).
 * @param[in] theCondition to be used to determine if theMessage is logged
 * @param[in] theExitCode value to use when exiting the application
 */
#define FLOG_IF(theCondition, theExitCode) \
  !(theCondition) ? (void) 0 : FLOG(theExitCode)

#else
#define FLOGM(theMessage, theExitCode) do {} while(false)
#define FLOG() if(true) { /* Empty */ } else GExL::ILogger::gNullStream
#define FLOGM_IF(theMessage, theCondition, theExitCode) \
  !(theCondition) ? (void) 0 : FLOGM(theMessage, theExitCode)
#define FLOG_IF(theCondition, theExitCode) \
  !(theCondition) ? (void) 0 : FLOG(theExitCode)
#endif

#if GExL_STRIP_LOG == INFO_LEVEL
/**
 * SLOG macro defines a simple macro that will log the Entry and Exit of the
 * scope (which might be a method or function) along with any << following
 * the macro when the scope macro variable (_gql_ + theName) created goes out
 * of scope. The messages and arguments are logged at theSeverity (see
 * GExL::SeverityType) level provided to the global Logger (see GExL::gLogger).
 * The Exit log entry will use the line number of the last SLOGR message used.
 * If no SLOGR macros were used the line number will be the same as the Entry
 * log message used.
 * @param[in] theScopeName (not in quotes!) to use for the variable created
 * @param[in] theSeverity to use when logging Entry and Exit of scope
 */
#define SLOG(theScopeName, theSeverity) \
  GExL::ScopeLogger _gql_##theScopeName(theSeverity, __FILE__, __LINE__, \
    #theScopeName); \
  _gql_##theScopeName.GetStream()

/**
 * SLOG macro defines a simple macro that will log the Entry and Exit of the
 * scope (which might be a method or function) along with any << following
 * the macro when the scope macro variable (_gql_ + theName) created goes out
 * of scope. The messages and arguments are logged at theSeverity (see
 * GExL::SeverityType) level provided to the global Logger (see GExL::gLogger).
 * The Exit log entry will use the line number of the last SLOGR message used.
 * If no SLOGR macros were used the line number will be the same as the Entry
 * log message used.
 * @param[in] theScopeName (not in quotes!) to use for the variable created
 * @param[in] theSeverity to use when logging Entry and Exit of scope
 * @param[in] theExitCode value to use when exiting the application
 */
#define SLOGE(theScopeName, theSeverity, theExitCode) \
  GExL::ScopeLogger _gql_##theScopeName(theSeverity, __FILE__, __LINE__, \
    theExitCode, #theScopeName); \
  _gql_##theScopeName.GetStream()

/**
 * SLOGR macro defines a simple macro that will allow the logging of all <<
 * following the SLOGR macro which is likely the return value(s) from a method
 * or function scope.  Every call to SLOGR will update the severity level,
 * source file, and source line number used when the Exit entry is logged by
 * the SLOG created ScopeLogger class, this is to help determine from the log
 * which return path a scope may have used on Exit. If the severity level of
 * SLOG or the last SLOGR is equal to GExL::SeverityFatal then the FatalShutdown
 * method (see ILogger) will be called after the Exit entry log message is
 * recorded in the ScopeLogger deconstructor. All the << values following the
 * SLOGR macro will be logged at theSeverity (see GExL::SeverityType) level
 * provided to the global Logger (see GExL::gLogger).
 * @param[in] theScopeName (not in quotes!) to use for the variable reference
 * @param[in] theSeverity to use when logging Entry and Exit of scope
 */
#define SLOGR(theScopeName, theSeverity) \
  if(!GExL::ILogger::GetLogger()) { \
    /* Empty */ \
  } else \
    _gql_##theScopeName.GetStream(theSeverity, __FILE__, __LINE__)

/**
 * SLOGR macro defines a simple macro that will allow the logging of all <<
 * following the SLOGR macro which is likely the return value(s) from a method
 * or function scope.  Every call to SLOGR will update the severity level,
 * source file, and source line number used when the Exit entry is logged by
 * the SLOG created ScopeLogger class, this is to help determine from the log
 * which return path a scope may have used on Exit. If the severity level of
 * SLOG or the last SLOGR is equal to GExL::SeverityFatal then the FatalShutdown
 * method (see ILogger) will be called after the Exit entry log message is
 * recorded in the ScopeLogger deconstructor. All the << values following the
 * SLOGR macro will be logged at theSeverity (see GExL::SeverityType) level
 * provided to the global Logger (see GExL::gLogger).
 * @param[in] theScopeName (not in quotes!) to use for the variable reference
 * @param[in] theSeverity to use when logging Entry and Exit of scope
 * @param[in] theExitCode value to use when exiting the application
 */
#define SLOGRE(theScopeName, theSeverity, theExitCode) \
  if(!GExL::ILogger::GetLogger()) { \
    /* Empty */ \
  } else \
    _gql_##theScopeName.GetStream(theSeverity, __FILE__, __LINE__, theExitCode)

#else
#define SLOG(theScopeName, theSeverity) \
  if(true) { /* Empty */ } else GExL::ILogger::gNullStream
#define SLOGE(theScopeName, theSeverity, theExitCode) \
  if(true) { /* Empty */ } else GExL::ILogger::gNullStream
#define SLOGR(theScopeName, theSeverity) \
  if(true) { /* Empty */ } else GExL::ILogger::gNullStream
#define SLOGRE(theScopeName, theSeverity, theExitCode) \
  if(true) { /* Empty */ } else GExL::ILogger::gNullStream
#endif

#else
#include <iostream>

#define ILOG() std::cout
#define WLOG() std::cout
#define ELOG() std::cout
#define FLOG(status) std::cout
#define ILOGM(message)
#endif
#endif // GExL_LOG_MACROS_HPP_INCLUDED

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
