### Overview
Directed graphs, or digraphs, are a type of graph structure where the connections between vertices, called nodes, are directional. In a directed graph, each arc is an ordered pair of vertices (v, w), where v is the tail and w is the head of the arc, typically expressed as v -> w and drawn with an arrowhead pointing from the tail to the head.

![ALT](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/1_DirectedGraph.png)

The key characteristics of directed graphs are directionality, adjacency (where w is adjacent to v), and reachability (being able to reach certain nodes from others by following the direction of the arcs).

### Terminologies
* **Directed Graph (Digraph)**: A graph structure where the connections between vertices, called nodes, are directional.
* **Vertex**: The nodes or points that make up a directed graph.
* **Arc**: The directed edges or directed lines that connect the vertices. An arc is an ordered pair of vertices (v, w), where v is the tail and w is the head.
* **Adjacency**: If there is an arc from node v to node w, then w is said to be adjacent to v.
* **Path**: A sequence of vertices v1, v2, ..., vn, such that v1 → v2, v2 → v3, ..., vn-1 → vn are arcs.
* **Path Length**: The number of arcs on a path, which is n-1.
* **Simple Path**: A path where all vertices, except possibly the first and last, are distinct.
* **Simple Cycle**: A simple path of length at least one that begins and ends at the same vertex.
* **Labeled Digraph**: A directed graph where each arc and/or vertex can have an associated label, such as a name, cost, or value.

### Diagram
![Directed Graph](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/2_DirectedGraph.png)

### Graph Representations
1. [[Adjacency Matrix]]
2. [[Adjacency List]]