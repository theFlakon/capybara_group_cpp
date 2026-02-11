#include <vector>
#include "student.cpp"

class Group {
private:
    std::vector<Student> _studentsList;

public:
    std::vector<Student> getTopThreeStudents() {
        std::vector<Student> topThree;
        topThree.push_back(_studentsList[0]);
        topThree.push_back(_studentsList[0]);
        topThree.push_back(_studentsList[0]);
        for(auto student : _studentsList) {
            if(student.calcAvgGrade() > topThree[0].calcAvgGrade()) {
                topThree[2] = topThree[1];
                topThree[1] = topThree[0];
                topThree[0] = student;
            }
            else if(student.calcAvgGrade() > topThree[1].calcAvgGrade()) {
                topThree[2] = topThree[1];
                topThree[1] = student;
            }
            else if(student.calcAvgGrade() > topThree[2].calcAvgGrade()) {
                topThree[2] = student;
            }
        }
        return topThree;
    }

    int getStudentCount() {
        return _studentsList.size();
    }
};