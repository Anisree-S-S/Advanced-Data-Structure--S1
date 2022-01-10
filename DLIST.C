#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Dnode
{
  struct Dnode *left;
  int data;
  struct Dnode *right;
};
typedef struct Dnode dnode;
dnode *getnode();
void main()
{
  dnode *first,*temp,*current;
  int i,n,pos,item,ch;
  first=NULL;
  clrscr();
  printf("enter the size of dlist");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    printf("enter the item of %d node",i);
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
  do
  {
    printf("\n\nenter your choice");
    printf("\n\t1 insert at first\n\t2 insert at last\n\t3 insert at any");
    printf("\n\t4 delete first\n\t5 delete last\n\t6 delete at any");
    printf("\n\t7 display\n\t8 search\n\t9 exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("enter the item");
	     scanf("%d",&item);
	     Insertdlistfirst(&first,item);
	     break;
      case 2:printf("enter the item");
	     scanf("%d",&item);
	     Insertdlistlast(&first,item);
	     break;
      case 3:printf("enter the item");
	     scanf("%d",&item);
	     printf("enter the position");
	     scanf("%d",&pos);
	     Insertdlistatany(&first,pos,item);
	     break;
      case 4:Deletefirst(&first);
	     break;
      case 5:Deletelast(&first);
	     break;
      case 6:printf("enter the position of the node to be delete");
	     scanf("%d",&pos);
	     Deleteatany(&first,pos);
	     break;
      case 7:display(first);
	     break;
      case 8:printf("enter the element to find");
	     scanf("%d",&item);
	     searchdlist(first,item);
	     break;
      case 9:exit(0);
      default:printf("\ninvalide");
    }
  }while(ch!=9);
  getch();
}
dnode *getnode()
{
  dnode *p;
  p=(dnode *)malloc(sizeof(dnode));
  return (p);
}
freenode(dnode *p)
{
  free(p);
}
Insertdlistfirst(dnode **first,int item)
{
  dnode *temp;
  temp=getnode();
  temp->data=item;
  temp->left=NULL;
  if(*first==NULL)
    temp->right=NULL;
  else
  {
    temp->right=*first;
    (*first)->left=temp;
  }
  *first=temp;
}
Insertdlistlast(dnode **first,int item)
{
 dnode *current,*temp;
 temp=getnode();
 temp->data=item;
 temp->right=NULL;
 if(*first==NULL)
 {
   temp->left=NULL;
   *first=temp;
 }
 else
 {
   current=*first;
   while(current->right!=NULL)
     current=current->right;
   temp->left=current;
   current->right=temp;
 }
}
Insertdlistatany(dnode **first,int pos,int item)
{
  dnode *temp,*current;
  int i;
  temp=getnode();
  temp->data=item;
  if(pos==1)
  {
    if(*first=NULL)
       (*first)->left=temp;
    temp->right=*first;
    temp->left=NULL;
    *first=temp;
  }
  else
  {
   i=2;
   current=*first;
   while((i<pos)&&(current->right!=NULL))
   {
     i++;
     current=current->right;
   }
   temp->left=current;
   temp->right=current->right;
   if(current->right!=NULL)
     temp->right->left=temp;
   current->right=temp;
  }
}
Deletefirst(dnode **first)
{
  dnode *current;
  int item;
  if(*first==NULL)
    printf("empty list");
  else
  {
    current=*first;
    *first=(*first)->right;
    if(*first!=NULL)
      (*first)->left=NULL;
    item=current->data;
    freenode(current);
    printf("deleted item is %d",item);
  }
}
Deletelast(dnode **first)
{
  dnode *current;
  int item;
  if(*first==NULL)
    printf("empty list");
  else
  {
    current=*first;
    while(current->right!=NULL)
      current=current->right;
    if(current->left!=NULL)
      current->left->right=current->right;
    else
      *first=NULL;
    item=current->data;
    freenode(current);
    printf("deleted item is %d",item);
  }
}
Deleteatany(dnode **first,int pos)
{
  dnode *current,*prev;
  int i=1,item;
  if(*first==NULL)
    printf("list is empty");
  else
  {
    current=*first;
    while(current!=NULL)
    {
      if(i==pos)
      {
	item=current->data;
	if(current->left==NULL)
	{
	  current->right->left=NULL;
	  *first=current->right;
	  freenode(current);
	}
	else if(current->right==NULL)
	{
	  current->left->right=current->right;
	  freenode(current);
	}
	else
	{
	   current->left->right=current->right;
	   current->right->left=current->left;
	   freenode(current);
	}
	printf("deleted item is %d",item);
      }
      i++;
      current=current->right;
    }
  }
}
display(dnode *first)
{
 if(first==NULL)
   printf("empty list");
 else
 {
    printf("\n the list is\n");
    while(first!=NULL)
    {
     printf("%d\t",first->data);
     first=first->right;
    }
 }
}
searchdlist(dnode *first,int item)
{
  int flag;
  if(first==NULL)
    printf("empty list");
  else
  {
    while(first!=NULL)
    {
      if(first->data==item)
      {
	flag=0;
	break;
      }
      else
      {
	flag=1;
	first=first->right;
      }
    }
  }
  if(flag==0)
    printf("item is found");
  else
    printf("not found");
}
