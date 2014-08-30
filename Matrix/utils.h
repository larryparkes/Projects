#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

#define DEBUG_LOGGING 1
#define DEBUG_FILENAME "matrix_test.txt"

static int line = 0;

struct LoggingSystem
{
    static std::ostream& GetLogger()
    {
        static LoggingSystem system(DEBUG_FILENAME); // this is defined one and only once for the life type of the program.
        return system.mStream;
    }

    LoggingSystem(const std::string& filename)
    {
        mStream.open(filename, std::ios::out);
    }

    ~LoggingSystem()
    {
        mStream.close();
    }

    std::ofstream mStream;
};

// this is the end case for the variadic template chain
inline void LogParameters(std::ostream& out)
{
    out << std::endl;
}
// This is a fine example of using variadic templates
template <typename T, typename... Args>
inline void LogParameters(std::ostream& out, T&& t, Args... rest)
{
    out << t;
    LogParameters(out, rest...);
}

template <typename... Args>
inline void Log(std::ostream& out, Args... rest)
{

    using std::chrono::system_clock;
    std::time_t now = system_clock::to_time_t(system_clock::now());
    std::tm * ptm = std::localtime(&now);
    char buffer[32];
    // Format: Mo, 15.06.2009 20:20:00
    std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
    out << line << ": " << buffer << ": ";
    LogParameters(out, rest...);
    line++;
}

#define LOG_DEBUG(...) \
    if (DEBUG_LOGGING) \
        Log(LoggingSystem::GetLogger(),  " ", __FUNCTION__, " ", __LINE__, ": ", __VA_ARGS__);
 //       Log(LoggingSystem::GetLogger(), __FILE__, " ", __FUNCTION__, " ", __LINE__, ": ", __VA_ARGS__);



#endif // UTILS_H_INCLUDED
