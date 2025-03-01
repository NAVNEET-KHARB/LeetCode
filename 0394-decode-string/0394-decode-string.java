class Solution {
    public String decodeString(String s) {
        Stack<Integer> countStack = new Stack<>();
        Stack<StringBuilder> resultStack = new Stack<>();
        StringBuilder current = new StringBuilder();
        int k = 0;
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                k = k * 10 + (c - '0'); 
            } else if (c == '[') {
                countStack.push(k);
                resultStack.push(current);
                current = new StringBuilder();
                k = 0;
            } else if (c == ']') {
                int repeatTimes = countStack.pop();
                StringBuilder decodedString = resultStack.pop();
                while (repeatTimes-- > 0) {
                    decodedString.append(current);
                }
                current = decodedString;
            } else {
                current.append(c);
            }
        }
        return current.toString();
    }
}