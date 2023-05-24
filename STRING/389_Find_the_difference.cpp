// MS

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        map<char, int> mps;
        map<char, int> mpt;

        for (auto ch : s)
        {
            mps[ch]++;
        }
        for (auto ch : t)
        {
            mpt[ch]++;
        }

        char ret;
        for (auto p : mpt)
        {
            if (mps.count(p.first) == 0 or mps[p.first] != p.second)
            {
                ret = p.first;
                return ret;
            }
        }
        return ret;
    }
};

// BS

// Idea;

// All letters persent in s is present in t.
// There is just one extra letter in t.
// Every character can be represented as an ASCII .
// ASCII value of the extra letter in t is derived as follows:
// Sum of all ASCII values of charcters in s -> sSum
// Sum of all ASCII values of charcters in t -> tSum
// Return the difference (tSum-sSum)
// Example 1:
// s = 'abc'
// t = 'abcd'
// sSum = 97+98+99 = 294
// tSum = 97+98+99+100 = 394

// Example 2:
// s = 'abc'
// t = 'dbac'
// sSum = 97+98+99 = 294
// tSum = 100+98+97+99 = 394

// In both examples, d (100) is the extra letter, which is equivalent to (tSum - sSum).

// So the real question is:

// Do we really need to store these in two variables? Or even in one other variable to maintain the diff?
// Should we iterate through each of the strings separately?
// Nope, here's the code:

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        for (int i = 0; i < s.size(); i++)
        {
            t[i + 1] += t[i] - s[i]; // Passing the diff: (t[i]-s[i]) to t[i+1]
        } 
        return t[t.size() - 1];      // The diff will be carried over to the last element eventually
    }
};