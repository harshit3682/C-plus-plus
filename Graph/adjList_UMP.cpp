#include <iostream>
using namespace std;
#include <list>
#include <unordered_map>

class graph
{
public:
        unordered_map<int, list<int>> adjList;
        void addEdge(int s, int e, int direction)
        {
                // direction==0 --> undirected graph
                // direction==1 --> directed graph
                adjList[s].push_back(e);
                if (direction == 0)
                {
                        adjList[e].push_back(s);
                }
        }

        void print()
        {
                cout << endl;
                for (auto i : adjList)
                {
                        cout << i.first << " --> ";
                        for (auto j : i.second)
                        {
                                cout << j << " , ";
                        }
                        cout << endl;
                }
        }
};

int main()
{
        graph g;
        int m, n;
        cout << "Enter no. of nodes: ";
        cin >> m;
        cout << " Enter no. of edges: ";
        cin >> n;
        cout << "Starting and Ending edges:" << endl;
        for (int i = 0; i < n; i++)
        {
                int s, e;
                cin >> s >> e;
                g.addEdge(s, e, 0);
        }
        g.print();
}