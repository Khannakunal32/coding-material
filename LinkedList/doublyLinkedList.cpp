#include<bits/stdc++.h>

using namespace std;

class doublyNode {
    public:
    
    int data;
    doublyNode* next;
    doublyNode* prev;
    
    
    doublyNode(int val){
        next= NULL;
        prev= NULL;
        data =val;
    }
};

void insertAtHead(doublyNode* &head, int val){
    // doublyNode* temp= head;
    doublyNode* n= new doublyNode(val);
    
    n->next= head;
    
    if(head!=NULL)
    head->prev = n;
   
    head=n;
    

}

void insertAtTail(doublyNode* &head, int val) {
    doublyNode* temp= head;
    
    if(head==NULL){ insertAtHead(head, val); return; }
    
    doublyNode* n= new doublyNode(val);
    
    while(temp->next!=NULL) temp=temp->next;
    
    temp->next= n;
    n->prev = temp;
    

}

void display(doublyNode* head) {
    
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}



void deleteAtHead(doublyNode* &head) {
    doublyNode* ptr= head;
    cout<<"dleteing at head";
    
    if(ptr==NULL) return;
    
    if(ptr->next == NULL && ptr->prev== NULL) {
        ptr=NULL;
        return;
    }
    
    head->next->prev = NULL;
    head= head->next;
    
    delete ptr;
}


void deletion(doublyNode* &head, int pos) {
    doublyNode* ptr= head;
    int count=1;
    
    if(pos==1) {
        deleteAtHead(head);
        return;
    }
    
    while(count!=pos && ptr!=NULL) {
        ptr= ptr->next;
        count++;
    }
    
    if(ptr==NULL) return;
    
    
    if(ptr->next==NULL) 
        { ptr->prev->next=NULL;
        }
        
    ptr->prev->next= ptr->next;
    ptr->next->prev= ptr->prev;
    
    delete ptr;
}




int main(){
    
    doublyNode* a=NULL;
    insertAtTail(a,1);
    insertAtTail(a,2);
    insertAtTail(a,3);
    
    insertAtHead(a,4);
    
    display(a);
    
    cout<<endl;
    
    deletion(a,2);
    display(a);
    cout<<endl;
    
    deletion(a,1);
    // deleteAtHead(a);
    display(a);
    
    return 0;
}