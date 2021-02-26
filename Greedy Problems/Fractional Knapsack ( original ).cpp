#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int weight;
    int value;
};

//sorting on value/weight
bool compare(Item a, Item b)
{
    double ans1 = ((double)a.value / a.weight);
    double ans2 = ((double)b.value / b.weight);
    return ans1 > ans2;
}

double knapsack(Item *arr, int n, int w)
{
    int curr_w = 0;
    double val = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr_w + arr[i].weight <= w)
        {
            curr_w += arr[i].weight;
            val += arr[i].value;
        }
        else
        {
            int rem = w - curr_w;
            val += ((double)rem / arr[i].weight) * arr[i].value;
            curr_w = w;
            break;
        }
    }
    return val;
}

int main()
{
    int n, w;
    cin >> n;
    cin >> w;

    Item *arr = new Item[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }
    cout << knapsack(arr, n, w) << endl;
    return 0;
}
