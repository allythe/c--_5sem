#ifndef CSVPARCER_H
#define CSVPARCER_H

#include "personrecord.h"
#include "dirent.h"
#include <exception>
#include <fstream>
#include <sstream>

class CsvParcer
{
private:
    vector<string> paths;
    PersonRecord* personRecord  = new PersonRecord();

public:
    void read_files(string path);
    void parce_csv();
    void show();
};

#endif // CSVPARCER_H
