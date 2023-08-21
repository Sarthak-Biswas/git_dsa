#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
vector<bool> vis(100000, false);
vector<int> disc(100000, -1);
vector<int> low(100000, -1);

int counter = 0;
int SCC = 0;

vector<int> Global_Stack;
vector<bool> Global_Stack_Hash(1e5+1, false);

void addEdge(int from, int to)
{
    graph[from].push_back(to);
}

void tarjans_DFS(int u)
{
    vis[u] = true;
    low[u] = disc[u] = ++counter;
    Global_Stack.push_back(u);
    Global_Stack_Hash[u] = true;

    for(int i : graph[u])
    {
        if(!vis[i])
        {
            tarjans_DFS(i);
            low[u] = min(low[u], low[i]);
        }
        if(Global_Stack_Hash[i])
            low[u] = min(low[u], disc[i]);
    }

    if(disc[u] == low[u])
    {
        while(Global_Stack.back() != u)
        {
            int i = Global_Stack.back();
            Global_Stack.pop_back();
            Global_Stack_Hash[i] = false;
        }
        Global_Stack.pop_back();
        Global_Stack_Hash[u] = false;

        ++SCC;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    while(e--)
    {
        int from, to;
        cin >> from >> to;

        addEdge(from, to);
    }

    for(int i=0; i<v; i++)
    {
        if(vis[i])
            continue;
        tarjans_DFS(i);
    }

    cout << "\nTotal SCC = " << SCC << endl;

    return 0;
}