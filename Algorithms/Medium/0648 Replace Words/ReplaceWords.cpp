#include <bits/stdc++.h>
using namespace std;

// Runtime - 206ms || Memory - 47.12 MB
class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        string word = "", ans = "";
        sentence += ' ';
        for (auto i : sentence)
        {
            if (i == ' ')
            {
                if (ans.size() > 0)
                    ans += ' ';
                string temp = "";
                for (auto j : word)
                {
                    temp += j;
                    if (st.count(temp))
                    {
                        break;
                    }
                }
                ans += temp;
                word = "";
            }
            else
                word += i;
        }
        return ans;
    }
};

int main()
{
    return 0;
}