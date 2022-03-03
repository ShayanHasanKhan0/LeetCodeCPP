#include <iostream>

using namespace std;


class NODE {
	public:
    NODE* left;
    NODE* right;
    int data;

    NODE(int val) {
        data=val;
        left=NULL;
        right=NULL;
    }

};

NODE* insertBST(NODE* root, int val) {
    if (root == NULL) {
        return new NODE(val); 
    }
    

    if (val < root->data) {
        root->left = insertBST(root->left,val);
    } else {
        root->right = insertBST(root->right,val);
    }
    
}

NODE* searchBST(NODE* root, int key) {
	if(root==NULL) {
		return NULL;
	}
	
	if(root->data == key) {
		return root;
	}
	if(key<root->data) {
		return searchBST(root->left, key);
	}
	return searchBST(root->right, key);
}

void inorder(NODE* root) {
    if(root==NULL) {
        return;
    }
    inorder(root->right);
    cout << root->data << " ";
    inorder(root->left);
}

// inorder successor
NODE* inorderSucc(NODE* root) {
        NODE * curr = root;
        while(curr && curr->left!=NULL){
            curr = curr->left;
        }
        return curr;
}

NODE* deleteBST(NODE* root, int val) {
	if( val < root->data ) {
		root->left=deleteBST(root->left);
	} else if( val > root->data ) {
		root->right=deleteBST(root->right);
	} else {
		if (root->left = NULL) {
//			case 1: ONE CHILD (only right node is there)
			NODE* temp = root->right;
			free(root);
			return temp;
		} else if (root->right = NULL) {
//			case 2: ONE CHILD (only left node is there)
			NODE* temp = root->left;
			free(root);
			return temp;
		}
//			case 3: TWO CHILD
		NODE* temp=inorderSucc(root->right);
        root->data = temp->data;
        root->left = deleteBST(root->right,temo->data);
	}
    return root;

    
} 

int main() {
    NODE* rootnode=NULL;
	rootnode = insertBST(rootnode, 5);

    insertBST(rootnode,7);
    insertBST(rootnode,8);
    insertBST(rootnode,9);
    insertBST(rootnode,2);
    insertBST(rootnode,4);
    insertBST(rootnode,3);

    // PRINT
    inorder(rootnode);
    deleteBST(rootnode,8);
    inorder(rootnode);
    
    if(searchBST(rootnode,6) == NULL) {
    	cout << "KEY DOESNT EXIST";
	}else {
		cout << "KEY EXIST";
	};
    
    cout<<endl;
    return 0;
}
