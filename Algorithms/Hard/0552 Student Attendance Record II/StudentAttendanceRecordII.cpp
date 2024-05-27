#include <bits/stdc++.h>
using namespace std;

// Runtime - 23ms || Memory - 25.28 MB
class Solution
{
    static constexpr int MOD = int(1e9 + 7);

public:
    int checkRecord(int n)
    {
        if (n == 1)
        {
            return 3;
        }

        vector<int> f(n + 1), g(n + 1);
        f[0] = g[0] = 1;
        f[1] = 3;
        f[2] = 8;
        g[1] = 2;
        g[2] = 4;
        for (int i = 3; i <= n; ++i)
        {
            g[i] = ((g[i - 1] + g[i - 2]) % MOD + g[i - 3]) % MOD;
            f[i] =
                (((f[i - 1] + f[i - 2]) % MOD + f[i - 3]) % MOD + g[i]) % MOD;
        }
        return f[n];
    }
};

namespace
{
    const auto __ = []
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        return 0;
    }();
}

// Runtime - 996ms || Memory - 386.59 MB
class Solution
{
public:
    const int MOD = 1e9 + 7;
    int checkRecord(int n)
    {
        if (n == 1)
        {
            return 3;
        }
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
                    if (k < 2)
                    {
                        dp[i][j][k + 1] =
                            (dp[i][j][k + 1] + dp[i - 1][j][k]) % MOD;
                    }
                    if (j < 1)
                    {
                        dp[i][j + 1][0] =
                            (dp[i][j + 1][0] + dp[i - 1][j][k]) % MOD;
                    }
                }
            }
        }
        int result = 0;
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                result = (result + dp[n][j][k]) % MOD;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}