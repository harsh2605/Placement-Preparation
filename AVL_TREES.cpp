// Inserting a node in AVL tree which is also called self balancing tree
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
struct Node
{
    int val;
    Node *leftch;
    Node *rightch;
    int height;
    Node(int key)
    {
        val = key;
        leftch = NULL;
        rightch = NULL;
    }
} *root = NULL;

int set_height(Node *root)
{
    int left_height = (root && root->leftch) ? root->leftch->height : 0;
    int right_height = (root && root->rightch) ? root->rightch->height : 0;
    return 1 + max(left_height, right_height);
}

int balancefactor(Node *root)
{
    int left = 0, right = 0;
    if (root->leftch != NULL)
    {
        left = root->leftch->height;
    }
    if (root->rightch != NULL)
    {
        right = root->rightch->height;
    }
    return left - right;
}
Node *llrotation(Node *p)
{
    Node *pl = p->leftch;
    Node *plr = p->leftch->rightch;

    pl->rightch = p;
    p->leftch = plr;

    pl->height = set_height(pl);
    p->height = set_height(p);
    if (root == p)
        root = pl;
    return pl;
}

Node *rrrotation(Node *p)
{
    Node *pr = p->rightch;
    Node *prl = pr->leftch;
    pr->leftch = p;
    p->rightch = prl;

    pr->height = set_height(pr);
    p->height = set_height(p);
    if (root == p)
    {
        root = pr;
    }
    return pr;
}
Node *lrrotation(Node *p)
{
    Node *pl = p->leftch;
    Node *plr = pl->rightch;
    p->leftch = plr->rightch;
    pl->rightch = plr->leftch;
    plr->leftch = pl;
    plr->rightch = p;
    p->height = set_height(p);
    pl->height = set_height(pl);
    plr->height = set_height(plr);
    if (root == p)
    {
        root = plr;
    }
    return plr;
}
Node *rlrotation(Node *p)
{
    Node *pr = p->rightch;
    Node *prl = pr->leftch;

    pr->leftch = prl->rightch;
    p->rightch = prl->leftch;

    prl->rightch = pr;
    prl->leftch = p;

    // Update height
    pr->height = set_height(pr);
    p->height = set_height(p);
    prl->height = set_height(prl);

    // Update root
    if (root == p)
    {
        root = prl;
    }
    return prl;
}
Node *insert_ele(Node *p, int key)
{
    if (p == NULL)
    {
        Node *new_node = new Node(key);
        new_node->height = 1;
        return new_node;
    }
    if (p->val > key)
        p->leftch = insert_ele(p->leftch, key);
    else
        p->rightch = insert_ele(p->rightch, key);

    p->height = set_height(p);

    if (balancefactor(p) == 2 && balancefactor(p->leftch) == 1)
    {
        return llrotation(p);
    }
    else if (balancefactor(p) == 2 && balancefactor(p->leftch) == -1)
    {
        return lrrotation(p);
    }
    else if (balancefactor(p) == -2 && balancefactor(p->rightch) == -1)
    {
        return rrrotation(p);
    }
    else if (balancefactor(p) == -2 && balancefactor(p->rightch) == 1)
    {
        return rlrotation(p);
    }
    return p;
}
void print_node(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " " << root->height << endl;
    print_node(root->leftch);
    print_node(root->rightch);
}
int main()
{
    root = insert_ele(root, 10);
    insert_ele(root, 8);
    insert_ele(root, 9);
    // insert_ele(root, 15);
    // insert_ele(root,12);
    // insert_ele(root, 40);
    // insert_ele(root, 70);
    // insert_ele(root, 67);
    print_node(root);
    return 0;
}