#include<iostream>
#include<filesystem>
using namespace std;
namespace fs=filesystem;
int main(){
    string dirpath="shiv";         //for removing the file give the file name
    if(fs::exists(dirpath) && fs::is_directory(dirpath)){        //istead of is_directory use is_regular_file
       fs::remove_all(dirpath);                                  //istead of remove_all use only remove  
       cout<<"directory removed successfully"<<endl;
}
   else{
        cout<<"directory doesnot exists"<<endl;
     }
}