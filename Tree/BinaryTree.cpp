
// tree implementation and orders

 /*       1 
         /  \
        2    3 
       / \   / \
      4  5  6   7  */
// preorder(root) =>  1 2 4 5 3 6 7 
// inorder(root) =>  4 2 5 1 6 3 7 
// postorder(root) =>  4 5 2 6 7 3 1 

#include <iostream>

using namespace std;

struct Node {
    
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
    
};

void preorder(Node* root){
    
    if(root==NULL) return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void inorder(Node* root){
    
    if(root==NULL) return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    
    if(root==NULL) return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


int main()
{
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right = new Node(3);
    
    root->left->left= new Node(4);
    root->left->right= new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    /*     1 
         /  \
        2    3 
       / \   / \
      4  5  6   7  */
    
    cout<<"\npreorder(root) =>  ";
    preorder(root);
    
    cout<<"\ninorder(root) =>  ";
    inorder(root);
     
    cout<<"\npostorder(root) =>  ";
    postorder(root);
    
    return 0;
}



//build tree using preorder and inorder
//  int preorder[]= {1,2,4,5,3,6,7};
//     int inorder[]= {4,2,5,1,6,3,7};


//o/p -> preorder of formed tree  preorder[]= {1,2,4,5,3,6,7};
#include <iostream>

using namespace std;

struct Node {
    
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
    
};

int search(int curr, int inorder[], int s, int e){
    
    while(s<=e){
        if(curr==inorder[s]) return s;
        s++;
    }

    return -1;
}

static int idx=0;

Node* preorderTree(int preorder[], int inorder[], int s, int e){
    
    if(s>e) return NULL;
    
    int curr= preorder[idx];
    idx++;
    
    Node* newRoot= new Node(curr);
    
    if(s==e) return newRoot;

    int p= search(curr, inorder, s, e);
    
    newRoot ->left= preorderTree(preorder, inorder, s, p-1);
    newRoot ->right= preorderTree(preorder, inorder, p+1, e);
    
    return newRoot;
}

void PrintPreorder(Node* root){
    
    if(root==NULL) return;
    cout<<root->data<<" ";
    PrintPreorder(root->left);
    PrintPreorder(root->right);
}

int main(){
    int preorder[]= {1,2,4,5,3,6,7};
    int inorder[]= {4,2,5,1,6,3,7};
    
    int e= sizeof(preorder)/sizeof(preorder[0]);
    
    Node* root= preorderTree(preorder, inorder, 0, e-1);
    
    PrintPreorder(root);
    
    return 0;
    
}




//build tree using postorder and inorder
//  poO[]={4, 5, 2, 6, 7, 3, 1 };
//     int inorder[]= {4,2,5,1,6,3,7};


//o/p -> preorder of formed tree  poO[]={4, 5, 2, 6, 7, 3, 1 };
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left, *right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

int search(int iO[], int s, int e, int curr){
    
    while(s<=e){
        if(iO[s]==curr) return s;
        s++;
    }
    
    return -1;
}

void printPoO(Node* root){
    
    if(root==NULL) return ;
    
    printPoO(root->left);
    printPoO(root->right);
    cout<<root->data<<" ";
}


Node* bt(int iO[], int poO[], int s, int e){
    
    int static i= e;
    if(s>e) return NULL;
    
    int cur= poO[i];
    i--;
    
    Node* nr= new Node(cur);
    
    if(s==e) return nr;
    
    int p=search(iO, s, e, cur);
    
    nr->right= bt(iO, poO, p+1, e);
    nr->left= bt(iO, poO, s, p-1);
    
    return nr;
}

int main()
{   int poO[]={4, 5, 2, 6, 7, 3, 1 };
    int iO[]= {4,2,5,1,6,3,7};
       
    int e= sizeof(iO)/sizeof(iO[0]);
    
   Node* root= bt(iO, poO, 0,e-1 );
    printPoO(root);
    
    return 0;
}


/*    1 
    /  \
   2    3 
  / \   / \
 4  5  6   7  */
 
//output
// countNode(root)   =>  7
//  sumNode(root)   =>  28
//  Level order of tree  =>  1 2 3 4 5 6 7 
// count of levels =>  3
//  sum at k=3 =>  22

#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left, *right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

void prO(Node* root){
    if(root==NULL) return;
    
    cout<<root->data<<" ";
    prO(root->left);
    prO(root->right);
}

int countNode(Node* root){
    if(root==NULL) return 0;
    return countNode(root->left) + countNode(root->right) +1;
}

int sumNode(Node* root){
    if(root==NULL) return 0;
    return sumNode(root->left) + sumNode(root->right) +root->data;
}

void printLevelOrder(Node* root){
    
    if(root==NULL) return;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int static cnt=1;
    
   while(!q.empty()){
       
           Node* n= q.front();
           q.pop(); 
         
       if(n!=NULL){
         cout<<n->data<<" ";
         
          if(n->left)
          q.push(n->left);
          
          if(n->right)
          q.push(n->right);
         
       }
       else if(!q.empty()){
           q.push(NULL);
           cnt++;
       }
   }
  cout<<"\ncount of levels =>  "<<cnt;
    return ;
    
}

int sumAtK(Node* root, int k){
    if(root==NULL) return 0;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int static c=1;
    int sum=0;
    
    while(!q.empty()){
        
        if(c==k){
            break;
        }
        
        Node* n= q.front();
        q.pop();
        
        if(n!=NULL){
           
            if(n->left) 
            q.push(n->left);
            
            if(n->right)
            q.push(n->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            c++;
        }
    }
    
    while(!q.empty()){
        Node* n= q.front();
        if(q.front()!=NULL)
        sum+= n->data;
        q.pop();
    }
    
    return sum;
    
}

int main(){
    
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);

    
    cout<<"\n countNode(root)   =>  "<<countNode(root);
    cout<<"\n sumNode(root)   =>  "<<sumNode(root);
    
    cout<<"\n Level order of tree  =>  ";
    printLevelOrder(root);
    
  cout<<"\n sum at level=3 =>  "<<sumAtK(root, 3);

    return 0;
}






// adding all left and right to the root node above

/*    1                            28
    /  \                          /  \                                
   2    3                        11   16 
  / \   / \                     / \   / \
 4  5  6   7                   4   5 6   7    */

//output
// height(root) of tree =>  3                           // 1  2  3  4 5 6 7 
//  sumRep(root) of tree and printing levelorder(root) =>  28 11 16 4 5 6 7 

#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left, *right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

void prO(Node* root){
    if(root==NULL) return;
    
    cout<<root->data<<" ";
    prO(root->left);
    prO(root->right);
}

int height(Node* root){
    if(root==NULL) return 0;
    
    int lheight= height(root->left);
    int rheight= height(root->right);
    
    return max(lheight, rheight)+1;
}

int sumRep(Node* &root){
    if(root==NULL) return 0;
    
    int a= sumRep(root->left) + sumRep(root->right)+ root->data;
        root->data= a;
        
        return root->data;
}

void lo(Node* root){
    if(root==NULL) return;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* n = q.front();
        q.pop();
        if(n!=NULL){
            cout<<n->data<<" ";
            
            if(n->left)
            q.push(n->left);
            
            if(n->right)
            q.push(n->right);
            
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
    
}

int main(){
    
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);

cout<<"\n height(root) of tree =>  "<<height(root);    
   
   sumRep(root);
   

cout<<"\n sumRep(root) of tree and printing levelorder(root) =>  ";    
   lo(root);

    return 0;
}