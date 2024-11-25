### Overview
Parent pointer is an array representation of trees. This representation uses the property of trees that each node has a unique parent.

The parent pointer representation does not facilitate operations that require child-of information. In addition, the parent pointer representation does not specify the order of the children of a node.

### Diagram
![Tree Diagram](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/2_Tree.png)

The indeces of the array represent the elements of the tree, while the element of the array represents the parent (-1 meaning no parent i.e., the root). 

### Functions
1. `Preorder`
2. `LeftMostSibling`
2. `RightSibling`