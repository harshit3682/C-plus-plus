#include <stdio.h>
#include <stdlib.h>
void merge(int *arr, int low, int high)
{
        int mid = (low + high) / 2;
        int len1 = mid - low + 1;
        int len2 = high - mid;
        int *firstArr = (int *)malloc(len1 * sizeof(int));
        int *secondArr = (int *)malloc(len2 * sizeof(int));

        int k = low;
        for (int i = 0; i < len1; i++)
        {
                firstArr[i] = arr[k++];
        }
        k = mid + 1;
        for (int i = 0; i < len2; i++)
        {
                secondArr[i] = arr[k++];
        }

        int Index1 = 0, Index2 = 0;
        k = low;
        while (Index1 < len1 && Index2 < len2)
        {
                if (firstArr[Index1] < secondArr[Index2])
                {
                        arr[k++] = firstArr[Index1++];
                }
                else //(secondArr[Index2] < firstArr[Index1])
                {
                        arr[k++] = secondArr[Index2++];
                }
        }
        while (Index1 < len1)
        {
                arr[k++] = firstArr[Index1++];
        }
        while (Index2 < len2)
        {
                arr[k++] = secondArr[Index2++];
        }
}

void merge_sort(int *arr, int low, int high)
{
        if (low >= high)
        {
                return;
        }
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, high);
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
                //  printf("%d element: ", i + 1);
                scanf("%d", &arr[i]);
        }
        merge_sort(arr, 0, n - 1);

        printf("\n Elements in Main function: ");
        for (int i = 0; i < n; i++)
        {
                printf("%d ", arr[i]);
        } // 3 7 18 21 11 9 2 1 19
}