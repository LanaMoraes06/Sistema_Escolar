#include "Teacher.h"
#include <iostream>

using namespace std;

Teacher::Teacher(int id, string name, int age, string specialty, double salary):Person(id, name, age) {
    this->specialty = specialty;
    this->salary = salary;
}

string Teacher::getSpecialty() {
    return this->specialty;
}

double Teacher::getSalary() {
    return this->salary;
}

void Teacher::setSpecialty(string specialty) {
    this->specialty = specialty;
}

void Teacher::setSalary(double salary) {
    this->salary = salary;
}
double Teacher::gratification() {
    double perc = 0.16;
    return this->salary + (this->salary * perc);
}

double Teacher::taxation() {
    double perc = 0.30;
    return this->salary - (this->salary * perc);
}


void Teacher::displayInfo() {
    cout << "\n----------------------------" << endl;
    cout << "RA:      " << id << endl;
    cout << "Nome:    " << name << endl;
    cout << "Idade:     " << age << endl;
    cout << "Salario: " << salary << endl;
    cout << "Especialidade: " << specialty << endl;
    cout << "Salario com gratificação: " << gratification() << endl;
    cout << "Salario com imposto: " << taxation() << endl;
    cout << "----------------------------" << endl;
}
