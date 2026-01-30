#include <string>

std::string decode(std::string string, int shift)
{
    std::string finalString = "";
    size_t stringSize = string.length();
    int alphSize = 'z' - 'a' + 1;

    for(int idx = 0; idx < stringSize; idx++)
    {
        char stringChar = string[idx];
        if(!isalpha(stringChar))
            continue;

        int effectiveShift = shift % alphSize;

        if(effectiveShift < 0)
            effectiveShift += alphSize;

        if((stringChar >= 'A' && stringChar <= 'Z') ||
           (stringChar >= 'a' && stringChar <= 'z'))
        {
            int effectiveChar = stringChar < 'a' ? 'A' : 'a';
            stringChar =
                ((stringChar - effectiveChar - effectiveShift + alphSize) %
                 alphSize) +
                effectiveChar;
        }

        finalString += stringChar;
    }

    return finalString;
}
