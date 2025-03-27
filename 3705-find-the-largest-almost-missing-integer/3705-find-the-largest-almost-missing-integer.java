class Solution {
    public int largestInteger(int[] nums, int k) {
        int n = nums.length, maxEle = 0;
        HashMap<Integer,Integer> mpp = new HashMap<>();
        for(int i = 0; i<n; i++){
            maxEle = Math.max(nums[i],maxEle);
            mpp.put(nums[i],mpp.getOrDefault(nums[i],0)+1);
        }
        int singleFreqEle = -1;
        for(int key : mpp.keySet()){
            if(mpp.get(key) == 1) singleFreqEle = Math.max(singleFreqEle,key);
        }
        if(k == 1) return singleFreqEle;
        else if(k == n) return maxEle;
        if(mpp.get(nums[0]) > 1 && mpp.get(nums[n-1]) > 1) return -1;
        else if(mpp.get(nums[0]) > 1) return nums[n-1];
        else if(mpp.get(nums[n-1]) > 1) return nums[0];
        return Math.max(nums[0],nums[n-1]);
    }
}