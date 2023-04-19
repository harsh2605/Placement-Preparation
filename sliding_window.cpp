// In the sliding window concept their are basically 3 things in which the questions are divided:
// 1.atmost
// 2.atleast
// 3.Exactly

// Subarray Product Less Than K
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int ans = 0;
    int i = 0, j = 0;
    long long sum = 1;
    while (j < nums.size())
    {
        sum *= nums[j];
        // cout<<sum<<endl;
        while (i < nums.size() && sum >= k)
        {
            sum /= nums[i];
            i++;
        }
        if (j >= i)
            ans += (j - i + 1);
        j++;
    }
    return ans;
}

// subarray sum less than k
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int ans = 0;
    int i = 0, j = 0;
    long long sum = 1;
    while (j < nums.size())
    {
        sum += nums[j];
        while (i < nums.size() && sum >= k)
        {
            sum -= nums[i];
            i++;
        }
        if (j >= i)
            ans += (j - i + 1);
        j++;
    }
    return ans;
}

// Count number of substring in which their are atleast k distinct characters
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
int solve(string &s, int k)
{
    int i = 0, j = 0, count = 0;
    unordered_map<char, int> mp;
    while (j < s.size())
    {
        mp[s[j]]++;
        j++;
        while (mp.size() >= k)
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0)
                mp.erase(s[i]);
            count += s.size() - j + 1;
            i++;
        }
    }
    return count;
}

// Subarray with k different integers
// Same variation question of counting substring having exactly k distinct characters
// This question is the variation of using both atmost k charcaters and than finding exactly k characters subarrays
// Approach find the count of number of subarrays having atmost k charcaters and subtract it from the number of arrays having exactly k-1 distinct characters
int atmost_k_characters(vector<int> &nums, int k)
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
    return atmost_k_characters(nums, k) - atmost_k_characters(nums, k - 1);
}

// Number of Substrings Containing All Three Characters
// You are provided with a string containing of only three characters a,b,c in repeated manner you have to count the total number of substring which has 3 character.
// Approach : Isme bas jab hume 3 character wala substring encounter ho jiega than all the characters next to the substring ke sath wo substring to baniega hi na to uske n-j se count kar lengai jab tak map ka size is=3 usko repeatedly add karte ja rhe hai
int numberOfSubstrings(string s)
{
    int n = s.size(), count = 0;
    unordered_map<char, int> mp;
    int i = 0, j = 0;
    while (j < s.size())
    {
        mp[s[j]]++;
        if (mp.size() == 3)
        {
            while (mp.size() == 3)
            {
                count += n - j;
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    return count;
}

// Very important question
// Sliding window maximum
// Given a k in every iteration we have to find the maximum element present in the window of size k
// Approach Here we use the data structure deque which will store the maximum element in the front() and all the elements which are smaller than the first element in the back in a sorted order of non-decreasing order
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> dq;
    int i = 0, j = 0;
    while (j < nums.size())
    {
        while (!dq.empty() && nums[j] > dq.back())
        {
            dq.pop_back();
        }
        dq.push_back(nums[j]);
        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            ans.push_back(dq.front());
            if (dq.front() == nums[i])
            {
                dq.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}

// Given a binary array, find the maximum sequence of continuous 1’s that can be formed by replacing at most k zeroes by ones.
pair<int, int> solve(vector<int> &vt, int &k)
{
    unordered_map<int, int> mp;
    int i = 0, j = 0;
    int maxi = INT_MIN, count = 0, point = 0;
    int index = 0;
    pair<int, int> pt{-1, -1};
    while (j < vt.size())
    {
        if (vt[j] == 0)
            point++;
        if (point <= k)
        {
            count++;
            if (count > maxi)
            {
                maxi = count;
                pt.first = i;
                pt.second = j;
            }
        }
        else if (point > k)
        {
            while (point != k)
            {
                if (vt[i] == 0)
                    point--;
                i++;
            }
            if (j - i + 1 > maxi)
            {
                maxi = j - i + 1;
                pt.first = i;
                pt.second = j;
            }
            count = j - i + 1;
        }
        j++;
    }
    return pt;
}

// Given an array. Calculate the sum of lengths of contiguous subarrays having all distinct elements.
int sumoflength(int s[], int n)
{
    unordered_map<int, int> mp;
    int i = 0, j = 0, count = 0;
    while (j < n)
    {
        mp[s[j]]++;
        if (mp.size() == j - i + 1)
        {
            int store = j - i + 1;
            count += ((store) * (store + 1)) / 2;
            j++;
        }
        else
        {
            while (mp.size() != j - i + 1)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            count += ((j - i + 1) * (j - i + 2)) / 2;
            j++;
        }
    }
    return count;
}

// Shortest Subarray with sum at least k
// Isme humko jo deque bananana hota hai wo hamesa monotonically increasing hona chaiye
int shortestSubarray(vector<int> &nums, int k)
{
    deque<pair<long long int, long long int>> dq;
    long long int i = 0, j = 0, sum = 0;
    long long int mini = INT_MAX;
    while (j < nums.size())
    {
        sum += nums[j];
        if (sum >= k)
        {
            mini = min(mini, j + 1);
        }
        pair<int, int> curr = {INT_MAX, INT_MAX};
        while (!dq.empty() && sum - dq.front().first >= k)
        {
            mini = min(mini, j - dq.front().second);
            curr = dq.front();
            dq.pop_front();
        }
        while (!dq.empty() && sum <= dq.back().first)
        {
            dq.pop_back();
        }
        dq.push_back({sum, j});
        j++;
    }
    return mini == INT_MAX ? -1 : mini;
}