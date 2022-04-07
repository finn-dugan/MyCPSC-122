#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

template <typename T>
ListD<T>::ListD()
{
 InitializeVars();
}

template<typename T>
void ListD<T>::Insert(T item, int pos)
{
 //new node goes between these two nodes
 doubleNode* insertPtA = FindPosition(pos);  
 doubleNode* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode* tmp = new doubleNode; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

template<typename T>
void ListD<T>::Delete(int pos)
{
 doubleNode* deletePt = FindPosition(pos);
 doubleNode* deletePtPrev = deletePt->prev;
 doubleNode* deletePtNext = deletePt->next;

 deletePtPrev->next = deletePtNext;
 deletePtNext->prev = deletePtPrev;

 delete deletePt;
 length--;
}

template<typename T>
void ListD<T>::PrintForward()
{
 doubleNode*  cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}

template<typename T>
void ListD<T>::PrintBackward()
{
 doubleNode*  cur = tail->prev;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->prev;
  i++;
 }
}

template<typename T>
void ListD<T>::InitializeVars()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

template<typename T>
doubleNode<T>* ListD<T>::FindPosition(int pos)
{
 doubleNode<T>* cur = head;
 int i = 0;  //begin at the dummy node
  while (i < pos - 1)
  {
   cur = cur->next;
   i++;
  }
 return cur;
}

template<typename T>
ListD<T>::~ListD()
{
 doubleNode<T>* cur = head;
 while(cur != NULL)
 {
  doubleNode<T>* temp = cur;
  cur = cur->next;
  delete temp;
 }
}

template<typename T>
ListD<T>::ListD(ListD<T>* lst)
{
 InitializeVars();
 //returns a pointer to the first node, which is what we want here
 doubleNode<T>* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  cout << cur->item << endl;
  Insert(cur->item,i);
  cur = cur->next;
 }
}