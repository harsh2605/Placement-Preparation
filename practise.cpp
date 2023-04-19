#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
int bs(int l, int total, long amt, vector<int> &price)
{
    int low = l;
    int high = price.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (high - low) / 2 + low;
        if ((long)(price[mid] - amt) <= (long)total)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    if (ans == -1)
        return -1;
    else
        return ans;
}
void solve(vector<int> &price, vector<int> &pos, vector<long> &amount)
{
    vector<int> ans;
    for (int i = 0; i < pos.size(); i++)
    {
        int cur = 0;
        if (pos[i] - 1 != 0)
        {
            cur = price[pos[i] - 2];
        }
        long store = bs(pos[i] - 1, amount[i], cur, price);
        if (store == -1)
            ans.push_back(0);
        else
            ans.push_back(store - (pos[i] - 1) + 1);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> price, pos;
    vector<long> amount;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        price.push_back(sum);
    }
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        pos.push_back(x);
    }
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        amount.push_back(x);
    }
    solve(price, pos, amount);
    return 0;
}