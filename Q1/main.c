#include <stdio.h>
#include <stdlib.h>

void print(int a[],int n)//for printing the array
{
    int i ;
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}
int findpath(int matrix[100][100],int path[100],int n,int currentlength)
{
    int i ,response ;
    if(currentlength==n)
    {
        if(matrix[path[currentlength-1]][0]==1)//is the last vertex connected to 0 since we have to come back to 0
            return 1;
        else
            return 0;//not connected to 0
    }
    for(i=0;i<n;i++)
    {
        if(matrix[path[currentlength-1]][i]==0||matrix[i][n]==1)//if this is not connected to the the previous vertex or it has already been traversed,then continue
        {
            continue;
        }
        path[currentlength]=i;//this is what we are printing
        matrix[i][n]=1;//traverses
            response=findpath(matrix,path,n,currentlength+1);//increasing the  length by 1
            if(response==1)
            {
                return 1;
            }
            else
            {
                path[currentlength]=0;//we will not include this vertex
                matrix[i][n]=0;//not traversed

            }
    }
}
int main()
{
    int n,m,i,j;
    scanf("%d",&n);
    scanf("%d",&m);
    int matrix[100][100],path[100];
    for(i=0;i<n+1;i++)
    {
        path[i]=0;//initialising the path to 0
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
            matrix[i][j]=0;
        }
    }
    for(i=0;i<m;i++)
    {
        int n1,n2;
        scanf("%d%d",&n1,&n2);
        matrix[n1][n2]=1;
        matrix[n2][n1]=1;

    }
    matrix[0][n]=1;
    findpath(matrix,path,n,1);//finding the path
    print(path,n+1);//n+1 since we want 0 to be printed again in the end
    return 0;

}
