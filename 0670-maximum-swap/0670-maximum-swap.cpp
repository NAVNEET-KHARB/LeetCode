class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        vector<int> maxRightIndex(n);
        maxRightIndex[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            maxRightIndex[i] = (numStr[i] > numStr[maxRightIndex[i + 1]])? i: maxRightIndex[i + 1];
        }
        for (int i = 0; i < n; ++i) {
            if (numStr[i] < numStr[maxRightIndex[i]]) {
                swap(numStr[i],numStr[maxRightIndex[i]]);
                return stoi(numStr);
            }
        }
        return num;
    }
};