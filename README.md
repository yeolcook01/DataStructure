# DataStructure

**language: c++**
**version: g++ 11, c++ 17**

## 1. Editor_DoublyLinkedList 📀
- DoublyLinkedList.h
- DoublyLinkedList.cpp
- part2_main.cpp
#### Part 1: Basic operations of doubly linked list
- Append a node, delete idx/data, reverse the ordering of the list, get the size of the list, check if empty, print the list
#### Part2: Editor implementation with doubly linked list
- Implement editor which edits an integer sequence with commands
- command  
  - L: move cursor one character to the left
  - R: move cursor one character to the right
  - B: delete character left of the cursor
  - P$: add character $ left of the cursor
  - V: reverse the sequence
  - F$*: Find all $ in the sequence and replace it to *


## 2. DocumentPrinter_PriorityQueue 🖨️

- PriorityQueue.hpp
- PriorityQueue.cpp
- part1_main.cpp
- part2_main.cpp

#### Part 1: Basic operations of priority queue
- Heapify(upHeap, downHeap), Insert&pop, swapPQ, topHeap, sizeHeap, emptyHeap
#### Part 2: Document printer implementation with priority queue
- Implement document printer which can only print one document at a time, and each document has its importance represented by natural numbers
- If there’s any other document in the queue with a higher importance, place the taken document at the end of the queue. Otherwise, print the taken document.
- command  
  - I id title priority: Insert a new document with given properties
  - P: Print ID and title of the top document, and pop it
  - T: Print ID and title of the top document without removing
  - S: Print the length of the queue
  - E: Print ‘1‘ if the queue is empty

## 3. SNUverse_Graph 📱
- SNUverse.h
- SNUverse.cpp

### SNUverse Implementation
SNUverse
- design and manage the relationships between accounts as a directed graph
- each account as vertex, and the following relationship as directed edge

#### Account class 
- Add following/follower, Delete following/follower

#### SNUverse class
- Create account, Delete account, Print
- Follow, Unfollow
- Recommended_freind: include followings of followings of src ID, excluding src ID’s fol- lowing, and src ID itself
- Common_friends: IDs that exist in the following list of both src ID and dest ID
- isReachable: check if there is a direct follow relationship from the source account to the destination account
- Distance: the shortest distance between the accounts with the specified source and destination IDs
