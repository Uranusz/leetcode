public class FindPeakElement162 {
    public static void main(String [] args) {
        //int[] arr = {1,2,3,4,5,6,0,-1};
        int[] arr = {1,2};
        System.out.println("peak: " + (new Solution()).findPeakElement(arr));
    }
}

class Solution {
    public int findPeakElement(int[] nums) {
        if (nums.length == 1)
            return 0;

        int left = 0, right = nums.length-1;

        while(left < right) {
            int mid = (left + right) / 2;

            if(nums[mid] < nums[mid+1])
                left = mid + 1;
            else
                right = mid;
        }

        //System.out.println("left: " + left + ", right: " + right);

        return left;
    }
}
