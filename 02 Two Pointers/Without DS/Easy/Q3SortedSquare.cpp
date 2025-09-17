/*
Q3. Sorted Squares
Return array of squares, sorted.
Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Square all and sort.
vector<int> brute(vector<int> &nums)
{
    int n = nums.size();
    vector<int> squared_nums(n);
    for (int i = 0; i < n; i++)
    {
        squared_nums[i] = abs(nums[i] * nums[i]);
    }
     sort(squared_nums.begin(), squared_nums.end());
    return squared_nums;
}
// TC -> O(NlogN), SC -> O(1)

// Better == Optimal -> Use two pointers (largest abs value at ends).
vector<int> optimal(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    int shift = right;
    vector<int> res(nums.size());
    while (left <= right)
    {
        if (abs(nums[left]) > abs(nums[right]))
        {
            res[shift] = nums[left] * nums[left];
            left++;
            shift--;
        }
        else
        {
            res[shift] = nums[right] * nums[right];
            right--;
            shift--;
        }
    }
    return res;
}
// TC -> O(N), SC -> O(N)

// main function
int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> res1 = brute(nums);
    for (int i : res1)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> res2 = optimal(nums);
    for (int i : res2)
    {
        cout << i << " ";
    }
    return 0;
}