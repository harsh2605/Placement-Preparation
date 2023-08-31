// Creation of tree
#include <bits/stdc++.h>
struct Node
{
    int data;
    struct Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(4);
}

// Level order traversal of a tree
void level(struct Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *ele = q.front();
            q.pop();
            ans.push_back(ele->data);
            if (ele->left != NULL)
            {
                q.push(ele->left);
            }
            if (ele->right != NULL)
            {
                q.push(ele->right);
            }
        }
    }
}

// Iterative preorder traversal
void preorder(struct Node *root)
{
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *ele = st.top();
        st.pop();
        cout << ele->data << " ";
        if (ele->right != NULL)
        {
            st.push(ele->right);
        }
        if (ele->left != NULL)
        {
            st.push(ele->left);
        }
    }
}

// Iterative inorder traversal
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *node = root;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    }
    return ans;
}

// Postorder traversal using 2 stack
vector<int> postorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    stack<TreeNode *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        TreeNode *node = st1.top();
        st1.pop();
        st2.push(node);
        if (node->left != NULL)
        {
            st1.push(node->left);
        }
        if (node->right != NULL)
        {
            st1.push(node->right);
        }
    }
    while (!st2.empty())
    {
        ans.push_back(st2.top()->val);
        st2.pop();
    }
    return ans;
}

// Inorder,preorder and postorder data in one traversal using a single stack
void solve(TreeNode *root)
{
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    while (!st.empty())
    {
        TreeNode *dir = st.top();
        st.pop();
        if (dir.second == 1)
        {
            pre.push_back(dir.first->val);
            dir.second++;
            st.push(dir);
            if (dir.first->left != NULL)
            {
                st.push(dir.first->left);
            }
        }
        else if (dir.second == 2)
        {
            in.push_back(dir.first->val);
            dir.second++;
            st.push(dir);
            if (dir.first->right != NULL)
            {
                st.push(dir.first->right);
            }
        }
        else
        {
            post.push_back(dir.first->val);
        }
    }
}

// maximum depth of a binary tree
int solve(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = solve(root->left);
    int rh = solve(root->right);
    return 1 + max(lh, rh);
}

// Check if the tree is balanced or not
// conditon of a tree to be balanced (abs(height(left subtree)-height(right subtree))<=1)
int solve(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = solve(root->left);
    int rh = solve(root->right);
    if (lh == -1 || rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}
bool balanced(TreeNode *root)
{
    if (solve(root) == -1)
        return false;
    return true;
}

// diameter of a bianry tree(it represent the maximum length of the distance of the node which is present far from each other)
int height(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left, maxi);
    int rh = height(root->right, maxi);
    maxi = max(maxi, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode *root)
{
    int maxi = INT_MIN;
    height(root, maxi);
    return maxi;
}

// Binary tree maximum path sum (You have to find the sum of nodes which is creating a path and has a maximum value)
// In this question we have checked the lh and rh with 0 because we know that adding any negative value to any value will decrease the value only so it is better not to add that value to the final result;
int solve(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int lh = max(0, solve(root->left, maxi));
    int rh = max(0, solve(root->right, maxi));
    maxi = max(maxi, root->val + lh + rh);
    return root->val + max(lh, rh);
}
int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    solve(root, maxi);
    return maxi;
}

// Same Tree(Check if two given trees are same or not)
bool issame(TreeNode *p, TreeNode *q)
{
    if (p == NULL || q == NULL)
        return (p == q);
    return (p->val == q->val) && issame(p->left, q->left) && issame(p->right, q->right);
}

// Zig-Zag tree traversal
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> store(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *ele = q.front();
            q.pop();
            int index = flag ? i : size - 1 - i;
            store[index] = ele->val;
            if (ele->left != NULL)
            {
                q.push(ele->left);
            }
            if (ele->right != NULL)
            {
                q.push(ele->right);
            }
        }
        flag = !flag;
        ans.push_back(store);
    }
    return ans;
}

