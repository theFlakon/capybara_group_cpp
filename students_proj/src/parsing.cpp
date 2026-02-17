#include <string>
#include <vector>
#include <sstream>
#include <cstddef>

bool parseRow(std::string& row)
{
    if (row.empty()) return false;

    std::stringstream ss(s: row);

    /* parse id and check */ 
    size_t id  = 0;
    ss >> id;
    
    /* parse surname and check */
    std::string surname{};
    ss >> surname;

    // first letter check
    if (islpha(surname[0]))
    {
        if (isupper(surname[0])) continue;
        else return false;
    } else return false;

    // other letters check
    for (size_t idx = 0; idx < surname.size(); ++idx)
    {
        if (isalpha(surname[idx]))
        {
            if (islower(surname[idx])) continue;
            else return false;
        }
    }   else return false;

    /* parse first grade */ 
    size_t firstGrade  = 0;
    ss >> firstGrade;

    /* parse second grade */ 
    size_t secondGrade  = 0;
    ss >> secondGrade;
    
    /* parse third grade */ 
    size_t thirdGrade  = 0;
    ss >> thirdGrade;
}   