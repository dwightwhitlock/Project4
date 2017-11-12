// Test driver
#include "TreeType.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//void testIntegersList();
//void testCharactersList();
//void testStudentsList();
int main()
{   
 return 0;
}
/*
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
    else if (command == "insertItem")
    { 
      int number;
      inFile >> number;
      list.insertItem(number);
      outFile << "\n";
    }
    else if (command == "deleteItem")
    { 
      int deleteInt;
      inFile >> deleteInt;
      list.deleteItem(deleteInt);
      outFile << "\n";
    }
    else if (command == "printList")
    { 
      list.printList(outFile);
    }
    else if (command == "merge")
    { 
      string line;
      SortedList<int> otherList;
      int x;
      getline(inFile, line);
      stringstream stream(line);
      while(stream >> x) 
      {
        otherList.insertItem(x);
      }
      otherList.printList(outFile);
      list.merge(otherList);
      outFile << "\n";
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

void testCharactersList()
{
SortedList<char> list;
string command;
ifstream inFile;
ofstream outFile;
inFile.open("charcommands.txt");
outFile.open("outFile.txt");

inFile>> command; // read commands from a text file

while (command != "Quit")
{
  try
  {
    if (command== "isEmpty")
      if(list.isEmpty())
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
      char item;
      int getLoc;
      inFile >> getLoc;
      item = list.get(getLoc);
      outFile << item << "\n";
    }
      else if (command == "insertItem")
    { 
      char insert;
      inFile >> insert;
      list.insertItem(insert);
      outFile << "\n";
    }
    else if (command == "deleteItem")
    { 
      char deleteChar;
      inFile >> deleteChar;
      list.deleteItem(deleteChar);
      outFile << "\n";
    }
    else if (command == "printList")
    { 
      list.printList(outFile);
    }
    else if (command == "merge")
    { 
      string line;
      SortedList<char> otherList;
      char x;
      getline(inFile, line);
      stringstream stream(line);
      while(stream >> x) 
      {
        otherList.insertItem(x);
      }
      list.merge(otherList);
      outFile << "\n";
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
} // testCharactersList 

void testStudentsList()
{
SortedList<Student> list;
string command;
ifstream inFile;
ofstream outFile;
inFile.open("studcommands.txt");
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
    outFile << length << endl;;
  } 
  else if (command == "makeEmpty")
  { 
    list.makeEmpty();
    outFile << "\n";
  } 
  else if (command == "get")
  { 
    Student studentObj;
    int getLoc;
    inFile >> getLoc;
    studentObj = list.get(getLoc);
    int id = studentObj.getID();
    string name = studentObj.getStudent();
    outFile << id << " " << name << "\n";
  }
  else if (command == "insertItem")
  { 
    Student studentObj;
    int id;
    string name;
    inFile >> id;
    inFile >> name;
    studentObj.setID(id);
    studentObj.setStudent(name);
    list.insertItem(studentObj);
    outFile << "\n";
  }
  else if (command == "deleteItem")
  { 
    int studentID;
    inFile >> studentID;
    Student newStud = list.get(studentID);
    list.deleteItem(newStud);
    outFile << "\n";
  }
  else if (command == "printList")
  { 
    list.printList(outFile);
  }
  else if (command == "merge")
  { 
    string line;
    SortedList<Student> otherList;
    int id;
    string name;
    Student temp;
    getline(inFile, line);
    stringstream stream(line);
    while(stream >> id)
    {
      stream >> name;
      temp.setID(id);
      temp.setStudent(name);
      otherList.insertItem(temp);
    }
    list.merge(otherList);
    outFile << "\n";
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
    outFile << "Item is not in the list." << endl;
    inFile>> command;
  }

} // while
} //testStudentList
*/
