#include <cstddef>
#include <string>

std::string compressor(std::string str)
{
    size_t len         = str.size();
    std::string result = "";
    int cnt            = 0;

    for(int idx = 0; idx < len; idx++)
    {
        if(idx == 0)
        {  // begining of string
            cnt++;
            continue;
        }

        if(str[idx - 1] != str[idx])
        {
            result += '0' + cnt;  // write number
            result += str[idx - 1];
            cnt = 1;
        }

        else
        {
            cnt++;
        }
    }

    if(cnt != 0)
    {
        result += '0' + cnt;
        result += str[len - 1];
    }

    return result;
}
