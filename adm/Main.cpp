#include <iostream>
#include <limits>
using namespace std;
#include "Director.h"
#include "School.h"
#include "Student.h"
#include "Teacher.h"


School school;

// Protótipos
void studentMenu();
void teacherMenu();
void directorMenu();

int main() {
    // Dados teste
    school.addTeacher(Teacher(100, "Almir", 33, "POO", 5000));
    school.addStudent(Student(1, "Lana", 19, 9, 9));
    school.addDirector(Director(110, "Begosso", 40, "Coordenador", 9000));

    int mainChoice = 0;
    while (mainChoice != 4) {
        cout << "\n-_-_-_-_- SISTEMA DE GESTAO ESCOLAR -_-_-_-_-" << endl;
        cout << "1. Area do Aluno" << endl;
        cout << "2. Area do Professor" << endl;
        cout << "3. Area do Diretor" << endl;
        cout << "4. Sair" << endl;
        cout << ">> Selecione uma opcao: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                studentMenu();
                break;
            case 2:
                teacherMenu();
                break;
            case 3:
                directorMenu();
                break;
            case 4:
                cout << "Saindo do sistema..." << endl;
                break;
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
    }
    return 0;
}


void studentMenu() {
    int id;
    cout << "\n-_-_-_-_- AREA DO ALUNO -_-_-_-_-\n";
    cout << "Digite seu RA: ";
    cin >> id;

    Student* s = school.getStudent(id);

    if (s != nullptr) {
        cout << "Bem-vindo(a), " << s->getName() << "!" << endl;
        s->displayInfo();
    } else {
        cout << "\nErro: Aluno nao encontrado no sistema." << endl;
    }
}

