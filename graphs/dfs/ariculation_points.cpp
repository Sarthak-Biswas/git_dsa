#include <bits/stdc++.h>
using namespace std;

// Similar to the concept of bridges
// Only differences are:
// 1. Add points both for disc[u] < low[i] and disc[u] = low[i] and parent != -1
// 2. Special case when parent = -1, count number of out going edges, if > 1 then it is articulation point

int v = 0;
vector<int> graph[1000];
vector<bool> vis(100001, false);
vector<int> disc(100001, -1);
vector<int> low(100001, -1);

vector<bool> points(100010, false);

int counter = 0;

void articulation(int u, int parent)
{
    vis[u] = true;
    disc[u] = low[u] = ++counter;

    int outGoingEdges = 0;

    for(int i : graph[u])
    {
        if(i == parent)
            continue;
        
        if(vis[i])
        {
            low[u] = min(low[u], disc[i]);
        }
        else
        {
            ++outGoingEdges;

            articulation(i, u);

            low[u] = min(low[u], low[i]);

            if(disc[u] <= low[i] && parent != -1)
                points[u] = true;
        }
    }

    if(parent == -1 && outGoingEdges > 1)
        points[u] = true;
}

void take_input()
{
    int from, to;
    cin >> from >> to;

    graph[from].push_back(to);
    graph[to].push_back(from);
}

void printArticulation(int V)
{
    for(int i=0; i<V; i++)
    {
        if(points[i])
            cout << i << " ";
    }

    cout << endl;
}

int main()
{
    int e;

    cin >> v >> e;

    while(e--)
        take_input();

    for(int i=0; i<v; i++)
        articulation(i, -1);

    cout<< "\nArticulation Points:" << endl;
    printArticulation(v);
}