/*
Q10. Count Distinct Elements in Every Window of Size K
Given array a and k, return an array where each element is the count of distinct elements
in that window of size k.
a=[1,2,1,3,4,2], k=3
window [1,2,1] -> distinct {1,2} -> 2
window [2,1,3] -> {1,2,3} -> 3
window [1,3,4] -> {1,3,4} -> 3
window [3,4,2] -> {2,3,4} -> 3
Output: [2,3,3,3]
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> For every window, insert elements into a set → size of set = distinct count.
vector<int> countBrute(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> ans; // to store count of distinct

    for (int i = 0; i <= n - k; i++)
    {
        unordered_set<int> st;
        for (int j = i; j < i + k; j++)
        {
            st.insert(arr[j]);
        }
        ans.push_back(st.size());
    }
    return ans;
}
// TC -> O(n * k * log k)

// Better / Optimal -> Maintain frequency hashmap for current window.
// When sliding: decrement freq of outgoing element (erase if 0), increment freq of incoming.
// Distinct count is hashmap size.

vector<int> countOptimal(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        // if out of window
        if (i >= k)
        {
            mp[arr[i - k]]--;
            if (mp[arr[i - k]] == 0)
            {
                mp.erase(arr[i - k]);
            }
        }
        // if inside window
        if (i >= k - 1)
        {
            ans.push_back(mp.size());
        }
    }
    return ans;
}
// TC -> O(n)

// main function
int main()
{
    vector<int> arr = {1, 2, 1, 3, 4, 2};
    int k = 3;

    // Brute force method
    vector<int> bruteResult = countBrute(arr, k);
    cout << "Brute Force Result: ";
    for (int x : bruteResult)
    {
        cout << x << " ";
    }
    cout << endl;

    // Optimal method
    vector<int> optimalResult = countOptimal(arr, k);
    cout << "Optimal Result: ";
    for (int x : optimalResult)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}