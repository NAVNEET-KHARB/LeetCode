class Solution {
    public String addBinary(String a, String b) {
        int n = a.length(), m = b.length();
        StringBuilder ans = new StringBuilder();
        int i = n-1, j = m-1;
        boolean carry = false;
        while(i>=0 && j>=0){
            if(a.charAt(i)=='1' && b.charAt(j) == '1'){
                if(carry){
                    ans.append('1');
                }else{
                    ans.append('0');
                    carry = true;
                }
            }
            else if(a.charAt(i)=='1' && b.charAt(j) == '0'){
                if(carry){
                    ans.append('0');
                }else{
                    ans.append('1');
                }
            }
            else if(a.charAt(i)=='0' && b.charAt(j) == '1'){
                if(carry){
                    ans.append('0');
                }else{
                    ans.append('1');
                }
            }
            else{
                if(carry){
                    ans.append('1');
                    carry = false;
                }else{
                    ans.append('0');
                }
            }
            i--;
            j--;
        }
        while(i>=0){
            if(a.charAt(i)=='1'){
                if(carry) ans.append('0');
                else{
                    ans.append('1');
                    carry = false;
                }
            }else{
                if(carry){
                    ans.append('1');
                    carry = false;
                }else ans.append('0');
            }
            i--;
        }
        while(j>=0){
            if(b.charAt(j)=='1'){
                if(carry) ans.append('0');
                else{
                    ans.append('1');
                    carry = false;
                }
            }else{
                if(carry){
                    ans.append('1');
                    carry = false;
                }else ans.append('0');
            }
            j--;
        }
        if(carry) ans.append('1');
        return ans.reverse().toString();
    }
}