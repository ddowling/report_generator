#include "File.h"
#include <iostream>

using namespace std;
using namespace report_generator;

int main()
{
    string filename = "test_file.cpp";

    cout << "Filename " << filename << endl;
    cout << "Extension " << File::getExtension(filename) << endl;

    string contents = File::readToString(filename);

    cout << "Contents :" << endl;
    cout << contents << endl;
}
