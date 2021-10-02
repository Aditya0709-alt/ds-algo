#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    int i, key, j;
    for (int i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void triplet(int arr[], int n)
{
    int i;
    if(n == 0)
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] == arr[k])
                {
                    int temp[] = {arr[i], arr[j], arr[k]};
                    for (int i = 0; i < 3; i++)
                    {
                        cout << temp[i] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
}

int main()
{
    int arr[] = {12, 78, 1, 6, 90, 3, 11, 13, 61, 79};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n);
    triplet(arr, n);
    cout << endl;
    return 0;
}
