class Solution {
    public int tupleSameProduct(int[] nums) {
        HashMap<Integer,Integer> mpp = new HashMap<>();
        for(int i = 0; i<nums.length; i++){
            for(int j = i+1; j<nums.length; j++){
                mpp.put(nums[i]*nums[j],mpp.getOrDefault(nums[i]*nums[j],0)+1);
            }
        }
        int ans = 0;
        for(int freq : mpp.keySet()){
            int freqVal = mpp.get(freq);
            int tuples = ((freqVal-1)*freqVal)/2;
            ans += 8*tuples;
        }
        return ans;
    }
}