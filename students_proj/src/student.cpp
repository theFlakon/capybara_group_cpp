#include <string>
#include <vector>

class Student
{
private:
    size_t _id;
    std::vector<double> _grades;
    std::string _surname;

public:
    Student(size_t id, std::vector<double> grades, std::string surname)
        : _id(id), _grades(std::move(grades)), _surname(std::move(surname))
    {
    }

    double calcAvgGrade

        size_t
        getId()
    {
        return this->_id;
    }
};
