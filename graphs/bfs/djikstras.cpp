#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> g;

void djikstra_shortest(int u, int v)
{

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

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