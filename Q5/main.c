#include<stdio.h>
#include<math.h>

int main()
{
    int n,m,i,j,w,k,x,y;
    int jValue;
    int min;
    scanf("%d %d",&n,&m);
    int arr[m][3];//this is an extra array for accessing the information
    int adj[n][n];
    int visited[n];
    int minimum = 1000;
    int weight[n];
    for(i=0;i<n;i++)
    {
        visited[i] = 0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            adj[i][j] = 0;
        }
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&x,&y,&w);
        adj[x][y] = w;
        adj[y][x] = w;
        arr[i][0] = x;
        arr[i][1] = y;
        arr[i][2] = w;

    }
    for(i=0;i<n;i++)
    {
        if(arr[i][2]<minimum)
        {
            minimum = arr[i][2];//finding the minimum weight
        }
    }
    printf("%d\n",minimum);
    int r,rValue;
    scanf("%d",&r);
    int rMatrix[r];
    for(i=0;i<r;i++)
    {
        scanf("%d",&rValue);
        rMatrix[i] = rValue;
        //arr[rValue][2] = minimum-1;
        adj[arr[rValue][0]][arr[rValue][1]] = minimum;//making the required edge weight minimum
        adj[arr[rValue][1]][arr[rValue][0]] = minimum;

    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%lld ",adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    int start = 0;//starting from this vertex
    visited[start] = 1;//STARTING FROM HERE
    int prod = 0;
    int kValue;
    for(i=0;i<n-1;i++)//this loop to capture one vertex at a time
    {        //n-1
        min = 1000;
        for(k=0;k<n;k++)//this is to traverse down through rows to checkg  if they are visited
        {
            if(visited[k]==1)
            {
                for(j=0;j<n;j++)//this loop to traverse through row of adjoint matrix
                {
                     if(j!=k && visited[j]==0)
                    {      if(adj[k][j]<min && adj[k][j]!=0)
                        {
                            //printf("%d %d\n",k,j);
                            min = adj[k][j];
                            jValue = j;
                            kValue = k;
                        }
                    }
                }
            }
        }
        printf("%d %d\n",kValue,jValue);
        prod = prod + adj[kValue][jValue];
        adj[kValue][jValue] = 10000;//so that it doesnt interfere with min operation
        adj[jValue][kValue] = 10000;
        visited[jValue] = 1;
    }
    for(i=0;i<r;i++)
    {
        prod = prod + arr[rMatrix[i]][2] - minimum;//since we had reduced the weights

    }
    printf("%d\n",prod);
}
