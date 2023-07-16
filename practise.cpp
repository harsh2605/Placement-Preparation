#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
void solve(int n)
{
    vector<string> st;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        string str = "";
        for (int j = 0; j < n; j++)
        {
            str += to_string(count);
            if (j != n - 1)
            {
                str += "*";
            }
            count++;
        }
        st.push_back(str);
    }
    for (int i = 0; i < n; i++)
    {
        if (i != 1)
        {
            cout << st[i];
            cout << "\n";
        }
    }
    cout << st[1];
}
int main()
{
    int n;
    cin >> n;
    solve(n);

    return 0;
}