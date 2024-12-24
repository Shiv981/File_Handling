#include <iostream>
#include <filesystem>
#include <chrono>
using namespace std;
namespace fs = std::filesystem;

void removeoldestfile(fs::path& directoryPath) {
    fs::path oldestFile;
    std::time_t oldestTime = std::time(nullptr);

    for (const auto& x : fs::directory_iterator(directoryPath)) {
        if (fs::is_regular_file(x)) {
            std::time_t fileTime = fs::last_write_time(x).time_since_epoch().count();

            if (fileTime < oldestTime) {
                oldestTime = fileTime;
                oldestFile = x;
            }
        }
    }

        fs::remove(oldestFile);
}

uintmax_t getSize(const fs::path& directoryPath) {
    if (fs::is_directory(directoryPath)) {
        uintmax_t size = 0;

        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            if (fs::is_regular_file(entry)) {
                size += fs::file_size(entry);
            }
        }

        return size / 1000;  // Convert to kilobytes
    }

    return 0;
}

int main() {
    fs::path pathToDir("shiv");

    uintmax_t a = getSize(pathToDir);
    if (a > 50) {
        removeoldestfile(pathToDir);
        cout<<"the oldest file is deleted"<<endl;
    }
  else{
     cout<<"memory occupied is less then 50 KB"<<endl;
}
}
