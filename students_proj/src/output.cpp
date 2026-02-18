#include "group.cpp"
#include <fstream>

bool outputGroupInfo(Group group) {
    std::ofstream outputFile("group.txt");
    
    if (!outputFile.is_open()) {
        return false;
    }
    
    std::vector<Student> topStudents = group.getTopThreeStudents();
    
    outputFile << "Информация по группе" << std::endl;
    outputFile << std::endl;
    
    outputFile << "Топ 3 студента (имя/средняя оценка):" << std::endl;
    for (int i = 0; i < 3 && i < group.getStudentCount(); i++) {
        outputFile  << "#" << i + 1 << " " << topStudents[i].getSurname() << " " 
        << topStudents[i].calcAvgGrade() << std::endl;
    }
    outputFile << std::endl;
    
    outputFile << "Статистика группы:" << std::endl;
    outputFile << "Общее кол-во студентов: " << group.getStudentCount() << std::endl;
    outputFile << "Средняя оценка группы: " << group.getAverageGroupGrade() << std::endl;
    outputFile << "Максимальная средняя оценка группы: " << group.getAverageMaxStudentsGrade() << std::endl;
    
    outputFile.close();
    
    return true;
}