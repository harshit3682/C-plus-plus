#include <iostream>
using namespace std;

int printrowsum(int **arr, int row, int col)
{
    cout << endl;
    cout << "Row sum is : ";
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << sum << " ";
    }
}

int printcolsum(int **arr, int row, int col)
{
    cout << endl;
    cout << endl;
    cout << "Column sum is : ";
    for (int j = 0; j < col; j++)
    {
        int sum1 = 0;
        for (int i = 0; i < row; i++)
        {
            sum1 = sum1 + arr[i][j];
        }
        cout << sum1 << " ";
    }
}

int printarray(int **arr, int row, int col)
{
    cout << "Printing array : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int m, n, row, col;
    cout << "Enter row size: ";
    cin >> m;
    cout << "Enter column size: ";
    cin >> n;

    //  int arr[m][n];
    int **arr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }

    cout << "Input elements : ";
    for (row = 0; row < m; row++)
    {
        for (col = 0; col < n; col++)
        {
            cin >> arr[row][col];
        }
    }

    printarray(arr, m, n);
    printrowsum(arr, m, n);
    printcolsum(arr, m, n);

    // int arr[3][3];
    // cout << "Input elements :"
    //      << " , ";
    // for (row = 0; row < 3; row++)
    // {
    //     for (col = 0; col < 3; col++)
    //     {
    //         cin >> arr[row][col];
    //     }
    // }

    // printarray(arr, 3, 3);
    // printrowsum(arr, 3, 3);
    // printcolsum(arr, 3, 3);
}