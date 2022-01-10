#include<stdio.h>
#include<conio.h>
void main()
{
 int a1[20],a2[20],a3[40],m,n,i,j,k=0;
 clrscr();
 printf("enter the size of array 1: ");
 scanf("%d",&m);
 printf("enter the elements");
 for(i=0;i<m;i++)
  scanf("%d",&a1[i]);
 printf("enter the size of array2 : ");
 scanf("%d",&n);
 printf("enter the elements of array2 ");
 for(i=0;i<n;i++)
  scanf("%d",&a2[i]);
 i=0;
 j=0;
 while(i<m&&j<n)
 {
  if(a1[i]<a2[j])
  {
   a3[k]=a1[i];
   i++;
  }
  else
  {
   a3[k]=a2[j];
   j++;
  }
  k++;
 }
 if(i>=m)
  while(j<n)
  {
   a3[k]=a2[j];
   j++;
   k++;
  }
 if(j>=n)
  while(i<m)
  {
   a3[k]=a1[i];
   i++;
   k++;
  }
 printf("\n after merging\n");
 for(i=0;i<n+m;i++)
  printf("%d\t",a3[i]);
 getch();
}