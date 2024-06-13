#include <bits/stdc++.h>
using namespace std;

// Runtime - 3ms || Memory - 20.98 MB
class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int moves = 0;
        for (int i = 0; i < seats.size(); i++)
        {
            moves += abs(seats[i] - students[i]);
        }
        return moves;
    }
};

int main()
{
    return 0;
}