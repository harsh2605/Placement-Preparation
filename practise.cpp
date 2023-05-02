#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
bool bs(vector<int> &vt, int maxi, int k)
{
    int total_ele = k * maxi;
    int cur = 0;
    for (int i = 0; i < vt.size(); i++)
    {
        if (vt[i] >= maxi)
        {
            cur += maxi;
        }
        else
        {
            cur += vt[i];
        }
        if (cur >= total_ele)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vt;
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        high += x;
        vt.push_back(x);
    }
    int low = 1, ans = 0;
    sort(vt.begin(), vt.end(), greater<int>());
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (bs(vt, mid, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}