#include <cmath>
#include <string>

static size_t strToSizet(const std::string& str);
static size_t calcStrNum(std::string::const_iterator& it);

std::string deComp(const std::string& str)
{
    std::string result{};

    for(auto it = str.begin(); it != str.end(); ++it)
    {
        if(!std::isdigit(*it))
        {
            result += *it;
            continue;
        }

        size_t deCompNum = calcStrNum(it);

        for(size_t innerIdx = 0; innerIdx < deCompNum; ++innerIdx)
            result += *it;
    }

    return result;
}

size_t strToSizet(const std::string& str)
{
    size_t strLen = str.size();
    size_t result = 0;

    for(ssize_t idx = strLen - 1; idx >= 0; --idx)
        result += pow(10, strLen - idx - 1) * (str[idx] - '0');

    return result;
}

size_t calcStrNum(std::string::const_iterator& it)
{
    std::string num{};

    do
    {
        num += *it;
        ++it;
    }
    while(std::isdigit(*it));

    return strToSizet(num);
}
