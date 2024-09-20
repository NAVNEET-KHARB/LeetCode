class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int least = prices[0], sleast = INT_MAX;
        for(int i = 1; i<n; i++){
            if(prices[i]<=least){
                sleast = least;
                least = prices[i];
            }else if(prices[i]<sleast) sleast = prices[i];
        }
        if(least+sleast<=money) return money - (least+sleast);
        return money;
    }
};