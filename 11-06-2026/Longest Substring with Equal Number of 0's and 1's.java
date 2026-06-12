import java.util.*;

class Dp_Longest_Substring_Equal_0s_1s {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the string of 0's and 1's: ");
        String s = sc.nextLine();

        int n = s.length();
        int[] dp = new int[n];
        HashMap<Integer, Integer> map = new HashMap<>();

        // Base case
        map.put(0, -1);
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            int value = (s.charAt(i) == '1') ? 1 : -1;
            if (i == 0) {
                dp[i] = value;
            } else {
                dp[i] = dp[i - 1] + value;
            }

            if (map.containsKey(dp[i])) {
                int len = i - map.get(dp[i]);
                maxLen = Math.max(maxLen, len);

            } else {
                map.put(dp[i], i);
            }
        }

        System.out.println("Maximum substring length = " + maxLen);
        sc.close();
    }
}
