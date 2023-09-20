#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num, rem, n = 0;
    float sum = 0.0;

    cout << "Enter an integer: ";
    cin >> n;

    num = n;
    int count = 0;

    while (n != 0)
    {
        n = n / 10;
        count++;
    }

    n = num;
    cout << "Digits : " << count << endl;
    while (num > 0)
    {
        rem = num % 10;
        sum += pow(rem, count);
        num = num / 10;
    }

    if ((int)sum == n)
        cout << n << " is an Armstrong number.";
    else
        cout << n << " is not an Armstrong number.";
    return 0;
}