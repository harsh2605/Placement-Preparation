// #include <bits/stdc++.h>
// using namespace std;
// int get_pivot_index(vector<int> &vt, int low, int high)
// {
//     int pivot = vt[low];
//     int i = low;
//     int j = high;
//     while (i < j)
//     {
//         while (vt[i] <= pivot && i <= high)
//         {
//             i++;
//         }
//         while (vt[j] > pivot && j >= low)
//         {
//             j--;
//         }
//         if (i < j)
//         {
//             swap(vt[i], vt[j]);
//         }
//     }
//     swap(vt[j], vt[low]);
//     return j;
// }
// void quick_sort(vector<int> &vt, int low, int high)
// {
//     if (low < high)
//     {
//         int partition = get_pivot_index(vt, low, high);
//         quick_sort(vt, low, partition - 1);
//         quick_sort(vt, partition + 1, high);
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> vt;
//     for (int i = 0; i < n; i++)
//     {
//         int n;
//         cin >> n;
//         vt.push_back(n);
//     }
//     quick_sort(vt, 0, vt.size() - 1);
//     for (int i = 0; i < vt.size(); i++)
//     {
//         cout << vt[i] << " ";
//     }
// }

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
int fibonnaci(int n,vector<int>&vt)
{
    if (n < 2)
        return n;
        if(vt[n]!=-1)
        return vt[n];
    vt[n]= fibonnaci(n - 1,vt) + fibonnaci(n - 2,vt);
    return vt[n];
}
int main()
{
    int n;
    cin >> n;
    vector<int>vt(n+1,-1);
    cout << fibonnaci(n,vt);
    return 0;
}