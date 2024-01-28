#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Student {
public:
    Student(const string& firstName, const string& lastName, const string& patronymic, const string& className) :
        firstName(firstName), lastName(lastName), patronymic(patronymic), className(className) {}

    const string& getFirstName() const { return firstName; }
    void setFirstName(const string& firstName) { this->firstName = firstName; }

    const string& getLastName() const { return lastName; }
    void setLastName(const string& lastName) { this->lastName = lastName; }

    const string& getPatronymic() const { return patronymic; }
    void setPatronymic(const string& patronymic) { this->patronymic = patronymic; }

    const string& getClassName() const { return className; }
    void setClassName(const string& className) { this->className = className; }

    void addGrade(int grade);
    void deleteGrade(int index);
    void editGrade(int index, int newGrade);
    double getAverageGrade() const;

    const vector<int>& getGrades() const;
    void setGrades(const vector<int>& grades);

private:
    string firstName;
    string lastName;
    string patronymic;
    string className;
    vector<int> grades;
};

class Class {
public:
    Class(const string& teacherName, const string& className) :
        teacherName(teacherName), className(className), students(nullptr) {}

    ~Class();

    void addStudent(const Student& student);
    void deleteStudent(int index);
    void updateAverageGrade();
    double getAverageGrade() const;

    vector<Student> getStudents() const;

private:
    string teacherName;
    string className;
    vector<Student*> students;

    void setTeacherName(const string& teacherName);
    string getTeacherName() const;

    void setClassName(const string& className);
    string getClassName() const;
};

