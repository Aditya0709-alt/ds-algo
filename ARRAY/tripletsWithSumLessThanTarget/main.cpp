#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int countTriplets(int arr[], int n, int sum)
{
    sort(arr, n);
    int res = 0;
    for (int i = 0; i < n - 2; i++)
    {

        int j = i + 1, k = n - 1;

        while (j < k)
        {
            if (arr[i] + arr[j] + arr[k] >= sum)
            {
                k--;
            }
            res += (k - j);
            j++;
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int a = countTriplets(arr, n, 6);
    cout << a << endl;

    return 0;
}