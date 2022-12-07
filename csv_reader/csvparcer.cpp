#include "csvparcer.h"


void CsvParcer::read_files(string path)
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
void CsvParcer::parce_csv()
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

void CsvParcer::show()
{
    personRecord->show();
}
