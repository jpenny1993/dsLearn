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
    std::string assertStr(assert);
    std::string fileStr(file);
    fileStr = getFilenameFromPath(fileStr);

    printf("ASSERT FAILED: %s\nFILE: %s\nLINE: %i\n",
            assertStr.c_str(), fileStr.c_str(), line);
}

#define DEBUG_ASSERT(x) \
    if(!(x)) { \
      logAssert(#x, __FILE__, __LINE__);\
    }

#define DEBUG_BREAKING_ASSERT(x) \
    if(!(x)) { \
      logAssert(#x, __FILE__, __LINE__);\
      assert(false); \
    }

#else
    #define DEBUG_ASSERT(x)
    #define DEBUG_BREAKING_ASSERT(x)
#endif

#endif //DEBUGGER__H
