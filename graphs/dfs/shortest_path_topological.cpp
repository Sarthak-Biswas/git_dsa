#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long int ll;

/*********** FOR DEBUGGING **************/
#define debug(x) cerr << #x <<" = " ; _print(x) ; cerr << endl;

template<class T> void _print(T x) {
    cerr << x ;
}

template<class T> void _print(vector<T> v) {
    cerr << "[ ";
    for(auto i : v)
        cerr << i << " ";
    cerr << "]";
}

template<class X, class Y> void _print(map<X,Y> mp) {
    cerr << "[ ";
    for(auto i : mp)
        cerr << i.first << ":" << i.second << " ";
    cerr << "]";
}

template<class X, class Y> void _print(unordered_map<X,Y> ump) {
    cerr << "[ ";
    for(auto i : ump)
        cerr << i.first << ":" << i.second << " ";
    cerr << "]";
}
/*********** FOR DEBUGGING **************/

/****************** CODE DOWN BELOW ******************/

unordered_map<int, vector<vector<int>>> g;
vector<int> sorted;
vector<bool> vis(1000,false);
vector<int> dist(1000,INT_MAX);

void topsort(int u)
{
    if(!vis[u])
    {
        vis[u] = true;

        for(auto i : g[u])
            topsort(i[0]);
        sorted.push_back(u);
    }
}

void pathMaker(int u)
{
    for(auto i : g[u])
    {
        dist[i[0]] = min(dist[i[0]], dist[u] + i[1]);
    }
}

int find_shortest(int s, int d)
{
    int pos = 0;
    dist[s] = 0;
    int path = INT_MAX;

    for(int i = sorted.size()-1; i>=0; i--)
    {
        if(sorted[i] == s)
        {
            pos = i;
            break;
        }
    }

    for(int i = pos; i>=0; i--)
    {
        int u = sorted[i];
        pathMaker(u);
    }

    return dist[d];
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
        int x,y,w;
        cin>>x>>y>>w;

        vector<int> tmp;
        tmp.push_back(y);
        tmp.push_back(w);

        g[x].push_back(tmp);
    }

    int s,d;
    cin>>s>>d;

    for(auto i : g)
    {
        topsort(i.first);
    }

    int path = find_shortest(s,d);

    cout<<"Shortest path from "<<s<<" to "<<d<<" is "<<path<<endl;

    return 0;
}