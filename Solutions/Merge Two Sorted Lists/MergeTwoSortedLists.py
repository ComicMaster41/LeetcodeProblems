# NOTE: self. (before the recursive call) was only necessary in the leetcode interface
# since there was a SOLUTIONS class. I removed it so that this code can be copied and used without issues

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def mergeTwoLists(list1, list2):
    if list1 is None:
        return list2
    if list2 is None:
        return list1

        # if head1.val <= head2.val
    if list1.val <= list2.val:
        list1.next = mergeTwoLists(list1.next, list2)
        return list1

    else:
        list2.next = mergeTwoLists(list1, list2.next)
        return list2

merg = mergeTwoLists([1,2,3,4,5], [6,7,8,9,10])
print(merg)
