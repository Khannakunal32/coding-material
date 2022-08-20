/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


class node {
    public:
    
    int data;
    node* next;
    
    node(int val){
        data=val;
    }
    
};

void insertAtTail(node* &head, int val){          // head is call by reference as we need changes in head while adding a new node
    node* temp= head;
    node* n = new node(val);
    
    if(head==NULL) {
        head=n;
        return;
    }
    
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}
 
void display(node* head) {                       // head is call by value as we do not want changes in value of head address or value
    while(head!=NULL)
    {
    cout<<head->data<<"->";
    head= head->next;
}
    cout<<"NULL"<<endl;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    
    if(head!=NULL){
        n->next = head;
    }
        head = n;

}

bool search(node* head, int key){
    node* ptr= head;
    
    while(ptr != NULL) {
        if(ptr->data == key) return true;
        
        ptr= ptr->next;
    }
    
    return false;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    
    cout<<"\nDelete "<<head->data<<" (this is at head)\n";
    
    head = head->next;
    delete todelete;
}


void deletion(node* &head, int val){
    node* ptr = head;
    
    if(head==NULL) { cout<<"\n no element present for deletion in linklist \n"; return; }
    
    if(head->next == NULL || head->data == val) {
    deleteAtHead(head);
    return;
    }
    
    
    while(ptr->next->data != val) 
        ptr= ptr->next;
    
    node* todelete = ptr->next;
    
    ptr->next= ptr->next->next;
    
    delete todelete;                       // this is to avoid memory leak

    cout<<"\ndelete "<<val<<endl;
}


node* reverseItr(node* &head) {
    node* prev= NULL;
    node* curr= head;
    node* nextptr;
    
    cout<<"Reversing the linked list with itrator  =>  ";
    while(curr != NULL) {
        nextptr= curr->next;
        curr->next=prev;
        prev=curr;
        curr= nextptr;
    }
    return prev;
    
}

node* reverseRecursively(node* &head) {
    
    if(head== NULL || head->next==NULL) 
        return head;
    
   node* newHead=reverseRecursively(head->next);
    head->next->next= head;
    head->next= NULL;
    
    return newHead;
}

    //kth node reverse
    
    node* kthReverse(node * &head , int k) {
    int count=0;
    node *prev=NULL,*curr=head, *next;
    
    
    while(curr!=NULL and count<k){
        next=curr->next;
        curr->next= prev;
        prev=curr;
        curr=next;
        count++;
    }
    
    if(next!=NULL)
    head->next= kthReverse(next,k);
    
    
    return prev;
}
    
node* makeCircular(node* &head, int pos){
  node* temp = head;
  node* tempAtPos = head;
  int count =1;
  
  cout<<"\nmaking Cicular linked list from pos "<<pos<<" ......";
  while(temp->next!= NULL)  {
      temp= temp->next;
  }
  while(count!= pos)  {
      tempAtPos= tempAtPos->next;
      count++;
  }
  
  temp->next = tempAtPos;
  return head;
} 


bool cirularDetection(node* head){
    node* slow= head;
    node* fast= head;
    
    cout<<"\nchecking if circle/loop exist  =>  ";
    
    while(fast!=NULL && fast->next!=NULL){
        
        slow= slow->next;
        fast= fast->next->next;
        
        if(fast == slow){
            cout<<" yes";
        return true;
        }
    }
   cout<<" no";
    return false;
} 

node* returnHead(node* head) {
    return head;
}
    


node* removeCycle(node* &head) {
    node* slow=head;
    node* fast=head;
    
    if(!cirularDetection(head)) return head;
    else cout<<"\nremove cycle/loop from this linked list ......... ";
    
    while(fast!=NULL && fast->next!=NULL) {
        fast = fast->next->next;
        slow= slow->next;
        
        if(fast== slow) break;
    }
    
    fast=head;
    
    while(fast->next!=slow->next) {
        fast=fast->next;
        slow=slow->next;
    }
    
    slow->next=NULL;
    
    return head;
    
}


