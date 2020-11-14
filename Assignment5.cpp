// ASU CSE310 Assignment #5
// Name of Author: William Schuhmann
// ASU ID: 1215016803
// Description: this is the main program that reads input from keyboard,
// it then call hash functions to execute hash commands given in the input.

//Assignment5.cpp

/**************************************************************************
//(1)Describe here what is your hash function?
    My hash function find the indec by taking every char in the given key, diving by m (size), multiplying by 4, and then using modulo m. They are then summed and modulo again, giving incides.
 
//(2)What is the number of collisions you expected?
    I thought there were going to be more than 5.
 
//(3)Did your hash function work well? Using the test cases, what's your hash table's load factor?
    I am not sure how to calculate load factor.
 
//(4)If you had to change your hash function to reduce the number of collisions, how will you change it?
    The more operations performed inbetween steps would probably decrease the amount of collisions, but I am not sure.
 
//----
***************************************************************************/

#include "Hash.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//This function extracts tokens from oneLine and get all info. of a Food
void getFoodInfo(string oneLine, string& FoodID, string& name, string& supplierID, double& price);

//This function extracts tokens from oneLine and get a Food key which is
//the combination of FoodID, name and supplierID
void getKey(string oneLine,string& command, string& FoodID, string& name, string& supplierID);

int main()
{
    //a variable represents the number of hash table slots
    int size;

    //a variable represents the number of commands
    int numOfCommand;

    //a variable represents the actual command name
    string command;

   string FoodID, name, supplierID;
   double price;
   string delimiter = ",";

    //declare any other necessary variables here
    string oneLine = "";
   //----

    cout << "Enter the size of the hash table: ";
    cin >> size;
    cin.ignore(20, '\n');

   //create the hash table with the relevant number of slots
    Hash* myHash = new Hash(size);
    //----

 do {
        cout << "\nEnter food info.(enter InsertionEnd to terminate): " << endl;
        getline(cin, oneLine);
        if(oneLine.compare("InsertionEnd") == 0)
            break;

      //if command is not InsertionEnd
      //Get one oneLine, call getFoodInfo(), then
      //insert the new Food inside the hash table
     getFoodInfo(oneLine, FoodID, name, supplierID, price);
     myHash->hashInsert(FoodID, name, supplierID, price);
      //----

    } while(true);

    cin >> numOfCommand;
    cin.ignore(20, '\n');

    for(int i= 0; i < numOfCommand; i++)
   {
         //get one oneLine from the input file and extract the first token,
         //if the token is hashDisplay, call the relevant function in Hash.h
       cout << "Enter command: \n" << endl;
       getline(cin, oneLine);

       getKey(oneLine, command, FoodID, name, supplierID);
       
       if(command.compare("hashDisplay") == 0)
       {
           myHash->hashDisplay();
           
           if (1 + i != numOfCommand)
           {
               cout << "\n";
           }
       }else if (command.compare("hashSearch") == 0)
       {
           myHash->hashSearch(FoodID, name, supplierID);
       }else if (command.compare("hashDelete") == 0)
       {
           myHash->hashDelete(FoodID, name, supplierID);
       }else
       {
           cout << "Invalid command" << endl;
       }
         //-----

         //if the token is hashSearch, call the relevant function in Hash.h
         //----

         //if the token is hashDelete, call the relevant function in Hash.h
         //----

      //for all other cases, show the following message
      //cout << "Invalid command" << endl;

   } //end for loop

    return 0;
} //end main

//*******************************************************************
//This function extract the tokens from one oneLine and
//get all Food info.
//*******************************************************************
void getFoodInfo(string oneLine, string& FoodID, string& name, string& supplierID, double& price)
{
   string delimiter = ",";

   //finish the remaining codes below
   //----
    int pos = oneLine.find(delimiter);
    string token = oneLine.substr(0, pos);
    FoodID = token;
    
    oneLine.erase(0, pos + delimiter.length());
    
    pos = oneLine.find(delimiter);
    token = oneLine.substr(0, pos);
    name = token;
    
    oneLine.erase(0, pos + delimiter.length());
    
    pos = oneLine.find(delimiter);
    token = oneLine.substr(0, pos);
    supplierID = token;
    
    oneLine.erase(0, pos + delimiter.length());
    
    pos = oneLine.find(delimiter);
    token = oneLine.substr(0, pos);
    price = stod(token);
    
    oneLine.erase(0, pos + delimiter.length());
   //----

   //Note: you can use stod to convert a string into double
   //but you will need c++11 compiler to achieve this
   //for example: price = stod(token);
}

//********************************************************************
//This function extracts the FoodID, name, supplierID from a given oneLine
//These info. forms the key of a Food.
//This function is given to you. Study it.
//********************************************************************

void getKey(string oneLine, string& command, string& FoodID, string& name, string& supplierID)
{
  string delimiter = ",";
  int pos = oneLine.find(delimiter);
  string token = oneLine.substr(0,pos);
  command = token;
  oneLine.erase(0, pos+delimiter.length());

  pos =oneLine.find(delimiter);
  token = oneLine.substr(0,pos);
  FoodID = token;
  oneLine.erase(0, pos+delimiter.length());

  pos = oneLine.find(delimiter);
  token = oneLine.substr(0,pos);
  name = token;
  oneLine.erase(0, pos+delimiter.length());

  pos = oneLine.find(delimiter);
  token = oneLine.substr(0,pos);
  supplierID = token;
  oneLine.erase(0, pos+delimiter.length());
}
