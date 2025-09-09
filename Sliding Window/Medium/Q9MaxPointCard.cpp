/*
Q9. Maximum Points From Cards
There are several cards arranged in a row, and each card has an associated number of points.
The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row.
You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1.
However, choosing the rightmost card first will maximize your total score.
The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Try all splits
int brute(vector<int> &a, int k)
{
    int n = a.size();
    int maxRes = INT_MIN;

    for (int i = 0; i <= k; ++i)
    {
        int sum = 0;

        // Take i cards from the front
        for (int j = 0; j < i; ++j)
        {
            sum += a[j];
        }

        // Take k - i cards from the back
        for (int j = 0; j < k - i; ++j)
        {
            sum += a[n - 1 - j];
        }

        maxRes = max(maxRes, sum);
    }

    return maxRes;
}
// TC -> O(k²)

// Better -> Start with taking all k from left; move one by one from left to right end using rolling updates.
int better(vector<int> &a, int k)
{
    int n = a.size();
    int sum = 0;

    // Start by taking all k cards from the front
    for (int i = 0; i < k; ++i)
    {
        sum += a[i];
    }
    int maxSum = sum;

    // Slide the window: remove from front, add from back
    for (int i = 1; i <= k; ++i)
    {
        sum -= a[k - i]; // remove from front
        sum += a[n - i]; // add from back
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}
// TC -> O(k)

// Optimal -> First calculate total sum then start shrinking the window, find minimum sum window
// then subtract from total sum
int optimal(vector<int> &a, int k)
{
    int n = a.size(), totalSum = 0, m = n - k;
    if (m == 0)
    {
        return accumulate(a.begin(), a.end(), 0);
    }
    for (int i = 0; i < n; i++)
    {
        totalSum += a[i];
    }
    int windowSum = 0, miniWindow = INT_MAX;
    int left = 0;
    for (int i = 0; i < n; i++)
    {
        windowSum += a[i];
        // shrink window from left if too big
        if (i - left + 1 > m)
        {
            windowSum -= a[left];
            left++;
        }
        if (i - left + 1 == m)
        {
            miniWindow = min(miniWindow, windowSum);
        }
    }
    return totalSum - miniWindow;
}
// TC -> O(n)

// main function
int main()
{
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    cout << "Brute Force Result: " << brute(cardPoints, k) << endl;
    cout << "Better Result: " << better(cardPoints, k) << endl;
    cout << "Optimal Result: " << optimal(cardPoints, k) << endl;

    return 0;
}