// Boundry level traversal of any tree(you have to traverse through the boundry only(left->leaf->right))
// This code is for the movement in anti-clock wise direction(You can do this in clock wise manner also)
bool isleaf(Node *root)
{
    if (root != NULL && root->left == NULL && root->right == NULL)
        return true;
    return false;
}
void left(Node *root, vector<int> &ans)
{
    Node *cur = root->left;
    while (cur)
    {
        if (!isleaf(cur))
            ans.push_back(cur->data);
        if (cur->left != NULL)
            cur = cur->left;
        else
            cur = cur->right;
    }
}
void leaf_node(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (isleaf(root))
        ans.push_back(root->data);
    leaf_node(root->left, ans);
    leaf_node(root->right, ans);
}
void right(Node *root, vector<int> &ans)
{
    Node *cur = root->right;
    stack<int> st;
    while (cur)
    {
        if (!isleaf(cur))
            st.push(cur->data);
        if (cur->right != NULL)
            cur = cur->right;
        else
            cur = cur->left;
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}
vector<int> boundary(Node *root)
{
    // Your code here
    vector<int> ans;
    if (!isleaf(root))
        ans.push_back(root->data);
    left(root, ans);
    leaf_node(root, ans);
    right(root, ans);
    return ans;
}

// Vertical order traversal of a tree(TC:O(NLOGN) SC:O(N))
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<pair<TreeNode *, pair<int, int>>> q; //{value,{level,vertical}};
    map<int, map<int, multiset<int>>> mp;      //(vertical,{level,ele});
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        root = temp.first;
        mp[temp.second.second][temp.second.first].insert(root->val);
        if (root->left != NULL)
        {
            q.push({root->left, {temp.second.first + 1, temp.second.second - 1}});
        }
        if (root->right != NULL)
        {
            q.push({root->right, {temp.second.first + 1, temp.second.second + 1}});
        }
    }
    for (auto itr : mp)
    {
        vector<int> col;
        for (auto mtr : itr.second)
        {
            col.insert(col.end(), mtr.second.begin(), mtr.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

// In top view and bottom view questions we can't use recursive traversal it will give wrong results
//Because if you perform any traversal on this tree it will get the wrong node first
//  top view of a binary tree
vector<int> topView(Node *root)
{
    // Your code here
    queue<pair<Node *, int>> q; // storing (node,vertical)
    q.push({root, 0});
    map<int, int> mp;
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        if (mp.find(temp.second) == mp.end())
            mp[temp.second] = temp.first->data;
        if (temp.first->left != NULL)
        {
            q.push({temp.first->left, temp.second - 1});
        }
        if (temp.first->right != NULL)
        {
            q.push({temp.first->right, temp.second + 1});
        }
    }
    vector<int> ans;
    for (auto itr : mp)
    {
        ans.push_back(itr.second);
    }
    return ans;
}

// bottom view of binary tree
vector<int> bottomView(Node *root)
{
    // Your Code Here
    queue<pair<Node *, int>> q; // storing (node,vertical)
    q.push({root, 0});
    map<int, int> mp;
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        mp[temp.second] = temp.first->data;
        if (temp.first->left != NULL)
        {
            q.push({temp.first->left, temp.second - 1});
        }
        if (temp.first->right != NULL)
        {
            q.push({temp.first->right, temp.second + 1});
        }
    }
    vector<int> ans;
    for (auto itr : mp)
    {
        ans.push_back(itr.second);
    }
    return ans;
}

// Rigth side view of a binary tree similar code can be written for the left side view of the binary tree starting from(root left and right in the recursion call)
void solve(TreeNode *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;
    if (ans.size() == level)
        ans.push_back(root->val);
    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}
vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    solve(root, ans, 0);
    return ans;
}

// Check if the tree is symmetric or not (same question as checking of two trees are same or not)
// TC:(O(N)) and SC:O(N)
bool solve(TreeNode *le, TreeNode *rig)
{
    if (le == NULL || rig == NULL)
        return (le == rig);
    return (le->val == rig->val) && solve(le->left, rig->right) && solve(le->right, rig->left);
}
bool isSymmetric(TreeNode *root)
{
    return solve(root->left, root->right);
}

// same question if you want to do this iteratively
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    queue<TreeNode *> q1, q2;
    TreeNode *l, *r;
    q1.push(root->left);
    q2.push(root->right);
    while (!q1.empty() && !q2.empty())
    {
        l = q1.front();
        r = q2.front();
        q1.pop();
        q2.pop();
        if (l == NULL && r == NULL)
            continue;
        if (l == NULL || r == NULL)
            return false;
        if (l->val != r->val)
            return false;
        q1.push(l->left);
        q1.push(l->right);
        q2.push(r->right);
        q2.push(r->left);
    }
    return true;
}

// Print path from root to node in a given binary tree
// Tc:O(N) SC:O(H)
bool solve(TreeNode *root, vector<int> &ans, int node)
{
    if (root == NULL)
        return false;
    ans.push_back(root->val);
    if (root->val == node)
        return true;
    if (solve(root->left, ans, node) || solve(root->right, ans, node))
        return true;
    ans.pop_back();
    return false;
}
vector<int> solution(TreeNode *root, int node)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    solve(root, ans, node);
    return ans;
}

