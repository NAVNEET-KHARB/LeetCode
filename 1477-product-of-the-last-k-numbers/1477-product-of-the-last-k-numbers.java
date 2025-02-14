class ProductOfNumbers {
    private ArrayList<Integer> prefixProduct = new ArrayList<>();
    private int size = 0;
    public ProductOfNumbers() {
        prefixProduct.add(1);
        size = 0;
    }
    public void add(int num) {
        if (num == 0) {
            prefixProduct = new ArrayList<Integer>();
            prefixProduct.add(1);
            size = 0;
        } else {
            prefixProduct.add(prefixProduct.get(size) * num);
            size++;
        }
    }
    public int getProduct(int k) {
        if (k > size) return 0;
        return ( prefixProduct.get(size) /  prefixProduct.get(size - k));
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */