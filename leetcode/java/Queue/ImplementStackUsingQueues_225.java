package Queue;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by Jasonhaven.Dai on18-9-27.
 **/
public class ImplementStackUsingQueues_225 {
    /**
     * Implement the following operations of a stack using queues.
     * <p>
     * push(x) -- Push element x onto stack.
     * pop() -- Removes the element on top of the stack.
     * top() -- Get the top element.
     * empty() -- Return whether the stack is empty.
     */
    private LinkedList q1;
    private LinkedList q2;

    public ImplementStackUsingQueues_225() {
        q1 = new LinkedList();
        q2 = new LinkedList();
    }

    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack obj = new MyStack();
     * obj.push(x);
     * int param_2 = obj.pop();
     * int param_3 = obj.top();
     * boolean param_4 = obj.empty();
     */
    public static void main(String[] args) {
        ImplementStackUsingQueues_225 stack = new ImplementStackUsingQueues_225();

        stack.push(1);
        stack.push(2);
        stack.top();   // returns 2
        stack.pop();   // returns 2
        stack.empty(); // returns false

    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        if (q1.isEmpty())
            q1.push(x);
        else
            q2.push(x);
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        return -1;
    }

    /**
     * Get the top element.
     */
    public int top() {
        return -1;
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return false;
    }
}
