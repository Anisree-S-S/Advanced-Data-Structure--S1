#include<stdio.h>
#include<conio.h>
struct DNode
{
   struct DNode *left;
   int data;
   struct DNode *right;
};
typedef struct DNode dnode;
dnode *getnode();
void main()
{
  dnode *first,*temp,*current;
  int i,n,item;
  clrscr();
  first=NULL;
  printf("Enter the size ofdoubly linked list");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
      printf("enter the data of node %d : ",i);
      scanf("%d",&item);
      temp=getnode();
      temp->data=item;
      temp->right=NULL;
      if(first==NULL)
      {
	 first=temp;
	 temp->left=NULL;
      }
      else
      {
	 current->right=temp;
	 temp->left=current;
      }
      current=temp;
  }
  current=first;
  while(current->right!=NULL)
    current=current->right;
  printf("the reverse of the dlist is\n");
  while(current!=NULL)
  {
     printf("%d\t",current->data);
     current=current->left;
  }
  getch();
}
dnode *getnode()
{
  dnode *p;
  p=(dnode *)malloc(sizeof(dnode));
  return(p);
}