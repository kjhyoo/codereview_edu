# Typing Machine

## Problem Statement
Our task is to implement typing machine using doubly linked list data structure. It is just
typical typing machine which can be found in many editors.
### This typing machine has 3 features:
- moving cursor,
- inserting/deleting characters near cursor,
- and printing whole string.
### You will implement 2 classes:
- class Node, which is each node of linked list.
- class TypingMachine, which is typing machine with features.


## Implementation
### class Node
We will implement Node type denoting each node of linked list.
+----------+---------Node-Type---------+----------+
| Previous | | Next |
<---+-- | Internal char type data | --+--->
| Node | | Node |
+----------+---------------------------+----------+

One public constructor and five public functions should be implemented.
- explicit Node(char data): This constructor should make Node storing data as internal
data.
- char GetData(): This function should return internal data.
- Node* InsertPreviousNode(char data): This function should make new Node with
given data and Insert between previous node and this node. (with new keyword of C++)
This function should return pointer of inserted node.
- Node* InsertNextNode(char data): This function should make new Node with given
data and Insert between next node and this node. (with new keyword of C++) This
function should return pointer of inserted node.
- Node* GetPreviousNode(): This function should return set previous node with Insert-
PreviousNode method. If not set, this function should return nullptr.
- Node* GetNextNode(): This function should return set next node with InsertNextNode.
If not set, this function should return nullptr.
- bool ErasePreviousNode(): This function should erase previous node and deallocate.
(with delete keyword of C++) If previous node does not exist so erase was unsuccessful,
you should return false. Otherwise, you should return true.
- bool EraseNextNode(): This function should erase previous node and deallocate. (with
delete keyword of C++) If next node does not exist so erase was unsuccessful, you should
return false. Otherwise, you should return true.
