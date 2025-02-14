class ProductOfNumbers {
public:
    vector<int> pre;

    ProductOfNumbers() {

    }
    
    void add(int num) {
        if(num == 0){
            pre.clear();
            return;
        }
        if(pre.empty()) pre.push_back(num);
        else pre.push_back(num * pre[pre.size() - 1]);
    }
    
    int getProduct(int k) {
        if(k > pre.size()) return 0;
        else if(k == pre.size()) return pre[pre.size() - 1];
        else return pre[pre.size() - 1] / pre[pre.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */