#include "klass.h"

Student::Student(const string& firstName, const string& lastName, const string& patronymic, const string& className) :
    firstName(firstName), lastName(lastName), patronymic(patronymic), className(className) {}

void Student::addGrade(int grade) {
    grades.push_back(grade);
}

void Student::deleteGrade(int index) {
    grades.erase(grades.begin() + index);
}

void Student::editGrade(int index, int newGrade) {
    grades[index] = newGrade;
}

double Student::getAverageGrade() const {
    if (grades.empty()) {
        return 0.0;
    }

    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }

    return double(sum) / grades.size();
}

const vector<int>& Student::getGrades() const {
    return grades;
}

void Student::setGrades(const vector<int>& grades) {
    this->grades = grades;
}

Class::Class(const string& teacherName, const string& className) :
    teacherName(teacherName), className(className), students(nullptr) {}

Class::~Class() {
    if (students != nullptr) {
        for (Student* student : students) {
            delete student;
        }

        delete[] students;
    }
}

void Class::addStudent(const Student& student) {
    if (students == nullptr) {
        students = new Student * [1];
        students[0] = new Student(student);
    }
    else {
        Student** newStudents = new Student * [studentsSize + 1];
        for (int i = 0; i < studentsSize; i++) {
            newStudents[i] = students[i];
        }

        newStudents[studentsSize] = new Student(student);

        delete[] students;
        students = newStudents;
        studentsSize++;
    }
}

void Class::deleteStudent(int index) {
    if (students == nullptr) {
        return;
    }

    if (index < 0 || index >= studentsSize) {
        return;
    }

    delete students[index];

    for (int i = index + 1; i < studentsSize; i++) {
        students[i - 1] = students[i];
    }

    studentsSize--;

    if (studentsSize == 0) {
        delete[] students;
        students = nullptr;
    }
}

void Class::updateAverageGrade() {
    if (students == nullptr) {
        return;
    }

    double sum = 0.0;
    for (Student* student : students) {
        sum += student->getAverageGrade();
    }

    averageGrade = sum / studentsSize;
}

double Class::getAverageGrade() const {
    return averageGrade;
}

vector<Student> Class::getStudents() const {
    vector<Student> students;
    for (Student* student : this->students) {
        students.push_back(*student);
    }

    return students;
}

void Class::setTeacherName(const string& teacherName) {
    this->teacherName = teacherName;
}

string Class::getTeacherName() const {
    return teacherName;
}

void Class::setClassName(const string& className) {
    this->className = className;
}

string Class::getClassName() const {
    return className;
}

