#include <iostream>
using namespace std;

void arrayRotate(int arr[], int arrSize, int pos)
{
    int temp[pos];
    for (int i = 0; i < pos; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = pos; i < arrSize; i++)
    {
        arr[i - pos] = arr[i];
    }

    for (int i = 0; i < pos; i++)
    {
        arr[arrSize - pos + i] = temp[i];
    }
}

int main()
{
    int arrSize, pos;
    cout << "Enter the number of elements in array: ";
    cin >> arrSize;
    int arr[arrSize];
    cout << "Enter " << arrSize << " elements of array: ";
    for (int i = 0; i < arrSize; i++)
        cin >> arr[i];
    cout << "Enter the number of positions to rotate: ";
    cin >> pos;
    arrayRotate(arr, arrSize, pos);
    cout << "Modified array: ";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
