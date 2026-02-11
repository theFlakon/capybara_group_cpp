#include <cctype>
#include <cstddef>

double getAverageGroupGrade(const Group& group) {
    double averageGroupScore = 0;
    size_t studentsLength = group.getLength();

    for(int i = 0; i < studentsLength; i++) {
        averageGroupScore += group.studentsList[i].calcAvgGrade();
    }

    return averageGroupScore / studentsLength;
}