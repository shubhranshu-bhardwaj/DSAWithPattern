/*
Q1. Reverse String
Given a string s, reverse the string and return it.
Example 1:
Input: s = "hello"
Output: "olleh"
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Use extra string to store the reverse string
string brute(string s)
{
    int len = s.length();
    string t = s;
    for (int i = 0; i < len; i++)
    {
        t[i] = s[len - 1 - i];
    }
    return t;
}
// TC -> O(N) + O(N) for creating new string, SC -> O(N) for new string

// Better == Optimal -> Swap in-place with two pointers.
string optimal(string s)
{
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}
// TC -> O(N), SC -> O(1)

// main function
int main()
{
    string s = "hello";
    cout << brute(s) << endl;
    cout << optimal(s) << endl;
    return 0;
}