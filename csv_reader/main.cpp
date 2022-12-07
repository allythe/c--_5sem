#include "person.h"
#include "personrecord.h"
#include "csvparcer.h"

using namespace std;

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
