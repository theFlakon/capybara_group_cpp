#include <algorithm>

double getAverageMaxStudentsGrade(const Group& group) {
    double maxGrade = 0;

    for(int i = 0; i < group.getLength(); i++) {
        maxGrade = std::max(group.studentsList[i].calcAvgGrade(), maxGrade);
    }

    return maxGrade
}