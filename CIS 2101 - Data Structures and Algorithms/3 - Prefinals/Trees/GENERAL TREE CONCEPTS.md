### Terminologies
* **Tree**: A hierarchical collection of nodes, with one root node and parenthood relations among nodes.  
* **Root**: The topmost node in a tree, with no parent.  
* **Node**: An element of a tree that may have a parent and children.  
* **Parent**: A node directly connected to one or more child nodes.  
* **Child**: A node directly connected and subordinate to a parent node.  
* **Subtree**: A node and all its descendants.  
* **Null Tree**: A tree with no nodes.  
* **Path Length**: One less than the number of nodes in the path.  
* **Ancestor**: A node with a path leading to another node.  
* **Descendant**: A node with a path originating from another node.  
* **Proper Ancestor**: An ancestor of a node, excluding the node itself.  
* **Proper Descendant**: A descendant of a node, excluding the node itself.  
* **Leaf**: A node with no proper descendants.
* **Height of a Node**: The length of the longest path from the node to a leaf.
* **Depth of a Node**: The length of the unique path from the root to the node.

### Diagram
![Tree Diagram](Attachments/1_Tree.png)

### Ordering of Nodes
There are several methods to systematically arrange the nodes of a tree. The three most common methods are `preorder`, `inorder`, and `postorder`.

1. `Preorder` - root -> left -> right
2. `Inorder` - left -> root -> right
3. `Postorder` - left -> right -> root

Using the diagram the result of each method would be:
1. `Preoreder` - A, B, D, E, C, F, G
2. `Inorder` - D, B, E, A, F, C, G 
3. `Postorder` - D, E, B, F, G, C, A
