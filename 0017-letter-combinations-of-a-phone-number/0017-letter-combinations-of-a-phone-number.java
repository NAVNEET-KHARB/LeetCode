class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if (digits == null || digits.length() == 0) return res;
        Map<Character, String> digitToLetters = new HashMap<>();
        digitToLetters.put('2', "abc");
        digitToLetters.put('3', "def");
        digitToLetters.put('4', "ghi");
        digitToLetters.put('5', "jkl");
        digitToLetters.put('6', "mno");
        digitToLetters.put('7', "pqrs");
        digitToLetters.put('8', "tuv");
        digitToLetters.put('9', "wxyz");
        backtrack(digits, 0, new StringBuilder(), res, digitToLetters);
        return res;        
    }
    private void backtrack(String digits, int ind, StringBuilder comb, List<String> res, Map<Character, String> digitToLetters) {
        if (ind == digits.length()) {
            res.add(comb.toString());
            return;
        }
        String letters = digitToLetters.get(digits.charAt(ind));
        for (char letter : letters.toCharArray()) {
            comb.append(letter);
            backtrack(digits, ind + 1, comb, res, digitToLetters);
            comb.deleteCharAt(comb.length() - 1);
        }
    }    
}