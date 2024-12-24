#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

int main() {
    string dirpath = "shiv";               //definig the dirctory path

    if (fs::exists(dirpath) && fs::is_directory(dirpath)) {   //cheaking the file is already exit?
        cout << "The directory exists" << endl;
    } else {
        if (fs::create_directory(dirpath)) {       //if not then create directory
            cout << "Directory created" << endl;
        } else {
            cout << "Failed to create the directory" << endl;
        }
    }

    return 0;
}
