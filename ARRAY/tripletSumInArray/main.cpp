#include <iostream>
using namespace std;

int tripletSum(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == x)
                {
                    return 1;
                }
            }
        }
    }
    return -1;
}

int main()
{

    int n, x;
    cin >> n;
    int arr[n];
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Result -> ";
    cout << tripletSum(arr, n, x) << endl;
    return 0;
}