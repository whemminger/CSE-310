//********************************************************
// Assignment: ASU CSE310 HW#3
// Your Name: William Schuhmann
// ASU ID: 1215016803
// ASU Email address: wschuhma@asu.edu
// Description: Header file for Assignment3.cpp
//********************************************************
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Food represents a food. Each food with a unique key
struct Food
{
    int key;
    string foodName;
    double price;
};

//class Heap represents a Max heap that contains Food objects. Underline data structure is
//a one dimensional array of Food objects.
class Heap
{
    private:
    struct Food* foodArr;    //an array of Food
    int capacity, size;

    public:
    Heap(int capacity);
    ~Heap();
    Food* getFoodArr();
    int getSize();
    int getCapacity();
    int isFound(int foodKey);
    bool increaseKey(int index, Food oneFoodwithNewKey);
    bool insert(int key, string foodName, double foodPrice);
    void heapify(int index);
    Food getHeapMax();
    void extractHeapMax();
    int leftChild(int parentIndex);
    int rightChild(int parentIndex);
    int parent(int childIndex);
    void printHeap();
};

//Constructor to dynamically allocate memory for a heap with the specified capacity
Heap::Heap(int capacity)
{
    size = 0;
    foodArr = new Food(capacity);
}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the heap.
//and prints the number of nodes deleted by it.
Heap::~Heap()
{
    //----
    //----
    cout << "\nThe number of deleted food items is: " << foodCount << endl;
}

//Finish all the remaining functions according to the project's description
//----
Food* getFoodArr()  //This is the accessor for the instance variable foodArr.
{
    
}

int getSize()   //This is the accessor for the instance variable size.
{
    
}

int getCapacity()   //This is the accessor for the instance variable capacity.
{
    
}

int isFound(int foodKey)    //Given a key, this method returns the Food object's index inside the foodArr if it find a food with the specific foodKey; otherwise it should return -1.
{
    
}

bool increaseKey(int index, Food foodwithNewKey)    //Given an index and a Food object called foodwithNewKey, this function increases the Food object at index's key to the new key as inside the foodWithNewKey. The function returns true if the operation is successful and false otherwise.
{
    
}

bool insert(int key, string foodName, double foodPrice) //Given the information of a Food object, namely its key, name and price, this function create a new Food ojbect and inserts it inside the                                                      //heap. If successful, it should update the size and return true; otherwise return false.
{

}

void heapify(int index) //As we learned in class, before we call this heapify( ) function, we assume that the binary tree rooted at left and right child of the node at index are already max heaps, but node at index might be samller than its children, thus violating the max-heap property. heapify( ) lets the node at index "float down" in the max-heap so that the subtree rooted at index obeys the max-hea property.
{
    
}

Food getHeapMax()   //This is the accessor for the root of the heap, it returns the largest Food object (also root) of the max-heap. Note: this function only get the root node information of the max-heap, it does NOT remove it.
{
    
}

void extractHeapMax()   //This function extracts the root of the heap. Basically we replace the root by the last node of the heap, then call heapify( ) to "float-down" the newly added root, we then decrease the size of the heap by 1.
{
    
}

int leftChild(int parentIndex)  //Given a parent node's index, this function returns its left child's index inside the 1D array.
{
    
}

int rightChild(int parentIndex) //Given a parent node's index, this function returns its right child's index inside the 1D array.
{
    
}

int parent(int childIndex)  //Given a node's index, this function returns its parent node's index inside the 1D array.
{
    
}
//----

void Heap::printHeap()  //This function uses the breadth-frist traversal to print out the contents of the heap.
{
    //----
    //----

    cout << left;
    cout << setw(5) << foodArr[i].key
         << setw(8) << foodArr[i].foodName
         << setw(8) << fixed << setprecision(2) << foodArr[i].price << endl;

}

