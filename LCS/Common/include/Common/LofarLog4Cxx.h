//# LofarLog4Cxx.h: Interface to the log4cxx logging package
//#
//# Copyright (C) 2007
//# ASTRON (Netherlands Institute for Radio Astronomy)
//# P.O.Box 2, 7990 AA Dwingeloo, The Netherlands
//#
//# This file is part of the LOFAR software suite.
//# The LOFAR software suite is free software: you can redistribute it and/or
//# modify it under the terms of the GNU General Public License as published
//# by the Free Software Foundation, either version 3 of the License, or
//# (at your option) any later version.
//#
//# The LOFAR software suite is distributed in the hope that it will be useful,
//# but WITHOUT ANY WARRANTY; without even the implied warranty of
//# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//# GNU General Public License for more details.
//#
//# You should have received a copy of the GNU General Public License along
//# with the LOFAR software suite. If not, see <http://www.gnu.org/licenses/>.
//#
//# $Id: LofarLog4Cxx.h 21325 2012-06-27 08:12:16Z mol $

#ifndef LOFAR_COMMON_LOG4CXX_H
#define LOFAR_COMMON_LOG4CXX_H

// \file
// Interface to the log4cxx logging package.

//# Includes
#include <Common/CasaLogSink.h>
#include <Common/lofar_iostream.h>
#include <Common/lofar_sstream.h>
#include <Common/lofar_string.h>

#ifdef ENABLE_TRACER
#include <Common/StringUtil.h>
#endif

#include <log4cxx/logger.h>
#include <log4cxx/propertyconfigurator.h>

#include <cstring>

//# This might be undefined if used by an external package like ASKAP.
#ifndef AUTO_FUNCTION_NAME
# define AUTO_FUNCTION_NAME __FUNCTION__
#endif


namespace LOFAR {

  // \ingroup Common
  // \addtogroup LofarLogger
  // @{

  //# -------------------- Initialisation of the logger module -------------------
  //
  // \name Initialisation of the logger module
  // Before you can use any function of the logger module you should initialize
  // the module with an appropriate properties-file. There are two functions 
  // available for this:
  // @{
  //
  // Only initializes the logger module.
#define INIT_LOGGER(filename)                   \
  do {                                          \
    ::LOFAR::initLog4Cxx(filename);             \
    ::LOFAR::CasaLogSink::attach();             \
  } while(0)

#define INIT_VAR_LOGGER(filename,logfile)       \
  do {                                          \
    ::LOFAR::initLog4Cxx(filename, logfile);    \
    ::LOFAR::CasaLogSink::attach();             \
  } while(0)

// After initialisation a thread is started to monitor any changes in the
// properties file. An intervaltime in millisecs must be provided.
#ifdef USE_THREADS
# define INIT_LOGGER_AND_WATCH(filename,watchinterval)      \
  do {                                                      \
    ::LOFAR::initLog4CxxAndWatch(filename, watchinterval);  \
    ::LOFAR::CasaLogSink::attach();                         \
  } while(0)
#else
# define INIT_LOGGER_AND_WATCH(filename,watchinterval) INIT_LOGGER(filename)
#endif

// Each new thread might need a partial reinitialisation and destruction in the logger
#define LOGGER_ENTER_THREAD()
#define LOGGER_EXIT_THREAD()

  //@}

  //# -------------------- Log Levels for the Operator messages ------------------
  //#
  //# LOG_FATAL(_STR) (message | stream)
  //# LOG_ERROR(_STR) (message | stream)
  //# LOG_WARN(_STR)  (message | stream)
  //# LOG_INFO(_STR)  (message | stream)
  //
  // \name Log Levels for the Operator messages
  //
  // The LofarLogger utility can log messages on six different levels:
  // <tt>FATAL - ERROR - WARN - INFO - DEBUG - TRACE</tt>.
  // There are strict rules how to use these levels so please read the programmer
  // manual of the LofarLogger before using it.
  //
  // For every level there are two calls made, <tt>LOG_\<level\></tt> and
  // <tt>LOG_\<level\>_STR</tt>.
  // The first form expects a string as an argument, the second form a stream.
  // The stream version allows you to use the operator<< but it is MUCH slower
  // than its string counterpart.
  // To simplifly the usage of strings you can call the global function 
  // 'formatString' that accepts printf like arguments and returns a string.
  //
  // The functions \c LOG_FATAL till \c LOG_INFO produce messages that are meant
  // for the operators. The message may NOT contain any 'inside' information,
  // they should tell:
  //  - WHAT situation has arisen
  //  - WHY this situation is a fault situation
  //  - HOW the situation should be solved (when appropriate)
  //
  // @{

