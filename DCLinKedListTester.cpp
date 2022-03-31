/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mohamad
 *
 * Created on 19 April 2021, 18:50
 */

#include <cstdlib>
#include "DCLinKedList.h"
void Displaymenu(){//display the menu
 cout<<"\n1: to test if the list is empty \n"
     <<"2: to search for the first occurrence of a data in the list \n"
     <<"3: to insert a data at the beginning of the list \n"
     <<"4: to insert a data at the end of the list \n"
     <<"5: to insert a data at a certain valid position \n" 
     <<"6: to insert a data n before "
         "the first node that contains a data m \n"
     <<"7: to insert a data n "
         "after the first node that contains a data m  \n"    
     <<"8: to delete the node at the beginning of the list \n"   
     <<"9: to delete the node at the end of the list \n"
     <<"10: to delete the node at a certain valid position \n"
     <<"11: to delete the first node "
         "that contains a certain data from the list \n"
     <<"12: to delete the node "
         "before the one that contains a certain data from the list  \n"
     <<"13: to delete the node after the one "
         "that contains a certain data from the list \n"
     <<"14: to cut and return the node at a certain valid position  \n"
     <<"15: to display the content of the nodes  \n"
     <<"16: to return the size of the list \n"
     <<"17: to exit";
}
  /*purpose: display the menu
    precondition: none
    post-condition: the menu is out;
     */

void Excute(DCLinKedList& list1){
 
    int choice,pos;
    ElementType b,c;
    
    do{
     Displaymenu();
     cout<<"\n enter you choice:"<<endl;
     cin>>choice;//prompt the user to inter his choice from the menu
     
     switch(choice){
         case 1: 
                if(list1.isEmpty())//check if list is empty
                   cout<< "list is empty"<<endl;
                  else
                      cout<<"the list is not empty"<<endl;
              
             break;
         case 2: 
                cout<<"enter the element to search its position"<<endl;
                cin>>b;
                //prompt the user to enter a data to search for it in the list
                pos=list1.search(b);//search the list for b
                if(pos==-1){
                 cout<<"the element not found"<<endl;
                 }
                 else{
                     cout<<"the element found at position :"<<pos<<endl;
                 }
             break;
         case 3:
                
                cout<<"enter the element to insert at begin the list"<<endl;
                cin>>b;//prompt the user to enter a data to insert it
                list1.insertAtBegin(b);
                cout<<list1<<endl;//display the list
               
             break;
         case 4:  
                
                cout<<"enter the element to insert at end the list"<<endl;
                cin>>b;//prompt the user to enter a data to insert it
                list1.insertAtEnd(b);
                cout<<list1<<endl;//display the list
             break;
         case 5: 
                
                
                cout<<"enter the element to insert"<<endl;
                cin>>b;//prompt the user to enter a data to insert it
                cout<<"enter the position of insertion"<<endl;
                cin>>pos;//prompt the user to enter a position
                list1.insertAtPos(b,pos);
                cout<<list1<<endl;//display the list
                
             break;
         case 6: 
                
                cout<<"enter the element to insert"<<endl;
                cin>>b;//prompt the user to enter a data to insert it
                cout<<"enter the element to insert before insertion"<<endl;
                cin>>c;
                list1.InsertBeforeData(b,c);
                cout<<list1<<endl;//display the list
             break;
         case 7: 
                
                cout<<"enter the element to insert"<<endl;
                cin>>b;//prompt the user to enter a data to insert it
                cout<<"enter the element to  insert after insertion"<<endl;
                cin>>c;//prompt the user to enter a data
                list1.insertAfterData(b,c);
                cout<<list1<<endl;//display the list
             break;
         case 8:
                list1.deleteFromBegin();//delete
                cout<<list1<<endl;//display the list
              break;
         case 9: 
                 list1.deleteFromEnd();//delete
                 cout<<list1<<endl;//display the list
              break;
         case 10:
               
               cout<<"enter the position of the element to be deleted"<<endl;
               cin>>pos;//prompt the user to enter a position
               list1.deleteAtPos(pos);//delete
               cout<<list1<<endl;//display the list
             break;
         case 11:
                
                cout<<"enter the element to delete"<<endl;
                cin>>b;//prompt the user to enter a data
                list1.deleteData(b);//delete
                cout<<list1<<endl;//display the list
             break;
         case 12:
                
                cout<<"enter the element to delete before"<<endl;
                cin>>b;//prompt the user to enter a data
                list1.deleteBeforeData(b);//delete
                cout<<list1<<endl;//display the list
             break;
         case 13:
                
                cout<<"enter the element to delete after"<<endl;
                cin>>b;//prompt the user to enter a data
                list1.deleteAfterData(b);//delete
                cout<<list1<<endl;//display the list
             break;
         case 14:
                cout<<"enter the position of the element to be cutted"<<endl;
                cin>>pos;//prompt the user to enter a position
                DCLinKedList::Nodeptr b;
                b=list1.cutAtpos(pos);//cut at the position
                if(b!=NULL){
                  cout<<"the data of the returned node is: "<<b->data<<endl;
                  //print the data of the returned element
                }
                cout<<list1<<endl;//display the list
             break;
         case 15:
                  cout<<list1<<endl;//display the list
         break;
         case 16: 
                 int size = list1.Size();
                 cout<<"the size of the list = "<<size<<endl;
                 //print the size of the list
                 break;
         case 17: 
             exit(0);//exit
             break;
     }
    }while(true);
     
    
}
 /*purpose: test the different SimpleLinKedList member function
      precondition: list1 valid SimpleLinKedList
      post-condition: a different execution is made at each of 
     the 17 cases depending of the choice of the user;
     */
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    DCLinKedList list1;//create SimpleLinKedList object
    Excute(list1);//call Excute to run a tester
    
  

    return 0;
}
