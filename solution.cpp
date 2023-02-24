// programme to find the second minimum of a number in O(N) time complexity in one go
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
int main()
{
    int n;
    cin >> n;
    vector<int> vt;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vt.push_back(x);
    }
    int mini = vt[0];
    int sec_mini = vt[1];
    if (mini > sec_mini)
    {
        int temp = mini;
        mini = sec_mini;
        sec_mini = temp;
    }
    for (int i = 2; i < n; i++)
    {
        if (vt[i] < mini)
        {
            sec_mini = mini;
            mini = vt[i];
        }
        else if (vt[i] < sec_mini && vt[i] > mini)
        {
            sec_mini = vt[i];
        }
    }
    cout << sec_mini << " " << mini << endl;
    return 0;
}

// programme to merge two sorted array without using any extra spaces
// time complexity:O(M*N)
// space complexity:O(1)
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
void swap(int &a, int &b)
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}
void merge(vector<int> &vt1, vector<int> &vt2)
{
    int i = 0, j = 0;
    while (i < vt1.size())
    {
        if (vt1[i] > vt2[0])
        {
            swap(vt1[i], vt2[0]);
        }
        int pos = 1, start = vt2[0];
        while (pos < vt2.size() && vt2[pos] < start)
        {
            vt2[pos - 1] = vt2[pos];
            pos++;
        }
        vt2[pos - 1] = start;
        i++;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vt1, vt2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vt1.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        vt2.push_back(x);
    }
    merge(vt1, vt2);
    for (int i = 0; i < n; i++)
    {
        cout << vt1[i] << " ";
    }
    for (int i = 0; i < m; i++)
    {
        cout << vt2[i] << " ";
    }
    return 0;
}

// with time complexity O(Nlogn) and space complexity O(1)(Have to complete using gap method)
// Merge two sorted array with time complexity of (O(N*logN)) ans space complexity of(O(1))
//   (Here we uses gap algorithm to solve this problem where you can find the gap using formula(ceil((n1+n2)/2)) and linearly iterating over the elements present in both the arrays having a gap you have to perform the operation untill gap is>=1(if the gap element first >elemtn last than swap both the values)
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
void merge(vector<int> &vt1, vector<int> &vt2)
{
    int i = 0;
    int store = (ceil((vt1.size() + vt2.size()) / (float)2));
    while (store != 0)
    {
        int ele = store;
        while (ele--)
        {
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vt1, vt2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vt1.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        vt2.push_back(x);
    }
    merge(vt1, vt2);
    for (int i = 0; i < n; i++)
    {
        cout << vt1[i] << " ";
    }
    for (int i = 0; i < m; i++)
    {
        cout << vt2[i] << " ";
    }
    return 0;
}

// find duplcaite elements in O(1) Space complexity
// input:{2,3,1,2,3} output:2,3
// In this question the elements present in the array is between 1 to N-1
vector<int> duplicates(int arr[], int n)
{
    // code here
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int store = arr[i] % n;
        arr[store] += n;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 2 * n)
        {
            ans.push_back(i);
        }
    }
    if (ans.size() == 0)
        return {-1};
    return ans;
}

// 11.Rearrange the elements of the array in the way it is like Max_element,min_element,sec_max,sec_min element and so on.... input: 1 2 3 4 5 6 output:6 1 5 2 4 3
// In this qeuestion we have take the max_ele as the element which is not a multiple of any of the number present in the array (TC:O(N) SC: O(1))
void rearrange(long long *arr, int n)
{

    // Your code here
    int start = 0, end = n - 1, max_ele = *max_element(arr, arr + n) + 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = (arr[end] % max_ele) * max_ele + arr[i];
            end--;
        }
        else
        {
            arr[i] = (arr[start] % max_ele) * max_ele + arr[i];
            start++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] /= max_ele;
    }
}

// 12.find the if the sum of any subarray elements in the subarray sum upyo 0 or not
// input:{4 2 -3 1 6} output:YES(2,-3,1) sum upto 0;
// My approach using prefix sum if two elements sum upto the same value || any sumation value is 0 than YES if no such elemets present than NO

bool subArrayExists(int arr[], int n)
{
    // Your code here
    unordered_map<int, int> mp;
    mp[arr[0]]++;
    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
        if (mp[arr[i]] != 0 || arr[i] == 0)
        {
            return true;
        }
        mp[arr[i]]++;
    }
    if (mp.size() == 1 && mp[0] == 1)
        return true;
    return false;
}

// 13.Find the longest consequitive sequence input:{2,6,1,9,4,5,3} output:6
// since :1 2 3 4 5 6 exist in the array and are in a consequitive manner
// The approach was to use a unordered set and than push all the elements in the unordered_set than linearly traverse over the nums array and check if nums[i]-1 element is present in the array if the element is present in the array we will do nothing and if it is not present in the array we will count it and find nums[i]+1 is present in the set and count it.
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]);
    }
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        if (st.find(ele - 1) == st.end())
        {
            while (st.find(ele) != st.end())
            {
                ele++;
            }
            ans = max(ans, ele - nums[i]);
        }
    }
    return ans;
}

// 14.Three way partioning of the array in this question we have to arrange the array in such a way such that the value of the first section of the array if less than the value of a in range [a,b] and the value greater than b lies in the last and the rest in the center of the array
// same as DNF algorithm
void threeWayPartition(vector<int> &nums, int a, int b)
{
    // code here
    int first = 0, sec = 0, last = nums.size() - 1;
    while (sec <= last)
    {
        if (nums[sec] < a)
        {
            swap(nums[sec], nums[first]);
            first++;
            sec++;
        }
        else if (nums[sec] >= a && nums[sec] <= b)
        {
            sec++;
        }
        else if (nums[sec] > b)
        {
            swap(nums[sec], nums[last]);
            last--;
        }
    }
}

// 15.In this question you have to find which element in the array occurs more than size/2 time in the array
// time complexity:O(N) and space complexity:O(1);
// approach : Used here moore voting algorithm
int majorityElement(vector<int> &nums)
{
    int count = 1, ele = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (ele == nums[i])
        {
            count++;
        }
        else if (count == 0)
        {
            ele = nums[i];
            count++;
        }
        else
        {
            count--;
        }
    }
    return ele;
}