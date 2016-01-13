public class PlusOne66 {
    public static void main(String[] args) {
        int [] digits = {9};

        int [] res = (new Solution()).plusOne(digits);

        for(int i = 0; i < res.length; ++i)
            System.out.print(res[i]);

        System.out.println();
    }
}

class Solution {
    public int[] plusOne(int[] digits) {

        boolean expand = false;

        for(int i = digits.length - 1; i >= 0; --i) {
            digits[i] += 1;

            if (digits[i] == 10) {
                digits[i] = 0;

                if(i == 0)
                    expand = true;
            } else
                break;
        }

        if(expand) {
            int [] res = new int[digits.length + 1];
            res[0] = 1;
            System.arraycopy(digits, 0, res, 1, digits.length);
            return res;
        }

        return digits;
    }
}
