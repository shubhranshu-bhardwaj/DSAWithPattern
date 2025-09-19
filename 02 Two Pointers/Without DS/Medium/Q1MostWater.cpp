/*
Q1. Container With Most Water (LeetCode 11)
Given height[], find the maximum area of water a container can store between two lines.
Example:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Check all pairs
int brute(vector<int> &height)
{
    int n = height.size(), maxWater = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            maxWater = max(maxWater, min(height[i],height[j])*(j-i));
        }
    }
    return maxWater;
}
// TC -> O(N^2), SC -> O(1)

// Better == Optimal -> two pointers from ends; always move the pointer at the smaller height
// this may improve the chance of larger min-height while width shrinks.
int optimal(vector<int> &height)
{
    int left = 0, right = height.size() - 1, maxWater = 0;
    while (left < right)
    {
        int width = right - left;
        int ht = min(height[left], height[right]);
        maxWater = max(maxWater, ht * width);
        if (height[left] > height[right])
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return maxWater;
}
// TC -> O(N), SC -> O(1)

// main function
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << brute(height) << endl;
    cout << optimal(height) << endl;
    return 0;
}