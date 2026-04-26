"""
876. Middle of the Linked List
Easy
Topics
premium lock icon
Companies
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
"""


"""
생각
linked list를 쭉 끝까지 순회하면서 리스트에 담아두고 //2 ? 아 근데 head값을 출력하라는 말이구나.
그럼 순회를 2번해서, 한번은 최대 길이 찾고, 두번째에는 해당 노드로 헤드 이동하기?
--> 정확히는 1.5번 순회하는 solution 1

투포인터. 
1 2 3 4 5
23
35

1 2 3 4 5 6
2 3
3 5
4 6

"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


# ## sol1: 1.5번 순회하자
# class Solution:
#     def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
#         ## find the mid index
#         curr = head
#         res = 0
#         while curr:
#             res += 1
#             curr = curr.next    
#         mid = res // 2
        
        
#         ## go to the mid node
#         res = head
#         for _ in range(mid):
#             res = res.next
        
#         return res
        

## sol2: two pointer    
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        ## find the mid index
        fast = head
        slow = head
        
        while fast and fast.next:
            fast = fast.next.next if fast.next.next else fast.next
            slow = slow.next
        
        res = slow
        return res
        
        