#include <bits/stdc++.h>
using namespace std;

#define debugValue(x) cerr << x << endl;
#define debug(x) cerr << #x << " = " << x << endl;
#define dbgline cerr << endl;

unordered_map<int, vector<int>> g;
vector<int> vis(1000,false);

void bfs(int u)
{
    list<int> q;
    q.push_back(u);
    vis[u] = true;

    while(!q.empty())
    {
        int v = q.front();
        q.pop_front();

        cout<<v<<", ";

        for(auto i : g[v])
        {
            if(!vis[i])
            {
                q.push_back(i);
                vis[i] = true;
            }
        }
    }
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

        debugValue(n);
        debug(x);
        debug(y);
        dbgline;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(g.begin()->first);
    return 0;
}