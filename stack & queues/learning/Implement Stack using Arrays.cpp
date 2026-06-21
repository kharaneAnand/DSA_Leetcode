class myStack {
private:
    vector<int> ans;
    int n;

public:
    myStack(int n) {
        this->n = n;
    }

    bool isEmpty() {
        return ans.size() == 0;
    }

    bool isFull() {
        return ans.size() == n;
    }

    void push(int x) {
        if(ans.size() >= n) return;
        ans.push_back(x);
    }

    void pop() {
        if(ans.empty()) return;
        ans.pop_back();
    }

    int peek() {
        if(ans.empty()) return -1;
        return ans.back();
    }
};