#ifndef ALUNO_H
#define ALUNO_H

#include "Person.h"

class Student : public Person {
private:
    double grade1;
    double grade2;

public:
    Student(int id, string name, int age, double grade1, double grade2);

    double getGrade1();
    double getGrade2();
    void setGrade1(double grade1);
    void setGrade2(double grade2);

    double getAverage();
    void displayInfo();
};

#endif