#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left = NULL;
    struct Node* right = NULL;
    bool color = false;
    // false = black, true = red
};

struct Node* head = NULL;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    cout<<sizeof(struct Node)<<endl;
    return 0;
}