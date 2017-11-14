#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
int main()
{
    int a,b,c,i,j;
    cin>>a>>b;
    int m1,m2;
    j=b;
    m2=((a-(b-1))*(a-(b-1)-1))/2;

int cou =0;
if(b==a-1)
{

    m1=1;

    cout<<m1<<" "<<m2;
    return 0;
}
else if(a==b)
{

m1=0;
cout<<m1<<" "<<m2;
return 0;
}
else if(b==1)
{
    cout<<m2<<" "<<m2;
    return 0;
}
else
{
    if()

    c=a/b;
    while(c>=1)
    {
    if(c>=1&&a-2>=b-1)
    cou++;
    if(a-2<b)
        break;


    a=a-2;
    b--;
    c=a/b;
    }







        cout<<cou<<" "<<m2;
        return 0;


}

}
*/

int a,b,u,v,n,i,j,ne=1;
int visited[10]= {0},mi,mincost=0,cost[10][10];
int  main()
{

   // printf("n Enter the number of nodes:");
    scanf("%d",&n);
   // printf("n Enter the adjacency matrix:n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    visited[1]=1;
    printf("n");
    while(ne<n)
    {
        for(i=1,mi=999; i<=n; i++)
            for(j=1; j<=n; j++)
                if(cost[i][j]<mi)
                    if(visited[i]!=0)
                    {
                        mi=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
        if(visited[u]==0 || visited[v]==0)
        {
            //printf("n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
            mincost+=mi;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("n Minimun cost=%d",mincost);

}
