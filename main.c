#include <stdio.h>

int main()
{
	int a,b,c,i,j,n,x,y;
	scanf("%d%d",&a,&b);
	int q[a][a];
	for(i=0;i<a;i++)
	{
		for(j=0;j<a;j++)
	   {
	   	 q[i][j]=0;
	   }
	}

	 for(i=0;i<b;i++)
	 {
	 	scanf("%d%d",&x,&y);
	 	q[x][y]=1;
	 	q[y][x]=1;
	 }
	 int pres,fin;
	 scanf("%d%d",&pres,&fin);
	 int temp ;
	 if(pres>fin)
	 { temp=fin;
	 	fin=pres;
	 	pres=temp;
	 }
	 if(pres==fin)
	 {
	 	printf("Yes");
	 	return 0;
	 }
	 int flag=1;
	 for(i=pres;;)
	 {
	 	 if(q[i][i+1]!=1&&i+1<=fin)
	 	 {
	 	 	flag=0;
	 	 	break;
	 	 }
	 	 if(q[i][i+1]=1&&i+1==fin)
	 	 {
	 	 	printf("Yes");
	 	 	return 0;
	 	 }
	 	 i++;
	 }
	 if(flag==0)
	 {
	 	printf("No");
	 	return 0;
	 }
	 }

