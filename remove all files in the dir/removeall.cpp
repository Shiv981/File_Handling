#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

int main() {
    string dirpath = " ";

    if (fs::exists(dirpath) && fs::is_directory(dirpath)) {
        for (const auto& entry : fs::directory_iterator(dirpath)) {
            if (fs::is_regular_file(entry)) {
                if (fs::remove(entry)) {
                    cout << "File deleted: " << entry.path() << endl;
                } else {
                    cout << "Failed to delete file: " << entry.path() << endl;
                }
            }
        }
    } else {
        cout << "The directory does not exist" << endl;
    }

    return 0;
}
