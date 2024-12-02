```text
procedure Dijkstra;
{ Computes shortest paths from vertex 1 in a directed graph }
begin
    S := ∅;          // Set S contains vertices included in the shortest path tree
    S := S ∪ {1};    // Add vertex 1 to S

    for i := 2 to n do
        D[i] := C[1, i];  { Initialize distances }

    for i := 1 to n-1 do begin
        // Select vertex w not in S with minimum D[w]
        w := vertex in V-S such that D[w] is minimum;
        
        S := S ∪ {w};   // Add w to S
        
        for each vertex v in V-S do
            D[v] := min(D[v], D[w] + C[w, v]); // Update distance to v
    end;
end;
```
