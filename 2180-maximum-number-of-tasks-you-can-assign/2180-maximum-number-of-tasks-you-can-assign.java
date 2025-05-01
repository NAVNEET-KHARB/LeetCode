class Solution {
    private boolean tasks(int mid, int[] tasks, int[] workers, int pills, int strength){
        int p = pills;
        TreeMap<Integer, Integer> ws = new TreeMap<>();
        for (int i = workers.length - mid; i < workers.length; i++) {
            ws.put(workers[i], ws.getOrDefault(workers[i], 0) + 1);
        }
        for (int i = mid - 1; i >= 0; i--) {
            Integer key = ws.lastKey();
            if (key >= tasks[i]) {
                ws.put(key, ws.get(key) - 1);
                if (ws.get(key) == 0) {
                    ws.remove(key);
                }
            } else {
                if (p == 0) {
                    return false;
                }
                key = ws.ceilingKey(tasks[i] - strength);
                if (key == null) {
                    return false;
                }
                ws.put(key, ws.get(key) - 1);
                if (ws.get(key) == 0) {
                    ws.remove(key);
                }
                p--;
            }
        }
        return true;
    }
    public int maxTaskAssign(int[] tasks, int[] workers, int pills, int strength) {
        int n = tasks.length, m = workers.length;
        Arrays.sort(tasks);
        Arrays.sort(workers);
        int low = 1, high = Math.min(n,m), ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(tasks(mid,tasks,workers,pills,strength) == true){
                ans = mid;
                low = mid+1;
            }else high = mid-1;
        }
        return ans;
    }
}