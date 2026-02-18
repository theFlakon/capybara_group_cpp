#include <cctype>
#include <string>
#include <vector>

static bool getNum(size_t& dest, std::string::const_iterator& srcIt,
                   const std::string::const_iterator strEnd);
static bool getWord(std::string& dest, std::string::const_iterator& srcIt,
                    const std::string::const_iterator strEnd);

bool parseRow(std::string& row)
{
    // ------------------------------------------------
    // For the proper work
    // last grade without this is processed incorrectly)

    if(row[row.length() - 1] == '\n')
        row.pop_back();
    row += ' ';

    // ------------------------------------------------

    const size_t GRADES_CNT = 3;

    auto rowIt = row.cbegin();

    size_t studentId = 0;
    std::string surname{};
    std::vector<size_t> gradesVec{};

    if(!getNum(studentId, rowIt, row.cend()))
        return false;

    if(!getWord(surname, rowIt, row.cend()))
        return false;

    for(size_t gradeIdx = 0; gradeIdx < GRADES_CNT; ++gradeIdx)
    {
        size_t currGrade = 0;

        if(!getNum(currGrade, rowIt, row.cend()))
            return false;

        gradesVec.push_back(currGrade);
    }

    return true;
}

bool getNum(size_t& dest, std::string::const_iterator& srcIt,
            const std::string::const_iterator strEnd)
{
    std::string numBuffer{};

    do
    {
        if(srcIt == strEnd || !isdigit(*srcIt))
            return false;

        numBuffer += *srcIt;
    }
    while(*++srcIt != ' ');

    dest = static_cast<size_t>(std::stoul(numBuffer));

    srcIt++;  // Go to the char after space

    return true;
}

bool getWord(std::string& dest, std::string::const_iterator& srcIt,
             const std::string::const_iterator strEnd)
{
    do
    {
        if(srcIt == strEnd || !isalpha(*srcIt))
            return false;

        dest += *srcIt;
    }
    while(*++srcIt != ' ');

    srcIt++;  // Go to the char after space

    return true;
}
