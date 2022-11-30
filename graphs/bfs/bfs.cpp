#include <bits/stdc++.h>
using namespace std;

#define debugValue(x) cerr << x << endl;
#define debug(x) cerr << #x << " = " << x << endl;
#define dbgline cerr << endl;

unordered_map<int, vector<int>> g;

void bfs(int u)
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

        debugValue(n);
        debug(x);
        debug(y);
        dbgline;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(auto i : g)
    {
        cout<<i.first<<endl;
    }
    return 0;
}