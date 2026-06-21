class MyQueue {
public:
    stack<int> st;
    stack<int> st2;
    int size;

    MyQueue() {
        size = 0;
    }

    void push(int x) {
        while (!st.empty()) {
            st2.push(st.top());
            st.pop();
        }

        st.push(x);

        while (!st2.empty()) {
            st.push(st2.top());
            st2.pop();
        }

        size++;
    }   

    int pop() {
        if (size == 0) return -1;

        int x = st.top();
        st.pop();
        size--;
        return x;
    }

    int peek() {
        if (size == 0) return -1;
        return st.top();
    }

    bool empty() {
        return size == 0;
    }
};