// find the middle of the stack in O(1) time complexity and perform all the opeartion like push,pop and delete middle node in O(1) time complexity
#include <bits/stdc++.h>
using namespace std;

class myStack
{
    struct Node
    {
        int num;
        Node *next;
        Node *prev;

        Node(int num) { this->num = num; }
    };

    // Members of stack
    Node *head = NULL;
    Node *mid = NULL;
    int size = 0;

public:
    void push(int data)
    {
        Node *temp = new Node(data);
        if (size == 0)
        {
            head = temp;
            mid = temp;
            size++;
            return;
        }

        head->next = temp;
        temp->prev = head;

        // update the pointers
        head = head->next;
        if (size % 2 == 1)
        {
            mid = mid->next;
        }
        size++;
    }

    int pop()
    {
        int data = -1;
        if (size != 0)
        {
            Node *toPop = head;
            data = toPop->num;
            if (size == 1)
            {
                head = NULL;
                mid = NULL;
            }
            else
            {
                head = head->prev;
                head->next = NULL;
                if (size % 2 == 0)
                {
                    mid = mid->prev;
                }
            }
            delete toPop;
            size--;
        }
        return data;
    }

    int findMiddle()
    {
        if (size == 0)
        {
            return -1;
        }
        return mid->num;
    }

    void deleteMiddle()
    {
        if (size != 0)
        {
            Node *toDelete = mid;
            if (size == 1)
            {
                head = NULL;
                mid = NULL;
            }
            else if (size == 2)
            {
                head = head->prev;
                mid = mid->prev;
                head->next = NULL;
            }
            else
            {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                if (size % 2 == 0)
                {
                    mid = mid->prev;
                }
                else
                {
                    mid = mid->next;
                }
            }
            delete toDelete;
            size--;
        }
    }
};

// Implement Stack using queue
// First approach will be using 2 queue to implement stack
// Here 1.first push the element in 2nd queue;
// 2.Than one by one take the element from the queue 1 and put it inside the queue 2
// 3.Take all the elements from queue 2 and copy them inside queue 1

// Second approach will be using a single queue
// In this you first push the element in the queue and than run a loop till queue size-1 and push the elements from the front to the back
void push(int x)
{
    q.push(x);
    for (int i = 0; i < q.size() - 1; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

// Implement queue using stack
// First approach is using 2 stack
// 1.Transfer all the elements from stack 1 to stack 2
// 2.Push the element to stack 1
// 3.Transfer all the elements from stack2 to stack1

// Second approach is also using 2 stack
// using input and output stack
// 1.push opeartion push the element in the stack 1
// 2.pop operation : if the output stack is empty than push all the elements from the input stack into output stack and return the top element
// 3.top operation : if the output stack is empty than push all the elements from the input stack into output stack and return the top element

// Valid parenthesis
// input:{}[] output :true and input:']' output :false;
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')' && !st.empty() && st.top() == '(')
        {
            st.pop();
        }
        else if (s[i] == '}' && !st.empty() && st.top() == '{')
        {
            st.pop();
        }
        else if (s[i] == ']' && !st.empty() && st.top() == '[')
        {
            st.pop();
        }
        else
            return false;
    }
    if (st.empty())
        return true;
    return false;
}

// Implement min-stack all the operation(function) in O(1) time
stack<pair<int, int>> st;
MinStack()
{
}
void push(int val)
{
    if (st.empty())
    {
        st.push({val, val});
    }
    else
    {
        st.push({val, min(st.top().second, val)});
    }
}

void pop()
{
    st.pop();
}

int top()
{
    return st.top().first;
}

int getMin()
{
    return st.top().second;
}

