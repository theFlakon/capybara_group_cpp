#include <numeric>
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

    double calcAvgGrade() const
    {
        double gradesSum = std::accumulate(_grades.begin(), _grades.end(), 0);
        auto gradesCnt = static_cast<double>(_grades.size());

        return gradesSum / gradesCnt;
    }

    // Getters
    size_t getId() const
    {
        return _id;
    }

    const std::vector<double>& getStudentsVec() const
    {
        return _grades;
    }

    const std::string& getSurname() const
    {
        return _surname;
    }
    // End of getters

    // Setters
    void setId(size_t id)
    {
        _id = id;
    }

    void setGrades(std::vector<double> grades)
    {
        _grades = std::move(grades);
    }

    void setSurname(std::string surname)
    {
        _surname = std::move(surname);
    }
    // End of setters
};
