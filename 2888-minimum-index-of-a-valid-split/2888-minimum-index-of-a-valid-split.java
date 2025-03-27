class Solution {
    public int minimumIndex(List<Integer> nums) {
        int freq = 0, n = nums.size();
        int maxFreq = 0, reqNum = nums.get(0), cnt = 1;
        for(int i = 1; i<n;i++){
            if(nums.get(i) == reqNum) cnt++;
            else cnt--;
            if(cnt == 0){
                reqNum = nums.get(i);
                cnt = 1;
            }
        }
        for(int num : nums){
            if(num == reqNum) maxFreq++;
        }
        for(int i = 0; i<n;i++){
            if(nums.get(i) == reqNum) freq++;
            if(freq*2 > (i+1) && (maxFreq-freq)*2 > (n-i-1)) return i;
        }
        return -1;
    }
}