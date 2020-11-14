// ASU CSE310 Assignment #5
// Name of Author: William Schuhmann
// ASU ID: 1215016803
// Description: A simple linked list that implements a list of Food objects. A user can perform searching, insertion or deletion on the linked list.

//LinkedList.h

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Food
{
    string foodID, name, supplierID;
    double price;
    struct Food* next;
};

class LinkedList
{
    private:
        struct Food* head;
        int size;
    public:
           LinkedList();
           ~LinkedList();
           Food* getHead();
           int getSize();
           bool insertFood(string foodID, string name, string supplierID, double price);
           bool deleteFood(string foodID);
           bool searchFood(string foodID);
           void displayList();
};

//Constructor
LinkedList::LinkedList()
{
    head = NULL;
    size = 0;
}

//Destructor
LinkedList::~LinkedList()
{
    //----
    Food *temp = head;

    while(temp!= NULL){
      Food *next = temp->next;
      delete temp;
      temp = next;
    }
    head = NULL;
}

//Accessor for the head
Food* LinkedList::getHead()
{
    return head;
}

//Return number of foods inside the Linked list
int LinkedList::getSize()
{
    return size;
}

//Insert the parameter food at the head of the linked list.
//return true if it is inserted successfully and false otherwise
bool LinkedList::insertFood(string foodID, string name, string supplierID, double price)
{
    //----
    bool truthVal;
    Food *temp = new Food;

    truthVal = searchFood(foodID);
    if(truthVal == true){
      return false;
    }else{
      temp->foodID = foodID;
      temp->name = name;
      temp->supplierID = supplierID;
      temp->price = price;
      temp->next = head;
      head = temp;
      size++;
      return true;
    }
 }

//Delete the food with the given foodID from the linked list.
//Return true if it is deleted successfully and false otherwise
bool LinkedList::deleteFood(string foodID)
{
    //----
    Food *Previous = NULL;
    Food *temp = head;

    if(temp == NULL){
      return false;
    }else{
        
      if(temp->foodID.compare(foodID) == 0){
        head = head->next;
        delete temp;
        size = size - 1;
        return true;
      } else{
        while(temp != NULL){
            
          if(temp->foodID.compare(foodID) == 0)
          {
            Previous->next = temp->next;
            delete temp;
            size = size - 1;
            return true;
          }
          Previous = temp;
          temp = temp->next;
        }
        return false;
      }
    }
}

//This function searches the food list with the given foodID
//returns true if it is found, otherwise return false.
bool LinkedList::searchFood(string foodID)
{
    //----
    Food *temp = head;

    while(temp!=NULL){
      if(temp->foodID.compare(foodID) == 0){
        return true;
      }
      temp = temp->next;
    }
    return false;
}

//This function displays the content of the linked list.
void LinkedList::displayList()
{
   struct Food *temp = head;
    if(head == NULL)
    {
        return;
    }
    while(temp != NULL)
    {
      cout << left;
      cout << setw(4) << temp->foodID
           << setw(30) << temp->name
           << setw(12) << temp->supplierID
           << setw(8) << temp->price << endl;
      temp = temp->next;
    }
}
