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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif



    return 0;
}