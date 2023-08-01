/*
The approach used is backatracking. We add an element to the temp array and use recursion on the updated temp array. This approach avoides duplicates
*/

// Backtracking Tree


class Solution {
    
    private static void kCombination(List<List<Integer>> output, List<Integer> temp, int start, int n, int k) {
        if (k == 0) {
            output.add(new ArrayList<>(temp));
            return;
        }

        for (int i = start; i <= n; i++) {
            temp.add(i);
            kCombination(output, temp, i + 1, n, k - 1);
            temp.remove(temp.size() - 1);
        }
    }

    public static List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> output = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        kCombination(output, temp, 1, n, k);
        return output;
    }
}