// Infix to postfix conversion
// Input :(1+3)*9 output:13+9*
// The basic approach to solve this problem is that when you encounter any operand(number or alphabet) just add that to your answer string and when you encounter any operator check it from the top of stack if the priority of the coming operator is less than the priority of the inserted opeartor just pop the elements from the stack and add in the answer string untill the condition become false and then push the coming operator in the stack.
// if you enounter any '(' then push this to stack and when you encounter ')' then run a while loop untill you get a '(' in the stack and while poping add the opeartor in the answer string;
string infixToPostfix(string exp)
{
    // Write your code here
    stack<char> st;
    unordered_map<char, int> mp;
    mp['^'] = 3;
    mp['*'] = 2;
    mp['/'] = 2;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['('] = 0;
    mp[')'] = 0;
    string str;
    for (int i = 0; i < exp.size(); i++)
    {
        if (mp.find(exp[i]) != mp.end())
        {
            if (st.empty() || exp[i] == '(')
            {
                st.push(exp[i]);
            }
            else if (exp[i] == ')')
            {
                while (st.top() != '(')
                {
                    str += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (st.size() && mp[st.top()] >= mp[exp[i]])
                {
                    str += st.top();
                    st.pop();
                }
                st.push(exp[i]);
            }
        }
        else
        {
            str += exp[i];
        }
    }
    while (!st.empty())
    {
        char store = st.top();
        str += store;
        st.pop();
    }
    return str;
}

// Infix - Prefix conversion
// Input : x + y *z / w + u Output : ++x/*yzwu

// 1.First, reverse the infix expression given in the problem.
// 2.Scan the expression from left to right.
// 3.Whenever the operands arrive, print them.
// 4.If the operator arrives and the stack is found to be empty, then simply push the operator into the stack.
// 5.If the incoming operator has higher precedence than the TOP of the stack, push the incoming operator into the stack.
// 6.If the incoming operator has the same precedence with a TOP of the stack, push the incoming operator into the stack.
// 7.If the incoming operator has lower precedence than the TOP of the stack, pop, and print the top of the stack. Test the incoming operator against the top of the stack again and pop the operator from the stack till it finds the operator of lower precedence or same precedence.
// 8.If the incoming operator has the same precedence with the top of the stack and the incoming operator is ^, then pop the top of the stack till the condition is true. If the condition is not true, push the ^ operator.
// 9.When we reach the end of the expression, pop, and print all the operators from the top of the stack.
// 10.If the operator is ‘)’, then push it into the stack.
// 11.If the operator is ‘(‘, then pop all the operators from the stack till it finds the ‘)’ bracket in the stack.
// 12.If the top of the stack is ‘)’, push the operator on the stack.
// 13.In the end, reverse the output. And print it.

// Prefix to infix conversion
// Solution{Just traverse the string from the backward side and apply the same rule when you convert postfix to infix conversion}
#include <bits/stdc++.h>
bool isOperator(char &c)
{
    return c == '-' || c == '+' || c == '/' || c == '*';
}

string prefixToInfixConversion(string &s)
{
    string ans = "";
    stack<string> stk;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (isOperator(s[i]))
        {
            string s1 = stk.top();
            stk.pop();
            string s2 = stk.top();
            stk.pop();
            stk.push("(" + s1 + s[i] + s2 + ")");
        }
        else
        {
            string tmp(1, s[i]);
            stk.push(tmp);
        }
    }
    return stk.top();
}

// Prefix to postfix conversion
// Reverse the string and apply the same process of postfix to infix
string preToPost(string s)
{

    // Write Your Code Here

    stack<string> st;

    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++)
    {

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {

            string ans = "";

            ans += s[i];

            st.push(ans);
        }

        else
        {

            string s1 = st.top();

            st.pop();

            string s2 = st.top();

            st.pop();

            string ans = s1 + s2 + s[i]; // ye step khali alag hai

            st.push(ans);
        }
    }

    return st.top();
}

