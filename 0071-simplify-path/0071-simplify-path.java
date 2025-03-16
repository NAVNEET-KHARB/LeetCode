class Solution {
    public String simplifyPath(String path) {
        int n = path.length(), i = 0;
        Stack<String> st = new Stack<>();
         while (i < n) {
            StringBuilder temp = new StringBuilder();
            while (i < n && path.charAt(i) == '/') i++;
            while (i < n && path.charAt(i) != '/') {
                temp.append(path.charAt(i));
                i++;
            }
            String dir = temp.toString();
            if (dir.equals("..")) {
                if (!st.isEmpty()) st.pop();
            } else if (!dir.equals(".") && !dir.isEmpty()) {
                st.push(dir);
            }
        }
        StringBuilder ans = new StringBuilder();
        while (!st.isEmpty()) {
            ans.insert(0,st.pop()).insert(0,"/");
        }
        return ans.length() == 0 ? "/" : ans.toString();
    }
}