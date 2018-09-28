package Array;

import java.util.Scanner;

/**
 * Created by Jasonhaven.Dai on18-9-27.
 **/
public class SearchInsertPosition_35 {
    public static int searchInsert(int[] nums, int target) {
        System.out.println("tar = " + target);
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] >= target) return i;
        }
        return nums.length;
    }

    public static void main(String[] args) {
        int[] a = {1, 3, 5, 6};
        Scanner in = new Scanner(System.in);
        while (true) {
            int target = in.nextInt();
            System.out.println(searchInsert(a, target));
        }
    }
}
