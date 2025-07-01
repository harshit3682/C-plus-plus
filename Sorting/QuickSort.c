#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high)
{
        int pivot = arr[low];
        int cnt = 0;
        // Finding No. smaller or equal to pivot:
        for (int i = low + 1; i <= high; i++)
        {
                if (arr[i] <= pivot)
                {
                        cnt++;
                }
        }
        // Placing pivot in its perfect place:
        int pivotIndex = low + cnt;
        int temp = arr[pivotIndex];
        arr[pivotIndex] = pivot;
        arr[low] = temp;

        int i = low;
        int j = high;
        while (i < pivotIndex && j > pivotIndex)
        {
                while (arr[i] <= pivot)
                {
                        i++;
                }
                while (arr[j] > pivot)
                {
                        j--;
                }
                if (i < pivotIndex && j > pivotIndex)
                {
                        int temp1 = arr[i];
                        arr[i++] = arr[j];
                        arr[j--] = temp1;
                }
        }
        return pivotIndex;
}
void quick_sort(int *arr, int low, int high)
{
        if (low >= high)
        {
                return;
        }
        int p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
}
int main()
{
        int n;
        printf("\nEnter array size: ");
        scanf("%d", &n);
        int *arr = (int *)malloc(n * sizeof(int));
        printf("Enter the elements:\n");
        for (int i = 0; i < n; i++)
        {
                printf("%d element: ", i + 1);
                scanf("%d", &arr[i]);
        }
        quick_sort(arr, 0, n - 1);
        printf("\n Elements in Main function: ");
        for (int i = 0; i < n; i++)
        {
                printf("%d ", arr[i]);
        }
}