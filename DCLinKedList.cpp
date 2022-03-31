/*-- DCLinKedList.cpp ------------------------------------------------------
 definitions SimpleLinKedList member functions
 */

/* 
 * File:   DCLinKedList.cpp
 * Author: mohamad
 * 
 * Created on 19 April 2021, 19:02
 */

#include "DCLinKedList.h"
#include <iostream.h>

//definition of Node constructor 
DCLinKedList::DNode::DNode(ElementType data){
    this->data=data;//assign data
    this->next=NULL;//assign next to null;
    this->previous=NULL;//assign previous to null;
}
//definition of DCLinKedList constructor
DCLinKedList::DCLinKedList() {
    myFirst=NULL;//assign myFirst
    mySize=0;//assign mySize to 0
}
//definition of DCLinKedList copy constructor
DCLinKedList::DCLinKedList(const DCLinKedList& orig) {
    mySize= orig.mySize;//assign my size to the orig size
    Nodeptr temp=orig.myFirst;
    myFirst= new DNode(temp->data);
    temp=temp->next;
    Nodeptr temp2=myFirst;
    //copy the orig element's data  into the linked list
    while (temp!=orig.myFirst){
        temp2->next= new DNode(temp->data);
        temp2->next->previous=temp2;
        temp=temp->next;
        temp2=temp2->next;
        }
    myFirst->previous=temp2;
    temp2->next=myFirst;
    
}
//definition of DCLinKedList destructor
DCLinKedList::~DCLinKedList() {
       Nodeptr tempPtr;
       Nodeptr temp2;
      //delete every node pointer
       tempPtr = myFirst;
       temp2=myFirst;
       myFirst = myFirst->next;
       delete tempPtr;
        while (myFirst != temp2) {
            tempPtr = myFirst;
            myFirst = myFirst->next;
            delete tempPtr;
         }
        delete temp2;
}
DCLinKedList& DCLinKedList:: operator=(const DCLinKedList& l){
    if (this != &l) {
        mySize= l.mySize;//assign my size to the l size
        Nodeptr temp=l.myFirst;
        myFirst= new DNode(temp->data);
        temp=temp->next;
        Nodeptr temp2=myFirst;
        //copy l element's data  into the linked list
        while (temp!=l.myFirst){
           temp2->next= new DNode(temp->data);
           temp2->next->previous=temp2;
           temp=temp->next;
           temp2=temp2->next;
           }
        //link myfirst and the last node
        myFirst->previous=temp2;
        temp2->next=myFirst;  
        }
    
    return *this;//return DCLinKedList
    }

bool DCLinKedList:: isEmpty() const{
  return myFirst==NULL;//return true if the list  is empty
}

int DCLinKedList:: search(ElementType n) const{
     
     Nodeptr temp = myFirst;
     for (int i=0;i<mySize;i++){
        if (temp->data==n)//check if the element data equal the determined data
         return i;//return integer representing the position pf the occurrence
        else 
         temp=temp->next;
       }
     return -1;//return -1 if not found
 }

void DCLinKedList:: insertAtBegin(const ElementType data){
       Nodeptr newPtr = new DNode(data);
       if (isEmpty()){
         myFirst = newPtr;//assign myFirst to NewPtr
         myFirst->next=myFirst;
         myFirst->previous=myFirst;
         mySize ++;
         }//increment mySize
       else {
         newPtr->next=myFirst;
         newPtr->previous=myFirst->previous;
         myFirst->previous->next=newPtr;
         myFirst->previous=newPtr;
         myFirst = newPtr;//insert NewPtr at begin
         mySize ++;//increment mySize
        }
       cout<<"insertion is done \n";//print insertion confirmation
 }
void DCLinKedList::  insertAtEnd(const ElementType data){
      Nodeptr newPtr = new DNode(data);
      if (isEmpty()){
          myFirst = newPtr; //assign myFirst to NewPtr
          myFirst->next=myFirst;
          myFirst->previous=myFirst;
          mySize ++;//increment mySize
        }
      else {
         newPtr->next=myFirst;
         newPtr->previous=myFirst->previous;
         myFirst->previous->next=newPtr;
         myFirst->previous=newPtr;//insert NewPtr at end
         mySize ++;//increment mySize
      }
}
void DCLinKedList:: insertAtPos(const ElementType data, int pos){
        if(pos<0 || pos>mySize){//check if pos is valid 
          cerr<<"illegal pos to insert";  
          }
        else{
          mySize++;//increment mySize
          Nodeptr newPtr = new DNode(data);
     
          if(pos==0){
            newPtr->next=myFirst;
            newPtr->previous=myFirst->previous;
            myFirst->previous->next=newPtr;
            myFirst->previous=newPtr;
            myFirst = newPtr;//insert NewPtr
            }
          else{
            Nodeptr temp = myFirst;
            for (int i=1;i<pos;i++){ 
                temp=temp->next; 
            }
            newPtr->previous=temp;
            newPtr->next=temp->next;
            temp->next->previous=newPtr;
            temp->next=newPtr; //insert NewPtr
           }   
          cout<<"insertion is done \n";//print insertion confirmation
        }
  }
