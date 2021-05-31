//
// Created by Matt Whitaker on 18/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_UTILS_LOG_H_
#define KAISHIENGINE_INCLUDE_KAISHI_UTILS_LOG_H_

namespace Kaishi {

#if defined(__GNUC__) && !defined(__llvm__) && !defined(__INTEL_COMPILER)
#define PRINTFLIKE(fmtarg,firstvararg) __attribute__((format(printf,fmtarg,firstvararg)))
#define NORETURN()      __attribute__((noreturn))
#elif __clang__
#define PRINTFLIKE(fmtarg,firstvararg) __printflike(fmtarg, firstvararg)
#define NORETURN()      /* If only */
#else
#define PRINTFLIKE(n,m) /* If only */
#define NORETURN()      /* If only */
#endif /* __GNUC__ */

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
 protected:
  explicit Log(LogLevel logLevel);
  static Log* log_;
  std::string value_;
  void print(const char *string, const char *colourFmtString);
 public:
  Log(Log &other) = delete;
  void operator=(const Log &) = delete;
  static Log *GetInstance(LogLevel logLevel);

  void setLogLevel(LogLevel logLevel);
  LogLevel getLogLevel();
  void debug(std::string &fmt, ...);
  void debug(const char *fmt, ...) PRINTFLIKE(2, 3);
  void info(std::string &fmt, ...);
  void info(const char *fmt, ...) PRINTFLIKE(2, 3);
  void warn(std::string &fmt, ...);
  void warn(const char *fmt, ...) PRINTFLIKE(2, 3);
  void error(std::string &fmt, ...);
  void error(const char *fmt, ...) PRINTFLIKE(2, 3);
  void critical(std::string &fmt, ...);
  void critical(const char *fmt, ...) PRINTFLIKE(2, 3);
};

}  // namespace Kaishi

#endif //KAISHIENGINE_INCLUDE_KAISHI_UTILS_LOG_H_
