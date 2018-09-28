package Stack;

import java.util.Stack;

/**
 * Created by Jasonhaven.Dai on18-9-27.
 **/
public class ImplementQueueUsingStacks_232 {
    /**
     * Implement the following operations of a queue using stacks.
     * <p>
     * push(x) -- Push element x to the back of queue.
     * pop() -- Removes the element from in front of queue.
     * peek() -- Get the front element.
     * empty() -- Return whether the queue is empty.
     */
    private Stack<Integer> sk1;
    private Stack<Integer> sk2;

    public ImplementQueueUsingStacks_232() {
        sk1 = new Stack<>();
        sk2 = new Stack<>();
    }

    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue obj = new MyQueue();
     * obj.push(x);
     * int param_2 = obj.pop();
     * int param_3 = obj.peek();
     * boolean param_4 = obj.empty();
     */
    public static void main(String[] args) {
        ImplementQueueUsingStacks_232 queue = new ImplementQueueUsingStacks_232();

        queue.push(1);
        queue.push(2);
        queue.pop();
        System.out.println(queue);
        queue.push(3);
        queue.push(4);
        System.out.println(queue);
        System.out.println(queue.pop());
        System.out.println(queue.pop());

    }

    /**
     * Push element x to the back of queue.
     */
    public void push(int x) {
        sk1.push(x);
    }

    /**
     * Removes the element from in front of queue and returns that element.
     */
    public int pop() {
        if (sk2.empty())
            while (!sk1.empty()) {
                sk2.push(sk1.pop());
            }
        return sk2.pop();
    }

    /**
     * Get the front element.
     */
    public int peek() {
        if (!sk2.empty()) return sk2.peek();
        while (!sk1.empty()) {
            sk2.push(sk1.pop());
        }
        return sk2.peek();
    }

    /**
     * Returns whether the queue is empty.
     */
    public boolean empty() {
        return sk2.empty() && sk1.empty();
    }

    @Override
    public String toString() {
        return "ImplementQueueUsingStacks_232{" +
                "sk1=" + sk1 +
                ", sk2=" + sk2 +
                '}';
    }
}
