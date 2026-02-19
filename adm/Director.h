#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Person.h"
#include <string>
class Director : public Person {
private:
    string jobTitle;
    double salary;

public:
    Director(int id, string name, int age, string jobTitle, double salary);
    
    string getJobTitle();
    double getSalary();
    void setJobTitle(string jobTitle);
    void setSalary(double salary);

    double gratification();
    double taxation(double salarioGratificado);
    void displayInfo();
};

#endif