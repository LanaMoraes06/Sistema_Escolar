#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(int id, string name, int age, double grade1, double grade2):Person(id, name, age) {
    this->grade1 = grade1;
    this->grade2 = grade2;
}

double Student::getGrade1() {
    return this->grade1;
}

double Student::getGrade2() {
    return this->grade2;
}

void Student::setGrade1(double grade1) {
    this->grade1 = grade1;
}

void Student::setGrade2(double grade2) {
    this->grade2 = grade2;
}

double Student::getAverage() {
    return (grade1 + grade2) / 2.0;
}

void Student::displayInfo() {
    cout << "\n----------------------------" << endl;
    cout << "RA:      " << id << endl;
    cout << "Nome:    " << name << endl;
    cout << "Idade:     " << age << endl;
    cout << "Nota 1: " << grade1 << endl;
    cout << "Nota 2: " << grade2 << endl;
    cout << "Media: " << getAverage() << endl;
    cout << "----------------------------" << endl;
}