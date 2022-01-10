#include<stdio.h>
#include<conio.h>
void main()
{
  int ar[20],i,n,item,ch;
  int front=-1,rear=-1;
  clrscr();
  printf("\nEnter the size of queue");
  scanf("%d",&n);
  do
  {
    printf("\n\nSelect your choice\n");
    printf("\n1 Insertion\n2 Deletion\n3 Queue front element");
    printf("\n4 Queue rear element\n5 Display\n6 Exit \n");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:if(rear==n-1)
		printf("\nQueue overflow");
	      else
	      {
		printf("\nEnter the element ");
		scanf("%d",&item);
		rear++;
		ar[rear]=item;
	      }
	      if(front==-1)
		 front=0;
	      break;
       case 2:if(front==-1)
		printf("\nQueue underflow");
	      if(front==rear)
	      {
		 front=-1;
		 rear=-1;
	      }
	      else
		 front++;
	      break;
       case 3:if(front==-1)
		 printf("\nEmpty queue");
	      else
		 printf("\n The front element is : %d",ar[front]);
	      break;
       case 4:if(front==-1)
		printf("\nEmpty queue");
	      else
		printf("\n The rear element is : %d",ar[rear]);
	      break;
       case 5:if(front==-1)
		printf("\nEmpty queue");
	      else
	      {
		printf("\n The queue is :\n");
		for(i=front;i<=rear;i++)
		    printf("%d\t",ar[i]);
	      }
	      break;
       case 6:exit(0);
       default:printf("\n Invalid input");
	       break;
    }
  }while(ch!=7);
  getch();
}

