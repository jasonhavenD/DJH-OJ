package Stack;

import java.util.ArrayList;
import java.util.Stack;

/**
 * Created by Jasonhaven.Dai on18-9-27.
 **/
public class MinStack_155 {
    /**
     * MinStack minStack = new MinStack();
     * minStack.push(-2);
     * minStack.push(0);
     * minStack.push(-3);
     * minStack.getMin();   --> Returns -3.
     * minStack.pop();
     * minStack.top();      --> Returns 0.
     * minStack.getMin();   --> Returns -2.
     */
    private Stack<Integer> stack;
    private ArrayList<Integer> mins;
    private Integer min = Integer.MAX_VALUE;

    public MinStack_155() {
        stack = new Stack<>();
        mins = new ArrayList<>();
    }

    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack obj = new MinStack();
     * obj.push(x);
     * obj.pop();
     * int param_3 = obj.top();
     * int param_4 = obj.getMin();
     */
    public static void main(String[] args) {
        MinStack_155 obj = new MinStack_155();
        obj.push(-2);
        obj.push(0);
        obj.push(-3);
        System.out.println(obj);
        obj.pop();
        System.out.println(obj);
        obj.pop();
        System.out.println(obj);
        obj.pop();
        System.out.println(obj);

        obj.push(-2);
        obj.push(0);
        obj.push(-3);
        System.out.println(obj);
        obj.pop();
        System.out.println(obj);
        obj.pop();
        System.out.println(obj);
        obj.pop();
        System.out.println(obj);
        obj.push(-2);
        obj.push(0);
        obj.push(-3);
        System.out.println(obj);
        obj.pop();
        System.out.println(obj);
        obj.pop();
        System.out.println(obj);
        obj.pop();
        System.out.println(obj);
//
//        ArrayList<Integer> mins = new ArrayList<>();
//        mins.add(1);
//        mins.add(22);
//        mins.add(3);
//        System.out.println(mins.size() - 1);
//        mins.remove(mins.size() - 1);
//        System.out.println(mins.size() - 1);
//        mins.remove(mins.size() - 1);
//        System.out.println(mins.size() - 1);
//        mins.remove(mins.size() - 1);
//        System.out.println(mins.size());


    }

    public void push(int x) {
        if (x < min) {
            min = x;
        }
        mins.add(min);
        stack.push(x);
    }

    public void pop() {
        if (stack.size() == 0) return;
        stack.pop();
        mins.remove(mins.size() - 1);
        if (stack.size() == 0) {
            min = Integer.MAX_VALUE;
            return;
        }
        min = mins.get(mins.size() - 1);
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return min;
    }

    public int size() {
        return mins.size();
    }

    @Override
    public String toString() {
        return "MinStack_155{" +
                "stack=" + stack +
                ", mins=" + mins +
                ", min=" + min +
                '}';
    }
}
