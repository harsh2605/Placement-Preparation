// This file is maintained to cover all the important question based on arrays and hashing,two pointers and prefix sum,suffix sum

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
// if the elements present in the array were from 1 to N and you donot have to modify the array than you will use cyle detection algorithm and use fast pointer and slow pointer concept(tc:O(N),sc:O(1))
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

// 12.find the if the sum of any subarray elements in the subarray sum upto 0 or not
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
// approach : Used here moore voting algo
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

// 16.Arrange the array elements as negative and positive elements with Time complexity O(N*N) and space complexity O(1)
// input:-5 -2 5 2 4 7 1 8 0 -8  output:-5 5 -2 2 -8 4 7 1 8 0

// This solution is O(N^3) solution
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
void right_rotate(vector<int> &vt, int start, int end)
{
    int ele = vt[end];
    for (int i = end - 1; i >= start; i--)
    {
        vt[i + 1] = vt[i];
    }
    vt[start] = ele;
}
void func(vector<int> &vt)
{
    for (int i = 0; i < vt.size(); i++)
    {
        if (i % 2 == 0 && vt[i] > 0)
        {
            for (int j = i + 1; j < vt.size(); j++)
            {
                if (vt[j] < 0)
                {
                    right_rotate(vt, i, j);
                    break;
                }
            }
        }
        else if (i % 2 == 1 && vt[i] < 0)
        {
            for (int j = i + 1; j < vt.size(); j++)
            {
                if (vt[j] > 0)
                {
                    right_rotate(vt, i, j);
                    break;
                }
            }
        }
    }
}
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
    func(vt);
    for (int i = 0; i < n; i++)
    {
        cout << vt[i] << " ";
    }
    return 0;
}

// 17.find the maximum product of the subarray
// In this question the basic approach wiil be to traverse the full array from the starting and store the maximum value at each step and similarly traverse the full array from the back and update the maximum value
// Time complexity: O(N) and space complexity:O(1)
long long maxProduct(vector<int> arr, int n)
{
    // code here
    long long maxii = 1;
    long long maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        maxii *= arr[i];
        maxi = max(maxi, maxii);
        if (maxii == 0)
        {
            maxii = 1;
        }
    }
    maxii = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        maxii *= arr[i];
        maxi = max(maxi, maxii);
        if (maxii == 0)
            maxii = 1;
    }
    return maxi;
}

// 18.Merge Intervals
// In this question we have to merge all the intervals
// input:[[1,3],[2,6],[8,10],[15,18]] output:[[1,6],[8,10],[15,18]]
// time complxity:O(N) ,Space complexity:O(1)
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());
    vector<int> temp = intervals[0];

    for (auto it : intervals)
    {
        if (temp[1] >= it[0])
        {
            temp[1] = max(temp[1], it[1]);
        }
        else
        {
            ans.push_back(temp);
            temp = it;
        }
    }

    ans.push_back(temp);

    return ans;
}

// 19.factorila of a number
// Normal method to calculate the factorial is using recursion with time complexity O(N)
int func(int n)
{
    if (n == 0)
        return 1;
    return n * func(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << func(n);
}

// 20.for big number factoial is find by different method time complexity of this approach will be
//  Time complexity:O(n*log(n!)) and space complexity : O(N)
vector<int> factorial(int N)
{
    // code here
    vector<int> store;
    store.push_back(1);
    int carry = 0;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < store.size(); j++)
        {
            int ele = store[j] * i + carry;
            store[j] = ele % 10;
            carry = ele / 10;
        }
        while (carry != 0)
        {
            store.push_back(carry % 10);
            carry /= 10;
        }
    }
    reverse(store.begin(), store.end());
    return store;
}

// 21.Minimum number of operations to bring all numbers <=k together
// This problem is similar to the problem where all ones are to be move to their adjacent by using minimum number of opeartion
// approach:In this we created a window size of number of element <=k and count the maximum element in the window which is <=k and the final answer will be (total_count-maxi)
int minSwap(int arr[], int n, int k)
{
    // Complet the function
    int i = 0, j = 0;
    int maxi = INT_MIN;
    int count = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            count++;
        }
    }
    while (j < n)
    {
        if (j - i + 1 < count)
        {
            if (arr[j] <= k)
            {
                ans++;
            }
            maxi = max(maxi, ans);
            j++;
        }
        else
        {
            if (arr[j] <= k)
            {
                ans++;
                maxi = max(maxi, ans);
            }
            if (arr[i] <= k)
            {
                ans--;
            }
            i++;
            j++;
        }
    }
    return count == 0 ? 0 : count - maxi;
}

