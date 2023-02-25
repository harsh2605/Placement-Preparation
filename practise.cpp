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