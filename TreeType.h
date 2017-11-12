#include <string>
#include <fstream>
typedef int ItemType;
struct TreeNode;
#include "QueType.h"
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

template <class ItemType>
class TreeType
{
public:
  TreeType();                     // constructor
 ~TreeType();                    // destructor
  TreeType(const TreeType& originalTree); 
  void operator=(const TreeType& originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int GetLength() const; 
  ItemType GetItem(ItemType item, bool& found);
  void PutItem(ItemType item);
  void DeleteItem(ItemType item); //(5) modify with PtrToSuccessor
  void ResetTree(OrderType order); 
  ItemType GetNextItem(OrderType order, bool& finished);
  void Print() const;

  //TO IMPLEMENT
  void LevelOrderPrint(ofstream &); //(2)
  
  void PreOrderPrint(ofstream &); //(3)
  void InOrderPrint(ofstream&);
  void PostOrderPrint(ofstream&);

  void Ancestors(ItemType); //(6)

private:
  TreeNode<ItemType> * PtrToSuccessor(TreeNode<ItemType> *& tree); //(4)

  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