void DCLinKedList::
  InsertBeforeData(const ElementType n,const ElementType m){
        int pos=search(m);
        if(pos==-1){//check for pos
           cerr<< "data not found";//print error message
        }
      
      else{
           insertAtPos(n,pos);//insert the data
          }
  
    }
  void DCLinKedList::insertAfterData(const ElementType n,const ElementType m){
     int pos=search(m);//check for pos
     if(pos==-1){
      cerr<< "data not found";//print error message
      }
     else{
      insertAtPos(n,(pos+1));//insert the data
      }
  }
  
  void DCLinKedList::deleteFromBegin(){
        if (isEmpty()){//check if empty
           cout << "Empty List" << endl;//print error message
          }
        else if(mySize==1){
                Nodeptr temp = myFirst;
                myFirst=NULL;
                delete temp;//delete the Node
                mySize--;//decrease size
            }
        else {
               Nodeptr temp = myFirst;
               myFirst->previous->next=myFirst->next;
               myFirst->next->previous = myFirst->previous;
               myFirst=myFirst->next;
               delete temp;//delete the Node
               mySize--;//decrease size
               cout<<"deletion is done"<<endl;//print deletion confirmation
             }
   }
  
  void DCLinKedList:: deleteFromEnd(){
        if (isEmpty()){//check if empty
            cout << "Empty List" << endl;//print error message
        }
        else if (myFirst->next == myFirst) {
                Nodeptr temp = myFirst;
                myFirst = NULL;
                delete temp;//delete the Node
                mySize--;//decrease size
                cout<<"deletion is done"<<endl;
        } 
        else {
                Nodeptr temp = myFirst;
                while (temp->next->next != myFirst){
                       temp= temp->next;
                }
                Nodeptr temp2 = temp->next;
                myFirst->previous=temp;
                temp->next=myFirst;
                delete temp2;//delete the Node
                mySize--;//decrease size
                cout<<"deletion is done"<<endl;//print deletion confirmation
            }
    }
  
   void DCLinKedList:: deleteAtPos(int pos){
      if(pos<0 || pos>=mySize){//check for the position
         cerr<<"illegal pos to delete"<<endl;
         //print error message if its not valid
      }
      else{
           mySize--;//decrease size
           Nodeptr temp = myFirst;
           if(pos==0){
                     if(myFirst->next == myFirst){
                     Nodeptr temp = myFirst;
                     myFirst=NULL;
                     delete temp;
                     }
                     else{
                    myFirst->next->previous=myFirst->previous;
                    myFirst->previous->next=myFirst->next;
                    myFirst=myFirst->next;//remove the node from the list
                     delete temp;//delete the Node
                     }
            }
            else{
                   for(int i=1;i<pos;i++){
                   temp=temp->next;
                   }
      
            Nodeptr temp2 =temp->next;
            temp2->next->previous=temp;
            temp->next=temp2->next;
            delete temp2;   
            }
           cout<<"deletion is done"<<endl;//print deletion confirmation
        }
 }
   
    void DCLinKedList:: deleteData(const ElementType n){
        int pos=(search(n));
        if(pos==-1){//check position
          cerr<< "data not found";//print error message if data not found
         }
        else{
        deleteAtPos(pos);//delete the Node with pos position
        }
 }
 
    void DCLinKedList:: deleteBeforeData(const ElementType n){
        int pos=(search(n));
        if(pos==-1){//check position
           cerr<< "data not found";//print error message if data not found
        }
        else if (pos==0){
           cerr<<"no data before found";
           //print error message if data not found before
        }
        else{
          deleteAtPos((pos-1));//delete the Node with pos-1 position
        }
   }
    void DCLinKedList:: deleteAfterData(const ElementType n){
        int pos=(search(n));
        if(pos==-1){//check position
           cerr<< "data not found";//print error message if data not found
        }
        else if(pos==mySize){
           cerr<<"no data after found";
           //print error message if data not found after
        }
        else{
           deleteAtPos((pos+1));//delete the Node with pos+1 position
        }
   }
    
    DCLinKedList:: DNode* DCLinKedList:: cutAtpos(int pos){
         if(pos<0 || pos>=mySize){//check for the position
         cerr<<"illegal pos to delete"<<endl;
         //print error message if its not valid
         return NULL;
      }
      else{
           mySize--;//decrease size
           Nodeptr temp = myFirst;
           if(pos==0){
                     if(myFirst->next == myFirst){
                     Nodeptr temp = myFirst;
                     myFirst=NULL;//remove the node from the list
                     cout<<"remove is done"<<endl;//print remove confirmation
                     return temp;//return the Node
                     }
                     else{
                    myFirst->next->previous=myFirst->previous;
                    myFirst->previous->next=myFirst->next;
                    myFirst=myFirst->next;//remove the node from the list
                    cout<<"remove is done"<<endl;//print remove confirmation
                     return temp;//return the Node
                     }
            }
            else{
                   for(int i=1;i<pos;i++){
                    temp=temp->next;
                   }
      
                   Nodeptr temp2 =temp->next;
                   temp2->next->previous=temp;
                   temp->next=temp2->next;//remove the node from the list
                   cout<<"remove is done"<<endl;//print remove confirmation
                   return temp2;   //return the Node
            }
        }
 }
    
    ostream& DCLinKedList:: display(ostream& out  ) const{
      if (isEmpty()){//check if list is empty
        cout << "Empty List";
      }
      else {
            Nodeptr temp = myFirst;
            cout << "The list is: ";
            out<<temp->data<<' ';
            temp=temp->next;
            while (temp != myFirst) {
               out << temp->data << ' ';//display list element
               temp=temp->next;
            }
      }
      return out;
    }
   
   
   int DCLinKedList::Size()const{
       return mySize;//return the size of the list
   }
   
  ostream& operator<<(ostream& out, const DCLinKedList& l){
          return l.display(out);//call display member function
    }