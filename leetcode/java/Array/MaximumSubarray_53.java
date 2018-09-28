package Array;

/**
 * Created by Jasonhaven.Dai on18-9-27.
 **/
public class MaximumSubarray_53 {
    public static int maxSubArray(int[] nums) {// Time Limit Exceeded
        int N = nums.length;
        int max_sum = nums[0];
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                int tmp_sum = 0;
                for (int k = i; k <= j; k++) {
                    tmp_sum += nums[k];
                }
                if (tmp_sum > max_sum) {
                    max_sum = tmp_sum;
                }
            }
        }
        return max_sum;
    }

    //https://siddontang.gitbooks.io/leetcode-solution/content/dynamic_programming/maximum_subarray.html
    public static int maxSubArray2(int[] nums) {// AC
        int sum = 0;
        int m = nums[0];

        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            m = Math.max(m, sum);
            //如果sum小于0了，将sum重置为0，从i + 1再次开始计算
            if (sum < 0) {
                sum = 0;
            }
        }

        return m;
    }


    public static void main(String[] args) {
//        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};//6
//        int[] nums = {-2, -1};//-1
//        int[] nums = {1};//1
        int[] nums = {-2, -3, -1};//-1
        System.out.println(maxSubArray2(nums));
    }
}