  // Should be used when an unrecoverable exception occures.
#define LOG_FATAL(message)    LofarLog(FATAL,message)
  // Should be used when an unrecoverable exception occures.
#define LOG_FATAL_STR(stream) LofarLogStr(FATAL,stream)

  // Should be used in case of recoverable exceptions and illegal start parms.
#define LOG_ERROR(message)    LofarLog(ERROR,message)
  // Should be used in case of recoverable exceptions and illegal start parms.
#define LOG_ERROR_STR(stream) LofarLogStr(ERROR,stream)

  // Should be used when an unexpected situation occured that could be solved by
  // the software itself.
#define LOG_WARN(message)     LofarLog(WARN,message)
  // Should be used when an unexpected situation occured that could be solved by
  // the software itself.
#define LOG_WARN_STR(stream)  LofarLogStr(WARN,stream)

  // Should be used to notify operator startup and normal termination of
  // programs. It can also be used for other 'global' actions.
#define LOG_INFO(message)     LofarLog(INFO,message)
  // Should be used to notify operator startup and normal termination of
  // programs. It can also be used for other 'global' actions.
#define LOG_INFO_STR(stream)  LofarLogStr(INFO,stream)

  // @}

  //# ------------------------- Debug Levels for the Integrator -------------------------
  //#
  //# LOG_DEBUG(_STR) (message | stream)
  //#
  // \name Debug Levels for the Integrator
  //
  // %Debug information is primarilry meant for the integrator/user of your moudule. 
  // Note that the user of your module is often a developer. The messages contain
  // information about the I/O boundaries of a software module. They should be
  // clear to someone who does not have detailed inside information.
  //
  // The debug messages can still be present in the final 'production' version of
  // your module, so don't overload your program with it.
  //
  // @{

#ifdef DISABLE_DEBUG_OUTPUT
#define LOG_DEBUG(message)
#define LOG_DEBUG_STR(stream)
#else

#define LOG_DEBUG(message)     LofarLog(DEBUG,message)
#define LOG_DEBUG_STR(stream)  LofarLogStr(DEBUG,stream)

#endif // DISABLE_DEBUG_OUTPUT

  // @}

  //# ----------------------- Trace Levels for the Programmer --------------------
  //#
  //# ALLOC_TRACER_CONTEXT
  //# INIT_TRACER_CONTEXT (scope, contextname)
  //# ALLOC_TRACER_ALIAS  (parent)
  //# LOG_TRACE_<type>(_STR) (stream)
  //#
  //# Where <type> = LOOP, VAR, CALC, COND, STAT, OBJ, RTTI or FLOW
  //#
  // \name Trace Levels for the Programmer
  //
  // The trace level is split up into five additive sublevels to be able to
  // control the amount of output generated on this trace level. Again there are
  // strict guidelines how to use the levels in order to improve maintenance of
  // the source (by other developers).
  //
  // Tracing is implemented different from the other levels to get maximum speed
  // for the decision whether of not to log a message. The fact remains though
  // that the string-form of the calls stay much faster than their stream-form
  // counterparts.
  //
  // Unlike the other loglevels the trace level will not be present anymore in the
  // final production code.
  //
  // @{

#ifdef ENABLE_TRACER

#define LOG_TRACE_LOOP(message)    LofarLogTrace(1, message)
#define LOG_TRACE_VAR(message)     LofarLogTrace(2, message)
#define LOG_TRACE_CALC(message)    LofarLogTrace(3, message)
#define LOG_TRACE_COND(message)    LofarLogTrace(4, message)
#define LOG_TRACE_STAT(message)    LofarLogTrace(5, message)
#define LOG_TRACE_OBJ(message)     LofarLogTrace(6, message)
#define LOG_TRACE_RTTI(message)    LofarLogTrace(7, message)
#define LOG_TRACE_FLOW(message)    LofarLogTrace(8, message)
#define LOG_TRACE_LOOP_STR(stream) LofarLogTraceStr(1, stream)
#define LOG_TRACE_VAR_STR(stream)  LofarLogTraceStr(2, stream)
#define LOG_TRACE_CALC_STR(stream) LofarLogTraceStr(3, stream)
#define LOG_TRACE_COND_STR(stream) LofarLogTraceStr(4, stream)
#define LOG_TRACE_STAT_STR(stream) LofarLogTraceStr(5, stream)
#define LOG_TRACE_OBJ_STR(stream)  LofarLogTraceStr(6, stream)
#define LOG_TRACE_RTTI_STR(stream) LofarLogTraceStr(7, stream)
#define LOG_TRACE_FLOW_STR(stream) LofarLogTraceStr(8, stream)
#define TRACE_LEVEL_LOOP 1
#define TRACE_LEVEL_VAR  2
#define TRACE_LEVEL_CALC 3
#define TRACE_LEVEL_COND 4
#define TRACE_LEVEL_STAT 5
#define TRACE_LEVEL_OBJ  6
#define TRACE_LEVEL_RTTI 7
#define TRACE_LEVEL_FLOW 8


// \internal
// Internal macro used by the LOG_TRACE_<level> macros.
#define LofarLogTrace(level,message) \
 do { \
  if (getTraceLogger()->isTraceEnabled()) { \
    ::LOFAR::ScopedDelayCancellation dc; \
    getTraceLogger()->forcedLog (log4cxx::Level::getTrace(), \
                                 message, \
                                 LOG4CXX_LOCATION); \
  } \
 } while(0)

// \internal
// Internal macro used by the LOG_TRACE_<level>_STR macros.
#define LofarLogTraceStr(level,stream) \
 do { \
  if (getTraceLogger()->isTraceEnabled()) { \
    ::LOFAR::ScopedDelayCancellation dc; \
    std::ostringstream	lfr_log_oss; \
    lfr_log_oss << stream; \
    getTraceLogger()->forcedLog (log4cxx::Level::getTrace(), \
                                 lfr_log_oss.str(), \
                                 LOG4CXX_LOCATION); \
  } \
 } while(0)


