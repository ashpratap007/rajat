#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *left;
		Node *right;
};

void preOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root)
{
    if(root==NULL) 
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void inOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

pair<bool,int> isBalanced(Node* root)
{
    // cout<<(true&&true)<<endl;
    if(root==NULL)
    {
        return make_pair(true,0);
    }
    pair<bool,int> left_tree = isBalanced(root->left);
    pair<bool,int> right_tree = isBalanced(root->right);
    bool is_balanced = bool((left_tree.first&&right_tree.first)&&(abs(left_tree.second-right_tree.second)<=1));
    // cout<<is_balanced<<endl;
    return make_pair(is_balanced,1+max(left_tree.second,right_tree.second));
}

Node* createNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
}

int main()
{
	Node *root = new Node();
	root->data = 1;
	root->left = new Node();
	root->right = new Node();
	root->left->data = 2;
	root->left->left = new Node();
	root->left->right = new Node();
	root->left->left->data = 4;
	root->left->left->left = NULL;
	root->left->left->right = NULL;
	root->left->right->data = 5;
	root->left->right->left = new Node();
	root->left->right->right = NULL;
	root->left->right->left->data = 8;
	root->left->right->left->left = NULL;
	root->left->right->left->right = NULL;
	root->right->data = 3;
	root->right->left = new Node();
	root->right->right = new Node();
	root->right->left->data = 6;
	root->right->left->left = NULL;
	root->right->left->right = NULL;
	root->right->right->data = 7;
	root->right->right->left = NULL;
	root->right->right->right = NULL;

    root->left->right->left->right = createNode(9);
	
	preOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    cout<<endl;
    inOrderTraversal(root);
    cout<<endl;
    
    pair<bool,int> is_balanced = isBalanced(root);
    cout<<is_balanced.first<<" "<<is_balanced.second;
    cout<<endl;
}
