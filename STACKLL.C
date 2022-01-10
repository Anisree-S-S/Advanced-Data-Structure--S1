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
  node *first,*temp,*current;
  int ch,item,i;
  clrscr();
  first=NULL;
  do
  {
    printf("\n\n select your choice");
    printf("\n\t1.push\n\t2.pop\n\t3.display\n\t4.exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("enter the data");
	     scanf("%d",&item);
	     temp=getnode();
	     if(temp==NULL)
	       printf("unable to create");
	     else
	     {
	       temp->data=item;
	       temp->link=first;
	       first=temp;
	     }
	     break;
      case 2:if(first==NULL)
	       printf("stack is empty");
	     else
	     {
	       current=first;
	       item=current->data;
	       first=first->link;
	       free(current);
	     }
	     break;
      case 3:if(first==NULL)
	       printf("stack is empty");
	     else
	     {
	       current=first;
	       while(current!=NULL)
	       {
		 printf("%d\t",current->data);
		 current=current->link;
	       }
	     }
	     break;
      case 4:exit(0);
    }
  }while(ch!=4);
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