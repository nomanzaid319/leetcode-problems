#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 99999;
void floyd( vector <vector<int>>& dest, int v)
{
    for(int k = 0; k < v; k++)
    {
        for(int i = 0; i < v; i++)
        {
            for(int j = 0; j < v; j++)
            {
                if(dest[i][k] != INF && dest[k][j] != INF)
                {
                    dest[i][j] = min(dest[i][j], dest[i][k] + dest[k][j]);
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:\n";

    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            if(dest[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << dest[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int v=5;
    
    vector<vector<int>> dest = {
        {0, 3, INF, 7, INF},
        {8, 0, 2, INF, INF},
        {5, INF, 0, 1, INF},
        {2, INF, INF, 0, 1},
        {INF, INF, INF, 2, 0}
    };

    floyd(dest, v);
    return 0;
}