#include<stdio.h>
#include<stdlib.h>
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
  node *front,*rear,*temp,*current;
  int i,ch,item;
  clrscr();
  front=NULL;
  rear=NULL;
  do
  {
    printf("\n\nselect your choice\n");
    printf("\n\t1 insert\n\t2 delete\n\t3 display\n\t 4exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\n enter the item to insert");
	     scanf("%d",&item);
	     temp=getnode();
	     if(temp==NULL)
	     {
	       printf("unable to create");
	       break;
	     }
	     temp->data=item;
	     temp->link=NULL;
	     if(front==NULL)
	       front=temp;
	     else
	     {
	       rear=front;
	       while(rear->link!=NULL)
		 rear=rear->link;
	       rear->link=temp;
	     }
	     break;
      case 2:if(front==NULL)
	       printf("queue is empty");
	     else
	     {
	       rear=front;
	       item=rear->data;
	       front=front->link;
	       free(rear);
	       printf("deleted item is %d",item);
	     }
	     break;
      case 3:if(front==NULL)
		printf("queue is empty");
	     else
	     {
	       current=front;
	       while(current!=NULL)
	       {
		  printf("%d\t",current->data);
		  current=current->link;
	       }
	     }
	     break;
      case 4:exit(0);
      default:printf("invalide input");
    }
  }while(ch!=5);
  getch();
}
node *getnode()
{
  node *p;
  p=(node *)malloc(sizeof(node));
  return (p);
}
freenode(node *p)
{
  free(p);
}