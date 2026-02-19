using namespace std;
#include "Director.h"
#include <iostream>


Director::Director(int id, string name, int age, string jobTitle, double salary):Person(id, name, age) {
    this->jobTitle = jobTitle;
    this->salary = salary;
}

string Director::getJobTitle() {
    return this->jobTitle;
}

double Director::getSalary() {
    return this->salary;
}

void Director::setJobTitle(string jobTitle) {
    this->jobTitle = jobTitle;
}

void Director::setSalary(double salary) {
    this->salary = salary;
}
double Director::gratification() {
    double perc = 0.16;
    double bonusSalary = this->salary + (this->salary * perc);
    return bonusSalary;
}

double Director::taxation(double bonusSalary) {
    double perc = 0.30;
    return bonusSalary - (bonusSalary * perc);
}


void Director::displayInfo() {
    cout << "\n----------------------------" << endl;
    cout << "RA:      " << id << endl;
    cout << "Nome:    " << name << endl;
    cout << "Idade:     " << age << endl;
    cout << "Salario: " << salary << endl;
    cout << "Cargo: " << jobTitle << endl;
    cout << "Salario com gratificação: " << gratification() << endl;
    cout << "Salario com imposto: " << taxation(gratification()) << endl;
    cout << "----------------------------" << endl;
}
