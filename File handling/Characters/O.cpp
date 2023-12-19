#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{

        char ch;
        ifstream infile("abc1.txt");
        while (!infile.eof())
        {
                infile.get(ch);
                cout << ch;
        }
        cout << endl;

        // Pointer to streambuf class
        // ifstream infile("abc1.txt");
        // cout << infile.rdbuf();
        // cout << endl;
        return 0;
}
