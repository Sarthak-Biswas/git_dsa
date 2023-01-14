#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left = NULL;
    struct Node* right = NULL;
};

struct Node* root = NULL;

struct Node* makeNode(int val)
{
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));

    tmp->data = val;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

struct Node* insertNode(struct Node* curr, int val)
{
    if(curr == NULL)
        return makeNode(val);

    if(curr->data == val)
        return curr;

    if(val < curr->data)
        curr->left = insertNode(curr->left, val);
    else
        curr->right = insertNode(curr->right, val);
    
    return curr;
}

struct Node* findNode(struct Node* curr, int val)
{
    if(curr == NULL)
        return curr;

    if(curr->data == val)
        return curr;

    if(val < curr->data)
        return findNode(curr->left, val);
    else
        return findNode(curr->right, val);
}

struct Node* findAncestor(struct Node* curr, int val)
{
    if(curr == NULL)
        return curr;

    if(curr->left != NULL)
    {
        if(curr->left->data == val)
            return curr;
    }

    if(curr->right != NULL)
    {
        if(curr->right->data == val)
            return curr;
    }
    
    if(val < curr->data)
        return findAncestor(curr->left, val);
    else
        return findAncestor(curr->right, val);
}

struct Node* findMinimum(struct Node* curr)
{
    while(curr->left != NULL && curr->left->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}

void deleteNode(struct Node* curr, int val)
{
    struct Node* temp = findNode(root, val);
    struct Node* ansc = findAncestor(root, val);

    if(temp == NULL)
        cout<<"The node does not exitst"<<endl;

    else
    {
        struct Node* m = findMinimum(temp);
        int mi;

        if(m->left == NULL)
            mi = m->data;
        else
            mi = m->left->data;

        temp->data = mi;

        while(!(temp->left == NULL || temp->left->data == mi))
        {
            if(temp->data < temp->left->data)
            {
                int t = temp->data;
                temp->data = temp->left->data;
                temp->left->data = t;
                temp = temp->left;
            }
        }

        if(m->left == NULL)
        {
            if(m == root)
            {
                root = m->right;
            }
            else
            {
                if(ansc->left == m)
                    ansc->left = m->right;
                else
                    ansc->right = m->right;
            }
        }
        else
        {
            m->left = m->left->right;
        }
    }
}

void inorderTraversal(struct Node* curr)
{
    if(curr == NULL)
        return;

    inorderTraversal(curr->left);
    cout<<curr->data<<" ";

    inorderTraversal(curr->right);
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

    vector<int> arr;

    while(n--)
    {
        int x;
        cin>>x;

        arr.push_back(x);
    }

    for(auto i : arr)
    {
        if(root == NULL)
            root = makeNode(i);

        else
            insertNode(root, i);
    }

    inorderTraversal(root);

    int x;
    cin>>x;

    deleteNode(root, x);
    cout<<endl;

    inorderTraversal(root);

    return 0;
}