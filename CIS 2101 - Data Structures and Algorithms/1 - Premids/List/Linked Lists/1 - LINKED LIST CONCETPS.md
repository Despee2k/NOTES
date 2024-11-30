### Overview
In this approach, a list is composed of cells, where each cell contains a list element and a pointer to the next cell. This implementation eliminates the need for contiguous memory to store the list, avoiding the need to shift elements when adding or removing items. However, it comes at the cost of additional space required for the pointers.

### Diagram
![ALT](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/INSERTNAME)

### Functions
1. `Insert`
    Variations:
    - `InsertFirst`
    - `InsertLast`
    - `InsertSorted`
    - `InsertLastUnique`
2. `Delete`
    Variations:
    - `DeleteAllOccurances`
3. `MakeNull`
4. `PrintList`
