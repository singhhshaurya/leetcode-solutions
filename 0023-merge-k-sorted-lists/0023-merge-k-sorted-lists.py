# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        for i in lists.copy():
            if i == None:
                lists.remove(i)
        if lists == None or lists == [None]:
            return None

        #build a heap specifically for linked lists heads.
        #REMEMBER
        #removing root - heapify down
        #build_heap - heapify_down, range = (len(arr)//2-1, -1, -1)
        #inserting - heapify up (not needed here)

        def heapify_down(heap, i):
            smallest = i #min heap
            size = len(heap)
            left = 2*i+1
            right = 2*i+2
            
            if left < size and heap[left].val < heap[smallest].val:
                smallest = left
            if right < size and heap[right].val < heap[smallest].val:
                smallest = right
                
            if smallest!=i:
                heap[i], heap[smallest] = heap[smallest], heap[i]
                heapify_down(heap, smallest)


        def build_heap(arr):
            for i in range(len(arr)//2-1, -1, -1): #heapify down me ye.
                heapify_down(arr,i)

        build_heap(lists)

        head = None #HAMARI RESULTANT LIST KA HEAD HOGA.
        temp = head

        while lists:
            if not temp:
                temp = ListNode()
                head = temp
            else:
                temp.next = ListNode()
                temp = temp.next
            temp.val = lists[0].val #first element of heap smallest

            lists[0] = lists[0].next #change the first element
            if lists[0] == None: #hata do bc
                lists[0] = lists[-1]
                lists.pop()

            heapify_down(lists, 0)

        return head

