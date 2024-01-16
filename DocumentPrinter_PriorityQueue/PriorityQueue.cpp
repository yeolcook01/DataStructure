#include "PriorityQueue.hpp"

// Part 1: Basic operations of priority queue (40 pts)
PriorityQueue::PriorityQueue(int d) {   // Constructor.
    if (d == 1) {
        direction = 1;
    }
    else if (d == -1) {
        direction = -1;
    }

    heap_size = 0;

}


PriorityQueue::~PriorityQueue() {   // Destructor.
}


void PriorityQueue::swapPQ(int idx1, int idx2) {    // Swaps the elements at the specified indices in the heap.
    int temp = heap[idx1];
    heap[idx1] = heap[idx2];
    heap[idx2] = temp;
}


void PriorityQueue::upHeap(int idx) {   // Adjust the heap by moving the specified element upwards.
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] * direction >= heap[idx] * direction) {
            swapPQ(parent, idx);
            idx = parent;
        }
        else {
            break;
        }
    }
}


void PriorityQueue::downHeap(int idx) { // Adjust the heap by moving the specified element downwards.

    if (direction == 1) { // MinHeap
        while (heap_size-1 >= 2*idx+2) {
            int child;
            if (heap[2*idx+1] >= heap[2*idx+2]) {
                child = 2*idx+2;
            }
            else {child = 2*idx+1;}
            if (heap[child] < heap[idx]) {
                swapPQ(child, idx);
                idx = child;
            }
            else {break;}
        }

        if (heap_size-1 < 2*idx+1) { return; } // no child
        else if (heap_size-1 == 2*idx+1) { // only left child
            if (heap[2*idx+1] < heap[idx]) {
                swapPQ(2*idx+1, idx);
                return;
            }
            else {return;}
        }
    }
    if (direction == -1) { // MaxHeap
        while (heap_size-1 >= 2*idx+2) {
            int child;
            if (heap[2*idx+1] <= heap[2*idx+2]) {
                child = 2*idx+2;
            }
            else {child = 2*idx+1;}
            if (heap[child] > heap[idx]) {
                swapPQ(child, idx);
                idx = child;
            }
            else {break;}
        }

        if (heap_size-1 < 2*idx+1) { return; } // no child
        else if (heap_size-1 == 2*idx+1) { // only left child
            if (heap[2*idx+1] > heap[idx]) {
                swapPQ(2*idx+1, idx);
                return;
            }
            else {return;}
        }
    }
}


void PriorityQueue::insertHeap(int e) { // Insert a new entry to the queue.
    heap.push_back(e);
    heap_size++;
    upHeap(heap_size-1);
}


int PriorityQueue::popHeap() {  // Pop its top entry. If the queue is empty, then print "Empty queue.".

    if (heap_size == 0) { // empty queue
        std::cout << "Empty queue." << std::endl;
        return 0;
    }

    else if (heap_size == 1) { // only root left
        int temp = heap[0];
        heap_size--;
        heap.pop_back();
        std::cout << temp << std::endl;
        return temp;
    }

    else { // more than one element
        int temp = heap[0];
        swapPQ(0, heap_size-1);
        heap_size--;
        heap.pop_back();
        downHeap(0);
        std::cout << temp << std::endl;
        return temp;
    }
}


int PriorityQueue::topHeap() const {    // Return its top entry. If the queue is empty, then print "Empty queue.".
    if (heap_size == 0) {
        std::cout << "Empty queue." << std::endl;
        return 0;
    }
    else {
        std::cout << heap[0] << std::endl;
        return heap[0];
    }
}


int PriorityQueue::sizeHeap() const {   // Return size of queue.
    return heap_size;
}


bool PriorityQueue::emptyHeap() const { // Check if the queue is empty. `1` for empty queue.
    if (heap_size == 0) {
        return true;
    }
    else {
        return false;
    }
}



//// Part 2: Document printer implementation with priority queue (60 pts)
Document::Document(std::string i_id, std::string i_title, int i_priority) {   // Constructor.
    id = i_id;
    title = i_title;
    priority = i_priority;
}


std::string Document::getId() const {   // Getter.
    return id;
}


std::string Document::getTitle() const {    // Getter.
    return title;
}


int Document::getPriority() const { // Getter.
    return priority;
}


Printer::Printer() {    // Constructor.
    heap_size = 0;
}


Printer::~Printer() {   // Destructor.
}


void Printer::swapDoc(int idx1, int idx2) { // Swaps the elements at the specified indices in the printer.
    Document temp = docs[idx1];
    docs[idx1] = docs[idx2];
    docs[idx2] = temp;
}


void Printer::upHeap(int idx) { // Adjust the heap by moving the specified element upwards.
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (docs[parent].getPriority() >= docs[idx].getPriority()) {
            swapDoc(parent, idx);
            idx = parent;
        }
        else {
            break;
        }
    }
}


void Printer::downHeap(int idx) {   // Adjust the heap by moving the specified element downwards.
    while (heap_size-1 >= 2*idx+2) {
        int child;
        if (docs[2*idx+1].getPriority() >= docs[2*idx+2].getPriority()) {
            child = 2*idx+2;
        }
        else {child = 2*idx+1;}
        if (docs[child].getPriority() < docs[idx].getPriority()) {
            swapDoc(child, idx);
            idx = child;
        }
        else {break;}
    }

    if (heap_size-1 < 2*idx+1) { return; } // no child
    else if (heap_size-1 == 2*idx+1) { // only left child
        if (docs[2*idx+1].getPriority() < docs[idx].getPriority()) {
            swapDoc(2*idx+1, idx);
            return;
        }
        else {return;}
    }
}


void Printer::insertDoc(std::string id, std::string title, int priority) {  // Insert a new doc. (modifiable)
    Document newDoc(id, title, priority);
    docs.push_back(newDoc);
    heap_size++;
    upHeap(heap_size-1);
}


void Printer::popDoc() {    // Pop its top doc. (modifiable)
    if (heap_size == 0) { // empty queue
        std::cout << "Empty queue." << std::endl;
    }

    else if (heap_size == 1) { // only root left
        Document temp = docs[0];
        heap_size--;
        docs.pop_back();
        std::cout << temp.getId() << " " << temp.getTitle() << std::endl;
    }

    else { // more than one element
        Document temp = docs[0];
        swapDoc(0, heap_size-1);
        heap_size--;
        docs.pop_back();
        downHeap(0);
        std::cout << temp.getId() << " " << temp.getTitle() << std::endl;
    }

}



Document Printer::topDoc() const {  // Returns the document with the highest priority.
    if (heap_size == 0) {
        std::cout << "Empty queue." << std::endl;
        Document emptyDoc("", "", 0);
        return emptyDoc;
    }
    else {
        std::cout << docs[0].getId() << " " << docs[0].getTitle() << std::endl;
        return docs[0];
    }

}

Document Printer::popM(int M) { // M <= size of printer
    if (heap_size == 1) { // only root left
        return docs[0];
    }

    else { // more than one element
        if (M == 1) {
            return docs[0];
        }
        else {
            for (int i=0; i<M-1; i++) {
                Document temp = docs[0];
                swapDoc(0, heap_size-1);
                heap_size--;
                docs.pop_back();
                downHeap(0);
            }
            return docs[0];
        }
    }
}



int Printer::sizePrinter() const {  // Returns the size of the queue.
    return heap_size;
}


bool Printer::emptyPrinter() const {    // Check if the queue is empty. `1` for empty queue.
    if (heap_size == 0) {
        return true;
    }
    else {
        return false;
    }
}