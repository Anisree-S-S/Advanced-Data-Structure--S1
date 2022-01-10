#include<stdio.h>
#include<conio.h>
void main()
{
   int i,item,ch,n,ar[20];
   int front=-1,rear=-1;
   clrscr();
   printf("\nEnter the size of circular queue");
   scanf("%d",&n);
   do
   {
     printf("\n\nSelect your choice");
     printf("\n1 Insertion\n2 Deletion\n3 Front elemenet\n4 Rear elemenet");
     printf("\n5 Display\n6 Exit\n");
     scanf("%d",&ch);
     switch(ch)
     {
	case 1:if(((front==0)&&(rear==n-1))||((front==rear+1)&&(rear>-1)))
		 printf("\nQueue overflow");
	       else
	       {
		 printf("\nEnter the item");
		 scanf("%d",&item);
		 rear=(rear+1)%n;
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
		 front=(front+1)%n;
	       break;
	case 3:if(front==-1)
		 printf("\nEmpty circularqueue");
	       else
		 printf("\nFront element is : %d",ar[front]);
	       break;
	case 4:if(front==-1)
		  printf("\nEmpty circularqueue");
	       else
		  printf("\nRear element is : %d",ar[rear]);
	       break;
	case 5:if(front==-1)
		 printf("\nEmpty circularqueue");
	       if(rear>=front)
		 for(i=front;i<=rear;i++)
		    printf("%d\t",ar[i]);
	       else
	       {
		 for(i=front;i<n;i++)
		    printf("%d\t",ar[i]);
		 for(i=0;i<=rear;i++)
		    printf("%d\t",ar[i]);
	       }
	       break;
	case 6:exit(0);
	default:printf("\nInvalid input");
     }
   }while(ch!=7);
  getch();
}
