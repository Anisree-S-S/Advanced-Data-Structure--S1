#include<stdio.h>
#include<conio.h>
struct rbtNode
{
   int data;
   char color;
   struct rbtNode *left,*right,*parent;
};
typedef struct rbtNode rbtnode;
struct rbtNode *root=NULL;
void leftRotate(rbtnode *x)
{
   rbtnode *y;
   y=x->right;
   x->right=y->left;
   if(y->left!=NULL)
      y->left->parent=x;
   y->parent=x->parent;
   if(x->parent==NULL)
      root=y;
   else if((x->parent->left!=NULL)&&(x->data==x->parent->left->data))
      x->parent->left=y;
   else
      x->parent->right=y;
   y->left=x;
   x->parent=y;
}
void rightRotate(rbtnode *y)
{
   rbtnode *x;
   x=y->left;
   y->left=x->right;
   if(x->right!=NULL)
      x->right->parent=y;
   x->parent=y->parent;
   if(y->parent==NULL)
      root=x;
   else if((y->parent->left!=NULL)&&(y->data==y->parent->left->data))
      y->parent->left=x;
   else
      y->parent->right=x;
   x->right=y;
   y->parent=x;
}
void color(rbtnode *z)
{
   rbtnode *y=NULL;
   while((z->parent!=NULL)&&(z->parent->color=='R'))
   {
       if((z->parent->parent->left!=NULL)&&(z->parent->data==z->parent->parent->left->data))
       {
	  if(z->parent->parent->right!=NULL)
	     y=z->parent->parent->right;
	  if((y!=NULL)&&(y->color=='R'))
	  {
	    z->parent->color='B';
	    y->color='B';
	    z->parent->parent->color='R';
	    if(z->parent->parent!=NULL)
	       z=z->parent->parent;
	  }
	  else
	  {
	     if((z->parent->right!=NULL)&&(z->data==z->parent->right->data))
	     {
	       z=z->parent;
	       leftRotate(z);
	     }
	     z->parent->color='B';
	     z->parent->parent->color='R';
	     rightRotate(z->parent->parent);
	  }
       }
       else
       {
	  if(z->parent->parent->left!=NULL)
	      y=z->parent->parent->left;
	  if((y!=NULL)&&(y->color=='R'))
	  {
	      z->parent->color='B';
	      y->color='B';
	      z->parent->parent->color='R';
	      if(z->parent->parent!=NULL)
		 z=z->parent->parent;
	  }
	  else
	  {
	     if((z->parent->left!=NULL)&&(z->data==z->parent->left->data))
	     {
		z=z->parent;
		rightRotate(z);
	     }
	     z->parent->color='B';
	     z->parent->parent->color='R';
	     leftRotate(z->parent->parent);
	  }
       }
   }
   root->color='B';
}
void insert(int val)
{
   rbtnode *x,*y,*z;
   z=(rbtnode*)malloc(sizeof(rbtnode));
   z->data=val;
   z->left=NULL;
   z->right=NULL;
   z->color='R';
   x=root;
   if(root==NULL)
   {
       root=z;
       root->color='B';
   }
   while(x!=NULL)
   {
      y=x;
      if(z->data<x->data)
	 x=x->left;
      else
	 x=x->right;
   }
   z->parent=y;
   if(y==NULL)
      root=z;
   else if(z->data<y->data)
      y->left=z;
   else
      y->right=z;
   color(z);
}
void inorder(rbtnode *root)
{
   rbtnode *temp=root;
   if(temp!=NULL)
   {
      inorder(temp->left);
      printf(" %d-%c ",temp->data,temp->color);
      inorder(temp->right);
   }
}
void main()
{
   int ch,val;
   clrscr();
   while(1)
   {
      printf("\n\nSelect your choice\n");
      printf("\t1 Insert\n\t2 Display\n\t3 Exit\n");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1:printf("Enter element : ");
		scanf("%d",&val);
		insert(val);
		break;
	 case 2:inorder(root);
		break;
	 case 3:exit(0);
      }
   }
   getch();
}
