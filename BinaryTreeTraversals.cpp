#include <iostream>

using namespace std;

class NODE {
    public:
        int data;
        NODE* left;
        NODE* right;

        NODE(int val) {
            data = val;
            left=NULL;
            right=NULL;
        }
};

// left root right
void inorder(NODE* root) {
    if (root==NULL) {
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// root left right
void preorder(NODE* root) {
    if (root==NULL) {
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// left right root
void postorder(NODE* root) {
    if (root==NULL) {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main() {
    
    NODE* root = new NODE(1);

    root->left = new NODE(2);
    root->right = new NODE(3);
    root->left->left = new NODE(4);
    root->left->right = new NODE(5);
    root->right= new NODE(3);
    root->right->left = new NODE(6);
    root->right->right = new NODE(7);

    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);

    return 0;
}