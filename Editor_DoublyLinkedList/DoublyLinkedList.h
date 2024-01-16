class Node {                                // Node class.
    int data;
    Node* prev;                             // Pointer variable to save the address of the previous node.
    Node* next;                             // Pointer variable to save the address of the next node.

    friend class DoublyLinkedList;
};

class DoublyLinkedList {                    // Doubly Linked List class.
public:
    DoublyLinkedList();                     // Constructor.
    ~DoublyLinkedList();                    // Destructor.

    int List_size();                        // Return the size of the list.
    bool Empty();                           // Check if the list is empty (`true` for empty).
    void Print();                           // Print all the data in the list.

    void Append(int data);                  // Insert new node to the list.
    void Delete_idx(int idx);                // Delete the node with index `idx`.
    void Delete_data(int data);             // Delete all nodes with the data value of `data`.
    void Reverse();                         // Reverse ordering of the list.

    // Required to solve Part 2.
    void Set_cursor(); //Set cursor at the tail
    void Left();	// move cursor one character to the left
    void Right();	// move cursor one character to the right
    void Backspace();	// delete character left of the cursor
    void Insert(int data);		//Insert a new node with the value 'data' to left-side of 'cursor.'
    void Find_and_replace(int from, int to);	// Find int 'from' in the list and replace it to 'to'.

private:
    Node* head;                             // Pointer variable indicating head.
    Node* tail;                             // Pointer variable indicating tail.

    Node* cursor;

    int size;
};


