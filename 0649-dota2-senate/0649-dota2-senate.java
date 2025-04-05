class Solution {
    public String predictPartyVictory(String senate) {
        Queue<Integer> radiantIndexQ = new LinkedList<>();
        Queue<Integer> direIndexQ = new LinkedList<>();
        for (int i = 0; i < senate.length(); i++) {
            if (senate.charAt(i) == 'R') {
                radiantIndexQ.add(i);
            } else {
                direIndexQ.add(i);
            }
        }
        while (!radiantIndexQ.isEmpty() && !direIndexQ.isEmpty()) {
            int rIndex = radiantIndexQ.poll();
            int dIndex = direIndexQ.poll();
            if (rIndex < dIndex) {
                radiantIndexQ.add(rIndex + senate.length());
            } else {
                direIndexQ.add(dIndex + senate.length());
            }
        }
        return radiantIndexQ.isEmpty() ? "Dire" : "Radiant";
    }
}