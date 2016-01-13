public class MergeTwoList21 {
    public static void main(String[] args) {
        // build 2 lists first
        ListNode l1 = new ListNode(1);
        l1.next = new ListNode(3);
        l1.next.next = new ListNode(4);
        l1.next.next.next = new ListNode(5);
        ListNode l2 = new ListNode(2);
        l2.next = new ListNode(5);
        l2.next.next = new ListNode(6);
        l2.next.next.next = new ListNode(9);
        ListNode l3 = (new Solution()).mergeTwoLists(l1, l2);
        System.out.println("merged:");

        while (l3 != null) {
            System.out.print(l3.val + " ");
            l3 = l3.next;
        }

        System.out.println();
    }
}

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
    }
}

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode p = dummyHead;

        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                p.next = l1;
                l1 = l1.next;
            } else {
                p.next = l2;
                l2 = l2.next;
            }

            p = p.next;
        }

        if (l1 != null) p.next = l1;

        if (l2 != null) p.next = l2;

        return dummyHead.next;
    }
}
