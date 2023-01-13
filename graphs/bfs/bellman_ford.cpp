#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<pair<int,int>>> g;
unordered_map<int, int> dist;

int bell_ford(int s, int d)
{
    int len = dist.size();

    dist[s] = 0;

    for(int i=0; i<len-1; i++)
    {
        for(auto i : g)
        {
            for(auto j : i.second)
            {
                dist[j.first] = min(dist[j.first], dist[i.first] + j.second);
            }
        }
    }

    for(int i=0; i<len-1; i++)
    {
        for(auto i : g)
        {
            for(auto j : i.second)
            {
                if(dist[i.first] + j.second < dist[j.first])
                    dist[j.first] = -10000;
            }
        }
    }

    return dist[d];
}

void print_neg_cycle()
{
    cout<<"[ ";

    for(auto i : dist)
    {
        cout<<i.first<<":"<<i.second<<" , ";
    }

    cout<<"]"<<endl;
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
        int x,y,z;

        cin>>x>>y>>z;

        g[x].push_back(make_pair(y,z));

        dist[x] = INT_MAX;
        dist[y] = INT_MAX;
    }

    int s,d;

    cin>>s>>d;

    int shortest = bell_ford(s,d);

    cout<<"Shortest path form "<<s<<" to "<<d<<" is "<<shortest<<endl;
    print_neg_cycle();
    
    return 0;
}