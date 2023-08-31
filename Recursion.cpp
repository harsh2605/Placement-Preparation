// One of the major difference between subarray,subsequence and subset is that:
// Subarray:

// Print all subsequence of the given array
// Time complexity:O(2^n) space complexity:O(n);
void solve(int index, vector<int> nums, vector<int> temp, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[index]);
    solve(index + 1, nums, temp, ans);
    temp.pop_back();
    solve(index + 1, nums, temp, ans);
}

// Merge sort
// Time complexity:O(NlogN)
// Space complexity :O(N)
void merge(vector<int> &nums, int low, int mid, int high)
{
    int first_arr = low;
    int sec_arr_start = mid + 1;
    vector<int> temp;
    while (first_arr <= mid && sec_arr_start <= high)
    {
        if (nums[first_arr] < nums[sec_arr_start])
        {
            temp.push_back(nums[first_arr]);
            first_arr++;
        }
        else
        {
            temp.push_back(nums[sec_arr_start]);
            sec_arr_start++;
        }
    }
    while (first_arr <= mid)
    {
        temp.push_back(nums[first_arr]);
        first_arr++;
    }
    while (sec_arr_start <= high)
    {
        temp.push_back(nums[sec_arr_start]);
        sec_arr_start++;
    }
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}
void merge_sort(vector<int> &nums, int low, int high)
{
    ///  cout<<"harsh";
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    merge_sort(nums, low, mid);
    merge_sort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}
vector<int> sortArray(vector<int> &nums)
{
    int n = nums.size() - 1;
    merge_sort(nums, 0, n);
    return nums;
}

// Combination sum
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Time compelxity:O(2^k*k);
// Space complexity:O(k*x) where k is the average length of the array and x is the number of combinaton
void solve(int index, vector<int> &can, vector<vector<int>> &ans, vector<int> temp, int target)
{
    if (index == can.size())
    {
        if (target == 0)
            ans.push_back(temp);
        return;
    }
    if (can[index] <= target)
    {
        temp.push_back(can[index]);
        solve(index, can, ans, temp, target - can[index]);
        temp.pop_back();
    }
    solve(index + 1, can, ans, temp, target);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, candidates, ans, temp, target);
    return ans;
}

// Combination sum 2 leetcode
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Time complexity:O(2^N)
void solve(int index, vector<vector<int>> &ans, vector<int> temp, vector<int> &can, int target)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = index; i < can.size(); i++)
    {
        if (i > index && can[i] == can[i - 1])
            continue;
        if (can[i] > target)
            break;
        temp.push_back(can[i]);
        solve(i + 1, ans, temp, can, target - can[i]);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, ans, temp, candidates, target);
    return ans;
}

// Subset sum 1
// finding the sum of all the subsets of an array
void solve(vector<int> &ans, int temp, vector<int> &nums, int index)
{
    if (index == nums.size())
    {
        ans.push_back(temp);
        return;
    }
    temp += nums[index];
    solve(ans, temp, nums, index + 1);
    temp -= nums[index];
    solve(ans, temp, nums, index + 1);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    int temp = 0;
    vector<int> ans;
    solve(ans, temp, arr, 0);
    return ans;
}

// Subset 2
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// finding all the unique subset
void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, int index)
{
    ans.push_back(temp);
    for (int i = index; i < nums.size(); i++)
    {
        if (i > index && nums[i] == nums[i - 1])
            continue;
        temp.push_back(nums[i]);
        solve(nums, ans, temp, i + 1);
        temp.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    solve(nums, ans, temp, 0);
    return ans;
}

// Permutation
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Time complexity:O(N!)*N
// Space complexity:O(N)+O(N)
void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, unordered_map<int, int> mp)
{
    if (temp.size() == nums.size())
    {
        ans.push_back(temp);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp[i] == 0)
        {
            temp.push_back(nums[i]);
            mp[i]++;
            solve(nums, ans, temp, mp);
            mp[i] = 0;
            temp.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    unordered_map<int, int> mp;
    solve(nums, ans, temp, mp);
    return ans;
}

// Permutation without using extra space only swaping technique is used
void solve(int index, vector<int> &nums, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(index + 1, nums, ans);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, nums, ans);
    return ans;
}

// Count inversion in this question you have to count the number of elements in the given array which form a pair such that arr[i]>arr[j] where i<j
// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
//  Output: 3
//  Explanation: The sequence 2, 4, 1, 3, 5
//  has three inversions (2, 1), (4, 1), (4, 3).

Approach:To solve this question we have use merge sort concept for getting a time complexity of O(NlogN)
where we see that when we have two sorted arrays at the time of combining we count the number of inversion part

    void
    merge(long long arr[], long long N, long long mid, long long low, long long high, long long &count)
{
    vector<long long> temp;
    long long i = low, j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            count += (mid - i + 1);
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= high)
    {
        temp.push_back(arr[j++]);
    }
    for (int k = low; k <= high; k++)
    {
        arr[k] = temp[k - low];
    }
}
void merge_sort(long long arr[], long long N, long long &count, long long low, long long high)
{
    if (low >= high)
    {
        return;
    }
    long long mid = (low + high) / 2;
    merge_sort(arr, N, count, low, mid);
    merge_sort(arr, N, count, mid + 1, high);
    merge(arr, N, mid, low, high, count);
}
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long count = 0;
    long long high = N - 1;
    merge_sort(arr, N, count, 0, high);
    return count;
}