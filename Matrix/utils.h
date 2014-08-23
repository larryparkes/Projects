#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <iostream>

#define DEBUG_LOGGING 1

// this is the end case for the variadic template chain
inline void Log(std::ostream& out)
{
    out << std::endl;
}
// This is a fine example of using variadic templates
template <typename T, typename... Args>
inline void Log(std::ostream& out, T&& t, Args... rest)
{
    out << t;
    Log(out, rest...);
}

#define LOG_DEBUG(...) \
    if (DEBUG_LOGGING) \
        Log(std::cout, __VA_ARGS__);


#endif // UTILS_H_INCLUDED
