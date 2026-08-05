# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        root = TreeNode(int(traversal[0]), None, None)

        stack = []
        depth = {}

        # print(root)
        # print(depth[stack[-1]])

        def newNode(val):
            node = TreeNode(val, None, None)
            return node

        count = 0
        ind = 0
        while ind<len(traversal):
            #print(stack, ind)
            if traversal[ind] == '-':
                count+=1
            else:
                val = ""
                while ind<len(traversal) and traversal[ind]!='-':
                    val+=traversal[ind]
                    ind+=1

                node = newNode(int(val))

                if stack == []:
                    stack.append(node)
                    depth[node] = 0
                    root = node
                    continue
                ind-=1 #val calculation me ek kadam aage chala jayega na.
                
                if depth[stack[-1]]<count:
                    stack[-1].left = node

                else:
                    node2 = stack.pop()
                    while depth[node2]>=count:
                        node2 = stack.pop()
                    node2.right = node

                stack.append(node)
                depth[node] = count
                count = 0
            ind+=1

        return root
        