//
// Created by Matt Whitaker on 18/04/2021.
//

#include "utils/Log.h"

#ifdef KAI_WINDOWS
#include <WinCon.h>
#endif

namespace Kaishi {

Log* Log::pinstance_{nullptr};
std::mutex Log::mutex_;


Log::Log(LogLevel logLevel) {
  m_LogLevel = logLevel;
}

Log *Log::GetInstance(LogLevel logLevel) {
  std::lock_guard<std::mutex> lock(mutex_);
  if (pinstance_ == nullptr) {
    pinstance_ = new Log(logLevel);
  }
  return pinstance_;
}
void Log::setLogLevel(LogLevel logLevel) {
  m_LogLevel = logLevel;
}
LogLevel Log::getLogLevel() {
  return m_LogLevel;
}
void Log::debug(std::string &fmt, ...) {
  debug("%s", fmt.c_str());
}
void Log::info(std::string &fmt, ...) {
  info("%s", fmt.c_str());
}
void Log::warn(std::string &fmt, ...) {
  warn("%s", fmt.c_str());
}
void Log::error(std::string &fmt, ...) {
  error("%s", fmt.c_str());
}
void Log::critical(std::string &fmt, ...) {
  critical("%s", fmt.c_str());
}
void Log::debug(const char *fmt, ...) {
  if (m_LogLevel <= LOGGING_LEVEL_DEBUG) {
    va_list args;
    va_start(args, fmt);
    //TODO: alloc memory
    char buffer[4096];
    int rc = vsnprintf(buffer, sizeof(buffer), fmt, args);
    print(buffer, CONSOLE_OUTPUT_BLU);
    va_end(args);
  }
}
void Log::info(const char *fmt, ...) {
  if (m_LogLevel <= LOGGING_LEVEL_INFO) {
    va_list args;
    va_start(args, fmt);
    //TODO: alloc memory
    char buffer[4096];
    int rc = vsnprintf(buffer, sizeof(buffer), fmt, args);
    print(buffer, CONSOLE_OUTPUT_RESET);
    va_end(args);
  }
}
void Log::warn(const char *fmt, ...) {
  if (m_LogLevel <= LOGGING_LEVEL_WARN) {
    va_list args;
    va_start(args, fmt);
    //TODO: alloc memory
    char buffer[4096];
    int rc = vsnprintf(buffer, sizeof(buffer), fmt, args);
    print(buffer, CONSOLE_OUTPUT_YEL);
    va_end(args);
  }
}
void Log::error(const char *fmt, ...) {
  if (m_LogLevel <= LOGGING_LEVEL_ERROR) {
    va_list args;
    va_start(args, fmt);
    //TODO: alloc memory
    char buffer[4096];
    int rc = vsnprintf(buffer, sizeof(buffer), fmt, args);
    print(buffer, CONSOLE_OUTPUT_RED);
    va_end(args);
  }
}
void Log::critical(const char *fmt, ...) {
  if (m_LogLevel <= LOGGING_LEVEL_CRITICAL) {
    va_list args;
    va_start(args, fmt);
    //TODO: alloc memory
    char buffer[4096];
    int rc = vsnprintf(buffer, sizeof(buffer), fmt, args);
    print(buffer, CONSOLE_OUTPUT_RED);
    va_end(args);
  }
}
void Log::print(const char *string, const char *colourFmtString) {
  time_t t = time(nullptr);
  char buffer[80];

  struct tm *timeInfo = localtime(&t);
  strftime(buffer, 80, m_TimeFormat, timeInfo);
  if (m_LogLevel >= LOGGING_LEVEL_ERROR && m_Filename.empty())
    fprintf(stderr, "%s%s %s" CONSOLE_OUTPUT_RESET, colourFmtString, buffer, string);
  else
    fprintf(stdout, "%s%s %s" CONSOLE_OUTPUT_RESET, colourFmtString, buffer, string);
}
}  // namespace Kaishi
