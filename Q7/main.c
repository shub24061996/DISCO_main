#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int N=1e3;

int n, k,i, sz=1, connected, ans=0;
int x[1000], y[1000], a[1000000], root[1000], size[1000], pt1[1000000], pt2[1000000];

void init()
{
	for(i=1;i<=n;i++)
	{
		root[i]=i;//this root is basically to group all the values together
		size[i]=1;
	}
}

int dist(int i, int j)
{
	int ans=(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
	return ans;
}

int rt(int k)
{
	while(k!=root[k])
	{
		root[k]=root[root[k]];//this is the root function to get the root values
		k=root[k];
	}
	return k;
}

void union1(int u, int v)
{
	int rt1=rt(u);
	int rt2=rt(v);
	if(size[rt1]>=size[rt2])//of the size of the first is greater than the second then we will add second to the first
	{
		size[rt1]+=size[rt2];
		size[rt2]=0;
		root[rt2]=root[rt1];
	}
	else
	{
		size[rt2]+=size[rt1];//opposite
		size[rt1]=0;
		root[rt1]=root[rt2];
	}
}

int main()
{
   scanf("%d",&n);

   	init();
   	for( i=1;i<=n;i++)
   	{
   		scanf("%d%d",&x[i],&y[i]);
   	}
   	int j;
   	connected=n;
   	scanf("%d",&k);
   	for( i=1;i<=n;i++)
   	{
   		for( j=i+1;j<=n;j++)
   		{
   			a[sz]=dist(i, j);//storing the distances
   			pt1[sz]=i;//storing the points
   			pt2[sz]=j;
   			sz++;//counter
   		}
   	}
   	sz--;
   	for( i=1;i<=sz;i++)
   	{
   		for( j=1;j<=sz;j++)
   		{
   			if(a[i]<a[j])
   			{//sort descending
   				int temp=a[i];
   				a[i]=a[j];
   				a[j]=temp;
   				temp=pt1[i];
   				pt1[i]=pt1[j];
   				pt1[j]=temp;
   				temp=pt2[i];
   				pt2[i]=pt2[j];
   				pt2[j]=temp;
   			}
   		}
   	}
   	for(i=1;i<=sz;i++)
   	{
   		if(rt(pt1[i])==rt(pt2[i]))//same root ,it means that they are already grouped
   			continue;
   		connected--;
   		union1(pt1[i], pt2[i]);//grouping together
   		ans+=a[i];
   		if(connected==k)//achieved
   			break;
   	}
   	for( i=1;i<=n;i++)
   	{
   		int check=0;
   		for( j=1;j<=n;j++)
   		{
   			if(rt(j)==i)
   			{
   				check=1;
   				printf("%d",j-1);//same roots then print the values
   			}
   		}
   		if(check)
   			printf("\n");
   	}
    return 0;
}
