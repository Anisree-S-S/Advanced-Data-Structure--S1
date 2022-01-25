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
  node *first,*temp,*current,*prev;
  int ch,item,pos,n,i;
  clrscr();
  first=NULL;
  printf("Enter the size of linked list");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
     printf("Enter the data of %d node : ",i);
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
     printf("\n\nSelect your choice\n");
     printf("\t1 Insert at first\n\t2 Insert at last\n\t3 Insert at any position");
     printf("\n\t4 Delete from first\n\t5 Delete from last\n\t6 Delete from any position");
     printf("\n\t7 Dislay\n\t8 Exit\n");
     scanf("%d",&ch);
     switch(ch)
     {
	case 1:printf("Enter the item to insert ");
	       scanf("%d",&item);
	       temp=getnode();
	       temp->data=item;
	       temp->link=first;
	       first=temp;
	       break;
	case 2:printf("Enter the item to insert ");
	       scanf("%d",&item);
	       temp=getnode();
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
	case 3:printf("Enter the item to insert ");
	       scanf("%d",&item);
	       printf("Enter the position ");
	       scanf("%d",&pos);
	       temp=getnode();
	       temp->data=item;
	       if((first==NULL)||(pos==1))
	       {
		  temp->link=first;
		  first=temp;
	       }
	       else
	       {
		  current=first->link;
		  prev=first;
		  i=2;
		  while(current!=NULL)
		  {
		    if(i==pos)
		       break;
		    else
		    {
		       prev=current;
		       current=current->link;
		       i++;
		    }
		  }
		  temp->link=current;
		  prev->link=temp;
	       }
	       break;
	case 4:if(first==NULL)
		  printf("The list is empty");
	       else
	       {
		   current=first;
		   item=current->data;
		   first=first->link;
		   free(current);
		   printf("The deleted item is %d ",item);
	       }
	       break;
	case 5:if(first==NULL)
	       {
		  printf("The list is empty");
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
	       printf("%d is the deleted node ",item);
	       break;
	case 6:printf("Enter the position of node to deleted");
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
		  printf("Deleted item is %d ",item);
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
		      printf("Deleteditem is %d",item);
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
		  printf("Empty list");
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
	case 8:exit(0);
	default:printf("\n invalid input");
     }
  }while(ch!=8);
  getch();
}
node *getnode()
{
   node *p;
   p=(node*)malloc(sizeof(node));
   return p;
}
