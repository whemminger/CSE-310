// ASU CSE310 Assignment #5
// Name of Author: William Schuhmann
// ASU ID: 1215016803
// Description: this is where you need to design functions on Hash hashTable,
// such as hashInsert, hashDelete, hashSearch and hashDisplay

//Hash.h

#include "LinkedList.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

class Hash
{
    private:
        LinkedList* hashTable;
        int m;         //size
    public:
      Hash(int size);
      ~Hash();
      bool hashInsert(string foodID, string name, string supplierID, double price);
      bool hashDelete(string foodID, string name, string supplierID);
      bool hashSearch(string foodID, string name, string supplierID);
      void hashDisplay();
      int hashFunction(string key);

      //add any other auxiliary functions here
      //----
};

//constructor
Hash::Hash(int size)
{
    hashTable = new LinkedList[size];
    m = size;
}

//Destructor
Hash::~Hash()
{
    //----
    delete[] hashTable;
}

//hashInsert inserts a Food with the relevant info. into the hashTable.
//it returns true if the data is inserted successfully and false otherwise
bool Hash::hashInsert(string foodID, string name, string supplierID, double price)
{
    //----
    int index_hash = hashFunction(name);
    bool index_result;
    index_result = hashTable[index_hash].insertFood(foodID,name, supplierID, price);
    
    if(index_result == true){
        cout << "slot index = " << index_hash << endl;
        return true;
    }else{
        return false;
    }
}

//hashDelete deletes a Food with the relevant key from the hashTable.
//it returns true if it is deleted successfully and false otherwise
//Note: key is the combination of foodID, name and supplierID
bool Hash::hashDelete(string foodID, string name, string supplierID)
{
      //----
    bool test = hashSearch(foodID, name, supplierID);
    int index_hash = hashFunction(name);
    bool result = hashTable[index_hash].deleteFood(foodID);
    
    if (result == true)
    {
        cout << setw(4) << foodID
             << setw(30) << name
             << setw(12) << supplierID
             << " is deleted from hash table.\n" << endl;
        return true;
    }else{
        cout << setw(4) << foodID
             << setw(30) << name
             << setw(12) << supplierID
             << " is NOT deleted from hash table.\n" << endl;
        return false;
    }
    return false;
}

//This function searches for a key inside the hash table and
//return true if it is found and false otherwise
//Note: key is the combination of foodID, name and supplierID
bool Hash::hashSearch(string foodID, string name, string supplierID)
{
    //----
    int index_hash = hashFunction(name);
    bool found = hashTable[index_hash].searchFood(foodID);
    
    if (found){
        cout << left
             << setw(4) << foodID
             << setw(30) << name
             << setw(12) << supplierID
             << " is found inside the hash table." << endl;
        return true;
    }
    
    if(!found){
        cout << left
            << setw(4) << foodID
            << setw(30) << name
            << setw(12) << supplierID
            << " is NOT found inside the hash table." << endl;
        return false;
    }
    return false;
 }

//This function prints all the elements from the hash hashTable.
void Hash::hashDisplay()
{
    //----
    for (int i = 0; i < m; i++)
    {
      if (hashTable[i].getHead() == NULL )
      {
          cout << "HashTable[" << i << "] is empty, size = 0" << endl;

          if( 1 + i != m)
          {
              cout << "\n";
          }
      } else{
        cout << "HashTable[" << i << "], size = " << hashTable[i].getSize() << endl;
        hashTable[i].displayList();

        if ( 1 + i != m)
        {
            cout << "\n";
        }
      }
    }
    //----
}

//This is the hash function you will need to design, test and refine
//Given a Food key, the function should return the slot index where it
//will be hashed to
int Hash::hashFunction(string key)
{
    //----
    int sumKey = 0;
    
    int charIntForm = 0;

    for (int i = 0; i<key.length(); i++)
    {
      charIntForm = int(key[i]);
      charIntForm /= m; 
      charIntForm *= 4;
      charIntForm %= m;
      sumKey += charIntForm;
    }
    return sumKey % m;
}
