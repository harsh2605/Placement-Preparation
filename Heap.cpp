// Creating heap by inserting elements(1 based indexing)
// This is creation of max_heap similar if you want to create a min_heap than simply just change the condition in the while loop.
// The question in which you have to convert min heap to max heap or vice-versa there you have to take the first element as always inserted and than run a loop from i=2 to n and one by one insert the ith element in the heap;
void insert_max_heap(vector<int> &vt, int &n) // Time is (logn)
{
    int i = n;
    int ele = vt[n];
    while (i > 1 && ele > vt[i / 2])
    {
        vt[i] = vt[i / 2];
        i = i / 2;
    }
    vt[i] = ele;
    n++;
}
// In the deletion we can only delete the root node and that will become the priority_element you.
// The process : first you have to take the last element of the array and put it in the first element of the array and than compare from its left and right child in case of max-heap if the parent element is smaller than the child element than swap the value and stick with the value only and do the same steps
int delete_node_max_heap(vector<int> &vt, int &n)
{
    int x = vt[n - 1];
    int ele = vt[1];
    vt[1] = x;
    int i = 1;
    int j = 2 * i;
    while (j < n - 2)
    {
        if (vt[j + 1] > vt[j])
        {
            j = j + 1;
        }
        if (vt[j] > vt[i])
        {
            swap(vt[j], vt[i]);
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
    vt[n - 1] = ele; // for heap sorting part
    n--;
}
int main()
{
    vector<int> vt(100, 0);
    int n = 1;
    vt[n] = 49;
    insert_max_heap(vt, n);
    vt[n] = 56;
    insert_max_heap(vt, n);
    vt[n] = 78;
    insert_max_heap(vt, n);
    vt[n] = 98;
    insert_max_heap(vt, n);
    vt[n] = 34;
    insert_max_heap(vt, n);
    vt[n] = 30;
    insert_max_heap(vt, n);
    vt[n] = 3;
    insert_max_heap(vt, n);
    vt[n] = 87;
    insert_max_heap(vt, n);
    for (int i = 1; i < n; i++)
    {
        cout << vt[i] << " ";
    }
    return 0;
}

// Heap sort //time :O(nlogn)
// You just go on deleting the elements from the array in a max-heap and store the deleted element in the free space at last than you will get a sorted array this is the process of heap sort;

// Sliding window maximum using priority queue(it can also be solved using deque)
vector<int> max_of_subarrays(vector<int> arr, int n, int k)
{
    // your code here
    vector<int> ans;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i], i});
    }
    ans.push_back(pq.top().first);
    for (int i = k; i < n; i++)
    {
        pq.push({arr[i], i});
        while (pq.top().second <= i - k)
        {
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;
}

// Kth smallest element in an array
int kthSmallest(int arr[], int l, int r, int k)
{
    // code here
    priority_queue<int> pq;
    for (int i = 0; i < (r - l + 1); i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

// Kth largest element
vector<int> kLargest(int arr[], int n, int k)
{
    // code here
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> ans(pq.size());
    int i = pq.size() - 1;
    while (!pq.empty())
    {
        ans[i] = pq.top();
        pq.pop();
        i--;
    }
    return ans;
}

// Kth largest Sum contigious subarray
// In this question you have to find the sum of the kth largest sum between every sum of subarray of the given array
// Expected Time Complexity: O(N2 * log K)
// Expected Auxiliary Space: O(K)
int kthLargest(vector<int> &Arr, int N, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += Arr[j];
            pq.push(sum);
            if (pq.size() > K)
                pq.pop();
        }
    }
    return pq.top();
}

// Reorganise String
// In this question qustion you have to arrange the string in such a way that no two similar character are adjacent
string reorganizeString(string s)
{
    priority_queue<pair<int, int>> pq;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    for (auto itr : mp)
    {
        pq.push({itr.second, itr.first});
    }
    string ans;
    while (pq.size() > 1)
    {
        auto top1 = pq.top();
        pq.pop();
        auto top2 = pq.top();
        pq.pop();
        ans += top1.second;
        ans += top2.second;
        top1.first--;
        top2.first--;
        if (top1.first > 0)
            pq.push(top1);
        if (top2.first > 0)
            pq.push(top2);
    }
    if (!pq.empty())
    {
        if (pq.top().first > 1)
            return "";
        ans += pq.top().second;
    }
    return ans;
}

// Minimum sum
// In this question you have to choose elements from the array and from two number and sum them so that the sum is minimum .
// Approach will be sort the array you will see that you have to make alternate element as one number and the same apply to another eleemnt and then sum that
string solve(int arr[], int n)
{
    // code here
    sort(arr, arr + n);
    int sum = 0, carry = 0;
    string ans = "";
    for (int i = n - 1; i >= 0; i -= 2)
    {
        sum = (arr[i] + arr[i - 1] + carry) % 10;
        carry = (arr[i] + arr[i - 1] + carry) / 10;
        ans = to_string(sum) + ans;
    }
    ans = to_string(carry) + ans;
    int i = 0;
    for (i = 0; i < ans.size(); i++)
    {
        if (ans[i] != '0')
        {
            break;
        }
    }
    if (i == ans.size())
        return "0";
    return ans.substr(i);
}

// Merge two binary heap(it is the same problem of inserting elements in an array to made the array a max heap with 0 based indexing)
void insert(vector<int> &a, int n)
{
    int ele = a[n];
    int i = n;
    while (i > 0)
    {
        if (i % 2 == 0)
        {
            int parent = (i / 2) - 1;
            if (ele > a[parent])
            {
                a[i] = a[parent];
                i = parent;
            }
            else
                break;
        }
        else
        {
            int parent = i / 2;
            if (ele > a[parent])
            {
                a[i] = a[parent];
                i = parent;
            }
            else
            {
                break;
            }
        }
    }
    a[i] = ele;
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // your code here
    for (int i = 0; i < b.size(); i++)
    {
        a.push_back(b[i]);
        insert(a, a.size() - 1);
    }
    return a;
}

// Is Binary tree heap
//Time complexity:O(N) and Space complexity:O(N);
bool solve(struct Node *tree, int &count, long long int &sum, long long int label)
{
    if (tree == NULL)
    {
        return 1;
    }
    if (tree->right != NULL && tree->left == NULL)
        return 0;
    if (tree->left && tree->left->data > tree->data)
        return 0;
    if (tree->right && tree->right->data > tree->data)
        return 0;
    ++count;
    sum += label;
    return solve(tree->left, count, sum, 2 * label) && solve(tree->right, count, sum, 2 * label + 1);
}
bool isHeap(struct Node *tree)
{
    // code here
    int count = 0;
    long long int label = 1;
    long long int sum = 0;
    bool flag = solve(tree, count, sum, label);
    if (flag && ((count * (count + 1)) / 2) == sum)
        return 1;
    return 0;
}