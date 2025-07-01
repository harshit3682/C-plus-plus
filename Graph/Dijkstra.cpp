#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void dijkstra(vector<vector<pii>> adjList, vector<int> &dist, int src)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq; // MIN HEAP...
    pq.push({0, src});                                 //{Weight to source,Source Node}
    dist[src] = 0;

    while (!pq.empty())
    {
        auto topp = pq.top();
        pq.pop();
        int nodeDist = topp.first;
        int node = topp.second;

        for (auto it : adjList[node])
        {
            if (nodeDist + it.second < dist[it.first])
            {
                dist[it.first] = nodeDist + it.second;
                pq.push({nodeDist + it.second, it.first});
            }
        }
    }
}
int main()
{
    int vertices = 5;
    // vector<vector<int>> edges{{0, 1, 5}, {0, 2, 8}, {1, 2, 9}, {1, 3, 2}, {2, 3, 6}};
    vector<vector<int>> edges{{0, 1, 7}, {0, 2, 1}, {0, 3, 2}, {1, 2, 3}, {1, 3, 5}, {1, 4, 1}, {3, 4, 7}};

    vector<vector<pii>> adjList(vertices);
    for (auto it : edges)
    {
        adjList[it[0]].push_back({it[1], it[2]});
        adjList[it[1]].push_back({it[0], it[2]});
    }

    vector<int> dist(vertices, INT_MAX);
    int src = 0;
    dijkstra(adjList, dist, src);

    for (auto it : dist)
    {
        cout << it << "     ";
    }
};
