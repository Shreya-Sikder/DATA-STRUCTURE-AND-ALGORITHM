#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool cmp(struct Item a,struct Item b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;

}


double fractionalKnapsack( vector<Item> &items, int n,int capacity)
{
    sort(items.begin(),items.end(),cmp);
    double profit=0.0;
    int remaining_weight=capacity;
    for(int i=0; i<n; i++)
    {
        if (remaining_weight==0) break;

        if(items[i].weight<=remaining_weight)
        {
            profit+=items[i].value;
            remaining_weight-=items[i].weight;
        }
        else
        {

            profit+=(double)(items[i].value*remaining_weight)/items[i].weight;
            break;
        }
    }
    return profit;
}

int main()
{
    cout << "Number of items: ";
    int n;
    cin >> n;

    vector<Item> items(n);
    cout << "Enter value and weight for each item:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> items[i].value >> items[i].weight;
    }

    int capacity;
    cout << "Maximum capacity: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(items, n, capacity);
    cout << "Maximum value in knapsack: " << maxValue << endl;

    return 0;
}
