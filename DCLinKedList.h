/*-- DCLinKedList.h ---------------------------------------------------------------
This header file defines the data type  DCLinKedList for processing
 doubly circular linked lists.
 private data members:
    * myFirst: pointer to the first Node
    * my size: the number of elements (nodes) in the list
 function are:
    -constructor
    -copy constructor
    -isEmpty:test if the list is empty
    -search: search the first occurrence of a data in the list
    -insertAtBegin: insert a data at the beginning of the list
    -insertAtEnd: insert a data at the end of the list
    -insertAtPos:  insert a data at a certain valid position
    -InsertBeforeData: insert a data before the first node that contains a data 
    -insertAfterData: insert a data after the first node that contains a data 
    -deleteFromBegin: delete the node at the beginning of the list
    -deleteFromEnd: delete the node at the end of the list
    -deleteAtPos: delete the node at a certain valid position
    -deleteData:delete the first node that contains a certain data from the list
   - deleteBeforeData:delete the node before the one that contains 
      a certain data from the list
    -deleteAfterData:delete the node after the one that contains 
     a certain data from the list
   - Node* cutAtpos:cut and return the node at a certain valid position
    -display: display the content of the nodes in the list
    -Size(): return the size of the list
 * private:
 * class Node: defines the data type Node for processing Node in a list
 *  public data members:
 *  data: the data contained in the node
 *  next:pointer to the next node
 *  functions constructor
 * 
 */
/* 
 * File:   DCLinKedList.h
 * Author: mohamad
 *
 * Created on 19 April 2021, 19:02
 */
#include <iostream.h>

#ifndef DCLINKEDLIST_H
#define DCLINKEDLIST_H

typedef int ElementType;
//define ElemetType as integer
class DCLinKedList {
public:
    