// Prefix sum and hashing concepts
// Some important Properties of mod:
//(a+b)%k=((a%k)+(b%k))%k;
//(a-b)%k=((a%k)-(b%k))%k;
//(a*b)%k=((a%k)*(b%k))%k;
// 22.Continuous Subarray Sum(In this question  you have to find out their exist a subarray whose length is>=2 and the sum of that subaray is divisble by k)
// approach : It is based on the approach that if any number suppose 6%5==1 than if we add some arbitary contant into it (6+5)%5==1 (((6+5)-6)%5==0 (hence proved))and it is giving the same reminer than the arbitary number is divisble by k so that arbitary number is the sum of number in the range of first occurance of that reminder and second occurance oif that reminder
bool checkSubarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] += nums[i - 1];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % k == 0 && i != 0)
        {
            return true;
        }
        if (mp.find(nums[i] % k) != mp.end())
        {
            if (i - mp[nums[i] % k] > 1)
                return true;
        }
        else
        {
            mp[nums[i] % k] = i;
        }
    }
    return false;
}

// 23.Subarray sum divisible by k
// The main approach is if suppose sum part of the array is divible by k and leaves the remainder k than the equation will bes1=(k*n+x) and some part including that is divisble by k and leaves the remainder k than the equation will be s2=(k*m+x) therefore the final equation will be s1-s2=k*(n-m) therefore we can see that the remaining element are divisible by k
// If the remainder is newgative just add k to it
long long subCount(long long arr[], int N, long long k)
{
    // Your code goes here
    long long ans = 0;
    unordered_map<int, int> mp;
    mp[0]++;
    for (int i = 1; i < N; i++)
    {
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < N; i++)
    {
        int rem = arr[i] % k;
        if (rem < 0)
        {
            rem += k;
        }
        ans += mp[rem];
        mp[rem]++;
    }
    return ans;
}

// 24.Subarray sum equal to k
// prefix sum concept
// approach :The approach is if the sum of some range is y and y-k is also available than the range between them is k .
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    mp[0] = 1;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != 0)
            nums[i] += nums[i - 1];
        if (mp.find(nums[i] - k) != mp.end())
        {
            ans += mp[nums[i] - k];
        }
        mp[nums[i]]++;
    }
    return ans;
}

// 25. find the triplet sum time:O(N^2) space:O(N)
bool find3Numbers(int A[], int n, int X)
{
    // Your Code Here
    for (int i = 0; i < n; i++)
    {
        int store = X - A[i];
        unordered_map<int, int> mp;
        for (int j = i + 1; j < n; j++)
        {
            if (mp.find(store - A[j]) != mp.end())
                return true;
            mp[A[j]]++;
        }
    }
    return false;
}

// same question with time complexity O(N^2) and space:O(1);
bool find3Numbers(int A[], int n, int X)
{
    // Your Code Here
    sort(A, A + n);
    for (int i = 0; i < n; i++)
    {
        int low = i + 1, high = n - 1;
        int store = X - A[i];
        while (low < high)
        {
            if (A[i] + A[low] + A[high] == X)
            {
                return true;
            }
            if (A[low] + A[high] < store)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
    }
    return false;
}

// 26.Arraneg the array elements in alternating postive and negative elements without using any extra spaces
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
void right_rotate(vector<int> &vt, int start, int end)
{
    int ele = vt[end];
    for (int i = end - 1; i >= start; i--)
    {
        vt[i + 1] = vt[i];
    }
    vt[start] = ele;
}
void func(vector<int> &vt)
{
    for (int i = 0; i < vt.size(); i++)
    {
        if (i % 2 == 0 && vt[i] > 0)
        {
            int ele = -1;
            for (int j = i + 1; j < vt.size(); j++)
            {
                if (vt[j] < 0)
                {
                    ele = j;
                    break;
                }
            }
            if (ele != -1)
                right_rotate(vt, i, ele);
        }
        else if (i % 2 == 1 && vt[i] < 0)
        {
            int ele = -1;
            for (int j = i + 1; j < vt.size(); j++)
            {
                if (vt[j] > 0)
                {
                    ele = j;
                    break;
                }
            }
            if (ele != -1)
                right_rotate(vt, i, ele);
        }
    }
}
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
    func(vt);
    for (int i = 0; i < n; i++)
    {
        cout << vt[i] << " ";
    }
    return 0;
}

// 27.Find the median of two sorted array of different size
// time complexity O(log(m+n)) size :O(1)
// approach if the sum of size of both the arrays are odd than only return the middle element else return the sum of middle and the previous element
double MedianOfArrays(vector<int> &nums1, vector<int> &nums2)
{
    // Your code goes here
    int i = 0, j = 0;
    int size = (nums1.size() + nums2.size()) / 2;
    int count = 0, first = INT_MAX, sec = INT_MAX, p = 0; // where first define the n-1 th term and n defines the nth term
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
        {
            p = nums1[i];
            i++;
        }
        else
        {
            p = nums2[j];
            j++;
        }
        if (count == size - 1)
            first = p;
        if (count == size)
        {
            sec = p;
            break;
        }
        count++;
    }
    if (sec == INT_MAX)
    {
        while (i < nums1.size())
        {
            if (count == size - 1)
                first = nums1[i];
            if (count == size)
                sec = nums1[i];
            i++;
            count++;
        }
        while (j < nums2.size())
        {
            if (count == size - 1)
                first = nums2[j];
            if (count == size)
                sec = nums2[j];
            j++;
            count++;
        }
    }
    if ((nums1.size() + nums2.size()) & 1)
        return sec;
    return ((first + sec) / (double)2);
}