// Lowest common ancestor
// First approach is to find the path from the root node to the node which is given in the question and similarly find the path of the second path with the same process and traverse through both the arrays and find the last element which is equal in both the array form the starting
// Another approach without extra space is using recursion
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else // if both left and right are not null than we get our final result
        return root;
}

// The follow up to this question is that it is asked that if some node from p and q is not present than you have to return NULL;
{The answer of the following question is that when you are returning the root in the last you can maintain a flag variable which will become true and justify that from both the sides nodes are coming}

// One more follow up question to lowest common ancestor is that when in the structure what if the it contain parent node also means it is given the pointer to the nodes parent
{
    This question will become similar to the linkedlist question where we have to find the intersection point of the Y shaped linkedlist
}
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution
{
public:
    Node *lowestCommonAncestor(Node *p, Node *q)
    {
        Node *a = p, *b = q;
        while (a != b)
        {
            a = (a == nullptr ? q : a->parent);
            b = (b == nullptr ? p : b->parent);
        }
        return a;
    }
};

// Similarly if more than two nodes are present in a vector whose common ancesto is to be found out
TreeNode *lowestCommonAncestor(TreeNode *root, const set<TreeNode *> &nodes_set)
{
    if (root == NULL || nodes_set.count(root) > 0) // just you have to check if the current root node is present in the set or not
    {
        return root;
    }
    TreeNode *l = lowestCommonAncestor(root->left, nodes_set);
    TreeNode *r = lowestCommonAncestor(root->right, nodes_set);

    if (l == NULL)
        return r;
    else if (r == NULL)
        return l;
    else
        return root;
}

public:
TreeNode *lowestCommonAncestor(TreeNode *root, vector<TreeNode *> &nodes)
{
    set<TreeNode *> nodes_set(nodes.begin(), nodes.end());
    return lowestCommonAncestor(root, nodes_set);
}

// child sum property of binary tree(in this question you have to make the tree with increment only in such a way that the parent node is equal to the sum of nodes in the left and right side)
// The basic idea of the question is ki data ka shortage nhi hone dena hai jaise jaise niche ja rhe ho waise waise data increase karna hai fir returning time adjust kar lengai kyuki yaha par humlog sirf increment kar sakte hai isliye
void solve(TreeNode *root)
{
    if (root == NULL)
        return;
    int cur = 0;
    if (root->left)
        cur += root->left->val;
    if (root->right)
        cur += root->right->val;
    if (root->data <= cur)
    {
        root->data = cur;
    }
    else
    {
        if (root->left)
            root->left->data = cur;
        if (root->right)
            root->right->data = cur;
    }
    solve(root->left);
    solve(root->right);
    int temp = 0;
    if (root->left)
        temp += root->left->data;
    if (root->right)
        temp += root->right->data;
    if (root->left || root->right)
        root->data = temp;
}

// Elements at a distance k from the given node
void parent_find(Node *root, unordered_map<Node *, Node *> &parent)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *ele = q.front();
        q.pop();
        if (ele->left != NULL)
        {
            parent[ele->left] = ele;
            q.push(ele->left);
        }
        if (ele->right != NULL)
        {
            parent[ele->right] = ele;
            q.push(ele->right);
        }
    }
}
void new_func(Node *root, Node *el, int k, set<Node *> ans)
{
    unordered_map<Node *, Node *> parent;
    parent_find(root, parent);
    unordered_map<Node *, bool> visited;
    int distance = 0;
    queue<Node *> qu;
    qu.push(el);
    while (!qu.empty())
    {
        int size = qu.size();
        if (distance == k)
            break;
        distance++;
        for (int i = 0; i < size; i++)
        {
            Node *ele = qu.front();
            qu.pop();
            if (ele->left && !visited[ele->left])
            {
                qu.push(ele->left);
                visited[ele->left] = true;
            }
            if (ele->right && !visited[ele->right])
            {
                qu.push(ele->right);
                visited[ele->right] = true;
            }
            if (parent[ele] && !visited[parent[ele]])
            {
                qu.push(parent[ele]);
                visited[parent[ele]] = true;
            }
        }
    }
    return qu.size();
}

// Minimum time to burn a tree(This question is same as finding the nodes at a distance k from the target node)
// In the solution we have taken fl=0 than updating that only if fl=1 because their might be the case that the nodes are burnt and again they are asked to be burnt so it wil increase the count.
class Solution
{
public:
    Node *target = NULL;
    void makeparent(Node *root, unordered_map<Node *, Node *> &parent)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
            {
                q.push(curr->left);
                parent[curr->left] = curr;
            }
            if (curr->right)

