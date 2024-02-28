#include<iostream>

using namespace std;

struct Node{
    
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }      
};

int solve(TreeNode* &root, int &dia){ 

        int lh=0,rh=0;
        if(root->left)
        lh=1+solve(root->left,dia); 
        if(root->right)
        rh=1+solve(root->right,dia);

        dia=max(dia,lh+rh);

        return max(lh,rh);

    }
int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    int dia = 0;
    caldiameter(root,dia);
    cout<<dia<<endl;

    return 0;
    
}