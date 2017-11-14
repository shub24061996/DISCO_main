#include <stdio.h>
#include <math.h>

int main()
{
    int a,c,i,j,b,n;
    scanf("%d%d",&a,&b);
    int q[a];
    for(i=0; i<a; i++)
    {
        q[i]=0;
    }
    int x,y;
    for(i=0; i<b; i++)
    {
        scanf("%d%d",&x,&y);
        q[x]++;
        q[y]++;
    }
    int counteven =0,countodd=0;
    for(i=0; i<a; i++)
    {
        if(q[i]%2==1)
        {
            countodd++;
        }
        else
        {
            counteven++;
        }
    }
    if(counteven==a||countodd==2)//since euler circuit is there ,then euler path is also there
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}
