#include <string>
#include <fstream>
#include "QueType.h"
using namespace std;
//typedef int ItemType;

template <class ItemType>
struct TreeNode
{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
};
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
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order); 
  ItemType GetNextItem(OrderType order, bool& finished);
  void Print() const;

  //To Implement
  void Ancestors(ItemType value);
  void LevelOrderPrint(ofstream &);
  void PreOrderPrint(ofstream& out);
  void InOrderPrint(ofstream& out);
  void PostOrderPrint(ofstream& out);
  void MirrorImage();
  void MakeTree();
private:
  TreeNode<ItemType> PtrToSuccessor(TreeNode<ItemType>*& tree);
  TreeNode<ItemType>* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

