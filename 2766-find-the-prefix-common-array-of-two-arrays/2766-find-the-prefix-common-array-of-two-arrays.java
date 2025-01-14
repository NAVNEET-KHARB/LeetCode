class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] freq = new int[n+1];
        int[] ans = new int[n];
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(A[i] == B[i]){
                cnt += 1;
                ans[i] = cnt;
            }else{
                freq[A[i]]++;
                freq[B[i]]++;
                if(freq[A[i]] == 2) cnt++;
                if(freq[B[i]] == 2) cnt++;
                ans[i] = cnt;
            }
        }
        return ans;
    }
}