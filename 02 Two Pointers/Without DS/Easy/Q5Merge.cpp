/*
Q5. Merge Two Sorted Arrays (in-place)
Merge nums2 into nums1 as one sorted array and return nums1.
Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Append and sort.
void brute(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = 0; i < n; i++)
    {
        nums1[m + i] = nums2[i];
    }
    sort(nums1.begin(), nums1.end());
}
// TC -> O((m+n)log(m+n)), SC -> O(1)

// Better -> Use new array to merge.
void better(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // Create a new array to hold the merged result
    vector<int> merged(m + n);
    int i = 0, j = 0, k = 0;

    // Merge the two arrays into the merged array
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            merged[k++] = nums1[i++];
        }
        else
        {
            merged[k++] = nums2[j++];
        }
    }

    // If any elements left in nums1, add them
    while (i < m)
    {
        merged[k++] = nums1[i++];
    }

    // If any elements left in nums2, add them
    while (j < n)
    {
        merged[k++] = nums2[j++];
    }

    // Copy the merged array back into nums1
    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = merged[i];
    }
}
// TC -> O(m+n), SC -> O(m+n)

// Optimal -> Merge backwards from the end.
void optimal(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}
// TC -> O(m+n), SC -> O(1)

// main function
int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    // Using brute force method
    vector<int> nums1_brute = nums1; // Copy to preserve original
    brute(nums1_brute, m, nums2, n);
    cout << "Brute Force Result: ";
    for (int i : nums1_brute)
    {
        cout << i << " ";
    }
    cout << endl;

    // Using better method
    vector<int> nums1_better = nums1; // Copy to preserve original
    better(nums1_better, m, nums2, n);
    cout << "Better Method Result: ";
    for (int i : nums1_better)
    {
        cout << i << " ";
    }
    cout << endl;

    // Using optimal method
    vector<int> nums1_optimal = nums1; // Copy to preserve original
    optimal(nums1_optimal, m, nums2, n);
    cout << "Optimal Method Result: ";
    for (int i : nums1_optimal)
    {
        cout << i << " ";
    }
    return 0;
}