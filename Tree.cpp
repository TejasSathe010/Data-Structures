#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
};

Node* getNewNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

Node* Insert(Node* root, int data){

    if(root == NULL){
        root = getNewNode(data);
    }
    else if(data <= root->data){
            root->left = Insert(root->left, data);
    }
    else if(data > root->data){
            root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(Node *root, int data){
    if(root == NULL){
        return false;
    }
    else if(root->data == data){
        return true;
    }
    else if(root->data > data){
        return Search(root->left, data);
    }
    else {
        return Search(root->right, data);
    }
}


void Inorder(Node *root){

    if(root == NULL){
        return;
    }

    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

void Postorder(Node *root){
    if(root == NULL){
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << endl;
}

void Preorder(Node *root){
    if(root == NULL){
        return;
    }

    cout << root->data << endl;
    Preorder(root->left);
    Preorder(root->right);
}



int main(){

    Node* root = NULL;
    root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);

    int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";


    // Inorder(root);
    // Postorder(root);
    Preorder(root);
}