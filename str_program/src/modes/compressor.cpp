#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>

std::string compressor(std::string str)
{
    size_t len = str.size();
    std::string result = "";
    int cnt = 1;

    for(size_t idx = 0; idx < len; idx++)
    {
        if(isdigit(str[idx]))
        {
            std::cerr << "Error: string contains num\n";
            return "";
        }

        if(idx == 0)
            continue;  // begining of string

        if(str[idx - 1] != str[idx])
        {
            result += std::to_string(cnt);  // write number
            result += str[idx - 1];         // write letter
            cnt = 1;
        }

        else
            cnt++;
    }

    if(cnt != 0)
    {
        result += std::to_string(cnt);  // for last sym
        result += str[len - 1];
    }

    return result;
}
