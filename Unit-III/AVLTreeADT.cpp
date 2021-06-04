#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    int height;
    struct Node *left,*right;
};
class AVLTreeADT{
    public:
        struct Node * insert(struct Node *,int);
        struct Node * remove(struct Node *,int);
        struct Node * search(struct Node *,int);
        struct Node * LL(struct Node *);
        struct Node * RR(struct Node *);
        struct Node * LR(struct Node *);
        struct Node * RL(struct Node *);
        int height(struct Node *);
        void printTree(struct Node *,int);
        void inorder(struct Node *);
        void preorder(struct Node *);
        void postorder(struct Node *);
        int big(int,int);
};
 struct Node * AVLTreeADT :: insert(struct Node *root,int value){
    if(root==NULL){
        root=(struct Node *) malloc(sizeof(struct Node));
        root->data=value;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else if(root->data >value){
        root->left=insert(root->left,value);
        if( (height(root->left) - height(root->right)) >= 2){
			if(value < root->left->data)
				root = LL(root);
			else
				root = LR(root);
		}
	}
	else if(root->data < value){
		root->right = insert(root->right, value);
		if((height(root->right) - height(root->left)) >= 2){
			if(value > root->right->data)
				root = RR(root);
			else
				root = RL(root);
		}
	}
	else{
     		cout<<"\n Data already exists...So discard it !";
	    	return root;
	}
	root->height = 1+ big(height(root->left), height(root->right));
	return root;
}
struct Node * AVLTreeADT :: LL(struct Node *t){
	struct Node *temp;
	temp = t->left;
	t->left = temp->right;
	temp->right = t;
	t->height = 1+ big(height(t->left), height(t->right));
	temp->height = 1+ big(height(temp->left), height(temp->right));
	return temp;
}
struct Node * AVLTreeADT :: RR(struct Node *t){
	struct Node *temp;
	temp = t->right;
	t->right = temp->left;
	temp->left = t;
	t->height = 1+ big(height(t->left), height(t->right));
	temp->height = 1+ big(height(temp->left), height(temp->right));
	return temp;
}
struct Node * AVLTreeADT :: LR(struct Node *t){
	t->left = RR(t->left);
	return LL(t);
}
struct Node * AVLTreeADT :: RL(struct Node *t){
	t->right = LL(t->right);
	return RR(t);
}

int AVLTreeADT :: height(struct Node *t){
	if(t==NULL)
		return -1;
	else if(t->left == NULL && t->right == NULL)
		return 0;
	else if(t->left == NULL)
		return 1 + height(t->right);
	else if(t->right == NULL)
		return 1+ height(t->left);
	else
		return 1+ big(height(t->left), height(t->right));
}
void AVLTreeADT :: printTree(struct Node *t,int level){
		if(t!=NULL){
			printTree(t->right, level+1);
			for(int i=0;i<level;i++)
				cout<<"  ";
			cout<<t->data<<"\n";
			printTree(t->left, level+1);
		}			
}

void AVLTreeADT :: inorder(struct Node *t){
        if(t!=NULL){
            inorder(t->left);
            cout<<t->data<<"  ";
            inorder(t->right);
        }
}
void AVLTreeADT :: preorder(struct Node *t){
    if(t!=NULL){
        cout<<t->data<<"  ";
        preorder(t->left);
        preorder(t->right);
    }
}
void AVLTreeADT :: postorder(struct Node *t){
    if(t!=NULL){
        postorder(t->left);
        postorder(t->right);
        cout<<t->data<<"  ";
    }
}
int AVLTreeADT :: big(int x, int y){
  return (x>y) ?x:y;
}
int main(){
	struct Node *root = NULL;
	AVLTreeADT obj;	int v;
	for(int i=0;i<8;i++){
	    cout<<"enter value";
	    cin>>v;
		root = obj.insert(root, v);
		obj.printTree(root,1);
	}
	cout<<"\n The inorder is\n";
	obj.inorder(root);
	cout<<"\n preorder is....";
	obj.preorder(root);
	cout<<"\n postorder is....";
	obj.postorder(root);
	cout<<"\n The AVL tree structure is....\n\n";
	obj.printTree(root,1);
	return 0;
}
