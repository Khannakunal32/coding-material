// Build Bst tree with array
// i/p arr= 5,1,3,4,2,7
// o/p inorder= 1,2,3,4,5,7 (a bst tree)
#include <iostream>

using namespace std;

struct Node{
    Node* left, *right;
    int data;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node* buildBST(int val, Node* &root){
    
    if(root==NULL) return new Node(val);
    
    if(val< root->data) 
    root->left= buildBST(val, root->left);
    else 
    root->right= buildBST(val, root->right);
    
    return root;
}

void inO(Node* root){
    if(root==NULL) return;
    
    inO(root->left);
    cout<<root->data<<" ";
    inO(root->right);
    return;
}

int main()
{
    int arr[]={5,1,3,4,2,7};
    
    int n= sizeof(arr)/ sizeof(arr[0]);
    
    Node* root= new Node(arr[0]);
    for(int i=1; i<n; i++) buildBST(arr[i],root);

    inO(root);
    return 0;
}