            {
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }
    }
    void findtarget(Node *root, int tar)
    {
        if (root == NULL)
            return;
        if (root->data == tar)
        {
            target = root;
        }
        findtarget(root->left, tar);
        findtarget(root->right, tar);
        return;
    }
    int minTime(Node *root, int tar)
    {
        // Your code goes here
        findtarget(root, tar);
        // cout<<target->data<<endl;
        int ans = 0;
        queue<Node *> q;
        unordered_map<Node *, Node *> parent;
        unordered_map<Node *, bool> vis;
        makeparent(root, parent);
        q.push(target);
        vis[target] = true;
        while (!q.empty())
        {
            int fl = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {

                Node *curr = q.front();
                q.pop();
                if (curr->left && !vis[curr->left])
                {
                    fl = 1;
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if (curr->right && !vis[curr->right])
                {
                    fl = 1;
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if (parent[curr] && !vis[parent[curr]])
                {
                    fl = 1;
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                }
            }
            if (fl)
                ans++;
        }
        return ans;
    }
};

// Count complete tree nodes(A complete tree means having either all the nodes filled or nodes at the last level is not necessary to be filled if filled they are filled and aligned to the left side)
// Time complexity:O(logN)^2 and space complexity:O(logN)
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = find_height_left(root);
        int rh = find_height_right(root);
        if (lh == rh)
            return (1 << lh) - 1; //(2^h-1)
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int find_height_left(TreeNode *root)
    {
        int count = 0;
        while (root != NULL)
        {
            count++;
            root = root->left;
        }
        return count;
    }
    int find_height_right(TreeNode *root)
    {
        int count = 0;
        while (root != NULL)
        {
            count++;
            root = root->right;
        }
        return count;
    }
};

// Flatten binary tree to linkedlist
// Solution using recursion
class Solution
{
public:
    TreeNode *prev = NULL;
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// Solution using stack
void flatten(TreeNode *root)
{
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop();
        if (cur->left != NULL)
        {
            st.push(cur->left);
        }
        if (cur->right != NULL)
        {
            st.push(cur->right);
        }
        if (!st.empty())
        {
            cur->right = st.top();
        }
        cur->left = NULL;
    }
}

// Binary Search Tree
// Search in a binary search tree
// Time complexity:O(Logn)
// Space complexity:O(H);//H is the height of the binary search tree
TreeNode *search(TreeNode *root, int val)
{
    while (root != NULL && root->val != val)
    {
        root = root->val < val ? root->right : root->left;
    }
    return root;
}

// ceil and floor of binary search tree
int findCeil(Node *root, int input)
{

    int ceil = -1;
    while (root != NULL)
    {
        if (root->data == input)
        {
            ceil = root->data;
            return ceil;
        }
        else if (root->data < input)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

int floor(Node *root, int x)
{
    // Code here
    int flor = -1;
    while (root != NULL)
    {
        if (root->data == x)
        {
            flor = x;
            return flor;
        }
        else if (root->data > x)
        {
            root = root->left;
        }
        else
        {
            flor = root->data;
            root = root->right;
        }
    }
    return flor;
}

// Insert into binary search tree
// Time complexity:O(logn)
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    TreeNode *store = root;
    if (root == NULL)
    {
        return new TreeNode(val);
    }
    while (true)
    {
        if (root->val <= val)
        {
            if (root->right != NULL)
            {
                root = root->right;
            }
            else
            {
                root->right = new TreeNode(val);
                break;
            }
        }
        else
        {
            if (root->left != NULL)
            {
                root = root->left;
            }
            else
            {
                root->left = new TreeNode(val);
                break;
            }
        }
    }
    return store;
}

// Kth smallest element in a binary search tree
// Solution:{Binary search tree has a property that if you make a inorder traversal than the elements will be sorted than you can find the kth largest and kth smallest element}
// for the kth largest element you just have to count the number of nodes present in the binary tree and than you have to find the element at N-k positon while doing the inorder traversal

// Validate binary search tree(Check whether a given tree is binary search tree or binary tree)
// Solution:This question is also done using the inorder traversal and checking if the previous element is greater than the current element than it is not a valid BST otherwise it is a BST

// LCA in Binary search tree
// Time complexity:O(H)
// Space complexity:O(1) without using stack space
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;
    if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    return root;
}