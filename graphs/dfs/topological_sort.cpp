#include <bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> g;
vector<bool> vis(1000, false);
vector<int> sorted;

void topsort(int u)
{
    if(!vis[u])
    {
        vis[u] = true;

        for(auto i : g[u])
            topsort(i);
        sorted.push_back(u);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

        int n;
        cin>>n;
        while(n--)
        {
            int x,y;

            cin>>x>>y;

            g[x].push_back(y);
        }

        for(auto i : g)
        {
            topsort(i.first);
        }

        for(auto i=sorted.rbegin();i!=sorted.rend();i++)
            cout<<*i<<" ";

    return 0;
}