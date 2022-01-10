#include<stdio.h>
#include<conio.h>
void main()
{
  int a[20],n,ch,i,item,top=-1;
  clrscr();
  printf("Enter the size of stack");
  scanf("%d",&n);
  do
  {
     printf("\n\nSelect your choice\n");
     printf("\n1 Push\n2 Pop\n3 Stack top\n4 Display\n5 Exit\n");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:if(top>=n)
		 printf("\nStack overflow");
	      else
	      {
		 printf("\nEnter an element");
		 scanf("%d",&item);
		 top++;
		 a[top]=item;
	      }
	      break;
       case 2:if(top<0)
		 printf("\nStack underflow");
	      else
	      {
		item=a[top];
		top--;
	      }
	      break;
       case 3:if(top<0)
		printf("\nEmpty stack");
	      else
		printf("\nStack top is %d ",a[top]);
	      break;
       case 4:if(top<0)
		 printf("\nEmpty stack");
	      else
	      {
		 printf("\n The stack is\n");
		 for(i=top;i>=0;i--)
		   printf("%d\t",a[i]);
	      }
	      break;
       case 5:exit(0);
       default:printf("Invalid input");
	       break;
     }
  }while(ch!=6);
getch();
}
