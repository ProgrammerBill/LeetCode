Preorder Morris
step:
1.If the current node's left child is NULL,restore the current node
and then set its right child as current node
2.If the current node's left child is not NULL,then find the Precursor
from its left tree based on Inorder traversal
A.If the Precursor's right child is NULL,then set its right child
as the current node,and restore the current node,then set the current node as the current node's left child
B.If the Precursor's right child is the current node,then set the Precursor's right child as NULL,then set the current node as the current node's right child
3.repeat the 1 and 2 step until the current node is NULL
