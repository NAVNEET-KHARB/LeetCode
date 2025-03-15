class StockSpanner {
    class Pair<S,P>{
        S first;
        P second;
        Pair(S first, P second){
            this.first = first;
            this.second = second;
        }
        public S first(){
            return this.first;
        }
        public P second() {
            return this.second;
        }
        public void setSecond(P val) {
            this.second = val;
        }
    }
    Stack<Pair<Integer,Integer>> st;
    public StockSpanner() {
        st = new Stack<>();
    }
    
    public int next(int price) {
        int span = 1;
        while(!st.isEmpty() && st.peek().first() <= price){
            span += st.pop().second();
        }
        st.push(new Pair<>(price,span));
        return span;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */