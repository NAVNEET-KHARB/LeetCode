#include <bits/stdc++.h>
using namespace std;

// Runtime - 160ms || Memory - 126.60 MB
class Solution
{
public:
    int findWinningPlayer(vector<int> &skills, int k)
    {
        int n = skills.size();
        if (k >= n - 1)
        {
            int maxSkill = *max_element(skills.begin(), skills.end());
            return find(skills.begin(), skills.end(), maxSkill) - skills.begin();
        }
        deque<int> queue;
        for (int i = 0; i < n; i++)
        {
            queue.push_back(i);
        }
        int consecutiveWins = 0;
        int currentWinner = queue.front();
        queue.pop_front();

        while (true)
        {
            int nextPlayer = queue.front();
            queue.pop_front();

            if (skills[currentWinner] > skills[nextPlayer])
            {
                consecutiveWins++;
                queue.push_back(nextPlayer);
            }
            else
            {
                consecutiveWins = 1;
                queue.push_back(currentWinner);
                currentWinner = nextPlayer;
            }
            if (consecutiveWins == k)
            {
                return currentWinner;
            }
        }
    }
};

int main()
{
    return 0;
}