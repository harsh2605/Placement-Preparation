// Jump game
// In this question you have to only tell whether we can reach to the end of the array or not;
// The approach is that you have to find the maximum reachable point from every point and if you are at a index where you are not yet rechable means that is the break point and you can't reach to the end;
bool canJump(vector<int> &nums)
{
    int max_rechable = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (max_rechable < i)
            return false;
        max_rechable = max(max_rechable, i + nums[i]);
    }
    return true;
}

//Jump game 2
//In this question you have to count the minimum number of steps to reach at the last of the array