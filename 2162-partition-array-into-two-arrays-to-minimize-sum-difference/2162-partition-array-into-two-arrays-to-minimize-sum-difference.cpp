class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N=nums.size(),res=0;
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = N/2;
        vector<vector<int>> left(n+1),right(n+1);
        for(int mask=0;mask<(1<<n);mask++){
            int sz=0,l=0,r=0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    l+=nums[i];
                    r+=nums[i+n];
                    sz++;
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        res = min(abs(sum-2*left[n][0]),abs(sum-2*right[n][0]));
        for(int sz=1;sz<n;sz++){
            sort(right[n-sz].begin(),right[n-sz].end());
            for(auto &a : left[sz]){
                int b = (sum-2*a)/2;
                int rsz = n-sz;
                auto itr = lower_bound(right[rsz].begin(),right[rsz].end(),b);
                if(itr!=right[rsz].end()){
                    res=min(res,abs(sum-2*(a+(*itr))));
                }
                if(itr!=right[rsz].begin()){
                    auto it = itr;it--;
                    res = min(res,abs(sum-2*(a+(*it))));
                }
            }
        }
        return res;
    }
};