class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        ArrayList<Integer> smaller = new ArrayList<>();
        ArrayList<Integer> bigger = new ArrayList<>();
        int pivotCnt = 0;
        for(int num : nums){
            if(num == pivot) pivotCnt++;
            else if(num<pivot) smaller.add(num);
            else bigger.add(num);
        }
        int ind = 0, sSz = smaller.size();
        while(ind<n){
            if(ind<sSz) nums[ind] = smaller.get(ind);
            else if(ind<sSz+pivotCnt) nums[ind] = pivot;
            else nums[ind] = bigger.get(ind-sSz-pivotCnt);
            ind++;
        }
        return nums;
    }
}