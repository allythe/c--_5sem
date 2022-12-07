#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
    Person(string name, string surname, int age, int level);

    void show();
    bool has_error();
private:
    string _name;
    string _surname;
    int _age;
    int _level;

};

#endif // PERSON_H
