#ifndef _UTIL_H_
#define _UTIL_H_

#include <string>
#include <istream>

namespace __util__ {

int string2int(const std::string str)
{
    int n = 0;
    std::stringstream stream;

    stream << str;
    stream >> n;

    return n;
}

std::string int2string(const int n)
{
    std::string str = "";
    std::stringstream stream;

    stream << n;
    stream >> str;

    return str;
}

}

#endif
