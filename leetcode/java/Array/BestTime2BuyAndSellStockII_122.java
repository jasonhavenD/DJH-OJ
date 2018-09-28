package Array;

/**
 * Say you have an Array for which the ith element is the price of a given stock on day i.
 * <p>
 * Design an algorithm to find the maximum profit.
 * <p>
 * You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 *
 * <p>
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 **/
public class BestTime2BuyAndSellStockII_122 {
    public static int maxProfit(int[] prices) {
        int ans = 0;
        int n = prices.length;
        for (int i = 0; i < n - 1; i++) {
            int k = i;
            for (int j = i + 1; j < n && prices[j] > prices[j - 1]; j++) k = j;//找到第一个最大的price
            if (k != i) {
//                System.out.println("i=" + i + ",j=" + k);
                int tmp = prices[k] - prices[i];
                ans += tmp;
                i = k;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = {7, 1, 5, 3, 6, 4};
        System.out.println(maxProfit(arr));// 7

        int[] arr2 = {1, 2, 3, 4, 5};
        System.out.println(maxProfit(arr2));//4

        int[] arr3 = {7, 6, 4, 3, 1};
        System.out.println(maxProfit(arr3));//0
    }
}
