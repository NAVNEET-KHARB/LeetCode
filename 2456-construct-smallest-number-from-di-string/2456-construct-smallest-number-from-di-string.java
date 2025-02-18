class Solution {
    public String smallestNumber(String pattern) {
        StringBuilder ans = new StringBuilder();
        Stack<Integer> num = new Stack<>();
        for(int i = 0; i<=pattern.length(); i++){
            num.push(i+1);
            if(i==pattern.length() || pattern.charAt(i) == 'I'){
                while(!num.isEmpty()) ans.append(num.pop());
            }
        }
        return ans.toString();
    }
}