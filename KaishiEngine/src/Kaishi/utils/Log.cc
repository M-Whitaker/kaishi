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
void Log::debug(std::string &str) {
  debug(str.c_str());
}
void Log::info(std::string &str) {
  info(str.c_str());
}
void Log::warn(std::string &str) {
  warn(str.c_str());
}
void Log::error(std::string &str) {
  error(str.c_str());
}
void Log::critical(std::string &str) {
  critical(str.c_str());
}
void Log::debug(const char *str) {
  if (m_LogLevel <= LOGGING_LEVEL_DEBUG) {
    print(str, CONSOLE_OUTPUT_RESET);
  }
}
void Log::info(const char *str) {
  if (m_LogLevel <= LOGGING_LEVEL_INFO) {
    print(str, CONSOLE_OUTPUT_BLU);
  }
}
void Log::warn(const char *str) {
  if (m_LogLevel <= LOGGING_LEVEL_WARN) {
    print(str, CONSOLE_OUTPUT_YEL);
  }
}
void Log::error(const char *str) {
  if (m_LogLevel <= LOGGING_LEVEL_ERROR) {
    print(str, CONSOLE_OUTPUT_RED);
  }
}
void Log::critical(const char *str) {
  if (m_LogLevel <= LOGGING_LEVEL_CRITICAL) {
    print(str, CONSOLE_OUTPUT_RED);
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
