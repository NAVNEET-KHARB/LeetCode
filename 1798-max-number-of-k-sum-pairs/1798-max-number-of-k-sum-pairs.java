class Solution {
    public int maxOperations(int[] nums, int k) {
        HashMap<Integer,Integer> mpp = new HashMap<>();
        int ans = 0;
        for(int num : nums){
            int req = k-num;
            if(mpp.containsKey(req)){
                ans++;
                mpp.put(req,mpp.get(req)-1);
                if (mpp.get(req) == 0) mpp.remove(req);
            }else mpp.put(num,mpp.getOrDefault(num,0)+1);
        }
        return ans;
    }
}