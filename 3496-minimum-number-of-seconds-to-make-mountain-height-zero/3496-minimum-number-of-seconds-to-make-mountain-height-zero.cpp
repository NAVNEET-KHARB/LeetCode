class Solution {
    bool isPoss(long long T, int mountainHeight,
                         const vector<int>& workerTimes) {
        long long total = 0;
        for (int time : workerTimes) {
            long long left = 0, right = mountainHeight;
            while (left < right) {
                long long mid = (left + right + 1) / 2;
                if (mid * (mid + 1) / 2 * time <= T) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            total += left;
            if (total >= mountainHeight) {
                return true;
            }
        }
        return total >= mountainHeight;
    }

public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1;
        long long right = *max_element(workerTimes.begin(), workerTimes.end()) *
                          (long long)mountainHeight * (mountainHeight + 1) / 2;
        while (left < right) {
            long long mid = left +(right - left) / 2;
            if (isPoss(mid, mountainHeight, workerTimes)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};