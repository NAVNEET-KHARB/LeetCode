class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;
        int cnt1 = 0, cnt2 = 0;
        int el1 = Integer.MIN_VALUE, el2 = Integer.MIN_VALUE;
        for(int num : nums){
            if(cnt1 == 0 && el2 != num){
                cnt1 = 1;
                el1 = num;
            }
            else if(cnt2 == 0 && el1 != num){
                cnt2 = 1;
                el2 = num;
            }else if(el1 == num) cnt1++;
            else if(el2 == num) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int num : nums){
            if(num == el1) cnt1++;
            else if(num == el2) cnt2++;
        }
        if(cnt1>n/3) ans.add(el1);
        if(cnt2>n/3) ans.add(el2);
        return ans;
    }
}