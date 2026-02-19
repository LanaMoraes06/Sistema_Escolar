using namespace std;
#include "School.h"


void School::addStudent(Student s) {
    students.push_back(s);
    cout << "Estudante  " << s.getName() << " foi adicionado com sucesso!" << endl;
}

void School:: removeStudent(int id) {
    bool found = false;
    for (auto i = students.begin(); i != students.end(); ++i) {
        if (i->getId() == id) {
            students.erase(i);
            cout << "Estudante foi removido com sucesso." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "ERRO: Estudante nao encontrado." << endl;
    }
}

Student* School::getStudent(int id) {
    for (auto &s : students) {
        if (s.getId() == id) {
            return &s;
        }
    }
    return nullptr;
}

void School::listAllStudents() {
    cout << "\n--- LISTA DE ESTUDANTES ---" << endl;
    if (students.empty()) {
        cout << "Nao ha estudantes registrados." << endl;
    } else {
        for (auto &s : students) {
            s.displayInfo();
            cout << "-----------------------" << endl;
        }
    }
}



void School::addTeacher(Teacher t) {
    teachers.push_back(t);
    cout << "Professor adicionado com sucesso!" << endl;
}

void School::removeTeacher(int id) {
    bool found = false;
    for (auto i = teachers.begin(); i != teachers.end(); ++i) {
        if (i->getId() == id) {
            teachers.erase(i);
            cout << "Professor removido com sucesso." << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << ">> Error: Teacher not found." << endl;
}

Teacher* School::getTeacher(int id) {
    for (auto &t : teachers) {
        if (t.getId() == id) {
            return &t;
        }
    }
    return nullptr;
}

void School::listAllTeachers() {
    cout << "\n--- LISTA DE PROFESSORES ---" << endl;
    if (teachers.empty()) {
        cout << "Nao ha professores registrados." << endl;
    } else {
        for (auto &t : teachers) {
            t.displayInfo();
            cout << "-----------------------" << endl;
        }
    }
}
Director* School::getDirector(int id) {
    for (auto &d : directors) {
        if (d.getId() == id) {
            return &d;
        }
    }
    return nullptr;
}
void School::addDirector(Director d) {
    directors.push_back(d);
}