  //#
  //# LOG_TRACE_LIFETIME(_STR) (level,message | stream)
  //#

  // Create a TraceLogger object that will output your message during construct
  // and destruction. Your message is preceeded with "ENTER:" or "EXIT:".
#define LOG_TRACE_LIFETIME(level,message) \
  ::LOFAR::LifetimeLogger _tmpLifetimeTraceObj(level, getTraceLogger(), \
              ::LOFAR::formatString("%s: %s", AUTO_FUNCTION_NAME, message), \
              __FILE__, __LINE__);

  // Create a TraceLogger object that will output your message during construct
  // and destruction. Your message is preceeded with "ENTER:" or "EXIT:".
#define LOG_TRACE_LIFETIME_STR(level,stream) \
  std::ostringstream lfr_log_oss; \
  lfr_log_oss << AUTO_FUNCTION_NAME << ": " << stream; \
  ::LOFAR::LifetimeLogger _tmpLifetimeTraceObj(level, \
                                               getTraceLogger(), \
                                               lfr_log_oss.str(), \
                                               __FILE__, __LINE__);

  //# ----------- implementation details tracer part -------------


#else  // ENABLE_TRACER
  //# Define dummies if tracing is disabled.
#define LOG_TRACE_LOOP(message)
#define LOG_TRACE_VAR(message)
#define LOG_TRACE_CALC(message)
#define LOG_TRACE_COND(message)
#define LOG_TRACE_STAT(message)
#define LOG_TRACE_OBJ(message)
#define LOG_TRACE_RTTI(message)
#define LOG_TRACE_FLOW(message)
#define LOG_TRACE_LOOP_STR(stream)
#define LOG_TRACE_VAR_STR(stream)
#define LOG_TRACE_CALC_STR(stream)
#define LOG_TRACE_COND_STR(stream)
#define LOG_TRACE_STAT_STR(stream)
#define LOG_TRACE_OBJ_STR(stream)
#define LOG_TRACE_RTTI_STR(stream)
#define LOG_TRACE_FLOW_STR(stream)
#define TRACE_LEVEL_LOOP 0
#define TRACE_LEVEL_VAR  0
#define TRACE_LEVEL_CALC 0
#define TRACE_LEVEL_COND 0
#define TRACE_LEVEL_STAT 0
#define TRACE_LEVEL_OBJ  0
#define TRACE_LEVEL_RTTI 0
#define TRACE_LEVEL_FLOW 0

#define LOG_TRACE_LIFETIME(level,message)
#define LOG_TRACE_LIFETIME_STR(level,stream)

#endif  // ENABLE_TRACER

#define LofarInitTracingModule
#define ALLOC_TRACER_CONTEXT 
#define ALLOC_TRACER_ALIAS(other)
#define INIT_TRACER_CONTEXT(scope,contextname) 

  //@}

