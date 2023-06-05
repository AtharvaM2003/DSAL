#include <iostream>
#include <stdlib.h>
using namespace std;

class node{
   
    public:
    node *left;
    int data;
    node *right;
};


class binary{  
    public:  
    node *root;
    node *temp;
    node *curr;

    binary()
    {
       root=NULL;
    }
void create();
void Display();
void inorder(node *);
void preorder(node *);
void postorder(node *);
void insert(node *,node *);
void search(node *,int key);
void min(node *);
void maxe(node *);
void Mirror(node *);
int longpath(node *);
//int DeleteNode(node *,int key);
};


void binary::create()
{
int op;
do
{
temp=new node;

cout<<"Enter the Data :";
cin>> temp->data;

temp->left=NULL;
temp->right=NULL;

if(root==NULL){
root=temp;
}
else{
insert(root,temp);
}
cout<<"Do you want to continue, press 1 : ";
cin>>op;
}while (op==1);

}

void binary::inorder(node *root)
{
    if(root!=NULL)
    { 
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void binary::preorder(node *root)
{
    if(root!=NULL)
    {
        
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void binary::postorder(node *root)
{
    if(root!=NULL)
    {
        
        postorder(root->left);
        postorder(root->right);
        cout<<" "<<root->data;
       
    }
}

void binary::insert(node *root,node *temp)
{
  char ch;
  //cout<<"Root Node:-"<<root->data;
  if(temp->data<root->data)
  {
      if(root->left==NULL)
      {
          root->left=temp;
      }
      else
      insert(root->left,temp);

  }
  else if (temp->data>root->data)
 {
 
      if(root->right==NULL)
      {
          root->right=temp;
      }
      else
      insert(root->right,temp);
  }
   
}

void binary::search(node *root,int key)
{
	//int key;
   if(root!=NULL)
   {
	if(key==root->data)
	{
		cout<<"Element is Found\n";
		
	}
	else if(key<root->data)
	{
		search(root->left,key);
	}
	else if(key>root->data)
	{
		search(root->right,key);
	}
	
   }	
	else
	{
		cout<<"Element is not found...\n";
	}		
}


void binary::min(node *root)
{
	
	if(root->left==NULL)
	{
		cout<<root->data;
	}
else
{
return min(root->left);
}
}

void binary::Display()
{
    cout<<"BST Traversal...";
    cout<<"\nInorder Representation:";
    inorder(root);
    cout<<"\nPreorder Representation:";
    preorder(root);
    cout<<"\nPostorder Representation:";
    postorder(root);
}


void binary::maxe(node *root)
{
	if(root->right==NULL)
	{
		cout<<root->data;
	}
else
{
return maxe(root->right);
}
}

void binary::Mirror(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
	node *t;
	t=new node;
	Mirror(root->left);
	Mirror(root->right);
	t=root->left;
	root->left=root->right;
	root->right=t;
	}	
}

int binary::longpath(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftlp=longpath(root->left);
    int rightlp=longpath(root->right);
    return max(leftlp,rightlp)+1;
}

node * DeleteNode(node* root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = DeleteNode(root->left, key);
 
    else if (key > root->data)
        root->right = DeleteNode(root->right, key);

    else {
    //Leaf node. 
    if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
    
    // Node has right child.
    if (root->left == NULL) {
         node *curr = root->right;
            free(root);
            return curr;
        }
        
       //Node has left child.
        else if (root->right == NULL) {
          node *curr = root->left;
            free(root);
            return curr;
        }
        
       //Node has both left and right children. 
        else
	{

	  node *curr = root->right;

	  while (curr->left != NULL)
	    curr = curr->left;
	  root->data = curr->data;
	  root->right = DeleteNode(root->right,curr->data);
}

 }
  return root;
}

int main() {
    binary nd;
    int key,ch;
    
    while (1)
    { 
    cout<<"\n1) Create and insert node in BST\n2)Traversal Tree\n3)Search element from BST\n4)Find Min element\n5)find Max element\n6)Delete node Tree\n7)Longest Path\n8)Mirror Tree\n9)Exit\n\n";
    cout<<"\nEnter your choice:";
    cin>>ch;
    switch (ch)
    {
    case 1:
    nd.create();
    break;
    
    case 2:
    nd.Display();
    break;
    
    case 3:
    cout<<"\nSearch Operation on BST..\n";
    cout<<"Enter Element to Search:";
	   cin>>key;
    nd.search(nd.root,key);
    break;
    
    case 4:
    cout<<"\nMin element:";
    nd.min(nd.root);
    break;
    
    case 5:
    cout<<"\nMax element:";
    nd.maxe(nd.root);
    break;
    
    case 6:
    cout<<"\nDelete Operation on BST..\n";
    cout<<"Enter Element to Search for Delete:";
    cin>>key;
    DeleteNode(nd.root,key);
    nd.inorder(nd.root);
    break;

    case 7:
    cout<<"\nLongest path:";
    cout<< nd.longpath(nd.root);
    break;
    
    case 8:
     cout<<"\nMirror Image of Tree:";
    nd.Mirror(nd.root);
    nd.Display();
    break;

    case 9:
    exit(1);
    cout<<"Thank you...!!";
    break;
    
    default:
    cout<<"Invalid choice..\n";
    }
    }
    return 0;
}
