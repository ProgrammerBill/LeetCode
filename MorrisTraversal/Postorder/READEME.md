Postorder Morris Traversal
step:
1.Set the current node as a tempary node
2.If the current node's left child is NULL,then set the current node
as the current node's right child
3.If the current node's left child is not NULL,find the prevcusor node of the current node from its left tree based on the Inorder traversal
A.If the prevcusor's right child is NULL,set the the prevcusor's right child as the current node,and then update the current node as the current node's left child
B.If the prevcusor's right child is the current node,the set it's right child as NULL,and then ouput the nodes from the current node's left child to the prevcusor reversely.
4.repeat the step 2 and 3 until the current node is NULL