  //#------------------------ Assert and FailWhen -------------------------------
  //#
  //# THROW		  (exception,stream)
  //# (DBG)ASSERT	  (condition,stream)
  //# (DBG)FAILWHEN (condition,stream)
  //#
  //# Note: only THROW needs to be defined here, the others are build on THROW
  //# in the LofarLogger.h file.
  //
  // \name Throw
  // @{
  //
  // This macro first sends a logrequest to logger <tt>\<module\>.EXCEPTION</tt>
  // before executing the real throw.
#undef THROW
#define THROW(exc,stream) \
 do { \
  ::LOFAR::ScopedDelayCancellation dc; \
  std::ostringstream lfr_log_oss;	\
  lfr_log_oss << stream;          \
  log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger(LOFARLOGGER_FULLPACKAGE ".EXCEPTION"); \
  LOG4CXX_DEBUG (logger, lfr_log_oss.str()); \
  throw (exc(lfr_log_oss.str(), THROW_ARGS)); \
 } while(0)

  // @}

  //# ----------- implementation details generic part -------------

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  // \internal
  // \name Internal macro's for standard logging functions
  // @{
#define LofarLog(level,message)                                 \
  do {                                                          \
    ::LOFAR::ScopedDelayCancellation dc;                        \
    log4cxx::LoggerPtr _logger =                                \
      log4cxx::Logger::getLogger(LOFARLOGGER_FULLPACKAGE);      \
    LOG4CXX_##level(_logger, message);                          \
  } while(0)

#define LofarLogStr(level,stream)      \
  do {                                 \
    std::ostringstream lfr_log_oss;    \
    lfr_log_oss << stream;             \
    LofarLog(level, lfr_log_oss.str()); \
  } while(0)
  // @}
#endif // DOXYGEN_SHOULD_SKIP_THIS


  // The LifetimeLogger class produces TRACE messages when an instance of this
  // class is created and when it is destroyed.
  class LifetimeLogger
  {
  public:
    LifetimeLogger(int,
		   const log4cxx::LoggerPtr& logger,
		   const std::string& msg,
		   const char* file=0, int line=-1)
      : itsLogger(logger), itsMsg(msg),
	itsFile(file), itsLine(line) 
    {
      if(itsLogger->isTraceEnabled()) {
        itsLogger->forcedLog(log4cxx::Level::getTrace(),
                             "ENTER: " + itsMsg, 
                             log4cxx::spi::LocationInfo(itsFile, 0, itsLine));
      }
    }
    
    ~LifetimeLogger()
    {
      if(itsLogger->isTraceEnabled()) {
        itsLogger->forcedLog(log4cxx::Level::getTrace(),
                             "EXIT: " + itsMsg, 
                             log4cxx::spi::LocationInfo(itsFile, 0, itsLine));
      }
    }
    
  private:
    log4cxx::LoggerPtr itsLogger;
    std::string        itsMsg;
    const char*        itsFile;
    int	               itsLine;
  };


  // @}

// The 'mother' of all trace-loggers is stored here.
extern log4cxx::LoggerPtr theirTraceLoggerRef;
// Function to return the 'mother' of all trace-loggers.
inline log4cxx::LoggerPtr& getTraceLogger() { return theirTraceLoggerRef; }

  // Initialize Log4cxx. 
  // \param propFile Name of the properties file. A missing \c ".log_prop"
  // extension will automatically be added. Note that \a propFile is
  // deliberatly passed by value, because we probably have to add the missing
  // file extension.
  // \param logFile Name of the output log file.
  // \param envVar Name of the environment variable that can be used in the
  // properties file as (part of) of the output log filename. It defaults to
  // \c LOG4CXX_LOGFILENAME. Note that the environment variable will \e
  // always be set to the contents of \a logFile, thereby possibly clobbering
  // it.
  void initLog4Cxx(string propFile, const string& logFile = "",
                     const string& envVar = "LOG4CXX_LOGFILENAME");

  // Initialize Log4cxx with a watchdog thread for the configuration file.
  // \param propFile Name of the properties file. A missing \c ".log_prop"
  // extension will automatically be added. Note that \a propFile is
  // deliberatly passed by value, because we probably have to add the missing
  // file extension.
  // \param watchInterval Time interval (in milliseconds) used by the watch
  // dog to check for changes in the configuration file.
  void initLog4CxxAndWatch(string propFile, unsigned int watchInterval);


} // namespace LOFAR

#include <Common/Thread/Cancellation.h>

#endif // file read before
