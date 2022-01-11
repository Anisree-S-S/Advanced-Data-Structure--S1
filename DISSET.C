#include<stdio.h>
#include<conio.h>
struct Disjset
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
void display()
{
   int i;
   printf("\n parent array is\n{");
   for(i=0;i<dis.n;i++)
     printf("%d\t",dis.parent[i]);
   printf("}\nrank array is\n{");
   for(i=0;i<dis.n;i++)
     printf("%d\t",dis.rank[i]);
   printf("}\n");
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
     dis.rank[yset]=-1;
  }
  else
  {
     dis.parent[yset]=xset;
     dis.rank[xset]=dis.rank[xset]+1;
     dis.rank[yset]=-1;
  }
}
int main()
{
  int n,x,y,ch;
  clrscr();
  printf("\nHow many elements");
  scanf("%d",&dis.n);
  makeset();
  do
  {
     printf("\n\nSelect your choice");
     printf("\n\t1 Union\n\t2 Find\n\t3 Display\n\t4 Exit\n");
     scanf("%d",&ch);
     switch(ch)
     {
	case 1:printf("enter elements to perform union");
	       scanf("%d%d",&x,&y);
	       Union(x,y);
	       break;
	case 2:printf("enter elements to check if connected components");
	       scanf("%d%d",&x,&y);
	       if(find(x)==find(y))
		  printf("connected components");
	       else
		  printf("not connected components");
	       break;
	case 3:display();
	       break;
	case 4:exit(0);
	default:printf("Invalidinput");
     }
  }while(ch!=5);
  return 0;
}

