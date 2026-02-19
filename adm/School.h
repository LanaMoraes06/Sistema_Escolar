#ifndef SCHOOL_H
#define SCHOOL_H

#include <vector>
#include <iostream>

#include "Director.h"
#include "Student.h"
#include "Teacher.h"

class School {
private:
    //sempre usar  std:: no .h..
    std::vector<Student> students;
    std::vector<Teacher> teachers;
    std::vector<Director> directors;


public:
// operacoes  aluno
    void addStudent(Student s);
    void removeStudent(int id);
    Student* getStudent(int id);
    void listAllStudents();

    // operacoes professor
    void addTeacher(Teacher t);
    void removeTeacher(int id);
    Teacher* getTeacher(int id);
    void listAllTeachers();

    Director *getDirector(int id);
    void addDirector(Director t);

};

#endif // SCHOOL_H