class MyQueue {
private:
    stack<int> in, out;
public:
    MyQueue() {

    }
    
    void push(int x) {
        while(!out.empty()){
            in.push(out.top());
            out.pop();
        }

        in.push(x);
        
        // add elements from in to out
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
    }
    
    int pop() {
        int i = out.top();
        out.pop();
        
        return i;
    }
    
    int peek() {
        return out.top();
    }
    
    bool empty() {
        return out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */