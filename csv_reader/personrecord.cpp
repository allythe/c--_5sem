#include "personrecord.h"

void PersonRecord::add(Person* person)
{
    if (person->has_error())
        throw runtime_error("person has an error in card");
    persons.push_back(person);
}
void PersonRecord::show()
{
    for (auto person: persons)
    {
        person->show();
    }
}

int PersonRecord::size()
{
    return persons.size();
}
