#include <cctype>
#include <string>

std::string chesarEncrypt(const std::string& input, int shift)
{
    std::string output = "";
    int alphabetSize = ('z' - 'a') + 1;
    shift %= alphabetSize;
    for(int i = 0; i < input.size(); i++)
    {
        if(!isalpha(input[i]))
            continue;  // if num -> continue

        char newChar = input[i] + shift;  // new chesar sym

        if(!isalpha(newChar))
        {
            int newShift = 0;
            if(input[i] <= 'Z')
            {
                newShift = shift - (alphabetSize - (input[i] - 'A'));
                newChar = 'A' + newShift;
            }
            else
            {
                newShift = shift - (alphabetSize - (input[i] - 'a'));
                newChar = 'a' + newShift;
            }
        }

        output += newChar;
    }
    return output;
}