void teacherMenu() {
    int idLogin, typedPassword;
    const int PASSWORD = 1234;

    cout << "\n---------- LOGIN DO PROFESSOR ----------\n";
    cout << "ID do Professor: ";
    cin >> idLogin;

    Teacher* loggedTeacher = school.getTeacher(idLogin);

    if (loggedTeacher == nullptr) {
        cout << "Erro: ID do Professor nao encontrado." << endl;
        return; // Sai da função teacherMenu e volta pro main
    }

    cout << "Senha: ";
    cin >> typedPassword;

    if (typedPassword != PASSWORD) {
        cout << "\nSenha incorreta!" << endl;
        return;
    }

    int teacherChoice = 0;
    while (teacherChoice != 6) { // 6 é Sair
        cout << "\n-_-_-_-_- PAINEL: " << loggedTeacher->getName() << " ---";
        cout << "\n1 - Meus Dados";
        cout << "\n2 - Consultar Aluno (por ID)";
        cout << "\n3 - Listar TODOS os Alunos";
        cout << "\n4 - Cadastrar Novo Aluno";
        cout << "\n5 - Remover Aluno";
        cout << "\n6 - Sair (Logout)";
        cout << "\n>> Opcao: ";
        cin >> teacherChoice;

        switch (teacherChoice) {
            case 1:
                loggedTeacher->displayInfo();
                break;
            case 2: {
                int searchId;
                cout << "Digite o ID do aluno para buscar: ";
                cin >> searchId;
                Student* stud = school.getStudent(searchId);
                if (stud != nullptr) {
                    stud->displayInfo();
                } else {
                    cout << "Aluno nao encontrado!" << endl;
                }
                break;
            }
            case 3:
                school.listAllStudents();
                break;
            case 4: {
                string name;
                int id, age;
                double grade1, grade2;

                cout << "--- Cadastro de Novo Aluno ---" << endl;
                cout << "ID (RA): "; cin >> id;
                cin.ignore(); // Limpa buffer
                cout << "Nome: "; getline(cin, name);
                cout << "Idade: "; cin >> age;
                cout << "Nota 1: "; cin >> grade1;
                cout << "Nota 2: "; cin >> grade2;

                Student newStudent(id, name, age, grade1, grade2);
                school.addStudent(newStudent);
                break;
            }
            case 5: {
                int deleteId;
                cout << "Digite o ID do aluno para remover: ";
                cin >> deleteId;
                school.removeStudent(deleteId);
                break;
            }
            case 6:
                cout << "Fazendo logout..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    }
}

void directorMenu() {
    int idLogin, typedPassword;
    const int PASSWORD = 4321;

    cout << "\n-_-_-_-_- LOGIN DO DIRETOR -_-_-_-_-\n";
    cout << "ID do Diretor: ";
    cin >> idLogin;

    Director* loggedDirector = school.getDirector(idLogin);

    if (loggedDirector == nullptr) {
        cout << "Erro: ID do Diretor nao encontrado." << endl;
        return;
    }

    cout << "Senha: ";
    cin >> typedPassword;

    if (typedPassword != PASSWORD) {
        cout << "\nSenha incorreta!" << endl;
        return;
    }

    int directorChoice = 0;
    // CORREÇÃO AQUI: O loop vai até 10, que é o Sair
    while (directorChoice != 10) {
        cout << "\n-_-_-_-_- PAINEL: " << loggedDirector->getName() << " ---";
        cout << "\n1 - Meus Dados";
        cout << "\n2 - Consultar Aluno (por ID)";
        cout << "\n3 - Listar TODOS os Alunos";
        cout << "\n4 - Cadastrar Novo Aluno";
        cout << "\n5 - Remover Aluno";
        cout << "\n6 - Consultar Professor (por ID)";
        cout << "\n7 - Listar TODOS os Professores";
        cout << "\n8 - Cadastrar Novo Professor";
        cout << "\n9 - Remover Professor";
        cout << "\n10 - Sair (Logout)";
        cout << "\n>> Opcao: ";
        cin >> directorChoice;

        switch (directorChoice) {
            case 1:
                loggedDirector->displayInfo();
                break;
            case 2: {
                int searchId;
                cout << "Digite o ID do aluno para buscar: ";
                cin >> searchId;
                Student* stud = school.getStudent(searchId);
                if (stud != nullptr) stud->displayInfo();
                else cout << "Aluno nao encontrado!" << endl;
                break;
            }
            case 3:
                school.listAllStudents();
                break;
            case 4: {
                string name;
                int id, age;
                double grade1, grade2;
                cout << "--- Cadastro de Novo Aluno ---" << endl;
                cout << "ID (RA): "; cin >> id;
                cin.ignore();
                cout << "Nome: "; getline(cin, name);
                cout << "Idade: "; cin >> age;
                cout << "Nota 1: "; cin >> grade1;
                cout << "Nota 2: "; cin >> grade2;
                school.addStudent(Student(id, name, age, grade1, grade2));
                break;
            }
            case 5: {
                int deleteId;
                school.listAllStudents();
                cout << "Digite o ID do aluno para remover: ";
                cin >> deleteId;
                school.removeStudent(deleteId);
                break;
            }
            case 6: {
                int searchId;
                cout << "Digite o ID do professor para buscar: ";
                cin >> searchId;
                Teacher* teac = school.getTeacher(searchId);
                if (teac != nullptr) teac->displayInfo();
                else cout << "Professor nao encontrado!" << endl;
                break;
            }
            case 7:
                school.listAllTeachers();
                break;
            case 8: {
                string name, specialty;
                int id, age;
                double salary;
                cout << "--- Cadastro de Novo Professor ---" << endl;
                cout << "ID (RA): "; cin >> id;
                cin.ignore();
                cout << "Nome: "; getline(cin, name);
                cout << "Idade: "; cin >> age;
                cin.ignore();
                cout << "Especialidade: "; getline(cin, specialty);
                cout << "Salario: "; cin >> salary;
                school.addTeacher(Teacher(id, name, age, specialty, salary));
                break;
            }
            case 9: {
                int deleteId;
                school.listAllTeachers();
                cout << "Digite o ID do professor para remover: ";
                cin >> deleteId;
                school.removeTeacher(deleteId);
                break;
            }
            case 10:
                cout << "Fazendo logout..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    }
}