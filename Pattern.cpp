// *
// **
// ***
// ****
// *****
// #include <bits/stdc++.h>
// using namespace std;
// #define ull unsigned long long
// #define ll long long
// void solve(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             cout << "* ";
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     solve(n);
//     return 0;
// }

// 1
// 12
// 123
// 1234
// 12345
// #include <bits/stdc++.h>
// using namespace std;
// #define ull unsigned long long
// #define ll long long
// void solve(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             cout <<j+1<<" ";
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     solve(n);
//     return 0;
// }

// 1
// 22
// 333
// 4444
// 55555
// #include <bits/stdc++.h>
// using namespace std;
// #define ull unsigned long long
// #define ll long long
// void solve(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             cout <<i+1<<" ";
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     solve(n);
//     return 0;
// }

// * * * * *
// * * * *
// * * *
// * *
// *
// #include <bits/stdc++.h>
// using namespace std;
// #define ull unsigned long long
// #define ll long long
// void solve(int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=n-i;j>0;j--)
//         {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     solve(n);
//     return 0;
// }

// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1
// #include <bits/stdc++.h>
// using namespace std;
// #define ull unsigned long long
// #define ll long long
// void solve(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j<n-i; j++)
//         {
//             cout <<j+1<<" ";
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     solve(n);
//     return 0;
// }

//     *
//    ***
//   *****
//  *******
// *********
// #include <bits/stdc++.h>
// using namespace std;
// #define ull unsigned long long
// #define ll long long
// void solve(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             cout << " ";
//         }
//         for (int j = 0; j < (2 * i + 1); j++)
//         {
//             cout << "*";
//         }
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             cout << " ";
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     solve(n);
//     return 0;
// }

// *********
//  *******
//   *****
//    ***
//     *
// #include<bits/stdc++.h>
// using namespace std;
// #define ull unsigned long long
// #define ll long long
// void solve(int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<i;j++)
//         {
//             cout<<" ";
//         }
//         for(int j=0;j<2*n-(2*i+1);j++)
//         {
//             cout<<"*";
//         }
//         for(int j=0;j<i;j++)
//         {
//             cout<<" ";
//         }
//         cout<<endl;
//     }
// }
// int main()
// {
// int n;
// cin>>n;
// solve(n);
// return 0;
// }


//     *    
//    ***   
//   *****  
//  ******* 
// *********
// *********
//  ******* 
//   *****  
//    ***   
//     *
// #include <bits/stdc++.h>
// using namespace std;
// #define ull unsigned long long
// #define ll long long
// void solve(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             cout << " ";
//         }
//         for (int j = 0; j < (2 * i + 1); j++)
//         {
//             cout << "*";
//         }
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             cout << " ";
//         }
//         cout << endl;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             cout << " ";
//         }
//         for (int j = 0; j < 2 * n - (2 * i + 1); j++)
//         {
//             cout << "*";
//         }
//         for (int j = 0; j < i; j++)
//         {
//             cout << " ";
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     solve(n);
//     return 0;
// }


// A
// AB
// ABC
// ABCD
// ABCDE
// #include<bits/stdc++.h>
// using namespace std;
// #define ull unsigned long long
// #define ll long long
// void solve(int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         char k='A';
//         for(int j=0;j<=i;j++)
//         {
//             cout<<char(k+j);
//         }
//         cout<<endl;
//     }
// }
// int main()
// {
// int n;
// cin>>n;
// solve(n);
// return 0;
// }

// E
// DE
// CDE
// BCDE
// ABCDE
// #include<bits/stdc++.h>
// using namespace std;
// #define ull unsigned long long
// #define ll long long
// void solve(int n)
// {
//     char k='A'+n-1;
//     for(int i=0;i<n;i++)
//     {
//         char store=k;
//         for(int j=0;j<=i;j++)
//         {
//             cout<<store;
//             store++;
//         }
//         k--;
//         cout<<endl;
//     }
// }
// int main()
// {
// int n;
// cin>>n;
// solve(n);
// return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
void solve(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 || i==n-1)
            {
                cout<<"*";
            }
            else if(j==0 || j==n-1)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
int main()
{
int n;
cin>>n;
solve(n);
return 0;
}