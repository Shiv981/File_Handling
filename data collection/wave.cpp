#include <iostream>
#include <cmath>
#include<fstream>
using namespace std;
int main()
{
    ofstream outfile;
    outfile.open("data.dat",ios::trunc | ios::out);
    for(int i=0;i<100;i++)
    {
        outfile <<i*1.75<<" "<<i*2.23<< "\n";
    }
    outfile.close();
    return 0;
}