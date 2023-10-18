#include <iostream>
using namespace std;
void print_spiral(int rows, int cols, int **arr)
{
        int startingRow = 0;
        int startingCol = 0;
        int endingCol = cols - 1;
        int endingRow = rows - 1;
        int count = 0;
        int total = rows * cols;
        // int arr[rows][cols];
        cout << "Printing in spiral form:" << endl;
        while (count < total)
        {
                // printing 1st row
                for (int i = startingCol; count < total && i <= endingCol; i++)
                {
                        cout << arr[startingRow][i] << " ";
                        count++;
                }
                startingRow++;

                // priinting last col
                for (int i = startingRow; count < total && i <= endingRow; i++)
                {
                        cout << arr[i][endingCol] << " ";
                        count++;
                }
                endingCol--;

                // printing last row
                for (int i = endingCol; count < total && i >= startingCol; i--)
                {
                        cout << arr[endingRow][i] << " ";
                        count++;
                }
                endingRow--;

                // printing first column
                for (int i = endingRow; count < total && i >= startingRow; i--)
                {
                        cout << arr[i][startingCol] << " ";
                        count++;
                }
                startingCol++;
        }
}
int main()
{
        int m, n;
        cout << "Rows: ";
        cin >> m;
        cout << "Columns: ";
        cin >> n;

        int **arr = new int *[m];
        for (int i = 0; i < m; i++)
        {
                arr[i] = new int[n];
        }

        cout << "ELEMENTS:" << endl;
        for (int i = 0; i < m; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        cin >> arr[i][j];
                }
        }
        print_spiral(m, n, arr);
        // int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
        // print_spiral(4, 4, arr);
}