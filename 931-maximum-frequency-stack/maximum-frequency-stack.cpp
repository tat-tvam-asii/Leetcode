class FreqStack {
public:
    FreqStack() {
        
    }
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> mp;
    int mx = 0;

    void push(int val) {
        mx = max(mx,++freq[val]);
        mp[freq[val]].push(val);
    }
    
    int pop() {
        int x = mp[mx].top();
        mp[mx].pop();
        if(mp[freq[x]--].empty()) mx--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */