#include <bits/stdc++.h>
using namespace std;

// When disc[u] <= low[i] ,the edge (u, i) is a bridge

int v = 0;
vector<int> graph[1000];
vector<bool> vis(100001, false);
vector<int> disc(100001, -1);
vector<int> low(100001, -1);

vector<pair<int, int>> bridge;

int counter = 0;

void bridges(int u, int parent)
{
    vis[u] = true;
    disc[u] = low[u] = ++counter;

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
            bridges(i, u);

            if(low[i] <= disc[u])
                low[u] = min(low[i], low[u]);
            else
                bridge.push_back(make_pair(u, i));
        }
    }
}

void take_input()
{
    int from, to;
    cin >> from >> to;

    graph[from].push_back(to);
    graph[to].push_back(from);
}

void printBridges()
{
    for(auto i : bridge)
        cout << i.first << " " << i.second << endl;
}

int main()
{
    int e;

    cin >> v >> e;

    while(e--)
        take_input();

    for(int i=0; i<v; i++)
        bridges(i, -1);

    cout<< "\nBridges:" << endl;
    printBridges();
}