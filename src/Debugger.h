#ifndef DEBUGGER__H
#define DEBUGGER__H

#ifndef NDEBUG // Define NDEBUG in the MAKE file to remove from production release

#include <cstdio>
#include <locale>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>

static std::string getFilenameFromPath(const std::string& path){

    using namespace std;

    vector<string> strings;
    istringstream f(path);
    string s;
    while (getline(f, s, '/')) {
        strings.push_back(s);
    }

    return strings.back();
}

static void logAssert(const char* assert, const char* file, int line) {

    // Uppercasing since we have only big characters in the Spelunky font
    // and lower-cased ones simply aren't displayed.
    std::string assertUppercased(assert);
    std::string fileUppercased(file);
    fileUppercased = getFilenameFromPath(fileUppercased);
    std::locale loc;

    for (char &i : fileUppercased)
        i = std::toupper(i, loc);
    for (char &i : assertUppercased)
        i = std::toupper(i, loc);

    printf("ASSERT FAILED: %s\nFILE: %s\nLINE: %i\n",
            assertUppercased.c_str(), fileUppercased.c_str(), line);
}

#define DEBUG_ASSERT(x) \
	if(!(x)) \
    { \
      logAssert(#x, __FILE__, __LINE__);\
    }

#define DEBUG_BREAKING_ASSERT(x) \
	if(!(x)) \
    { \
      logAssert(#x, __FILE__, __LINE__);\
      assert(false); \
    }

#else
    #define DEBUG_ASSERT(x)
    #define DEBUG_BREAKING_ASSERT(x)
#endif

#endif //DEBUGGER__H
