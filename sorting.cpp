// 1.Find missing and repeating number in an array having elements between 1-N
int *findTwoElement(int *arr, int n)
{
    // code here
    int ans[2] = {0, 0};
    for (int i = 0; i < n;)
    {
        if (arr[i] != arr[arr[i] - 1])
            swap(arr[arr[i] - 1], arr[i]);
        else
            i++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i + 1 != arr[i])
        {
            ans[0] = arr[i];
            ans[1] = i + 1;
            break;
        }
    }
    int *res = ans;
    return res;
}

// another solution
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        // code here
        for (int i = 0; i < n; i++)
        {
            arr[(arr[i] % (n + 1)) - 1] += (n + 1);
        }
        int rep = 0, mis = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 2 * (n + 1))
            {
                rep = i + 1;
            }
            else if (arr[i] < (n + 1))
            {
                mis = i + 1;
            }
        }
        int ans[2];
        ans[0] = rep;
        ans[1] = mis;
        int *anss = ans;
        return anss;
    }
};

// 2.Majority element(In this question you have to serahc the element which is present more than (n/2) times in the array)
// Approach:Here we will use moree's voting algorithm which deals with the counting of the number and different number appears it reduces its value and if the number stored in the ele is found it increments the value of the count, if the value of the count becomes 0 than it resets its value (bascially it check in every continuous array if the fixed element count becomes 0 therefore it means that in that particular part the element can't be a majority element)

int majorityElement(int a[], int size)
{
    // your code here
    int ele, count = 0;
    for (int i = 0; i < size; i++)
    {
        if (count == 0)
        {
            ele = a[i];
            count = 1;
        }
        else if (a[i] == ele)
        {
            count++;
        }
        else
            count--;
    }
    int cur = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == ele)
            cur++;
    }
    if (cur > (size / 2))
        return ele;
    return -1;
}

// 3.majority element 2 (count>(n/3) times)
vector<int> majorityElement(vector<int> &nums)
{
    int ele1 = INT_MIN, ele2 = INT_MIN, cnt1 = 0, cnt2 = 0;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt1 == 0 && ele2 != nums[i])
        {
            cnt1 = 1;
            ele1 = nums[i];
        }
        else if (cnt2 == 0 && ele1 != nums[i])
        {
            cnt2 = 1;
            ele2 = nums[i];
        }
        else if (nums[i] == ele1)
        {
            cnt1++;
        }
        else if (nums[i] == ele2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    int count1 = 0, count2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == ele1)
        {
            count1++;
        }
        else if (nums[i] == ele2)
        {
            count2++;
        }
    }
    if (count1 > (nums.size() / 3))
        ans.push_back(ele1);
    if (count2 > (nums.size() / 3))
        ans.push_back(ele2);
    return ans;
}

// 4.3sum problem(finding triplet which will sum upto 0)
// Time complexity:O(N^2) and space complexity:O(1)
// To get the unique triplet we will not consider the elements which will repeat and hence move the pointers accorndingly
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    if (nums.size() == 0 || nums.size() == 1)
        return res;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i == 0 || (i > 0 && (nums[i] != nums[i - 1])))
        {
            int low = i + 1, high = nums.size() - 1, store = 0 - nums[i];
            while (low < high)
            {
                if (nums[low] + nums[high] == store)
                {
                    vector<int> ans;
                    ans.push_back(nums[i]);
                    ans.push_back(nums[low]);
                    ans.push_back(nums[high]);
                    res.push_back(ans);
                    while (low < high && nums[low] == nums[low + 1])
                        low++;
                    while (low < high && nums[high] == nums[high - 1])
                        high--;
                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] < store)
                    low++;
                else
                    high--;
            }
        }
    }
    return res;
}

// 5.count triplet whose sum is less than the given value
long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    sort(arr, arr + n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            long long res = arr[i] + arr[j] + arr[k];
            if (res < sum)
            {
                ans += (k - j);
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return ans;
}

// 6.3sum closest (You have to find the triplet sum which is much closer to target or it can be target)
int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int ans, dif = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int j = i + 1, k = nums.size() - 1;
        while (j < k)
        {
            int store = nums[i] + nums[j] + nums[k];
            if (store == target)
            {
                return target;
            }
            else if (store < target)
            {
                if (abs(store - target) < dif)
                {
                    ans = store;
                    dif = abs(store - target);
                }
                j++;
            }
            else
            {
                if (abs(store - target) < dif)
                {
                    ans = store;
                    dif = abs(store - target);
                }
                k--;
            }
        }
    }
    return ans;
}

// 7.Merge two sorted arrays
// Input :arr1=[1,3,5,7] ,arr2=[0,2,6,8,9]
// output:arr1=[0,1,2,3] arr2=[5,6,7,8,9]

// In this the first approach will be we will take the first element of the second array and check with the last element of the first array if the second arrays element is smaller than the first array element than we will swap the numbers and move the pointers if it is not than we will break the loop and after that we will sort both the arrays

// The second approach will be gap method
// In this method what we do is that we will take the gap as =(arr1.size()+arr2.size())/2;
// Time complexity:O((n+m)*log(n+m))
// space complexity:O(1)
void solve(vector<int> &vt1, vector<int> &vt2)
{
    int gap = (vt1.size() + vt2.size()) / 2 + (vt1.size() + vt2.size()) % 2;
    int len = vt1.size() + vt2.size();
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // arr1 and arr1
            if (right < vt1.size() && vt1[left] < vt1[right])
            {
                swap(vt1[left], vt1[right]);
            }
            // arr1 and arr2
            else if (left < vt1.size() && vt1[left] < vt2[right - vt1.size()])
            {
                swap(vt1[left], vt2[right - vt1.size()]);
            }

            // arr2 and arr2
            else if (left >= vt1.size())
            {
                swap(vt2[left - vt1.size()], vt2[right - vt1.size()]);
            }
            left++;
            right++;
        }
        if (gap == 1)
            break;
        gap = gap / 2 + gap % 2;
    }
}

// 8.Zero sum subarray (find the number of subarrays in the array which has a sum of 0)
// Time complexity:O(n)
// space complexity:O(n)
long long int findSubarray(vector<long long int> &arr, int n)
{
    // code here
    unordered_map<long long int, long long int> mp;
    mp[0] = 1;
    int sum = 0, ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (mp.find(sum) != mp.end())
        {
            ans += mp[sum];
        }
        mp[sum]++;
    }
    return ans;
}

// 9.Product array puzzle(In this question you have to form an array with every element representing the product of all the elements in the array except the current element)
// If it is asked that you are not allowed to use the division operator than you can do this
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    // code here
    long long int pro = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        pro *= nums[i];
    }
    vector<long long int> ans;
    for (int i = 0; i < n; i++)
    {
        long long int temp = pro;
        long long int count = 0;
        while (temp != 0)
        {
            temp -= nums[i];
            count++;
        }
        ans.push_back(count);
    }
    return ans;
}