class Solution {

    public List<String> stringMatching(String[] words) {
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words.length; j++) {
                if (i == j)
                    continue;
                if (isstr2stringOf(words[j], words[i])) {
                    ans.add(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
    private boolean isstr2stringOf(String str1, String str2) {
        for (int i = 0; i < str1.length(); i++) {
            boolean str2Fits = true;
            for (int j = 0; j < str2.length(); j++) {
                if (i + j >= str1.length() || str1.charAt(i + j) != str2.charAt(j)) {
                    str2Fits = false;
                    break;
                }
            }
            if (str2Fits) {
                return true;
            }
        }
        return false;
    }
}