int main()
{
    node* x= NULL;
    
    insertAtTail(x,1);
    insertAtTail(x,2);
    insertAtTail(x,3);
    
    insertAtHead(x,4);
    
    display(x);
    
    int key = 2;
        cout<<"is "<<key<<" present?  =>  "<<(search(x,key)?"true":"false")<<endl;
    
    deletion(x,2);
    display(x);

    deletion(x,4);
    display(x);
    
    node* y=NULL;
     insertAtTail(y,1);
    insertAtTail(y,2);
    insertAtTail(y,3);
    cout<<"\n\n";
    display(y);
    
    // reverseItr(y);
    node* revItr=reverseItr(y);
    display(revItr);
    
    // if(cirularDetection(revItr)==true) cout<<"\nthis is a circular linked list"; else cout<<"\nthis is not a circular linked list";
    
    // reverseRecursively
    cout<<"\n\n";
    display(x);
    cout<<"Reversing the linked list recursively  =>  ";
    display(reverseRecursively(x));
    
    
  node* z=NULL;
     insertAtTail(z,1);
    insertAtTail(z,2);
    insertAtTail(z,3);
    insertAtTail(z,4);
    insertAtTail(z,5);
    insertAtTail(z,6);
    display(z);
    cout<<"Reversing the kth node =>  ";
    node* newHead= kthReverse(z,2);
    display(newHead);
    
    cout<<"\n\n";
     
     
     
   node* q=NULL;
     
     insertAtTail(q,1);
    insertAtTail(q,2);
    insertAtTail(q,3);
    insertAtTail(q,4);
    insertAtTail(q,5);
    insertAtTail(q,6);
    
    display(q);
    
    makeCircular(q,4);
    
    cout<<"\n1->2->3->4->5->6->4->5->6->4->5->6->4->5......(never endling loop)\n";
    
   cirularDetection(q);
   
    removeCycle(q);
    
   cirularDetection(q);
   
   cout<<endl;
   display(q);
    
    
    return 0;
    
}







//creating intersection 

// 1 3 5 7 9 11 
// 10 20 30 
//  creating intersection at 2 =>  10 20 30 3 5 7 9 11 
//  interesection found at element => 3

#include <iostream>

using namespace std;

class node
{
public:
  int data;
  node *next;

    node (int val)
  {
    data = val;
  }
};

void
insertAtHead (node * &head, int val)
{
  node *n = new node (val);

  if (head == NULL)
    {
      head = n;
      return;
    }

  n->next = head;
  head = n;
}


void
insertAtTail (node * &head, int val)
{
  node *n = new node (val);
  node *ptr = head;

  if (head == NULL)
    {
      insertAtHead (head, val);
      return;
    }

  while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }

  ptr->next = n;
}

void
display (node * head)
{
  node *ptr = head;

  while (ptr != NULL)
    {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
}

int                                // display size of the linnked list
listSize (node * head)
{
  int count = 1;
  if (head == NULL)
    return 0;

  while (head->next != NULL)
    {
      head = head->next;
      count++;
    }
  return count;
}

void createIntersection (node* &head1, node* &head2, int pos) {             // create intersectio of two linked list at given position
    int l1= listSize(head1);
    int l2= listSize(head2);
    
    if(pos>l1 && pos>l2) {
        cout<<"\npositon "<<pos<<" not exist to instersect at";
        return;
    }
    
    node* ptr1;
    node* ptr2;
    
    if(l1<l2) {
        ptr1= head2;
        ptr2=head1;
    } else {
        ptr1=head1;
        ptr2=head2;
    }
    
    int count=1;
    
    while(count!= pos) {
        ptr1=ptr1->next;
        count++;
    }
    while(ptr2->next!=NULL) {
        ptr2= ptr2->next;
    }
    
    ptr2->next= ptr1;
    
}

int checkIntersection(node* head1, node* head2) {         // checks if intersection is present in two linked list
     int l1= listSize(head1);
    int l2= listSize(head2), diff;
    node* ptr1; node* ptr2;
    
   if(l1>l2){
       diff= l1-l2;
        ptr1 = head1;
        ptr2 = head2;
   } else {
       diff= l2-l1;
        ptr1 = head2;
        ptr2 = head1;
   }
   
   int count =diff;
   
   while(diff!=0){
       ptr1 = ptr1->next;
       diff--;
   }
   
   
   while(ptr1!=NULL && ptr2!=NULL) {
       
       if(ptr1 == ptr2) {
           cout<<"\n interesection found at element => "<<ptr2->data;
           return 0;
       }
       ptr1=ptr1->next;
       ptr2=ptr2->next;
       count++;
   }
   
cout<<"\n interesection not found ";
   return -1;
}

int
main ()
{
  node *q = NULL;

  insertAtTail (q, 1);
  insertAtTail (q, 2);
  insertAtTail (q, 3);
  insertAtTail (q, 4);
  insertAtTail (q, 5);
  insertAtTail (q, 6);

  display (q);

cout<<"\n";
    node* x= NULL;
  insertAtTail (x, 10);
  insertAtTail (x, 20);
  insertAtTail (x, 30);
  
  display(x);
  
  cout<<"\n creating intersection .....";
  createIntersection(q,x,8);
  
  display(x);
  
  checkIntersection(x,q);
  
  
  return 0;
}





//merging linked list
// output
// 1 3 5 7 9 11 
// 2 8 22 

//  merging two sorted arrays (iterative method) => 1 2 3 5 7 8 9 11 22 

#include <iostream>

using namespace std;

class node
{
public:
  int data;
  node *next;

    node (int val)
  {
    data = val;
  }
};

void
insertAtHead (node * &head, int val)
{
  node *n = new node (val);

  if (head == NULL)
    {
      head = n;
      return;
    }

  n->next = head;
  head = n;
}


void
insertAtTail (node * &head, int val)
{
  node *n = new node (val);
  node *ptr = head;

  if (head == NULL)
    {
      insertAtHead (head, val);
      return;
    }

  while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }

  ptr->next = n;
}

