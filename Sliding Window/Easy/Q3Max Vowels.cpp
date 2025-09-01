/*
Q3. Max Vowels in Substring of Length K
s="abciiidef", k=3
“abc”=1
“bci”=1
“cii”=2
“iii”=3 (max)
…
*/

#include <bits/stdc++.h>
using namespace std;

// function to check vowel
bool isVowel(char ch)
{
    return string("aeiou").find(ch) != string ::npos;
}

// Brute -> start calculating vowel for each start of i
int maxVowel(string s, int k)
{
    int n = s.length(), maxCount = 0;
    // run outer loop from 0-n-k
    for (int i = 0; i <= n - k; i++)
    {
        // count for each start of i
        int count = 0;
        // run inner loop from i-i+k
        for (int j = i; j < i + k; j++)
        {
            if (isVowel(s[j]))
            {
                count++;
            }
        }
        // compare the count
        maxCount = max(count, maxCount);
    }
    return maxCount;
}
// TC -> O(n*k)
// Better -> Precompute vowel counts in prefix array.
int countBetter(string s, int k)
{
    int n = s.length(), maxCount = 0;
    vector<int> ans(n + 1, 0); // for storing count of vowel
    for (int i = 0; i < n; i++)
    {
        ans[i + 1] = ans[i] + isVowel(s[i]);
    }
    // now check the count for each substring
    for (int i = 0; i <= n - k; i++)
    {
        int count = ans[i + k] - ans[i];
        // compare count
        maxCount = max(maxCount, count);
    }
    return maxCount;
}
// TC -> O(n)
// Optimal -> Using sliding window, start count from i-n and check according to size
int optimal(string s, int k)
{
    int n = s.length(), count = 0, maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        count += isVowel(s[i]);
        // if it's out of substring
        if (i >= k)
        {
            count -= isVowel(s[i - k]);
        }

        // if it's in substring
        if (i >= k - 1)
        {
            maxCount = max(count, maxCount);
        }
    }
    return maxCount;
}
// TC -> O(n)

// main function
int main()
{
    string s = "abciiidef";
    int k = 3;
    int res1 = maxVowel(s, k);
    cout << "Count using brute: " << res1 << endl;
    int res2 = countBetter(s, k);
    cout << "Count using better: " << res2 << endl;
    int res3 = optimal(s, k);
    cout << "count using optimal: " << res3 << endl;
    return 0;
}