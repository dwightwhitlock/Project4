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
  return 0;
}

void testIntegersList()
{
TreeType<int> intTree;
string command;
ifstream inFile;
ofstream outFile;
inFile.open("input.txt");
outFile.open("outFile.txt");
if(!outFile)
{
  std::cout << "error openning output file" << endl;
  return;
}

inFile>> command; // read commands from a text file

  while (command != "Quit")
  {

      if (command== "IsEmpty")
        if(intTree.IsEmpty()){
          outFile << "list is empty" << endl;
        }
        else{
          outFile << "list is not empty" << endl;
        }
      else if (command == "GetLength")
      { 
        int length = intTree.GetLength();
        outFile << length << endl;
      }
      else if (command == "MakeEmpty")
      { 
        intTree.MakeEmpty();
        outFile << "\n";
      }
      else if (command == "GetItem")
      { 
        bool found = false;
        int item;
        int getLoc;
        inFile >> getLoc;
        item = intTree.GetItem(getLoc, found);
        if(found){
          outFile << item << "found\n";
        }
        else{
          outFile << item << "not found\n";
        }
      }
      else if (command == "GetNextItem")
      { 
        bool finished = false;
        int item;
        string order;
        OrderType orderr;
        inFile >> order;

        if(order == "IN_ORDER"){
          orderr = IN_ORDER;
        }
        else if(order == "IN_ORDER"){
          orderr = PRE_ORDER;
        }
        else{
          orderr = POST_ORDER;
        }

        item = intTree.GetNextItem(orderr, finished);
        if(finished){
          outFile << item;
        }
        else{
          outFile << "Treen empty\n";
        }
      }
      else if (command == "PutItem")
      { 
        int number;
        inFile >> number;
        intTree.PutItem(number);
        outFile << "\n";
      }
      else if (command == "DeleteItem")
      { 
        int deleteInt;
        inFile >> deleteInt;
        intTree.DeleteItem(deleteInt);
        outFile << "\n";
      }
      else if (command == "printTree")
      { 
        intTree.Print();
      }
      else if (command == "LevelOrderPrint")
      { 
        intTree.LevelOrderPrint(outFile);
      }
      else if (command == "PreOrderPrint")
      { 
        intTree.PreOrderPrint(outFile);
      }
      else if (command == "PostOrderPrint")
      { 
        intTree.PostOrderPrint(outFile);
      }
      else if (command == "ResetTree")
      { 
        string order;
        OrderType orderr;
        inFile >> order;

         if(order == "IN_ORDER"){
          orderr = IN_ORDER;
        }
        else if(order == "IN_ORDER"){
          orderr = PRE_ORDER;
        }
        else{
          orderr = POST_ORDER;
        }

        intTree.ResetTree(orderr);
      }
      else if (command == "GetLength")
      { 
        int length;
        length = intTree.GetLength();
        outFile << length << endl;
      }
      else if (command == "MirrorImage")
      { 
        TreeType<int> Mirror;
        Mirror = intTree.MirrorImage();
        Mirror.Print();
      }
      else
      outFile << "Undefined Command" << endl;

    inFile>> command;
  } // while
} // testIntegersList