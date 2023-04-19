// Rotate the matrix by 90 degree in clockwise direction
//[1,2,3]      [7,4,1]
//[4,5,6]   -> [8,5,2]
//[7,8,9]      [9,6,3]
// Approach ye hai ki uppar se diagonally cut karte jio aur waise hi swap hoga
// time complexity:O(N^2) and space complexity:O(1)
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < m; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// If you want to rotate the same matrix in anticlockwise direction which is similar to the question of finding transpose of a matrix we just need to rotate the matrix by clockwise in 90 degree and reverse the whole matrix
void rotate(vector<vector<int>> &matrix)
{
    // Your code goes here
    int n = matrix.size();
    int m = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < m; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    reverse(matrix.begin(), matrix.end());
}

// Kth smallest element in a matrix
// You have given a matrix in which the row are sorted and the columns are also sorted in ascending order
// You have to find the kth smallest element in the matrix
// The first approach will be using a priority_queue which will have always k elemets present and if the size of pq exceeds k than pop a element Tiem complexity:O(nlogk) space complexitry:O(k)
// To remove the space complexity we have used the below method
int less_ele(int &ele, vector<vector<int>> &mati, int &n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int store = upper_bound(mati[i].begin(), mati[i].end(), ele) - mati[i].begin();
        count += store;
    }
    return count;
}
int kthSmallest(vector<vector<int>> &mati, int k)
{
    int n = mati.size();
    int low = mati[0][0];
    int high = mati[n - 1][n - 1];
    while (low < high)
    {
        int mid = ((high - low) / 2) + low;
        // int mid=(low+high)/2;
        if (less_ele(mid, mati, n) < k)
        {
            low = mid + 1;
        }
        else
            high = mid;
    }
    return low;
}

// In this question you have given a matrix in which you have to find the common elements which are their in all the rows
// Time Complexity:O(n*m) space complexity:O(m)
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

// You have to find the largest rectangle in a matrix
// Approach : This question is similar to Largest area of a histogram in which we will maintain two array left and right and from the current postion we find out how many elements are greater than equal to the curret element and the same applies to the right side also and the final answer is (the current element height *(left+right+1));

void solve(vector<int> &dup, vector<int> &vt)
{
    int n = dup.size() - 1;
    stack<pair<int, int>> st; // it will store the next smaller element with its index;
    for (int i = dup.size() - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            vt.push_back(n - i);
        }
        else
        {
            while (!st.empty() && st.top().first >= dup[i])
            {
                st.pop();
            }
            if (st.empty())
                vt.push_back(n - i);
            else
                vt.push_back(st.top().second - 1 - i);
        }
        st.push({dup[i], i});
    }
}
int largest(vector<int> &heights)
{
    vector<int> dup = heights;
    vector<int> right, left;
    solve(dup, right);
    reverse(dup.begin(), dup.end());
    solve(dup, left);
    reverse(right.begin(), right.end());
    int maxi = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        maxi = max(maxi, heights[i] * (left[i] + right[i] + 1));
    }
    return maxi;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> vt(m, 0);
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
                vt[j] += '1' - '0';
            else
                vt[j] = 0;
        }
        maxi = max(maxi, largest(vt));
    }
    return maxi;
}

// Set the matrix to 0
// In this question what you have to do is that as you encountered a 0 make the row and column all elements as 0
// Time complexity:O(N*M) space complexity:O(1);
void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int mark = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    mark = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int i = 0; i < m; i++)
            matrix[0][i] = 0;
    }
    if (mark == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

// Diagonal Traversal of matrix
// Given input : 1 2 3
//               4 5 6
//               7 8 9
// Output : 1 4 2 7 5 3 8 6 9
vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans;
    for (int k = 0; k < n; k++)
    {
        int i = k;
        int j = 0;
        while (i >= 0 && j <= m - 1)
        {
            ans.push_back(mat[i][j]);
            i--;
            j++;
        }
    }
    for (int k = 1; k < m; k++)
    {
        int i = n - 1;
        int j = k;
        while (i >= 0 && j <= m - 1)
        {
            ans.push_back(mat[i][j]);
            i--;
            j++;
        }
    }
    return ans;
}

// Real diagonal matrix priting question on leetcode
//  Given input : 1 2 3
//                4 5 6
//                7 8 9
//  Output : 1 2 4 7 5 3 6 8 9
// First approach where we will use extra space by creating a map of int,vector here the time complexity will be
// Time Complexity:O(n*m)
// Space complexity:O(m+n-1) ie the number of diagonals present
vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans;
    map<int, vector<int>> mp;
    int mark = 0;
    for (int k = 0; k < n; k++)
    {
        int i = k;
        int j = 0;
        vector<int> temp;
        while (i >= 0 && j <= m - 1)
        {
            temp.push_back(mat[i][j]);
            i--;
            j++;
        }
        mp[mark] = temp;
        mark++;
    }
    for (int k = 1; k < m; k++)
    {
        int i = n - 1;
        int j = k;
        vector<int> temp;
        while (i >= 0 && j <= m - 1)
        {
            temp.push_back(mat[i][j]);
            i--;
            j++;
        }
        mp[mark] = temp;
        mark++;
    }
    mark = 0;
    for (auto itr : mp)
    {
        if (mark % 2 == 1)
        {
            reverse(itr.second.begin(), itr.second.end());
            for (int i = 0; i < itr.second.size(); i++)
            {
                ans.push_back(itr.second[i]);
            }
        }
        else
            for (int i = 0; i < itr.second.size(); i++)
            {
                ans.push_back(itr.second[i]);
            }
        mark++;
    }
    return ans;
}

// Same question with time complexity:O(N*M) and space complexity:O(1)(if we ignore the result vector)
vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int r = 0, c = 0;
    vector<int> ans;
    for (int i = 0; i < n * m; i++)
    {
        ans.push_back(mat[r][c]);
        if ((r + c) % 2 == 0)
        {
            if (c == m - 1)
            {
                r++;
            }
            else if (r == 0)
            {
                c++;
            }
            else
            {
                r--;
                c++;
            }
        }
        else
        {
            if (r == n - 1)
            {
                c++;
            }
            else if (c == 0)
            {
                r++;
            }
            else
            {
                c--;
                r++;
            }
        }
    }
    return ans;
}