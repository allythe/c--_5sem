#ifndef PERSONRECORD_H
#define PERSONRECORD_H

#include "person.h"
#include <vector>

class PersonRecord
{
public:
    PersonRecord(){}
    void add(Person* person);
    void show();
    int size();
private:
    vector<Person*> persons;
};

#endif // PERSONRECORD_H
