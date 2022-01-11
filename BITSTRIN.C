#include<stdio.h>
#include<conio.h>
void input();
void output();
void setunion();
void intersection();
void difference();
int a[]={0,0,0,0,0,0,0,0,0};
int b[]={0,0,0,0,0,0,0,0,0};
int c[]={0,0,0,0,0,0,0,0,0};
int main()
{
   int ch;
   clrscr();
   do
   {
      printf("\n\nSelect your choice");
      printf("\n\t1 Input\n\t2 Union\n\t3 Intersection");
      printf("\n\t4 Difference\n\t5 Exit\n");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1:input();
		break;
	 case 2:setunion();
		break;
	 case 3:intersection();
		break;
	 case 4:difference();
		break;
	 case 5:exit(0);
	 default:printf("Invalid input");
      }
   }while(ch!=6);
   return 0;
}
void input()
{
  int n,x,i;
  printf("\nEnter the size of the first set");
  scanf("%d",&n);
  printf("Enter the elemnts  ");
  for(i=1;i<=n;i++)
  {
     scanf("%d",&x);
     a[x]=1;
  }
  printf("\nEnter the size of second set");
  scanf("%d",&n);
  printf("Enter the elements  ");
  for(i=1;i<=n;i++)
  {
     scanf("%d",&x);
     b[x]=1;
  }
  printf("\n First set is\n{");
  for(i=1;i<=9;i++)
     printf("%d\t",a[i]);
  printf("}\n\nSecond set is\n{");
  for(i=1;i<=9;i++)
     printf("%d\t",b[i]);
  printf("}");
}
void output(int c[])
{
  int i;
  printf("\n the set is\n{");
  for(i=1;i<=9;i++)
    if(c[i]!=0)
      printf("%d\t",i);
  printf("}");
}
void setunion()
{
   int i,c[10];
   for(i=1;i<=9;i++)
   {
     if(a[i]!=b[i])
	c[i]=1;
     else
	c[i]=a[i];
   }
   printf("{");
   for(i=1;i<=9;i++)
     printf("%d\t",c[i]);
   printf("}");
   output(c);
}
void intersection()
{
   int i,c[10];
   printf("{");
   for(i=1;i<=9;i++)
   {
     if(a[i]==b[i])
       c[i]=a[i];
     else
       c[i]=0;
   }
   printf("{");
   for(i=1;i<=9;i++)
      printf("%d\t",c[i]);
   printf("}");
   output(c);
}
void difference()
{
   int i,c[10];
   for(i=1;i<=9;i++)
   {
      if((a[i]==1)&&(b[i]==0))
	 c[i]=1;
      else
	 c[i]=0;
   }
   printf("{");
   for(i=1;i<=9;i++)
     printf("%d\t",c[i]);
   printf("}");
   output(c);
}





