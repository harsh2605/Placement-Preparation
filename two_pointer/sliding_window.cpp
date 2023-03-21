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