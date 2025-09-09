/*
Q8. Grumpy Bookstore Owner (fixed-size gain window)
customers[i] and grumpy[i] (0/1). Owner can apply a secret technique for exactly X minutes
to convert grumpy minutes to not-grumpy. Maximize satisfied customers.
Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
Output: 16
Explanation:
The bookstore owner keeps themselves not grumpy for the last 3 minutes.
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Brute -> Loop over the entire day and calculate how many customers are satisfied without using the technique.
Then, for each possible X-minute window, calculate how many unsatisfied customers could be turned
satisfied if the owner uses the technique during that window.
*/
int bruet(vector<int> &cust, const vector<int> &grumpy, int X)
{
    int n = cust.size(), baseSat = 0, bestExtraSat = 0;
    // first calculate without technique
    for (int i = 0; i < n; i++)
    {
        if (grumpy[i] == 0)
        {
            baseSat += cust[i];
        }
    }
    // now calculate for extra using technique
    for (int i = 0; i + X <= n; i++)
    {
        int extraSat = 0;
        for (int j = i; j < i + X; j++)
        {
            if (grumpy[j] == 1)
            {
                extraSat += cust[j];
            }
        }
        bestExtraSat = max(bestExtraSat, extraSat);
    }
    return baseSat + bestExtraSat;
}
// TC -> O(n * X)

// Better == Optimal -> Compute base once; slide a window of size X accumulating extra only where grumpy==1.
int optimal(vector<int> &cust, const vector<int> &grumpy, int X)
{
    int n = cust.size(), baseSat = 0, bestExtraSat = 0, extraSat = 0;
    // first calculate without technique
    for (int i = 0; i < n; i++)
    {
        if (grumpy[i] == 0)
        {
            baseSat += cust[i];
        }
    }
    // calculate for first window with technique
    for (int i = 0; i < X; i++)
    {
        if (grumpy[i] == 1)
        {
            extraSat += cust[i];
        }
    }
    bestExtraSat = extraSat;
    // Slide the window from i = X to n - 1
    for (int i = X; i < n; i++)
    {
        // Add new right element if grumpy
        if (grumpy[i] == 1)
            extraSat += cust[i];
        // Remove left element (i - X) if grumpy
        if (grumpy[i - X] == 1)
            extraSat -= cust[i - X];
        // Update max extra
        bestExtraSat = max(bestExtraSat, extraSat);
    }
    return baseSat + bestExtraSat;
}
// TC -> O(n)

// main function
int main()
{
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int X = 3;

    // Use brute force method
    int bruteAns = bruet(customers, grumpy, X);
    cout << "Brute Force Answer: " << bruteAns << endl;

    // Use optimal method
    int optimalAns = optimal(customers, grumpy, X);
    cout << "Optimal Answer: " << optimalAns << endl;

    return 0;
}