#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
void insert_max_heap(vector<int> &vt, int &n) // Time is (logn)
{
    int i = n;
    int ele = vt[n];
    while (i > 1 && ele > vt[i / 2])
    {
        vt[i] = vt[i / 2];
        i = i / 2;
    }
    vt[i] = ele;
    n++;
}
int delete_node_max_heap(vector<int> &vt, int &n)
{
    int x=vt[n-1];
    int ele=vt[1];
    vt[1]=x;
    int i=1;
    int j=2*i;
    while(j<n-2)
    {
        if(vt[j+1]>vt[j])
        {
            j=j+1;
        }
        if(vt[j]>vt[i])
        {
            swap(vt[j],vt[i]);
            i=j;
            j=2*i;
        }
        else
        break;
    }

}
int main()
{
    vector<int> vt(100, 0);
    int n = 1;
    vt[n] = 49;
    insert_max_heap(vt, n);
    vt[n] = 56;
    insert_max_heap(vt, n);
    vt[n] = 78;
    insert_max_heap(vt, n);
    vt[n] = 98;
    insert_max_heap(vt, n);
    vt[n] = 34;
    insert_max_heap(vt, n);
    vt[n] = 30;
    insert_max_heap(vt, n);
    vt[n] = 3;
    insert_max_heap(vt, n);
    vt[n] = 87;
    insert_max_heap(vt, n);
    cout<<delete_node_max_heap(vt,n);
    cout<<delete_node_max_heap(vt,n);
    cout<<delete_node_max_heap(vt,n);
    for (int i = 1; i < n; i++)
    {
        cout << vt[i] << " ";
    }
    return 0;
}
