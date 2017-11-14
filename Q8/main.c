#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a,b,v,u,n,i,j,n,ne=1;
int visited[10]= {0},min,mincost=1,cost[10][10];
int main()
{
    int e;
    scanf("%d",&n);
    scanf("%d",&e);
    int c;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cost[i][j]=999;
        }
    }
    for(i=0; i<e; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        cost[a][b]=c;
        cost[b][a]=c;

    }
    visited[1]=1;
    while(ne<n)
    {
        for(i=1,min=999; i<=n; i++)
        {


            for(j=1; j<=n; j++)
            {


                if(log(cost[i][j])<log(min))//since we are considering the products
                {




                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }

        if(visited[u]==0||visited[v]==0)
        {
            ne++;
            mincost*=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;//so that it is not included again
    }
    printf("minimum cost is %d",mincost);

}



