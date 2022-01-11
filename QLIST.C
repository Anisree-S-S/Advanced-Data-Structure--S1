#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
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
  int item,ch;
  clrscr();
  front=NULL;
  rear=NULL;
  do
  {
     printf("\nselect your choice\n");
     printf("\n\t1 Insert\n\t2 Delete\n\t3 Front element");
     printf("\n\t4 Rear element\n\t5 Display\n\t6 Exit");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:printf("enter the item ");
	      scanf("%d",&item);
	      temp=getnode();
	      temp->data=item;
	      temp->link=NULL;
	      if(front==NULL)
	      {
		 front=temp;
		 rear=temp;
	      }
	      else
	      {
		 rear->link=temp;
		 rear=temp;
	      }
	      break;
       case 2:if(front==NULL)
		 printf("queue is empty");
	      else
	      {
		 temp=front;
		 item=temp->data;
		 front=front->link;
		 if(front==NULL)
		    rear=NULL;
		 free(temp);
	      }
	      break;
       case 3:if(front==NULL)
		printf("queue is empty");
	      else
		printf("The front element is %d",front->data);
	      break;
       case 4:if(front==NULL)
		 printf("queue is empty");
	      else
		 printf("The rear element is %d",rear->data);
	      break;
       case 5:if(front==NULL)
		printf("queue is empty");
	      else
	      {
		printf("the queue is\n");
		temp=front;
		while(temp!=NULL)
		{
		   printf("%d\t",temp->data);
		   temp=temp->link;
		}
	      }
	      break;
       case 6:exit(0);
       default:printf("invalid input");
     }
  }while(ch!=7);
  getch();
}
node *getnode()
{
  node *p;
  p=(node *)malloc(sizeof(node));
  return p;
}