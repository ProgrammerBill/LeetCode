Morris Traversal
This method is different from the tradition way(use Stack)
which cost only O(n)time and O(1)space

step:
1.If the current node's left child is NULL,then output or store the 
current node and make its right child as current node
2.If the current node's left child is not NULL,then find the precursor
from its left tree based on Inorder Traversal
 A.If the precursor's right child is NULL,then set it's right child as
the current node,and update the current node to the current node's left
child.
 B.If the precursor's right child is the current node,then set the precursor's right child as NULL(recover the tree's original shape),and then output the current node.Update the current node as the current node's right child.
3. repeat the 1 and 2 step until the current node is NULL
