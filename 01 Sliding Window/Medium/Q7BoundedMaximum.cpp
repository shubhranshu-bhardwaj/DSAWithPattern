/*
Q7. Number of Subarrays With Bounded Maximum
Given nums and bounds [L,R], count subarrays whose max element is in [L, R].
a=[2,1,4,3], L=2, R=3 → valid: [2], [2,1], [3], [4,3]? no (max=4). Total 3.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> For each (i,j), track running max; count if L ≤ max ≤ R.
int brute(vector<int> &a, int L, int R)
{
    int n = a.size(), count = 0;
    for (int i = 0; i < n; i++)
    {
        int maxi = INT_MIN;
        for (int j = i; j < n; j++)
        {
            maxi = max(maxi, a[j]);
            if (maxi >= L && maxi <= R)
            {
                count++;
            }
        }
    }
    return count;
}
// TC -> O(n²)

// Optimal -> Track lastGreater (last index with >R) and
// lastInRange (last index with [L..R]). Each i contributes max(0, lastInRange - lastGreater).
int optimal(vector<int> &a, int L, int R)
{
    int n = a.size(), count = 0, lastGrt = -1, lastInRange = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > R)
        {
            lastGrt = i;
        }
        if (a[i] >= L && a[i] <= R)
        {
            lastInRange = i;
        }
        if (lastInRange != -1)
        {
            count += max(0, lastInRange - lastGrt);
        }
    }
    return count;
}
// TC -> O(n)

// main function
int main()
{
    vector<int> a = {2, 1, 4, 3};
    int L = 2, R = 3;

    // Brute-force method
    int resultBrute = brute(a, L, R);
    cout << "Brute-force Result: " << resultBrute << endl;

    // Optimal method
    int resultOptimal = optimal(a, L, R);
    cout << "Optimal Result: " << resultOptimal << endl;

    return 0;
}