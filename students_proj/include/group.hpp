#ifndef GROUP_HPP
#define GROUP_HPP

#include <vector>
#include "student.hpp"

class Group {
private:
    std::vector<Student> _studentsList;

public:
    std::vector<Student> getTopThreeStudents();
    void addStudent(const Student& student);
    int getStudentCount();
    double getAverageGroupGrade();
    double getAverageMaxStudentsGrade();
};

#endif