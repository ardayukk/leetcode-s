class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode listFinal = dummy;

        while (l1 != null && l2 != null) {
            int num1 = l1.val;
            int num2 = l2.val;

            if (num1 < num2) {
                listFinal.next = l1;
                l1 = l1.next;
            } 
            else {
                listFinal.next = l2;
                l2 = l2.next;
            }
            listFinal = listFinal.next;
        }

        if (l1 != null) {
            listFinal.next = l1;
        } else {
            listFinal.next = l2;
        }

        return dummy.next;
    }
}
