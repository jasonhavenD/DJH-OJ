package Queue;

import java.util.LinkedList;
import java.util.Stack;

/**
 * Created by Jasonhaven.Dai on18-9-27.
 **/
public class ImplementStackUsingQueues2_225 {
    private Stack<Integer> stack;

    public ImplementStackUsingQueues2_225() {
        stack = new Stack<>();
    }

    public static void main(String[] args) {
        ImplementStackUsingQueues2_225 stack = new ImplementStackUsingQueues2_225();

        stack.push(1);
        stack.push(2);
        System.out.println(stack);
        System.out.println(stack.top());
        ;   // returns 2
        System.out.println(stack.pop());
        ;   // returns 2
        System.out.println(stack);
        stack.empty(); // returns false


    }


    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        stack.push(x);
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        return stack.pop();
    }

    /**
     * Get the top element.
     */
    public int top() {
        return stack.get(stack.size() - 1);
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return stack.isEmpty();
    }

    @Override
    public String toString() {
        return "ImplementStackUsingQueues2_225{" +
                "stack=" + stack +
                '}';
    }
}