void
display (node * head)
{
  node *ptr = head;

  while (ptr != NULL)
    {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
}


node* mergeSortedLists(node* head1, node* head2) {              //merging two sorted arrays
    node* p1= head1;
    node* p2= head2;
    node* newHead= new node(-1);
    
    cout<<"\n merging two sorted arrays (iterative method) => ";
    node* p3= newHead;
    
    while(p1!=NULL && p2!=NULL){
        
        if(p1->data < p2->data) {
            p3->next= p1;
            p1=p1->next;
        }
        else {
            p3->next= p2;
            p2=p2->next;
        }
        
        p3= p3->next;
    }
    
    while(p1!=NULL) {
        p3->next= p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL) {
        p3->next= p2;
        p2=p2->next;
        p3=p3->next;
    }
    
    newHead=newHead->next;
    
    return newHead;
    
}

node* mergingRecursion(node* head1, node* head2) {              //merging two sorted lists using recursion
    node* p1= head1;
    node* p2= head2;
    node* newHead;
    
    if(p1==NULL) return p2;
    else if(p2==NULL) return p1;
    
    
    
    if(p1->data<p2->data) {
        newHead= head1;
        newHead->next = mergingRecursion(p1->next, p2);
    }
    else {
        newHead= head2;
        newHead->next = mergingRecursion(p1, p2->next);
    }
    
    return newHead;
}

int
main ()
{

  
  // merging two sorted linked list
  cout<<endl<<endl;
  node *a = NULL;

  insertAtTail (a, 1);
  insertAtTail (a, 3);
  insertAtTail (a, 5);
  insertAtTail (a, 7);
  insertAtTail (a, 9);
  insertAtTail (a, 11);

  display (a);

cout<<"\n";
    node* b= NULL;
  insertAtTail (b, 2);
  insertAtTail (b, 8);
  insertAtTail (b, 22);
  
  display(b);
  
  cout<<"\n";
   display(mergeSortedLists(a,b));
   
//     cout<<"\n merging two sorted arrays (iterative method) => ";
//   display(mergingRecursion(a,b));         
  
  return 0;
}






//even after odd                         // level 2
//output for input=1 2 3 4 5 
// 1 3 5 2 4 
#include <iostream>

using namespace std;

class node
{
public:
  int data;
  node *next;

    node (int val)
  {
    data = val;
  }
};

void
insertAtHead (node * &head, int val)
{
  node *n = new node (val);

  if (head == NULL)
    {
      head = n;
      return;
    }

  n->next = head;
  head = n;
}


void
insertAtTail (node * &head, int val)
{
  node *n = new node (val);
  node *ptr = head;

  if (head == NULL)
    {
      insertAtHead (head, val);
      return;
    }

  while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }

  ptr->next = n;
}

void
display (node * head)
{
  node *ptr = head;

  while (ptr != NULL)
    {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
}


void evenAfterOdd(node* head){
    if(head==NULL || head->next==NULL) return head;

    node* odd=head;
    node* even=head->next;
    node* evenst=even;
    


    while(odd->next!=NULL && even->next!=NULL ) {
        // odd->next= odd->next->next;
        odd->next= even->next;
        odd=odd->next;
        even->next= odd->next;
        // even->next = even->next->next;
        even=even->next;
    }
    
    odd->next=evenst;    
}

int
main ()
{
  node* c= NULL;
  insertAtTail(c,1);
  insertAtTail(c,2);
  insertAtTail(c,3);
  insertAtTail(c,4);
  insertAtTail(c,5);
  insertAtTail(c,6);
//   display(c);
evenAfterOdd(c);
  display(c);
  return 0;
}




//appending the list at kth pos


node *
kappend (node * &head, int k)
{
  node *ptr = head;
  node *temp;
  node *newHead;
  int count = 1;

  cout << "\n\n appending the list at " << k << " =>  ";

  if (ptr->next == NULL || listSize (head) == k)
    return head;


  while (ptr != NULL && count != k)
    {
      ptr = ptr->next;
      count++;
    }

  newHead = ptr->next;
  temp = ptr->next;


  while (temp->next != NULL)
    temp = temp->next;

  temp->next = head;
  ptr->next = NULL;


  return newHead;
}

int main()
{
 node *q = NULL;

  insertAtTail (q, 1);
  insertAtTail (q, 2);
  insertAtTail (q, 3);
  insertAtTail (q, 4);
  insertAtTail (q, 5);
  insertAtTail (q, 6);

  display (q);

  display (kappend (q, 3));

  return 0;

  }