// postfix to prefix conversion
stack<string> post;
for (char ch : s)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        string add = "";
        add += ch;
        post.push(add);
    }
    else
    {
        string top2 = post.top();
        post.pop();
        string top1 = post.top();
        post.pop();
        post.push(ch + top1 + top2); // ye step alag hai isme
    }
}
string ans1 = "";
while (post.size() != 0)
{
    ans1 += post.top();
    post.pop();
}
return ans1;

// Monotonic stack queue

// Next greater element 1
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp;
    stack<int> st;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            mp[nums2[i]] = -1;
            st.push(nums2[i]);
        }
        else
        {
            while (!st.empty() && st.top() < nums2[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                mp[nums2[i]] = st.top();
            }
            else
                mp[nums2[i]] = -1;
            st.push(nums2[i]);
        }
    }
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(mp[nums1[i]]);
    }
    return ans;
}

// Next greatest element 2
// In this question you have to find the next greatest element in a circular array means when you are at a index you can look first front for greatest element if not found than have a look at the back side from the starting point
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge(n, 0);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
            st.pop();
        if (i < n)
        {
            if (st.empty())
                nge[i] = -1;
            else
                nge[i] = st.top();
        }
        st.push(nums[i % n]);
    }
    return nge;
}

// Next Smallest element
vector<int> Solution::prevSmaller(vector<int> &A)
{
    stack<int> st;
    vector<int> store;
    for (int i = 0; i < A.size(); i++)
    {
        if (st.empty())
        {
            store.push_back(-1);
            st.push(A[i]);
        }
        else
        {
            while (!st.empty() && st.top() >= A[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                store.push_back(st.top());
            }
            else
                store.push_back(-1);
            st.push(A[i]);
        }
    }
    return store;
}

// Traping rain water problem
// The approach which will take Time complexity:O(N) Space complexity:O(N)
int trap(vector<int> &height)
{
    vector<int> pre(height.size(), 0), suf(height.size(), 0);
    int maxi = INT_MIN;
    for (int i = 0; i < height.size(); i++)
    {
        pre[i] = max(maxi, height[i]);
        maxi = max(maxi, height[i]);
    }
    maxi = INT_MIN;
    for (int i = height.size() - 1; i >= 0; i--)
    {
        suf[i] = max(maxi, height[i]);
        maxi = max(maxi, height[i]);
    }
    int ans = 0;
    for (int i = 0; i < height.size(); i++)
    {
        ans += min(pre[i], suf[i]) - height[i];
    }
    return ans;
}
// Second approach using two pointer approach
int trap(vector<int> &height)
{
    int ans = 0;
    int start = 0, end = height.size() - 1;
    int left_max = 0, right_max = 0;
    while (start <= end)
    {
        if (height[start] <= height[end])
        {
            if (left_max <= height[start])
            {
                left_max = height[start];
            }
            else
            {
                ans += (left_max - height[start]);
            }
            start++;
        }
        else
        {
            if (right_max <= height[end])
            {
                right_max = height[end];
            }
            else
            {
                ans += (right_max - height[end]);
            }
            end--;
        }
    }
    return ans;
}

// Largest rectangle on histogram
void solve(vector<int> &dup, vector<int> &vt)
{
    int n = dup.size() - 1;
    stack<pair<int, int>> st; // it will store the next smaller element with its index;
    for (int i = dup.size() - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            vt.push_back(n - i);
        }
        else
        {
            while (!st.empty() && st.top().first >= dup[i])
            {
                st.pop();
            }
            if (st.empty())
                vt.push_back(n - i);
            else
                vt.push_back(st.top().second - 1 - i);
        }
        st.push({dup[i], i});
    }
}
int largestRectangleArea(vector<int> &heights)
{
    vector<int> dup = heights;
    vector<int> right, left;
    solve(dup, right);
    reverse(dup.begin(), dup.end());
    solve(dup, left);
    reverse(right.begin(), right.end());
    int maxi = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        maxi = max(maxi, heights[i] * (left[i] + right[i] + 1));
    }
    return maxi;
}

