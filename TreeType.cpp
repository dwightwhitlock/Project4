#include<iostream>
using namespace std;
#include "TreeType.h"

template<class ItemType>
bool TreeType<ItemType>::IsFull() const
// Returns true if there is no room for another item 
//  on the free store; false otherwise.
{
  TreeNode<ItemType>* location;
  try
  {
    location = new TreeNode<ItemType>;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

template<class ItemType>
bool TreeType<ItemType>::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
  return root == NULL;
}

template<class ItemType>
int TreeType<ItemType>::GetLength() const
// Calls recursive function CountNodes to count the 
// nodes in the tree.
{
  return CountNodes(root);
}

template<class ItemType>
int CountNodes(TreeNode<ItemType>* tree)
// Post: returns the number of nodes in the tree.
{
  if (tree == NULL)
    return 0;
  else 
    return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

template<class ItemType>
ItemType TreeType<ItemType>::GetItem(ItemType item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
  Retrieve(root, item, found);
  return item;
}

template<class ItemType>
void Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found)
// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem; 
//       otherwise found is false and item is unchanged.
{
  if (tree == NULL)
    found = false;                     // item is not found.
  else if (item < tree->info)      
    Retrieve(tree->left, item, found); // Search left subtree.
  else if (item > tree->info)
    Retrieve(tree->right, item, found);// Search right subtree.
  else
  {
    item = tree->info;                 // item is found.
    found = true;
   }
} 

template<class ItemType>
void TreeType<ItemType>::PutItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
  Insert(root, item);
}

template<class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
  if (tree == NULL)
  {// Insertion place found.
    tree = new TreeNode<ItemType>;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info)
    Insert(tree->left, item);    // Insert in left subtree.
  else
    Insert(tree->right, item);   // Insert in right subtree.
}

template<class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
	bool found = false;
	GetItem(item, found);
	if (found)
		Delete(root, item);
	else
		cout << item << "is not in tree\n";
}

template<class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
  if (item < tree->info)
    Delete(tree->left, item);   // Look in left subtree.
  else if (item > tree->info)
    Delete(tree->right, item);  // Look in right subtree.
  else
    DeleteNode(tree);           // Node found; call DeleteNode.
}   

//MODIFY!!!
template<class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no 
//       longer in the tree.  If tree is a leaf node or has only 
//       non-NULL child pointer the node pointed to by tree is 
//       deleted; otherwise, the user's data is replaced by its 
//       logical predecessor and the predecessor's node is deleted.
{
  ItemType data;
  TreeNode<ItemType>* tempPtr;

  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else if (tree->right == NULL)
  {
    tree = tree->left;
    delete tempPtr;
  }
  else
  {
    GetPredecessor(tree->left, data);
    tree->info = data;
    Delete(tree->left, data);  // Delete predecessor node.
  }
}

template<class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}

template<class ItemType>
void PrintTree(TreeNode<ItemType>* tree, ofstream& out) 
// Prints info member of items in tree in sorted order on screen.
{
  if (tree != NULL)
  {
    PrintTree(tree->left, out);   // Print left subtree.
    out << tree->info<<"  ";
    PrintTree(tree->right, out);  // Print right subtree.
  }
}

template<class ItemType>
void TreeType<ItemType>::Print(ofstream& out) const
// Calls recursive function Print to print items in the tree.
{
  PrintTree(root, out);
}

template<class ItemType>
TreeType<ItemType>::TreeType()
{
  root = NULL;
}

template<class ItemType>
TreeType<ItemType>::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
  Destroy(root);
}

template<class ItemType>
void Destroy(TreeNode<ItemType>*& tree)
// Post: tree is empty; nodes have been deallocated.
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

template<class ItemType>
void TreeType<ItemType>::MakeEmpty()
{
  Destroy(root);
  root = NULL;
}

