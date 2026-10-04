Step‑by‑Step Explanation
Insert Function : 
Compare new key with current node.
Smaller → go left.
Larger → go right.
If NULL → create new node.

Delete Function: 
Search for the node.

Three cases:

Node has no child → just delete.
Node has one child → replace with child.
Node has two children → replace with inorder successor (minimum in right subtree).

Inorder Traversal : 
Prints nodes in sorted order.
Useful to check correctness after insertions/deletions.