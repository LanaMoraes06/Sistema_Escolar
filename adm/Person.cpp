
#include "Person.h"

Person::Person(int id, string name, int age) {
    this->id = id;
    this->name = name;
    this->age = age;
}

int Person::getId() {
    return this->id;
}

string Person::getName() {
    return this->name;
}

int Person::getAge() {
    return this->age;
}
void Person::setName(string name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}