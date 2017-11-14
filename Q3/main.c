#include <stdio.h>
#include <stdlib.h>

void copy(float a[],float b[],int n)//this is for copying the current probability to the previous probability
{
    int i;
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
}
int degree(int a,int *graph,int n)//calculating the degree of the vertex
{
    int i ;
    int deg=0;
    for(i=0;i<n;i++)
    {
        if(*(graph+a*n+i)==1)//passing a 2d array
        {
            deg++;
        }
    }
    return deg ;
}
int edge(int a,int b,int *graph,int n)
{
    if(*(graph+a*n+b)==1)//edge condition
        return 1;
    else
        return 0;
}
float probabilityjtoi(int a,int b,int *graph,int n)
{
    float result ;
    if(degree(a,graph,n)==0)
    {
        result=(float)1/n;//cannot go anywhere
    }
    else if(degree(a,graph,n)!=0&&(!edge(a,b,graph,n)))//no edge from j to i
    {
        result= 0;
    }
    else if(degree(a,graph,n)!=0&&edge(a,b,graph,n))//edge is there ,then 1/degree is the probability
    {
        result=(float)1/degree(a,graph,n);
    }
    return result;
}
float findprobability(float prevprobability[],int i,int *graph,int n)
{
    int j;
    float result= 0;
    for(j=0;j<n;j++)
    {
        result=result+prevprobability[j]*probabilityjtoi(j,i,graph,n);
    }
    return result;

}
int main()
{
    int n;
    scanf("%d",&n);
    int graph[n][n];
    int i,j;
    float prevprobability[n];
    for(i=0;i<n;i++)
    {
        prevprobability[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }
    prevprobability[0]=1;
    int m;
    scanf("%d",&m);
    int a,b;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        graph[a][b]=1;
    }
    float currentprobability[n];
    for(j=1;j<1000;j++)
    {
        for(i=0;i<n;i++)
        {
            currentprobability[i]=findprobability(prevprobability,i,(int *)graph, n);

        }
        copy(currentprobability,prevprobability,n);
    }
    for(i=0;i<n;i++)
    {
        printf("%f\n",currentprobability[i]);
    }
    return 0;
}
