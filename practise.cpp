#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
void solve(vector<vector<int>> &vt)
{
    int n = vt.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[vt[0][i]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mp[vt[i][j]] == i)
            {
                mp[vt[i][j]] = i + 1;
                if (mp[vt[i][j]] == n)
                {
                    cout << vt[i][j] << " ";
                }
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vt;
    for (int i = 0; i < n; i++)
    {
        vector<int> res;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            res.push_back(x);
        }
        vt.push_back(res);
    }
    solve(vt);
    return 0;
}