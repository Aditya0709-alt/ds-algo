public class PlaceFlowers {

    static boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0, flower = 0, i = 0;
        boolean flag = true;
        int a = flowerbed.length;
        while (a != 0) {
            while (i < flowerbed.length) {
                if (flowerbed[i] == 1) {
                    flag = false;
                    count = 0;
                } else if (flag) {
                    count++;
                    if (count == 2) {
                        flower++;
                        count = 0;
                        if (flower == n) {
                            return true;
                        }
                    }
                } else {
                    flag = true;
                }
                i++;
            }
            a--;
        }
        if (count == 1) {
            flower++;
            if (flower == n) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[] flowerbed = new int[] { 1, 0, 0, 1 };

        int n = 2;
        System.out.println(canPlaceFlowers(flowerbed, n));
    }
}
