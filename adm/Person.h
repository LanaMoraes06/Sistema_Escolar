#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
public:
    int id;
    string name;
    int age;

public:
    Person(int id, string name, int age);

    int getId();
    string getName();
    int getAge();

    void setName(string name);
    void setAge(int age);
};

#endif