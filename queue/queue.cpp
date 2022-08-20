//queue basic implementation

//output
// q.push(1)  q.push(2)  q.push(3)
// q.peek()  =>  1
// q.pop()  q.pop()  q.pop() q.pop()  4th time=> 

//  No element available to dequeue..
// q.peek()  =>  
//  No element available to peek..
// -1
//  queue is empty

#include <iostream>

using namespace std;
#define n 100


class queue {
    int *arr;
    int front;
    int back;
    
    public:
    queue(){
        arr= new int[n];
        front =-1;
        back =-1;
    }
    
   void push(int var){                 //enqueue
        
        if(back==n-1){
            cout<<"\n Stack Overflow..\n";
            return;
        }
        
        back++;
        arr[back]=var;
        
        if(front==-1) front++;
        
    }
    
    void pop() {                           //dequeue
        if(front==-1 or front>back) {
             cout<<"\n No element available to dequeue..\n";
            return;
        }
        front++;
    }
    
    int peek() {                          // similar to top in stack
         if(front==-1 or front>back) {
             cout<<"\n No element available to peek..\n";
            return -1;
        }
        return arr[front];
    }
    
    bool empty() {                        //empty
        if(front==-1 or front>back) {
            return true;
        }
        return false;
    }
    
    
    
};



using namespace std;

int main()
{
     queue q;
   cout<<"q.push(1)  q.push(2)  q.push(3)\n";
   q.push(1);
   q.push(2);
   q.push(3);
   
   cout<<"q.peek()  =>  "<<q.peek();
   
   cout<<"\nq.pop()  q.pop()  q.pop() q.pop()  4th time=> \n";
   q.pop();
   q.pop();
   q.pop();
   q.pop();

   cout<<"q.peek()  =>  "<<q.peek();
   
   (q.empty())?cout<<"\nqueue is empty\n":cout<<"\nqueue is not empty\n";


    return 0;
}




//Queue using linked list 
//output
//q.push(1)  q.push(2)  q.push(3)
// q.peek()  =>  1
// q.pop()  q.pop()  q.pop() q.pop()  4th time=> 

//  No element available to dequeue..
// q.peek()  =>  
//  No element available to dequeue..
// -1
// queue is empty


#include <iostream>

using namespace std;

class node{
    public:
    
    int data;
    node* next;
    
    node(int var){
        data= var;
        next= NULL;
    }
};

class queueUsingLL {
                                // 1 2 3 
    node* front;
    node* back;
    public:
    queueUsingLL(){
        front = NULL;
        back = NULL;
    }
    
  void  push(int var) {
        node* n= new node(var);
        
        if(front==NULL){
            front=n;
            back=n;
            return;
        }
        
        back->next=n;
        back=n;
        return;
    }
    
    void pop(){
       if(front==NULL)  {
           cout<<"\n No element available to dequeue..\n";
           return;
       }
       
      node* todelete = front;
      front= front ->next;
      delete todelete;
    }
    
    int peek(){
         if(front==NULL)  {
           cout<<"\n No element available to dequeue..\n";
           return -1;
       }
        return front->data;
    }
    
    bool empty(){
        return (front==NULL);
    }
};

int main()
{
    queueUsingLL q;
   cout<<"q.push(1)  q.push(2)  q.push(3)\n";
   q.push(1);
   q.push(2);
   q.push(3);
   
   cout<<"q.peek()  =>  "<<q.peek();
   
   cout<<"\nq.pop()  q.pop()  q.pop() q.pop()  4th time=> \n";
   q.pop();
   q.pop();
   q.pop();
   q.pop();

   cout<<"q.peek()  =>  "<<q.peek();
   
   (q.empty())?cout<<"\nqueue is empty\n":cout<<"\nqueue is not empty\n";

    

    return 0;
}




//queue using Stacks      method 1
//output
// q.push(1)  q.push(2)  q.push(3)
// q.peek()  =>  3
// q.pop()  q.pop()  q.pop() q.pop()  4th time=> 

//  No element available to dequeue..

//  No element available to dequeue..

//  No element available to dequeue..
// q.peek()  =>  
//  No element available to dequeue..
// -1
// queue is empty



#include <iostream>
#include <stack>


using namespace std;

                       // 1 2 3 4 5  //5 4 3 2 1


class queueUsingStack{
    stack <int> s1;
    stack <int> s2;
    
    public:
    
   void push(int val){
      s1.push(val);  
    }
    
   void pop(){
        if(s1.empty() && s2.empty()) {
             cout<<"\n No element available to dequeue..\n";
           return;
        } 
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ;
    }
    
    bool empty(){
        
        return (s1.empty() and s2.empty());
    }
    
    int peek(){
         if(s1.empty() && s2.empty()) {
             cout<<"\n No element available to dequeue..\n";
           return -1;
        } 
        if(s2.empty()) {
           while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        } 
        return s2.top();
        }
        if(s1.empty()) return s2.top();
    }
    
    
};


