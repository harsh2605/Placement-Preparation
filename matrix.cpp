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
//You have given a matrix in which the row are sorted and the columns are also sorted in ascending order
//You have to find the kth smallest element in the matrix
//The first approach will be using a priority_queue which will have always k elemets present and if the size of pq exceeds k than pop a element Tiem complexity:O(nlogk) space complexitry:O(k)
//To remove the space complexity we have used the below method
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

//In this question you have given a matrix in which you have to find the common elements which are their in all the rows
//Time Complexity:O(n*m) space complexity:O(m)