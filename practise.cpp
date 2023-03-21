#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
void solve(string &s, int k)
{
    unordered_map<char, int> mp;
    int i = 0, j = 0, ans = 0;
    while (j < s.size())
    {
        mp[s[j]]++;
        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            ans++;
        }
        else
        {
            mp.erase(s[j]);
            while (mp.size() == k)
            {
                ans++;
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
        }
    }
}
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    solve(s, k);
    return 0;
}
