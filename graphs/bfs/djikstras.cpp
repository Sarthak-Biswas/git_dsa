#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> g;

void djikstra_shortest(int u, int v)
{
    
}

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        int x,y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    int u,v;

    cin>>u>>v;

    djikstra_shortest(u,v);

    return 0;
}