// Test driver
#include "TreeType.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void testIntegersList();
int main()
{   
  testIntegersList();
}

void testIntegersList()
{
SortedList<int> list;
string command;
ifstream inFile;
ofstream outFile;
inFile.open("intcommands.txt");
outFile.open("outFile.txt");

inFile>> command; // read commands from a text file

while (command != "Quit")
{
  try
  {
    if (command== "isEmpty")
      if( list.isEmpty())
        outFile << "list is empty" << endl;
      else
        outFile << "list is not empty" << endl;
    else if (command == "getLength")
    { 
      int length = list.getLength();
      outFile << length << endl;
    }
    else if (command == "makeEmpty")
    { 
      list.makeEmpty();
      outFile << "\n";
    }
    else if (command == "get")
    { 
      int item;
      int getLoc;
      inFile >> getLoc;
      item = list.get(getLoc);
      outFile << item << "\n";
    }
    else if (command == "putItem")
    { 
      int number;
      inFile >> number;
      list.insertItem(number);
      outFile << "\n";
    }
    else if (command == "DeleteItem")
    { 
      int deleteInt;
      inFile >> deleteInt;
      list.deleteItem(deleteInt);
      outFile << "\n";
    }
    else if (command == "printTree")
    { 
      list.printList(outFile);
    }
    else if (command == "LevelOrderPrint")
    { 
     
    }
    else if (command == "PreOrderPrint")
    { 
     
    }
    else if (command == "PostOrderPrint")
    { 
     
    }
    else if (command == "ResetTree")
    { 
     
    }
    else if (command == "GetLength")
    { 
     
    }
    else if (command == "MirrorImage")
    { 
     
    }
    else
    outFile << "Undefined Command" << endl;

  inFile>> command;
  } // try
  catch (FullList)
  {
    outFile << "List is full, insertion failed." << endl;
    inFile>> command;
  }  
  catch (EmptyQueue)
  {
     outFile << "List is empty, EmtpyList exception thrown." << endl;
     inFile>> command;
  }
  catch (DuplicateItem)
  {
    outFile << "DuplicateItem exception thrown." << endl;
    inFile>> command;
  }
  catch (NotInitalized)
  {
    outFile << "List has not been initalized." << endl;
    inFile>> command;
  }
  catch (NotInList)
  {
    outFile << "Item is not in the list." << endl;
    inFile>> command;
  }
  catch (OutOfBounds)
  {
    outFile << "Index out of range." << endl;
    inFile>> command;
  }
} // while
} // testIntegersList