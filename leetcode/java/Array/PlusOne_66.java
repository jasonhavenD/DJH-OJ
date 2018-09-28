package Array;

import java.util.Arrays;

/**
 * Created by Jasonhaven.Dai on18-9-27.
 **/
public class PlusOne_66 {
    public static int[] plusOne(int[] digits) {//递归问题，迭代实现
        if (digits == null || digits.length == 0)
            return digits;
        int N = digits.length;
        int carry = 1;
        for (int i = N - 1; i >= 0; i--) {//从后往前依次计算
            int digit = (digits[i] + carry) % 10;//当前位数值
            carry = (digits[i] + carry) / 10;//进位数值0 or 1
            digits[i] = digit;//更新值
            if (carry == 0)//没有进位就结束
                return digits;
        }
        //如果全部都有进位，结果为新的10^(N+1)
        int[] ans = new int[N + 1];
        ans[0] = 1;
        return ans;
    }

    public static void main(String[] args) {
//        int[] a = {1, 2, 3};// 1 2 4
//        int[] a = {1, 4, 9};// 1 5 0
        int[] a = {9, 9, 9, 9};//10000
        System.out.println(Arrays.toString(plusOne(a)));
    }
}
