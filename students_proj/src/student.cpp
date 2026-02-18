#include <numeric>
#include <string>
#include <vector>
#include "student.hpp"


Student::Student(size_t id, std::vector<double> grades, std::string surname)
    : _id(id), _grades(std::move(grades)), _surname(std::move(surname)) {

}
 
double Student::calcAvgGrade() const
{
    double gradesSum = std::accumulate(_grades.begin(), _grades.end(), 0);
    auto gradesCnt = static_cast<double>(_grades.size());

    return gradesSum / gradesCnt;
}

// Getters
size_t Student::getId() const
{
    return _id;
}

const std::vector<double>& Student::getStudentsVec() const
{
    return _grades;
}

const std::string& Student::getSurname() const
{
    return _surname;
}
// End of getters

// Setters
void Student::setId(size_t id)
{
    _id = id;
}

void Student::setGrades(std::vector<double> grades)
{
    _grades = std::move(grades);
}

void Student::setSurname(std::string surname)
{
    _surname = std::move(surname);
}
// End of setters
