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
   node *top,*temp,*current;
   int ch,item,i,n;
   clrscr();
   top=NULL;
   do
   {
     printf("\n\n Select your choice");
     printf("\n\t1 Push\n\t2 Pop\n\t3 Top element\n\t4 Display\n\t5 Exit\n");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:printf("enter the element to insert");
	      scanf("%d",&item);
	      temp=getnode();
	      temp->data=item;
	      temp->link=top;
	      top=temp;
	      break;
       case 2:if(top==NULL)
		 printf("stack is empty");
	      else
	      {
		 current=top;
		 item=current->data;
		 top=top->link;
		 free(current);
	      }
	      break;
       case 3:if(top==NULL)
		printf("stack is empty");
	      else
		printf("Stack top element is %d",top->data);
	      break;
       case 4:if(top==NULL)
		printf("stack is empty");
	      else
	      {
		current=top;
		while(current!=NULL)
		{
		   printf("%d\t",current->data);
		   current=current->link;
		}
	      }
	      break;
       case 5:exit(0);
       default:printf("Invalid input");
     }
   }while(ch!=6);
   getch();
}
node *getnode()
{
  node *p;
  p=(node *)malloc(sizeof(node));
  return p;
}

