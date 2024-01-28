#include <iostream>
#include <fstream>
#include "klass.h"

using namespace std;

int main() {
    // Создаем класс
    Class class7B("Иванова А.Н.", "7Б");

    // Добавляем учеников
    class7B.addStudent(Student("Иван", "Иванов", "Иванович", "7Б"));
    class7B.addStudent(Student("Петр", "Петров", "Петрович", "7Б"));
    class7B.addStudent(Student("Сергей", "Сергеев", "Сергеевич", "7Б"));

    // Добавляем оценки
    class7B.getStudents()[0].addGrade(5);
    class7B.getStudents()[0].addGrade(4);
    class7B.getStudents()[0].addGrade(3);
    class7B.getStudents()[1].addGrade(4);
    class7B.getStudents()[1].addGrade(5);
    class7B.getStudents()[1].addGrade(5);
    class7B.getStudents()[2].addGrade(5);
    class7B.getStudents()[2].addGrade(5);
    class7B.getStudents()[2].addGrade(5);

    // Выводим средний балл по классу
    cout << "Средний балл по классу: " << class7B.getAverageGrade() << endl;

    // Удаляем ученика
    class7B.deleteStudent(1);

    // Выводим средний балл по классу после удаления ученика
    cout << "Средний балл по классу после удаления ученика: " << class7B.getAverageGrade() << endl;

    return 0;
}