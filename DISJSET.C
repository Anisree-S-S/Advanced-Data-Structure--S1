#include<stdio.h>
#include<conio.h>
struct DisjSet
{
  int parent[10];
  int rank[10];
  int n;
}dis;
void makeset()
{
  int i;
  for(i=0;i<dis.n;i++)
  {
     dis.parent[i]=i;
     dis.rank[i]=0;
  }
}
void displayset()
{
  int i;
  printf("\n parent array\n");
  for(i=0;i<dis.n;i++)
     printf("%d\t",dis.parent[i]);
  printf("\n rank array \n");
  for(i=0;i<dis.n;i++)
     printf("%d\t",dis.rank[i]);
  printf("\n");
}
int find(int x)
{
   if(dis.parent[x]!=x)
      dis.parent[x]=find(dis.parent[x]);
   return dis.parent[x];
}
void Union(int x,int y)
{
   int xset=find(x);
   int yset=find(y);
   if(xset==yset)
      return;
   if(dis.rank[xset]<dis.rank[yset])
   {
     dis.parent[xset]=yset;
     dis.rank[xset]=-1;
   }
   else if(dis.rank[xset]>dis.rank[yset])
   {
     dis.parent[yset]=xset;
     dis.parent[yset]=-1;
   }
   else
   {
     dis.parent[yset]=xset;
     dis.rank[xset]++;
     dis.rank[yset]=-1;
   }
}
int main()
{
  int n,x,y,ch;
  clrscr();
  printf("\n how many elements ?");
  scanf("%d",&dis.n);
  makeset();
  do
  {
    printf("\n menu\n");
    printf("\n\t1 union\n\t2 find\n\t3 display\n\t4 exit\nenter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("enter elements");
	     scanf("%d%d",&x,&y);
	     Union(x,y);
	     break;
      case 2:printf("enter elements to check if connected component");
	     scanf("%d%d",&x,&y);
	     if(find(x)==find(y))
	       printf("connected components");
	     else
	       printf("not connected components");
	     break;
      case 3:displayset();
	     break;
      case 4:exit(0);
      default:printf("invalide input");
    }
  }while(ch!=0);
  return 0;
}
