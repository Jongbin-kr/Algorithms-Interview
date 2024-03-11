from typing import *
def show_node(head):
    while head:
        print(head.val)
        head = head.next
    
    print('---end show node---')
    
    return head
    
    