    class DNode {
      public:
                  ElementType data;//the data contained in the node
                  DNode* next;//pointer to the next
                  DNode* previous;//pointer to the previous
                  DNode(ElementType data);
                  /*purpose:construct a Node object;
                   precondition:none
                   post-condition: a Node object with 
                   determined data is constructed and next
                    and previous pointing to null;*/

     };

    
    DCLinKedList();
    /*purpose: construct a DCLinKedList object;
      precondition: none
      post-condition:An empty DCLinKedList object has been constructed
      with mySize is O
     */
    DCLinKedList(const DCLinKedList& orig);
    /*purpose:  construct a DCLinKedList object similar to an exist one
      precondition:none
      post-condition: a DCLinKedList object has been constructed
      with mySize to the orig size and the element data equal to the orig 
      element's data
     */
    virtual ~DCLinKedList();
    /*purpose:destructor
      precondition:none
      post-condition:all pointer deleted
     */
    DCLinKedList& operator=(const DCLinKedList& l);
    /*purpose: make a DCLinKedList object similar to an exist one
      precondition:none
      post-condition:DCLinKedList object (size) mySize to the l size and
      the element data equal to the l element's data
     */
    bool isEmpty() const;
    /*purpose: Check if a list is empty
      precondition:none
      post-condition: true is returned if the DCLinKedList is empty, 
     false if not.
     */
    int search(ElementType n) const;
    /*purpose:search for the position of the first occurrence 
     of an ElementType data in the list 
      precondition:the  n is a valid ElementType
      post-condition: integer with the position of the first occurrence 
      of n ElementType is returned and -1 if the its  not found
     */
    void insertAtBegin(const ElementType data);
    /*purpose:Insert a value into the list at the begin.
      precondition: data is the value to be inserted;
      post-condition:a Node that have the value as a data is
      inserted in the begin of the list and printing 
      a confirmation message for the insertion,
     */
    void insertAtEnd(const ElementType data);
    /*purpose:Insert a value into the list at the end.
      precondition:data is the value to be inserted;
      post-condition:a Node that have the value as a data is
      inserted in the end of the list and printing 
      a confirmation message for the insertion,
     */
    void insertAtPos(const ElementType data, int post);
      /*purpose:Insert a value into the list at a given position
      precondition:data is the value to be inserted;
      post-condition:a Node that have the value as a data is
      inserted in the determined position in the list and printing 
      a confirmation message for the insertion,
     * print an error message if the position is not valid
     */
    void InsertBeforeData(const ElementType n,const ElementType m);
    /*purpose:Insert a value into the list before the first node that contains a
      determined data
      precondition:n is the value to be inserted,
      m is the determined valid data to insert before it 
      post-condition:a Node that have the value as a data is
      inserted before the first the determined data in the list and printing 
      a confirmation message for the insertion,
      if the determined data not found print an error message;
     */
    void insertAfterData(const ElementType n,const ElementType m);
    /*purpose:Insert a value into the list after the first node that contains a
      determined data
      precondition:n is the value to be inserted,
      m is the determined valid data to insert after it
      post-condition:  a Node that have the value as a data is
      inserted after the first the determined data in the list and printing 
      a confirmation message for the insertion,
      if the determined data not found print an error message;
     */
    void deleteFromBegin();
     /*purpose:Remove a value from the list at begin
      precondition:none
      post-condition:the first node in the list is delete
      with printing a confirmation message for the deletion,
      and print an error message if the list is empty
     */
    void deleteFromEnd();
    /*purpose: Remove a value from the list at end 
      precondition:none
      post-condition:the last node in the list is delete
      with printing a confirmation message for the deletion,
      and print an error message if the list is empty
     */
    void deleteAtPos(int pos);
    /*purpose: Remove a value from the list at a determined position
      precondition:none
      post-condition: the Node at the determined position is delete 
      with printing a confirmation message for the deletion
      and an error message is printed is position is not valid;
     */
    void deleteData(const ElementType n);
    /*purpose: delete the first node that contains a certain data from the list
      precondition: n is the value to be deleted
      post-condition:the Node at the position of node that contain n is delete 
      with printing a confirmation message for the deletion
     and printing an error message if the data not found in the list
     */
    void deleteBeforeData(const ElementType n);
    /*purpose:delete the node before the one that contains a certain data from 
      the list
      precondition:  n is the value to delete before
      post-condition:he Node at the position 
      before the node that contain n is delete 
      with printing a confirmation message for the deletion
      and printing an error message if the data not found in the list or if 
      there is no Node before the determined Node
     */
    void deleteAfterData(const ElementType n);
    /*purpose: delete the node after the one that contains a certain data from 
      the list
      precondition: n is the value to delete after it
      post-condition: the Node at the position 
      after the node that contain n is delete 
      with printing a confirmation message for the deletion
      and printing an error message if the data not found in the list or if 
      there is no Node after the determined Node
     */
    DNode* cutAtpos(int pos);
    /*purpose:cut and return the node at a certain valid position
      precondition:none
      post-condition:the Node at the determined position is removed from the 
      list and returned
      with printing a confirmation message for the remove
      and an error message is printed if position is not valid;
     */
    ostream& display(ostream& out ) const;
    /*purpose: Display a DCLinKedList
      precondition:The ostream out is open
      post-condition:The list represented by thisSimpleLinKedList object has been
      inserted into out.
     */
    int Size()const;
    /*purpose: return the Size of a DCLinKedList
      precondition:none;
      post-condition: return integer (the DCLinKedList mySize);
     */
    friend ostream& operator<<(ostream& out, const DCLinKedList& l);
     //friend operator to  outputs the list by calling the display
    //member function
    
    
    typedef  DNode* Nodeptr;
    //define Nodeptr that is a pointer to Node
private:
   Nodeptr myFirst;
    //pointer to a node that represent the first element of a list
   int mySize;
   //integer that represent the numbers of elements nodes in a list

};

#endif /* DCLINKEDLIST_H */

