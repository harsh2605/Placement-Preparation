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