// Maximal area of rectangle in a grid ;
// The approach will be you have to iterate over every row and add the value of its block in the next row if the next row bloack value is not 0;
// By doing this a new values of every row is created and than on every row apply to concept of finding maximum area in a histogram and in this way you can find the maximum area;
class Solution
{
public:
    void solve(vector<int> &dup, vector<int> &vt)
    {
        int n = dup.size() - 1;
        stack<pair<int, int>> st; // it will store the next smaller element with its index;
        for (int i = dup.size() - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                vt.push_back(n - i);
            }
            else
            {
                while (!st.empty() && st.top().first >= dup[i])
                {
                    st.pop();
                }
                if (st.empty())
                    vt.push_back(n - i);
                else
                    vt.push_back(st.top().second - 1 - i);
            }
            st.push({dup[i], i});
        }
    }
    int largest(vector<int> &heights)
    {
        vector<int> dup = heights;
        vector<int> right, left;
        solve(dup, right);
        reverse(dup.begin(), dup.end());
        solve(dup, left);
        reverse(right.begin(), right.end());
        int maxi = INT_MIN;
        for (int i = 0; i < heights.size(); i++)
        {
            maxi = max(maxi, heights[i] * (left[i] + right[i] + 1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> vt(m, 0);
        int maxi = INT_MIN;
        // maxi=max(maxi,largest(store));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    vt[j] += '1' - '0';
                else
                    vt[j] = 0;
            }
            maxi = max(maxi, largest(vt));
        }
        return maxi;
    }
}

// Remove K digits from a given string to reduce the value of the given string
string
removeKdigits(string num, int k)
{
    stack<char> st;
    string ans;
    int count = 0;
    for (int i = 0; i < num.size(); i++)
    {
        while (!st.empty() && count < k && st.top() > num[i])
        {
            count++;
            st.pop();
        }
        st.push(num[i]);
    }
    while (count != k)
    {
        st.pop();
        count++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    string res;
    bool flag = false;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] != '0')
        {
            flag = true;
        }
        if (flag == true)
        {
            res += ans[i];
        }
    }
    return res.size() == 0 ? "0" : res;
}

// LRU Cache(Least recently used)
// Our approach will be creating a doubly linkedlist of head and tail nodes and both are connected to each other
// If suppose someone call the get method and the value of the get is already present in the hash map then the value will be updated and the node will come to the front behind the head node and the previous node will be deleted from its position;
// You have to make a head and a tail nodes and act accordingy and if koi node ko nikalna ho to wo humesa tail side se niklega and dalna hai to humesa head side se dalega
struct ListNode
{
    int key;
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int key, int val)
    {
        this->key = key;
        this->val = val;
    }
};
unordered_map<int, ListNode *> mp;
ListNode *head = new ListNode(-1, -1);
ListNode *tail = new ListNode(-1, -1);
int cap;
void delete_node(ListNode *cur)
{
    ListNode *temp = cur->next;
    cur->prev->next = temp;
    temp->prev = cur->prev;
}
void add_node(ListNode *cur)
{
    ListNode *temp = head->next;
    cur->next = temp;
    head->next = cur;
    cur->prev = head;
    temp->prev = cur;
}
LRUCache(int capacity)
{
    cap = capacity;
    head->next = tail;
    tail->prev = head;
}

int get(int key)
{
    if (mp.find(key) != mp.end())
    {
        ListNode *store = mp[key];
        int value = store->val;
        mp.erase(key);
        delete_node(store);
        add_node(store);
        mp[key] = head->next;
        return value;
    }
    return -1;
}

void put(int key, int value)
{
    if (mp.find(key) != mp.end())
    {
        ListNode *store = mp[key];
        mp.erase(key);
        delete_node(store);
    }
    if (mp.size() == cap)
    {
        mp.erase(tail->prev->key);
        delete_node(tail->prev);
    }
    add_node(new ListNode(key, value));
    mp[key] = head->next;
}

