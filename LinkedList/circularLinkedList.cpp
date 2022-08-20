//  output 0 1 2 3 4 
//  Deleting at head => 1 2 3 4 

//  Deleting at 9 =>             //(ie at first positioin)
//  Deleting at head => 2 3 4 

#include <bits/stdc++.h>

using namespace std;


class cNode {                   //cNode is circularNode
    public:
    int data;
    cNode* next;
    
    cNode(int val){
        data=val;
    }
    
};

void createCircularList(cNode* &head) {
    cNode* ptr= head;
    
    while(ptr->next!=NULL) ptr= ptr->next;
    
    cout<<"\n circular linked list formed ....\n";
    ptr->next= head;
    
}


void insertIntoHead(cNode* &head, int val ){
    
    cNode* n= new cNode(val);
    
    if(head==NULL) {
        head= n; 
        n->next= head;
        return;
    }
    
    
    cNode* ptr= head;
    while(ptr->next!=head) {
        ptr= ptr->next;
    }
    
    ptr->next= n;
    n->next= head;
    head= n;
    
}

void insertIntoTail(cNode* &head, int val) {
    cNode* n= new cNode(val);
    
    if(head==NULL) {
        insertIntoHead(head, val);
        return;
    }
    
    insertIntoHead(head, val);
    head=head->next;
}


void display(cNode* head) {
    cNode* ptr= head;
   
   do{                                    //do while loop is used so that ptr goes to next term and then we find and stop the loop when ptr becomes head;
       cout<<ptr->data<<" ";              // so first these statements execute then the check executes
    ptr=ptr->next;
    
   }while(ptr!=head);
   
    cout<<"\n";
}


int listSize(cNode* head) {
  int count =1;
  cNode* ptr= head;
  if(head==NULL) {
      count=0;
      return count;
  }
  
  while(ptr->next!=head) {
      ptr= ptr->next;
      count++;
  }
  return count;
}


void deleteAtHead(cNode* &head) {
    cNode* ptr= head;
    cNode* toDelete =head;
    
    cout<<"\n Deleting at head => ";
    while(ptr->next!=head) {
        ptr= ptr->next;
    }
    ptr->next= head->next;
    head= ptr->next;
    
    delete toDelete;
}

void deletion(cNode* &head, int pos) {
    cNode* ptr= head;
    int count=1;
    
     cout<<"\n Deleting at "<<pos<<" => ";
    int l= listSize(head);
    pos= pos % l;
    
    if(pos==1 ) {
        deleteAtHead(head);
        return;
    }
    
     
    while(count!=pos-1){
        ptr=ptr->next;
        count++;
    }
    cNode* toDelete = ptr->next;
    
    ptr->next= ptr->next->next;
    
    delete toDelete;
    
}

int main(){
    
    cNode* a=NULL;
   
    insertIntoTail(a,1);
    insertIntoTail(a,2);
    insertIntoTail(a,3);
    insertIntoTail(a,4);
    insertIntoHead(a,0);
    
    display(a);
    
    // deleteAtHead(a);
    deletion(a,8);
    display(a);
    
    // cout<<listSize(a);
    
    return 0;
}