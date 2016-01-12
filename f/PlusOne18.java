import java.util.*;
import java.util.ArrayList;

public class PlusOne18{
   public static void main(String[] args){
   int[] nums = {1,3,4,5,6,9};
   List<Integer> intList = new ArrayList<Integer>();
   for(int index = 0; index< nums.length; index++){
         intList.add(nums[index]);
   }

   System.out.println("plus one:" +(new Solution()).plusOne(intList));
   }
}
class Solution{
public int[] plusOne(List<Integer> digits){
    for(int i = digits.size()-1;i>=0;i--){
    int digit = digits.get(i);
    int[] array = new int[digits.size()];
    array = digits.toArray(array);

    if(digit<9){
        digits.set(i,digit+1);
       // int[] array = digits.stream().toArray(int[]::new);
        return array;
    }else{
        digits.set(i,0);
    }
    
    }
     digits.add(0);
     digits.set(0,1);
}



}
