class Solution {
    public int[] findEvenNumbers(int[] digits) {
        int[] cnt = new int[10];
        for(int d : digits) cnt[d]++;
        ArrayList<Integer> res = new ArrayList<>();
        for(int num = 100; num<=998; num+=2){
            int currNum = num;
            int[] currCnt = new int[10];
            while(currNum>0){
                int digit = currNum%10;
                currNum /= 10;
                currCnt[digit]++;
            }
            boolean flag = true;
            for(int i = 0; i<10; i++){
                if(currCnt[i]>cnt[i]){
                    flag = false;
                    break;
                }
            }
            if(flag) res.add(num);
        }
        int i = 0;
        int[] ans = new int[res.size()];
        for(int num : res){
            ans[i++] = num;
        }
        return ans;
    }
}