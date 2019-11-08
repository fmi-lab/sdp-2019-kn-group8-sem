class StackBasedQueue {
private:
    std::stack<int> pushStack;
    std::stack<int> popStack;

public:

    /** Push element x to the back of queue. */
    void push(int x) {
        pushStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        this->peek();
        popStack.pop();
    }

    /** Get the front element. */
    int peek() {
        if (popStack.empty()) {
            while (!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
        return popStack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return pushStack.empty() && popStack.empty();
    }
}; 
