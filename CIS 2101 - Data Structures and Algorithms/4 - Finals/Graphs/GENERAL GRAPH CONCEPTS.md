### Terminologies
* **Graph (G)**: A mathematical structure composed of two finite sets: 
    * a nonempty set of vertices (V(G)) and 
    * a set of edges (E(G)) that are associated with either one or two vertices as their endpoints
* **Vertex**: Points or dots in a graph that represent discrete elements or locations
* **Edge**: Line segments or connections that join two vertices in a graph, potentially allowing crossings at points that are not vertices themselves
* **Edge-Endpoint Function**: The systematic correspondence that maps each edge to its associated vertex or vertices
* **Loop**: An edge characterized by having only a single vertex as its endpoint
* **Parallel Edges**: Multiple distinct edges that share an identical set of endpoints
* **Connected Edges**: An edge that directly links its designated endpoints
* **Adjacent Vertices**: Two vertices that are directly connected by an edge, or in the case of a loop, a vertex that is connected to itself
* **Incident Edges**: Edges that are directly linked to a specific vertex
* **Adjacent Edges**: Edges that share a common endpoint
* **Isolated Vertex**: A vertex that has no edges connected to or incident upon it

### Diagram
![Graph Diagram](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/1_Graph.png)

Using the given graph find:
1. All edges that are incident on v1
2. All vertices that are adjacent to v1
3. All edges that are adjacent to e1
4. All loops
5. All parallel edges
6. All vertices that are adjacent to themselves
7. All isolated vertices.

Answer:
1. E1, E2, and E3 are incident on V1
2. V2 and V3 are adjacent to V1
3. E2, E3, and E4 are adjacent to E1
4. E6 and E7 are loops
5. E2 and E3 are parallel
6. V5 and V6 are adjacent to themselves
7. V4 is an isolated vertex

### Types of Graphs
1. [[1 - DIRECTED GRAPH CONCEPTS|Directed Graph]]
2. [[1 - UNDIRECTED GRAPH CONCEPTS|Undirected Graph]]

### Differences Between Directed and Undirected
![Graph Comparison Diagram](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/4_GraphDifference.png)