#include <bits/stdc++.h>
using namespace std;

// Runtime - 0ms | Memory - 8.29 MB
class Solution
{
public:
    bool isPal(string &str, int left, int right)
    {
        if (left >= right)
            return true;
        else if (str[left] != str[right])
            return false;
        return isPal(str, left + 1, right - 1);
    }
    bool isPalindrome(string &str)
    {
        auto it = remove_if(str.begin(), str.end(), [](char const &c)
                            { return !isalnum(c); });
        // In the above line of code, remove_if function shifts all the element to the end which are specified in the third arg's function and returns an iterator to the beginning of the removable string.
        str.erase(it, str.end());
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return isPal(str, 0, str.length() - 1);
    }
};
int main()
{
    return 0;
}