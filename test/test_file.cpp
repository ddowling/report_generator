#include "File.h"
#include <iostream>

using namespace std;

int main()
{
    std::string filename = "test_file.cpp";

    cout << "Filename " << filename << endl;
    cout << "Extension " << File::getExtension(filename) << endl;

    std::string contents = File::readToString(filename);

    cout << "Contents :" << endl;
    cout << contents << endl;
}
