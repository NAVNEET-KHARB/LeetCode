class Solution {
    void merge(vector<pair<int,int>> &numPairs, vector<int> &ans, int low, int mid, int high){
        vector<pair<int,int>> temp(high-low+1);
        int left = low, right = mid+1, ind = 0;
        while(left<=mid && right<=high){
            if(numPairs[left].first<=numPairs[right].first){
                temp[ind++] = numPairs[right++];
            }else{
                ans[numPairs[left].second] += high-right+1;
                temp[ind++] = numPairs[left++];
            }
        }
        while(left<=mid) temp[ind++] = numPairs[left++];
        while(right<=high) temp[ind++] = numPairs[right++];
        for(int i = low; i<=high; i++) numPairs[i] = temp[i-low];
    }
    void mergeSort(vector<pair<int,int>> &numPairs, vector<int> &ans, int low, int high){
        if(low<high){
            int mid = low+(high-low)/2;
            mergeSort(numPairs,ans,low,mid);
            mergeSort(numPairs,ans,mid+1,high);
            merge(numPairs,ans,low,mid,high);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> numPairs;
        for(int i = 0;i<n; i++){
            numPairs.push_back({nums[i],i});
        }
        vector<int> ans(n,0);
        mergeSort(numPairs,ans,0,n-1);
        return ans;
    }
};