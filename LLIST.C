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
  node *first,*temp,*current,*prev;
  int ch,item,pos,n,i,flag=0;
  clrscr();
  first=NULL;
  printf("enter the size of linked list");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    printf("enter the data of %d node ",i);
    scanf("%d",&item);
    temp=getnode();
    temp->data=item;
    temp->link=NULL;
    if(first==NULL)
      first=temp;
    else
      current->link=temp;
    current=temp;
  }
  do
  {
    printf("\n\n select your choice\n");
    printf("\n\t1 insert at first\n\t2 insert at last");
    printf("\n\t3 insert at any position\n\t4 delete first node");
    printf("\n\t5 delect last node\n\t6 delete node at any position");
    printf("\n\t7 display\n\t8 searching\n\t9 exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\n enter the iten to insert");
	     scanf("%d",&item);
	     temp=getnode();
	     if(temp==NULL)
	       printf("\nunable to create node");
	     else
	     {
	       temp->data=item;
	       temp->link=first;
	       first=temp;
	     }
	     break;
      case 2:printf("\n enter the item to insert");
	     scanf("%d",&item);
	     temp=getnode();
	     if(temp==NULL)
	     {
	       printf("unable to create a node");
	       break;
	     }
	     temp->data=item;
	     temp->link=NULL;
	     if(first==NULL)
	       first=temp;
	     else
	     {
	       current=first;
	       while(current->link!=NULL)
		 current=current->link;
	       current->link=temp;
	     }
	     break;
      case 3:printf("\n enter the item to insert");
	     scanf("%d",&item);
	     printf("\n enter the position ");
	     scanf("%d",&pos);
	     temp=getnode();
	     if(temp==NULL)
	     {
	       printf("unable to create a node");
	       break;
	     }
	     if((first==NULL)||(pos==1))
	     {
	       temp->data=item;
	       temp->link=first;
	       first=temp;
	     }
	     current=first->link;
	     prev=first;
	     i=1;
	     while(current!=NULL)
	     {
	       if((i+1)==pos)
		 break;
	       else
	       {
		 prev=current;
		 current=current->link;
		 i++;
	       }
	     }
	     temp->data=item;
	     temp->link=current;
	     prev->link=temp;
	     break;
      case 4:if(first==NULL)
	       printf("the linked list is empty");
	     else
	     {
	       current=first;
	       item=current->data;
	       first=first->link;
	       free(current);
	       printf("\n deleted item id %d",item);
	     }
	     break;
      case 5:if(first==NULL)
	     {
	       printf("the list is empty");
	       break;
	     }
	     current=first;
	     prev=NULL;
	     if(first->link==NULL)
	       first=first->link;
	     else
	     {
	       while(current->link!=NULL)
	       {
		 prev=current;
		 current=current->link;
	       }
	       prev->link=current->link;
	     }
	     item=current->data;
	     free(current);
	     printf("\n the deleted item is %d",item);
	     break;
      case 6:printf("\n enter the position of the node to delete");
	     scanf("%d",&pos);
	     if(first==NULL)
	     {
	       printf("list is empty");
	       break;
	     }
	     if(pos==1)
	     {
	       current=first;
	       item=current->data;
	       first=first->link;
	       free(current);
	       printf("the deleted item is %d",item);
	       break;
	     }
	     current=first->link;
	     prev=first;
	     i=2;
	     while(current!=NULL)
	     {
	       if(i==pos)
	       {
		 prev->link=current->link;
		 item=current->data;
		 free(current);
		 printf("deleted item is %d" ,item);
	       }
	       else
	       {
		 prev=current;
		 current=current->link;
	       }
	       i++;
	     }
	     break;
      case 7:if(first==NULL)
	       printf("the list is empty");
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
      case 8:printf("enter the item to sesrch");
	     scanf("%d",&item);
	     if(first==NULL)
	       printf("list is empty");
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
	     if(flag==0)
	       printf("\n the item is not found");
	     else
	       printf("\n the item is found");
	     break;

      case 9:exit(0);
      default:printf("invalid input");
    }
  }while(ch!=8);
  getch();
}
node *getnode()
{
  node *p;
  p=(node *)malloc(sizeof(node));
  return(p);
}
freenode(node *p)
{
  free(p);
}

