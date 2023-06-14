// 1. Search in a rotated sorted array with only distinct elements present in the array;
// Approach we have to observe that when we are calculating the mid we have to check that which side is sorted either the left side or the right and if the target is between the sorted side we have to move their otherwise we have to mode in the unsorted side
int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (high - low) / 2 + low; // this can be (low+high)>>1
        if (nums[mid] == target)
            return mid;
        if (nums[low] <= nums[mid])
        {
            if (target >= nums[low] && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (target >= nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
    }
    return -1;
}

// Find the minimum in rotated sorted array
// Approach: The main approach is to all check to the high value whether it is greater than or less than the middle value if the high value is greater than the mid value than we can judge that the minimum cannot be find the right side so we eliminate the right side and we will point the high value to the mid because the mid value also be the answer and similarly if the high value is lesser than mid value than we will move the pointer to the right side ie low=mid+1;
int findMin(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (nums[high] < nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return nums[low];
}

// minimum in a rotated sorted array with duplicate elements;
// Approach: In the previous question we have eliminated the left and right when they are greater than or less than but in this case we have the case of equal elements also therefore we can't eliminate the full side when we encounter any equal element(ie:nums[mid]==nums[high])-->(lets take the case of 1 1 1 1 0 1 1 in this case if we have eliminated the whole right side when we see that 1==1 than we will miss 0 which is the lowest element therefore we will just shift the high value and make it high=high-1)
// The time complexity will be O(N) for the case lets take [1,1,1,1,1,1,1];
int findMin(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (nums[mid] < nums[high])
        {
            high = mid;
        }
        else if (nums[mid] == nums[high])
        {
            high = high - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return nums[low];
}

// Find the peak element
// approach: if the mid+1 value is smaller than the mid value than it is always a gurantee that a peak element will be their in the left side so we will eleminate the right side and if the mid+1 element is greater than the mid element than we will get a peak element in the right side so we will eliminate the left side
int findPeakElement(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (nums[mid + 1] < nums[mid])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}

// search in rotated sorted array with duplicate
bool search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        if (nums[middle] == target)
            return true;
        if ((nums[low] == nums[middle]) && (nums[middle] == nums[high]))
        {
            low++;
            high--;
        }
        else if (nums[low] <= nums[middle])
        {
            if ((target >= nums[low] && target <= nums[middle]))
                high = middle - 1;
            else
                low = middle + 1;
        }
        else
        {
            if (target >= nums[middle] && target <= nums[high])
                low = middle + 1;
            else
                high = middle - 1;
        }
    }
    return false;
}

// Finding the peak element in a matrix
// the peak element is the element in the matrix where the value surrounded by the particular value is lesser
// Approach : The basis approach is that we will do binary search on the rows and for the mid pointing row we will find the index of the maximum element because we will conclude from there is that both the elements to the left and right is smaller than the maximum element so we have to only check the top and bottom element
// So we will treat the entire column as solving the PEAK ELEMENT 1 qestion and apply the same logic
// Time complexity:O(n*logm)
int find_max(vector<vector<int>> &mat, int mid)
{
    int index = 0, maxi = INT_MIN;
    for (int i = 0; i < mat[0].size(); i++)
    {
        if (mat[mid][i] > maxi)
        {
            maxi = mat[mid][i];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int low = 0, high = mat.size() - 1;
    int index = 0;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        index = find_max(mat, mid);
        if (mat[mid + 1][index] < mat[mid][index])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {low, index};
}

// Single element
// You have given a sorted array whether all elements have duplicate except a single element you have to find that element only in the array
// Approach : Basically you have to see the indexing suppose you are at a index which is odd than you know that including that element all the element from the back count will be even and the nums[mid]==nums[mid-1] mean that the left ordering of elements are correct we have to move to the right side and similarly we have to do in case when we encounter any even index
int singleNonDuplicate(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        // This whole if can be replaced with if(nums[mid]==nums[mid^1])
        {
            low = mid + 1;
        }
        else
            high = mid;
    }
    return nums[low];
}

// Search in a 2-d matrix
// When the row is sorted and the first element of the row is greater than the last element of the previous row
// The same code is applicable of the matrix having row wise and column wise sorted matrix
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int i = 0, j = matrix[0].size() - 1;
    while (i < matrix.size() && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
        {
            j--;
        }
        else
            i++;
    }
    return false;
}

// Aggresive cows
// https://practice.geeksforgeeks.org/problems/aggressive-cows/1
bool check(vector<int> &stalls, int dis, int &k)
{
    int count = 0, i = 0, j = 1;
    while (j < stalls.size())
    {
        if (stalls[j] - stalls[i] >= dis)
        {
            count++;
            i = j;
            j++;
        }
        else
        {
            j++;
        }
    }
    if (count + 1 >= k)
        return true;
    return false;
}

int solve(int n, int k, vector<int> &stalls)
{

    // Write your code here
    sort(stalls.begin(), stalls.end());
    int low = 1, high = *max_element(stalls.begin(), stalls.end());
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (check(stalls, mid, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

// Peak Index in a mountain
// In this qns we have to find the index of the peak element and the peak element property is that all the number in the left side of the peak element is amller than the peak element in increasing fashion and in the right side in decreasing fashion
// Approach : we have to observe one thing is that we have to first set our low to 1 and high to the second last element of the array and after encountering any middle value we will check the mid+1 element if the mid+1 elements value is less than the mid value we will conclude from here is that we will not get any element in the right which will be peak so we move to the left side and the same applies to low.
// Time complexity: O(logn)
int peakIndexInMountainArray(vector<int> &arr)
{
    int low = 1, high = arr.size() - 2;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (arr[mid + 1] < arr[mid])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

// Find in mountain array
//  https://leetcode.com/problems/find-in-mountain-array/
// Approach : 3 step process : 1.calculate the peak element
//                             2.binary search on the left part
//                             3.binary search on the right part
// Time complexity :O(log n) and space complexity :O(1);
int left(int low, int high, MountainArray &mountainArr, int &target, int &ans)
{
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (mountainArr.get(mid) == target)
        {
            ans = mid;
            return true;
        }
        else if (mountainArr.get(mid) < target)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return false;
}
int right(int low, int high, MountainArray &mountainArr, int &target, int &ans)
{
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (mountainArr.get(mid) == target)
        {
            ans = mid;
            return true;
        }
        else if (mountainArr.get(mid) < target)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return false;
}
int peak(MountainArray &mountainArr)
{
    int low = 1, high = mountainArr.length() - 2;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (mountainArr.get(mid + 1) < mountainArr.get(mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int findInMountainArray(int target, MountainArray &mountainArr)
{
    int index = peak(mountainArr); // logn
    int ans = -1;
    if (mountainArr.get(index) == target)
        return index;
    if (left(0, index - 1, mountainArr, target, ans)) // logn
        return ans;
    right(index + 1, mountainArr.length() - 1, mountainArr, target, ans); // logn
    return ans;
}

// Minimum speed to arrive on time
int minSpeedOnTime(vector<int> &dist, double hour)
{
    int low = 1, high = 1e7 + 9;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        double total_time = 0;
        for (auto itr : dist)
        {
            total_time = ceil(total_time);
            total_time += ((double)itr / (double)mid);
        }
        if (total_time > hour)
        {
            low = mid + 1;
        }
        else
            high = mid;
    }
    return low >= 1e7 + 9 ? -1 : low;
}

// kth missing positive number
// https://leetcode.com/problems/kth-missing-positive-number/
int findKthPositive(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;
    if (arr[arr.size() - 1] - (arr.size()) == 0)
        return arr.size() + k;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int ele = arr[mid] - (mid + 1);
        if (ele < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (high == -1)
        return k;
    return arr[high] + (k - (arr[high] - (high + 1)));
}

// Find median in sorted matrix by row wise having only odd number of elements present in the matrix
int median(vector<vector<int>> &matrix, int R, int C)
{
    // code here
    int low = INT_MAX;
    int high = INT_MIN;
    for (int i = 0; i < R; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][C - 1]);
    }
    //    cout<<low<<" "<<high<<endl;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (bs(matrix, mid) > ((R * C) / 2))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}