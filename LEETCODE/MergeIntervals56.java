class Solution {
  static int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        int start = intervals[0][0];
        int end = intervals[0][1];

        ArrayList<int[]> arr = new ArrayList<>();
        for (int i[] : intervals) {
            if (i[0] <= end) {
                end = Math.max(end, i[1]);
            } else {
                int temp[] = { start, end };
                arr.add(temp);
                start = i[0];
                end = i[1];
            }

        }
        int[] temp = { start, end };
        arr.add(temp);
        return arr.toArray(new int[arr.size()][]);
    }
}
