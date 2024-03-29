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

// with time complexity O((N+M)log(N+M)) and space complexity O(1)(Have to complete using gap method)
// Merge two sorted array with time complexity of O((N+M)log(N+M)) ans space complexity of(O(1))
//   (Here we uses gap algorithm to solve this problem where you can find the gap using formula(ceil((n1+n2)/2)) and linearly iterating over the elements present in both the arrays having a gap you have to perform the operation untill gap is>=1(if the gap element first >elemtn last than swap both the values)
void swaping(long long arr1[], long long arr2[], int ind1, int ind2)
{
    if (arr1[ind1] > arr2[ind2])
    {
        swap(arr1[ind1], arr2[ind2]);
    }
}
void merge(long long arr1[], long long arr2[], int n, int m)
{
    // code here
    int len = n + m;
    int gap = (len / 2) + (len % 2); // findng the ceil value by this method
    while (gap)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // arr1 and arr2
            if (left < n && right >= n)
            {
                swaping(arr1, arr2, left, right - n);
            }
            // arr2 and arr2
            else if (left >= n)
            {
                swaping(arr2, arr2, left - n, right - n);
            }
            // arr1 and arr1
            else
            {
                swaping(arr1, arr1, left, right);
            }
            left++;
            right++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
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

// find the duplicate element in O(1) time complexity without modifying the array
// Here we use HARE AND THE TORTOISE APPROACH(slow and fast pointer)
// Time complexity is : O(N)
// Space complexity is : O(1)

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
int solve(vector<int> vt)
{
    int slow = vt[0];
    int fast = vt[0];
    do
    {
        slow = vt[slow];
        fast = vt[vt[fast]];
    } while (slow != fast);
    fast = vt[0];
    while (fast != slow)
    {
        slow = vt[slow];
        fast = vt[fast];
    }
    return fast;
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
    cout << solve(vt);
    return 0;
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

// 14.Three way partioning of the array in this question we have to arrange the array in such a way such that the value of the first section of the array is less than the value of a in range [a,b] and the value greater than b lies in the last and the rest in the center of the array
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
    count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == ele)
        {
            count++;
        }
    }
    if (count > (nums.size() / 2))
        return ele;
    // if no element present in the array is present more than (n/2) times
    return -1;
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

// 26.Arrange the array elements in alternating postive and negative elements without using any extra spaces
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

// 28.Subarray with k different integers
// Here we use the concept of subtracting substrings with atmost k charcter with atmost k-1 characters
int calc(vector<int> &nums, int k)
{
    int i = 0, j = 0;
    unordered_map<int, int> mp;
    int count = 0;
    while (j < nums.size())
    {
        mp[nums[j]]++;
        while (mp.size() > k)
        {
            mp[nums[i]]--;
            if (mp[nums[i]] == 0)
                mp.erase(nums[i]);
            i++;
        }
        count += (j - i + 1);
        j++;
    }
    return count;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return calc(nums, k) - calc(nums, k - 1);
}

// 29.contigious subarray
// In this question we have to find the longest subarray with equal numbers of 0's and 1's
// The approach is make all the 0 in the array as -1 and calculate the longest substring having sum 0
int findMaxLength(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            nums[i] = -1;
    }
    int j = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    int maxi = 0, sum = 0;
    while (j < nums.size())
    {
        sum += nums[j];
        if (mp.find(sum) != mp.end())
        {
            maxi = max(maxi, j - mp[sum]);
        }
        else
        {
            mp[sum] = j;
        }
        j++;
    }
    return maxi;
}

// range sum query-immutable
// In this question what we have to do is that we have to calculate the sum of the element in the given range continuously
// so the brute force approach will be to calculate the sum by traversing through each element and summing up
vector<vector<int>> store;
void NumMatrix(vector<vector<int>> &matrix)
{
    store = matrix;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[0].size(); j++)
        {
            store[i][j] += store[i][j - 1];
        }
    }
}

int sumRegion(int row1, int col1, int row2, int col2)
{
    int sum = 0;
    for (int i = row1; i <= row2; i++)
    {
        if (col1 == 0)
        {
            sum += store[i][col2];
        }
        else
        {
            sum += (store[i][col2] - store[i][col1 - 1]);
        }
    }
    return sum;
}

// Finding factorial of larger number using array;
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
void solve(int n)
{
    vector<int> store;
    store.push_back(1);
    while (n--)
    {
        int carry = 0;
        for (int i = 0; i < store.size(); i++)
        {
            int temp = store[i] * n + carry;
            carry = carry / 10;
            store[i] = temp % 10;
            if (carry != 0)
            {
                store.push_back(carry);
                break;
            }
        }
    }
    reverse(store.begin(), store.end());
    for (int i = 0; i < store.size(); i++)
    {
        cout << store[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}

// Array ADT raw implementation
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
class Arr_adt
{
private:
    int *array;
    int size;
    int capacity;

public:
    Arr_adt() // making of constructor
    {
        capacity = 1;
        size = 0;
        array = new int[capacity];
    }
    Arr_adt(int capacity) // User defined
    {
        this->capacity = capacity;
        size = 0;
        array = new int[capacity];
    }
    int getCapacity() { return capacity; }
    int getSize() { return size; }
    void push_back(int value)
    {
        if (size == capacity)
        {
            growArray();
        }
        array[size] = value;
        size++;
    }
    void pop_back()
    {
        array[size - 1] = 0;
        size--;
        if (size == (capacity / 2))
        {
            shrinkArray();
        }
    }
    void growArray()
    {
        int *temp = new int[capacity * 2];
        capacity *= 2;
        for (int i = 0; i < size; i++)
        {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
    }
    void shrinkArray()
    {
        capacity = size;
        int *temp = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
    }
    void print_array()
    {
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
    }
};
int main()
{
    Arr_adt arr;
    arr.push_back(5);
    arr.push_back(7);
    arr.push_back(9);
    arr.push_back(10);
    arr.print_array();
    return 0;
}

