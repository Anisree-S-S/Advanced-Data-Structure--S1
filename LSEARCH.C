#include<stdio.h>
#include<conio.h>
struct Node
{
   int data;
   struct Node *link;
};
typedef struct Node node;
node *getnode();
void main()
{
  node *first,*current,*temp;
  int n,i,flag=0,item;
  clrscr();
  first=NULL;
  printf("enter the size of list\n");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
     temp=getnode();
     printf("enter the element ");
     scanf("%d",&item);
     temp->data=item;
     temp->link=NULL;
     if(first==NULL)
	first=temp;
     else
	current->link=temp;
     current=temp;
  }
  printf("\nEnter the element to search  ");
  scanf("%d",&item);
  if(first==NULL)
    printf("\n list is empty");
  else
  {
    current=first;
    while(current!=NULL)
    {
      if(current->data==item)
      {
	 flag=1;
	 break;
      }
      else
	 current=current->link;
    }
  }
  if(flag==1)
     printf("the element %d is found",item);
  else
     printf("\n the element is not found");
  getch();
}
node *getnode()
{
   node *p;
   p=(node *)malloc(sizeof(node));
   return p;
}