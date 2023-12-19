#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
        string str = "Programming is going to be a lot of fun is myth."
                     "While it takes a lot of hard work and consistency.";

        ofstream outfile("abc1.txt");
        for (int i = 0; i < str.size(); i++)
        {
                outfile.put(str[i]);
        }
        cout << "FILE WRITTEN" << endl;

        outfile.seekp(0, std::ios::beg);
        char ch;
        ifstream infile("abc1.txt");
        while (!infile.eof())
        {
                infile.get(ch);
                cout << ch;
        }
        cout << endl;
}