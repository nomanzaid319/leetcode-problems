// Write a program to solve the Activity Selection Problem using the Greedy Method.



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ActivitySelection(vector<int> start, vector<int> finish, int n)
{
    // Step 1: Sort activities according to finish time
    vector<pair<int, int>> activities;

    for (int i = 0; i < n; i++)
    {
        activities.push_back({finish[i], start[i]});
    }

    sort(activities.begin(), activities.end());

    // Step 2: Select the first activity
    int selected = 1;

    // Step 3: lastFinish = finish time of first activity
    int lastFinish = activities[0].first;

    cout << "Selected Activity: 1 ";

    // Step 4: Check remaining activities
    for (int i = 1; i < n; i++)
    {
        if (activities[i].second >= lastFinish)
        {
            selected++;

            lastFinish = activities[i].first;

            cout << i + 1 << " ";
        }
    }

    // Step 5: Return selected
    return selected;
}

int main()
{
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    vector<int> start(n), finish(n);

    cout << "Enter start times:\n";
    for (int i = 0; i < n; i++)
        cin >> start[i];

    cout << "Enter finish times:\n";
    for (int i = 0; i < n; i++)
        cin >> finish[i];

    int result = ActivitySelection(start, finish, n);

    cout << "\nMaximum number of selected activities = "
         << result;

    return 0;
}
