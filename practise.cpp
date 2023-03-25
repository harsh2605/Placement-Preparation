// #include <bits/stdc++.h>
// using namespace std;
// #define ull unsigned long long
// #define ll long long
// void solve(vector<int> &vt)
// {
//     unordered_map<int, int> mp;
//     int i = 0, j = 0;
//     int maxi = INT_MIN, count = 0, point = 0;
//     int index = 0;
//     while (j < vt.size())
//     {
//         if (vt[j] == 0)
//             point++;
//         if (point <=1)
//         {
//             count++;
//             if (count > maxi)
//             {
//                 maxi = count;
//                 index = i;
//             }
//         }
//         else if (point > 1)
//         {
//             while (point != 1)
//             {
//                 if (vt[i] == 0)
//                     point--;
//                 i++;
//             }
//             if (j - i + 1 > maxi)
//             {
//                 maxi = j - i + 1;
//                 index = i;
//             }
//             count = j - i + 1;
//         }
//         j++;
//     }
//     cout << maxi << " " << index << endl;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> vt;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         vt.push_back(x);
//     }
//     solve(vt);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
pair<int, int> solve(vector<int> &vt, int &k)
{
    unordered_map<int, int> mp;
    int i = 0, j = 0;
    int maxi = INT_MIN, count = 0, point = 0;
    int index = 0;
    pair<int, int> pt{-1,-1};
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
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vt;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vt.push_back(x);
    }
    pair<int,int>ans=solve(vt, k);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}