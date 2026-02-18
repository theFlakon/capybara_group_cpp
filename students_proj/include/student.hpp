#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <cstddef>
#include <string>
#include <vector>

class Student
{
private:
    size_t _id;
    std::vector<double> _grades;
    std::string _surname;

public:
    Student(size_t id, std::vector<double> grades, std::string surname);
    Student();
    double calcAvgGrade() const;

    size_t getId() const;
    const std::vector<double>& getStudentsVec() const;
    const std::string& getSurname() const;

    void setId(size_t id);
    void setGrades(std::vector<double> grades);
    void setSurname(std::string surname);
};

#endif