// Sliding window maximum using deque;
// In this you hava to find the maximum element in every subarray of size K;
// Time complexity:O(N)+O(N)
// Space complexity:O(K)
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

// Celebrity problem
// In this question you have to find the man who is known buy everybody but he doesnot know anyone
// You are given a matrix than also you have to give a solution with O(N) time complexity
// 1.First step is to put all the persons which means the row number in a stack ;
// 2.Than take out two elements from the stack and find that if a knows b if yes than push b and b knows a than push a(ye kaise pata chalega ki a knows b ki nhi is that yoyu have to go to M[a][b] and check if the value is 1 or not);
// 3.we have to do this untill the size of the stack become 1;
// 4.Than after stack size become 1 than we have to take out the top element and check the row of that element that all the row value should be 0 and all the column value of the stack top row number should be 1 except the diagonal element than if both the condition of the row and column are true than we have our celebrity with us;

int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    stack<int> st;
    int a, b;
    for (int i = 0; i < M.size(); i++)
    {
        st.push(i);
    }
    while (st.size() != 1)
    {
        a = st.top();
        st.pop();
        b = st.top();
        st.pop();
        if (M[b][a] == 0)
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }
    int i = 0;
    while (i < n)
    {
        if (M[st.top()][i] == 0)
        {
            i++;
        }
        else
        {
            return -1;
        }
    }
    int j = 0;
    while (j < n)
    {
        if (st.top() == j)
        {
            ;
        }
        else
        {
            if (M[j][st.top()] == 0)
                return -1;
        }
        j++;
    }
    return st.top();
}

// Reverse first k elements of a queue;
void solve(queue<int> &q, int count, int k)
{
    if (count == k)
        return;
    int ele = q.front();
    q.pop();
    solve(q, count + 1, k);
    q.push(ele);
}
queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.
    int final_count = q.size() - k;
    int count = 0;
    solve(q, count, k);
    while (final_count != 0)
    {
        q.push(q.front());
        q.pop();
        final_count--;
    }
    return q;
}

// Find non-repeating character in a stream
// In this question we will be given elements in a stream and then we have to output the element which are non repeating from the starting
string FirstNonRepeating(string A)
{
    // Code here
    string ans;
    unordered_map<char, int> mp;
    queue<char> q;
    for (int i = 0; i < A.size(); i++)
    {
        mp[A[i]]++;
        q.push(A[i]);
        while (!q.empty())
        {
            if (mp[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

// Remove middle element from the stack using recursion
void solve(stack<int> &st, int size, int count)
{
    if (count == size / 2)
    {
        st.pop();
        return;
    }
    int ele = st.top();
    st.pop();
    solve(st, size, count + 1);
    st.push(ele);
}
void deleteMid(stack<int> &s, int sizeOfStack)
{
    // code here..
    int count = 0;
    solve(s, s.size(), count);
}

// Reverse a stack using recursion
// Time complexity:O(N^2);
void insert_bottom(int ele, stack<int> &st)
{
    if (st.size() == 0)
    {
        st.push(ele);
        return;
    }
    int eler = st.top();
    st.pop();
    insert_bottom(ele, st);
    st.push(eler);
    return;
}
void solve(stack<int> &st, int count)
{
    if (st.size() == 1)
    {
        return;
    }
    int ele = st.top();
    st.pop();
    solve(st, count + 1);
    insert_bottom(ele, st);
    return;
}
void Reverse(stack<int> &St)
{
    int count = 0;
    solve(St, count);
}

// Longest valid parenthesis
// input:((()))())() output:8
int findMaxLen(string s)
{
    // code here
    stack<int> st;
    st.push(-1);
    int ans = INT_MIN;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.size() == 0)
            {
                st.push(i);
            }
            else
                ans = max(ans, i - st.top());
        }
    }
    return ans == INT_MIN ? 0 : ans;
}