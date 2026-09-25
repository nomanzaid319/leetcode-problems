#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int profit;
    double ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n, M;

    cout << "Enter number of items: ";
    cin >> n;

    Item item[n];

    cout << "Enter weight and profit of each item:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> item[i].weight >> item[i].profit;

        item[i].ratio =
            (double)item[i].profit / item[i].weight;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> M;

    // Sort according to Profit/Weight ratio
    sort(item, item + n, compare);

    double totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        if (M > 0 && item[i].weight <= M)
        {
            // Take complete item
            M = M - item[i].weight;
            totalProfit = totalProfit + item[i].profit;
        }
        else
        {
            // Take fractional part
            if (M > 0)
            {
                totalProfit = totalProfit +
                    item[i].profit *
                    ((double)M / item[i].weight);

                M = 0;
            }

            break;
        }
    }

    cout << "Maximum Profit = " << totalProfit << endl;

    return 0;
}