int main()
{
    queueUsingStack q;
   cout<<"q.push(1)  q.push(2)  q.push(3) q.push(4)\n";
   q.push(1);
   q.push(2);
   q.push(3);
   q.push(4);

  q.pop();
   cout<<"q.pop() then q.peek()  =>  "<<q.peek();
   
   cout<<"\nq.pop()  q.pop()  q.pop() q.pop()  4th time=> \n";
   q.pop();
   q.pop();
   q.pop();
   q.pop();

   cout<<"q.peek()  =>  "<<q.peek();
   
   (q.empty())?cout<<"\nqueue is empty\n":cout<<"\nqueue is not empty\n";

    

    return 0;
}




//method 2 queue using stack
// q.push(1)  q.push(2)  q.push(3) q.push(4)
// q.pop()  q.pop()  q.pop() q.pop()  4th time=> 
// queue is empty
class queueUsingStackRecursion {
    stack <int> sr;
    public:
    
    void push(int val){
        sr.push(val);
    }
    
    int pop(){
        if(sr.empty()) {
            // cout<<"\n No element available to dequeue..\n";
            return -1 ;
        }
        
         int temp=sr.top();
    sr.pop();
     
     if(sr.empty()) {
         return 0;
     } 
     pop();
     sr.push(temp);
    
    
    }
    
    bool empty(){
        
        return (sr.empty());
    }
};

int main()
{
    queueUsingStackRecursion q;
   cout<<"q.push(1)  q.push(2)  q.push(3) q.push(4)\n";
   q.push(1);
   q.push(2);
   q.push(3);
   q.push(4);

   cout<<"\nq.pop()  q.pop()  q.pop() q.pop()  4th time=> \n";
  q.pop();
  q.pop();
  q.pop();
  q.pop();
   
   (q.empty())?cout<<"\nqueue is empty\n":cout<<"\nqueue is not empty\n";

    

    return 0;
}



// Stack using queue    costly is pop() method
// pushing =>  1
//  pushing =>  2
//  popping =>  2 
//  pushing =>  3
//  popping =>  3 
//  popping =>  1 
//  No elements present to delete
// -1 
// Stack is empty
#include<bits/stdc++.h>

using namespace std; 

class Stack {
    queue<int> q1;
    queue<int> q2;
    int n;
    public:
    
    Stack() {
        n=0;
    }
    
    void push(int var) {
        cout<<"\n pushing =>  "<<var;
        q1.push(var);
        n++;
    }
    
    int pop(){
        if(q1.empty()) {
            cout<<"\n No elements present to delete\n";
            return -1;
        }
        int temp=n;
        while(temp>1){
            q2.push(q1.front());
            q1.pop();
            temp--;
        }
        
        int deletedEle= q1.front();
        
        q1.pop();
        
        swap(q2,q1);
        
            n--;
            cout<<"\n popping =>  ";
        return deletedEle;
    }
    
    bool empty(){
        return (q1.empty());
    }
    
    
    // void top  similar to pop function
};



int main() {
      Stack a;
      
   a.push(1);
   a.push(2);
  cout<< a.pop()<<" ";
   a.push(3);
   
   
  cout<< a.pop()<<" ";
  cout<< a.pop()<<" ";
  cout<< a.pop()<<" ";

   
   (a.empty())?cout<<"\nStack is empty\n":cout<<"\nStack is not empty\n";

    return 0;
}









//  Stack using queue    costly is push() method
// pushing =>  1
//  pushing =>  2
//  popping =>  2 
//  pushing =>  3
//  popping =>  3 
//  popping =>  1 
//  No elements present to delete
// -1 
// Stack is empty


class Stack {
    queue<int> q1;
    queue<int> q2;
    int n;
    public:
    
    Stack(){
        n=0;
    }
    
    void push(int val){
        cout<<"\n pushing =>  "<<val;
        
        if(q1.empty()) {
            q1.push(val);
            n++;
            return;
        }
        
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        q1.push(val);
        
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        // swap(q2,q1);
        
        n++;
        
    }
    
    int pop() {
         if(q1.empty()) {
            cout<<"\n No elements present to delete\n";
            return -1;
        }
        int deletedEle= q1.front();
        q1.pop();
        n--;
         cout<<"\n popping =>  ";
        return deletedEle;
    }
    
   bool empty() {
       return q1.empty();
   }
};


int main() {
    
      Stack a;
      
   a.push(1);
   a.push(2);
  cout<< a.pop()<<" ";
   a.push(3);
   
   
  cout<< a.pop()<<" ";
  cout<< a.pop()<<" ";
  cout<< a.pop()<<" ";

   
   (a.empty())?cout<<"\nStack is empty\n":cout<<"\nStack is not empty\n";

    return 0;
}