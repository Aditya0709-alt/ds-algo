#include <iostream>
using namespace std;

void swapNum(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void zeroEnd(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swapNum(arr, i, j);
            j++;
        }
    }
}

int main()
{
    int arr[] = {1, 0, 9, 0, 8, 7, 0, 0, 3, 4, 0, 0, 1, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    zeroEnd(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}