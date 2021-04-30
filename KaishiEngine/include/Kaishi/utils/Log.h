//
// Created by Matt Whitaker on 18/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_UTILS_LOG_H_
#define KAISHIENGINE_INCLUDE_KAISHI_UTILS_LOG_H_

namespace Kaishi {

#define CONSOLE_OUTPUT_RED "\x1B[31m"
#define CONSOLE_OUTPUT_GRN "\x1B[32m"
#define CONSOLE_OUTPUT_YEL "\x1B[33m"
#define CONSOLE_OUTPUT_BLU "\x1B[34m"
#define CONSOLE_OUTPUT_MAG "\x1B[35m"
#define CONSOLE_OUTPUT_CYN "\x1B[36m"
#define CONSOLE_OUTPUT_WHT "\x1B[37m"
#define CONSOLE_OUTPUT_RESET "\x1B[0m"

typedef enum LogLevel {
  LOGGING_LEVEL_DEBUG = 10,
  LOGGING_LEVEL_INFO = 20,
  LOGGING_LEVEL_WARN = 30,
  LOGGING_LEVEL_ERROR = 40,
  LOGGING_LEVEL_CRITICAL = 50
} LogLevel;

class Log {
 private:
  static Log *pinstance_;
  static std::mutex mutex_;
  LogLevel m_LogLevel;
  const char *m_TimeFormat = "%FT%TZ";
  std::string m_Filename;
  void print(const char *string, const char *colourFmtString);

 protected:
  explicit Log(LogLevel logLevel);
  static Log* log_;
  std::string value_;

 public:
  Log(Log &other) = delete;
  void operator=(const Log &) = delete;
  static Log *GetInstance(LogLevel logLevel);

  void setLogLevel(LogLevel logLevel);
  LogLevel getLogLevel();
  void debug(std::string &str);
  void debug(const char* str);
  void info(std::string &str);
  void info(const char* str);
  void warn(std::string &str);
  void warn(const char* str);
  void error(std::string &str);
  void error(const char* str);
  void critical(std::string &str);
  void critical(const char* str);
};

}  // namespace Kaishi

#endif  //KAISHIENGINE_INCLUDE_KAISHI_UTILS_LOG_H_
