#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
        char ch = 'A';
        int p = 45;
        double q = 4.87;
        string str1 = "harshit";
        string str2 = "rautela";

        ofstream outfile("abc.txt");
        outfile << ch << ' ' << p << " " << q << str1 << " " << str2;
        cout << "file written" << endl;
        cout << endl;

        // String with embedded blanks:
        outfile << "India is democratic country." << endl;
        outfile << "India is diversified in culture which is beauty of it." << endl;
        outfile << "India has largest population over the globe." << endl;
        outfile << "India has 5th largest economy " << endl;

        // Read file:
        ifstream infile("abc.txt");
        infile >> ch >> p >> q >> str1 >> str2;
        cout << ch << endl;
        cout << p << endl;
        cout << q << endl;
        cout << str1 << endl;
        cout << str2 << endl;

        // Read to EOF:
        char buffer[100];
        while (!infile.eof())
        {
                infile.getline(buffer, 100);
                cout << buffer << endl;
        }
        return 0;
}