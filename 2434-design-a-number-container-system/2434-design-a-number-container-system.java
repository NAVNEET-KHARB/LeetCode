class NumberContainers {
    private Map<Integer, TreeSet<Integer>> numInds;
    private Map<Integer, Integer> indNumRel;
    public NumberContainers() {
        numInds = new HashMap<>();
        indNumRel = new HashMap<>();
    }

    public void change(int index, int number) {
        if (indNumRel.containsKey(index)) {
            int prevNum = indNumRel.get(index);
            numInds.get(prevNum).remove(index);
            if (numInds.get(prevNum).isEmpty()) {
                numInds.remove(prevNum);
            }
        }
        indNumRel.put(index, number);
        numInds.putIfAbsent(number, new TreeSet<>());
        numInds.get(number).add(index);
    }

    public int find(int number) {
        if (numInds.containsKey(number)) {
            return numInds.get(number).first();
        }
        return -1;
    }
}
/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index, number);
 * int param_2 = obj.find(number);
 */