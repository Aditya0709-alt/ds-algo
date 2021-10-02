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

void findTriplet(int arr[], int n)
{

    sort(arr, n);

    for (int i = n - 1; i >= 0; i--)
    {
        int j = 0;
        int k = i - 1;

        while (j < k)
        {

            if (arr[i] == arr[j] + arr[k])
            {

                cout << "numbers are " << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                return;
            }

            else if (arr[i] > arr[j] + arr[k])
                j += 1;

            else
                k -= 1;
        }
    }

    cout << "No such triplet exists";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    findTriplet(arr, n);
    return 0;
}

