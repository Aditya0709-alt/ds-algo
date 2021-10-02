#include <iostream>
using namespace std;

int binarySearch(int arr[], int x, int s, int e)
{
    int mid = s + (e - s) / 2;
    if (e >= s)
    {

        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[mid] > x)
        {
            return binarySearch(arr, x, s, mid - 1);
        }

        return binarySearch(arr, x, mid + 1, e);
    }
    return mid;
}

int main()
{
    int arr[] = {1, 3, 11, 13, 56, 58};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << binarySearch(arr, 55, 0, n - 1) << endl;
    return 0;
}