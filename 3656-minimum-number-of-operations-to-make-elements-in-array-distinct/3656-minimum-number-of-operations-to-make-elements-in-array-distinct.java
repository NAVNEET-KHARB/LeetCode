class Solution {
    public int minimumOperations(int[] nums) {
        HashMap<Integer,Integer> mpp = new HashMap<>();
        int repEle = 0;
        for(int num : nums){
            if(mpp.getOrDefault(num,0) == 1) repEle++;
            mpp.put(num,mpp.getOrDefault(num,0)+1);
        }
        int startInd = 0, ans = 0;
        while(repEle>0){
            for(int i = 0; i<Math.min(nums.length-startInd,3); i++){
                int ind = i + startInd;
                mpp.put(nums[ind],mpp.get(nums[ind])-1);
                if(mpp.get(nums[ind]) == 1) repEle--;
                if(mpp.get(nums[ind]) == 0) mpp.remove(nums[ind]);
            }
            startInd += 3;
            ans++;
        }
        return ans;
    }
}