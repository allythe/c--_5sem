#include "person.h"

Person::Person(string name, string surname, int age, int level)
{
    _name = name;
    _surname = surname;
    _age = age;
    _level = level;
}

void Person::show()
{
    cout << "\nname: " << _name << " \nsurname: " << _surname << "\nage: " << _age << "\nlevel: " << _level << endl;
}

bool  Person::has_error()
{
    if ((_name.size()==0) || (_surname.size()==0) || (_age == NULL) || (_level == NULL))
        return true;
    return false;
}
