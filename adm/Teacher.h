#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

class Teacher : public Person {
private:
    string specialty;
    double salary;

public:
    Teacher(int id, string name, int age, string specialty, double salary);
    
    string getSpecialty();
    double getSalary();
    void setSpecialty(string specialty);
    void setSalary(double salary);

    double gratification();
    double taxation();
    void displayInfo();
};

#endif