#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int key, int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else
        {
            if (key < arr[mid])
            {
                return binarySearch(arr, key, 0, mid - 1);
            }
            else
            {
                return binarySearch(arr, key, mid + 1, end);
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "enter key" << endl;
    cin >> key;
    int ans = binarySearch(arr, key, 0, n - 1);
    if (ans == -1)
    {
        cout << "element not found" << endl;
    }
    else
    {
        cout << "element found at : " << ans << endl;
    }
    return 0;
}
