#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={5,6,7,8};
    int *store=&arr[0];
    cout<<*store;
    cout<<sizeof(store)/sizeof(arr[0]);
}