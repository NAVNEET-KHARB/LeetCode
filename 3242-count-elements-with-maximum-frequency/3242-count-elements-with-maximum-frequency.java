class Solution {
    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer,Integer> mpp = new HashMap<>();
        int maxF = 0, ans = 0;
        for(int num : nums){
            mpp.put(num,mpp.getOrDefault(num,0)+1);
            maxF = Math.max(maxF,mpp.get(num));
        }
        for(int num : nums) if(mpp.get(num) == maxF) ans++;
        return ans;
    }
}