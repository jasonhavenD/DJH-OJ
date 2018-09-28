package Array;

/**
 * Say you have an Array for which the ith element is the price of a given stock on day i.
 * <p>
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * <p>
 * Note that you cannot sell a stock before you buy one.
 * <p>
 * <p>
 * Created by Jasonhaven.Dai on18-9-28.
 **/
public class BestTime2BuyAndSellStock_121 {
    public static int maxProfit(int[] prices) {
        int ans = 0;
        int n = prices.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[i] < prices[j]) {
                    int tmp = prices[j] - prices[i];
                    if (tmp > ans) ans = tmp;
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = {7, 1, 5, 3, 6, 4};
        System.out.println(maxProfit(arr));// 5

        int[] arr2 = {7, 6, 4, 3, 1};
        System.out.println(maxProfit(arr2));//0
    }
}
