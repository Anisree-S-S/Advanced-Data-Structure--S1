#include<stdio.h>
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
      printf("\nselect your choice");
      printf("\n\t1 input\n\t2 union\n\t3 intersection\n\t");
      printf("4 difference\n\t5 exit");
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
	default:printf("invalid input");
      }
   }while(ch!=6);
   return 0;
}
void input()
{
  int n,x,i;
  printf("enter the size of 1st set\n");
  scanf("%d",&n);
  printf("enter the elements");
  for(i=1;i<=9;i++)
  {
    scanf("%d",&x);
    a[x]=1;
  }
  printf("enter the size of 2nd set");
  scanf("%d",&n);
  printf("enter the elements");
  for(i=1;i<=9;i++)
  {
    scanf("%d",&x);
    b[x]=1;
  }
  printf("1st set is\n\t{");
  for(i=1;i<=n;i++)
    printf("%d\t",a[i]);
  printf(" }");
  printf("\n 2nd set is\n\t{");
  for(i=1;i<=n;i++)
    printf("%d \t, ",b[i]);
  printf(" }");
}
void output(int c[])
{
  int i;
  printf("\n set is \n\t {" );
  for(i=1;i<=9;i++)
   if(c[i]!=0)
      printf("%d \t, ",i);
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
  for(i=1;i<=9;i++)
    printf("%d\t",c[i]);
  output(c);
}
void intersection()
{
   int i,c[10];
   for(i=0;i<=9;i++)
   {
     if(a[i]==b[i])
	c[i]=a[i];
     else
	c[i]=0;
   }
   for(i=1;i<=9;i++)
     printf("%d\t",c[i]);
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
  for(i=0;i<=9;i++)
    printf("%d\t",c[i]);
  output(c);
}