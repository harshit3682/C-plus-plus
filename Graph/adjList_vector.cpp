#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
using namespace std;

void create_adjList(vector<vector<int>> edges, vector<vector<int>> &adjList)
{
    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
}
int main()
{
    vector<vector<int>> edges{{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}};
    // int n = edges.size();
    vector<vector<int>> adjList(5);
    create_adjList(edges, adjList);

    cout << "u" << setw(4) << "v" << endl;
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << i << "   --> ";
        for (auto it : adjList[i])
        {
            cout << it << " , ";
        }
        cout << endl;
    }
}
