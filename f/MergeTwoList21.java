public class MergeTwoList21{
   public static void main(String[] args){
   ListNode l1=[1,3,4,5];
   ListNode l2=[2,5,7,9];

   System.out.println("merge two list:" +(new Solution()).mergeTwoList(l1,l2));

   }

}

class Solution{
  public listNode mergeTwoLists(ListNode l1, ListNode 12){
  ListNode dummyHead = new ListNode(0);
  ListNode p = dummyHead;

  while(l1 != null && l2 != null){
        if(l1.val<l2.val){
        p.next = l1;
        l1 = l1.next;
        }else{
        p.next = l2;
        l2 = l2.next;
        }
        p = p.next;
  }
  if(l1 != null) p.next = l1;
  if(l2 != null) p.next = l2;
  return dummyHead.next;
  }

}
