#ifndef GROUP_HPP
#define GROUP_HPP

#include "student.hpp"
#include <vector>

class Group
{
private:
    std::vector<Student> _studentsList;

public:
    std::vector<Student> getTopThreeStudents();
    void addStudent(const Student& student);
    int getStudentCount();
    double getAverageGroupGrade();
    double getAverageMaxStudentsGrade();
};

bool makeGroup(std::ifstream& inputFile, Group& rsGroup);

#endif
