#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <vector>

#include "dirent.h"

using namespace std;
class Person
{
public:
    Person(string name, string surname, int age, int level)
    {
        _name = name;
        _surname = surname;
        _age = age;
        _level = level;
    }

    void show()
    {
        cout << "\nname: " << _name << " \nsurname: " << _surname << "\nage: " << _age << "\nlevel: " << _level << endl;
    }

    bool has_error()
    {
        if ((_name.size()==0) || (_surname.size()==0) || (_age == NULL) || (_level == NULL))
            return true;
        return false;
    }
private:
    string _name;
    string _surname;
    int _age;
    int _level;

};

class PersonRecord
{
public:
    PersonRecord(){}
    void add(Person* person)
    {
        if (person->has_error())
            throw runtime_error("person has an error in card");
        persons.push_back(person);
    }
    void show()
    {
        for (auto person: persons)
        {
            person->show();
        }
    }
    int size()
    {
        return persons.size();
    }
private:
    vector<Person*> persons;
};

class CsvParcer
{
private:
    vector<string> paths;
    PersonRecord* personRecord  = new PersonRecord();

public:
    void read_files(string path)
    {
        struct dirent *file;
        DIR *dp = opendir(path.c_str());
        if (dp)
        {
            while((file =readdir(dp))!=NULL)
            {
                string name = file->d_name;
                if (name.length() > 4 &&  name.substr(name.length()-4, 4) == ".csv")
                    paths.push_back(path + "/"+ name);
            }
        }
        else
            throw runtime_error("no such file or directory");

        closedir(dp);
        if (paths.empty())
            throw runtime_error("no files with .csv extension");
        else
        {
            for (auto path: paths)
                cout << " path " <<path <<endl;
        }
    }
    void parce_csv()
    {
        while(!paths.empty())
        {
            ifstream inputFile;
            string cur_path = paths.back();
            paths.pop_back();

            inputFile.open(cur_path);
            string line = "";

            cout << "curr path is " << cur_path <<endl;
            while(getline(inputFile, line))
            {
                string name;
                string surname;
                int age;
                int level;

                string tmpString;
                stringstream inputString(line);

                getline(inputString, name, ',');
                getline(inputString, surname, ',');

                getline(inputString, tmpString, ',');
                age = atoi(tmpString.c_str());

                getline(inputString, tmpString);
                level = atoi(tmpString.c_str());

                Person* person = new Person(name, surname, age, level);

                try
                {
                    personRecord->add(person);
                }
                catch(exception& ex)
                {
                    cout << ex.what() << endl;
                }


                line = "";

            }
        }
    }

    void show()
    {
        personRecord->show();
    }
};


int main()
{
    string path = "../csv_reader";
    CsvParcer* myParcer = new CsvParcer();
    try
    {
        myParcer->read_files(path);
        myParcer->parce_csv();
        myParcer->show();

    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    }
}
