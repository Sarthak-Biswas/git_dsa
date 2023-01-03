#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<pair<int,int>>> g;

// comparator overloading to make min-heap priority queue on second element of pair<>
struct myComp{
    bool operator()(
        pair<int,int> const &a,
        pair<int,int> const &b
    ){
        return a.second>b.second;
    }
};

// djikstras algorith to find shortest path in ~ O(V logE)
int djikstra_shortest(int u, int v) 
{
    vector<int> dist(1000,INT_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, myComp> pq;

    dist[u] = 0;

    pq.push(make_pair(u,0));

    while(!pq.empty())
    {
        int edge = pq.top().first;
        int weight = pq.top().second;

        pq.pop();

        if(edge == v)
            break;

        for(auto i : g[edge])
        {
            if( weight + i.second < dist[i.first] && weight <= dist[edge] )
            {
                dist[i.first] = weight + i.second;
                pq.push(make_pair(i.first, dist[i.first]));
            }
        }
    }

    return dist[v];
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

    // make a undirected graph
    while(n--)
    {
        int x,y,w;
        cin>>x>>y>>w;

        pair<int,int> tmp1(y,w);
        pair<int,int> tmp2(x,w);

        g[x].push_back(tmp1);
        g[y].push_back(tmp2);
    }

    int s,d;
    cin>>s>>d;

    int shortest = djikstra_shortest(s, d);

    cout<<"Shortest path form "<<s<<" to "<<d<<" is "<<shortest<<endl;

    return 0;
}