template<class ItemType>
TreeType<ItemType>::TreeType(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
//  into root.
{
  CopyTree(root, originalTree.root);
}

template<class ItemType>
void TreeType<ItemType>::operator=(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
// into root.
{
  {
  if (&originalTree == this)
    return;             // Ignore assigning self to self
  Destroy(root);      // Deallocate existing tree nodes
  CopyTree(root, originalTree.root);
  }
}

template<class ItemType>
void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* originalTree)
// Post: copy is the root of a tree that is a duplicate 
//       of originalTree.
{
  if (originalTree == NULL)
    copy = NULL;
  else
  {
    copy = new TreeNode<ItemType>;
    copy->info = originalTree->info;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}

template<class ItemType>
void TreeType<ItemType>::ResetTree(OrderType order)
// Calls function to create a queue of the tree elements in 
// the desired order.
{
  switch (order)
  { 
  case PRE_ORDER:    preQue.MakeEmpty();
		             PreOrder(root, preQue);
                     break;
  case IN_ORDER:     inQue.MakeEmpty();
					 InOrder(root, inQue);
                     break;
  case POST_ORDER:  postQue.MakeEmpty();
					PostOrder(root, postQue);
                     break;
  }
}

template<class ItemType>
void PreOrder(TreeNode<ItemType>* tree, QueType& preQue)
// Post: preQue contains the tree items in preorder.
{
  if (tree != NULL)
  {
    preQue.Enqueue(tree->info);
    PreOrder(tree->left, preQue);
    PreOrder(tree->right, preQue);
  }
}

template<class ItemType>
void InOrder(TreeNode<ItemType>* tree, QueType& inQue)
// Post: inQue contains the tree items in inorder.
{
  if (tree != NULL)
  {
    InOrder(tree->left, inQue);
    inQue.Enqueue(tree->info);
    InOrder(tree->right, inQue);
  }
}

template<class ItemType>
void PostOrder(TreeNode<ItemType>* tree, QueType& postQue)
// Post: postQue contains the tree items in postorder.
{
  if (tree != NULL)
  {
    PostOrder(tree->left, postQue);
    PostOrder(tree->right, postQue);
    postQue.Enqueue(tree->info);
  }
}

template<class ItemType>
ItemType TreeType<ItemType>::GetNextItem(OrderType order, bool& finished)
// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
//       If item is the last one in the queue, finished is true; 
//       otherwise finished is false.
{
  finished = false;
  ItemType item;
  switch (order)
  {
    case PRE_ORDER  : preQue.Dequeue(item);
                      if (preQue.IsEmpty())
                        finished = true;
                      break;
    case IN_ORDER   : inQue.Dequeue(item);
                      if (inQue.IsEmpty())
                        finished = true;
                      break;
    case  POST_ORDER: postQue.Dequeue(item);
                      if (postQue.IsEmpty())
                        finished = true;
                      break;
  }
  return item;
}

template<class ItemType>
TreeNode<ItemType>* PtrToSuccessor(TreeNode<ItemType>*& tree)
// Post: Returns the pointer to the succesor node
{
  if(tree->left != NULL){return;}

  while(tree->right!=NULL)
  {
    tree->right;
  }
  while(tree->right!=NULL)
  {
    tree->left;
  }
}

template<class ItemType>
void TreeType<ItemType>::Ancestors(ItemType value, ofstream& out)
//Precondition: Tree is initialized
// Postcondition: The ancestors of the node whose info member is value have been printed
{
  TreeNode<ItemType>* temp = root;
  if(root==NULL){return;}

  while(temp->info != value)
    out << temp->info;
    if(root->info < value)
    {
      temp->left;
    }
    else
    {
      temp->right;
    }
  //Do I print the values of the nodes from the roots to the value passed by refrence?
}

template<class ItemType>
void TreeType<ItemType>::MakeTree(ItemType list[])
//Precondition: Input parameter is a sorted array
// Postcondition: Complete reading from input and new tree assigned to root
{
  TreeNode<ItemType>* tree = new TreeNode<ItemType>;
  MakeTreeRec(list, tree);
  root = tree;
}

template<class ItemType>
void MakeTreeRec(int list[], TreeNode<ItemType>* tree) 
//Precondition: Input parameter is a sorted array
// Postcondition: Complete reading from input and new tree assigned to root
{
  int length;
  length = ( sizeof(list)/ sizeof(list[0]));

  int mid = length/2;
  if((length%2)!=0){
    mid++;
  }

  int left[mid];
  int right[mid];

  //tree.PutItem(list[mid]);

  for(int x=0; x<length; x++){
    if(x<mid){
      left[x] = list[x];
    }
    else{
      right[x] = list[x];
    }
  }

  if(length!=1)
  {
    MakeTreeRec(left, tree);
    MakeTreeRec(right, tree);
  }

  return tree;
}

/**
 * Uses breadth first search to print the tree by level
 **/
template<class ItemType>
void TreeType<ItemType>::LevelOrderPrint(ofstream & out){
  //LevelOrder(root, levelOrderQue);
  queue<TreeNode<ItemType> * > queue;
  TreeNode<ItemType> * temp;
  temp = root;
  
  while(temp != NULL){
    levelOrderQue.push(temp);

    if(temp->left != NULL){
       queue.push(temp->left);
    }
    if(temp->right != NULL){ 
      queue.push(temp->right);  
    }
    temp = queue.front();
    queue.pop();
  }

  //order stored in levelOrderQue
  int levelHeight = levelOrderQue.front()->height;

  while(!levelOrderQue.empty()){
    temp = levelOrderQue.front();
    levelOrderQue.pop();
    
    if(temp->height == levelHeight){
      out << temp->info << " ";
    }
    else{
      levelHeight = temp->height;
      out << endl;
      out << temp->info << " ";   
    }
  }//while
}//levelOrder

/**
 * Prints the tree on screen in preorder
 **/
template<class ItemType>
void TreeType<ItemType>::PreOrderPrint(ofstream& out){
  PreOrder(root, preQue);
  while(!preQue.IsEmpty()){
    ItemType item;
    preQue.Dequeue(item);
    out << item;
    out << " ";
  }
}

/**
 * Prints the tree on screen in inorder
 **/
template<class ItemType>
void TreeType<ItemType>::InOrderPrint(ofstream& out){
  InOrder(root,inQue);
   while(!inQue.IsEmpty()){
    ItemType item;
    inQue.Dequeue(item);
    out << item;
    out << " ";
  }
}

/**
 * Prints the tree on screen in postorder
 **/
template<class ItemType>
void TreeType<ItemType>::PostOrderPrint(ofstream& out){
  PostOrder(root, postQue);
   while(!postQue.IsEmpty()){
    ItemType item;
    postQue.Dequeue(item);
    out << item;
    out << " ";
  }
}

/**
 * Searches the tree post order and swaps nodes to create a mirror
 **/
template<class ItemType>
void Mirror(TreeNode<ItemType> * tree){
  if(tree != NULL)
    {
      Mirror(tree->left);
      Mirror(tree->right);
      //swap
      TreeNode<ItemType> * temp;
      temp = tree->left;
      tree->left = tree->right;
      tree->right = temp;
    }
}

template<class ItemType>
TreeType<ItemType> TreeType<ItemType>::MirrorImage(){
  TreeType<ItemType> copy = *this;
  Mirror(copy.root);
  return copy;
}