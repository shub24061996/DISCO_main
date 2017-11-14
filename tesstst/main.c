#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    int data;
    struct node *next;
} node;
int vis[100]= {0};
node *g[100];
void ins(int u,int v)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    p->data=v;
    p->next=NULL;
    if(g[u]==NULL)
    {
        g[u]=p;
    }
    else
    {
        node *t =g[u];
        while(t->next!=NULL)
        {
            t=t->next;

        }
        t->next=p;
    }
}
void dfs(int v)

{
    node *p= g[v];
    printf("%d",v);
    vis[v]=1;
    while(p)
    {
        if(!vis[p->data])
        {
            dfs[p->data];
        }
        p=p->next;
    }
}
int main()
{
    int count =0;
    int n,v,e,u;
    printf("number of vertices and edges");
    scanf("%d%d",&n,&v);
    int i ;
    for(i=0; i<e; i++)
    {
        scanf("%d%d",&u,&v);
    }
    for(i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            dfs[i];
            count++;
        }
    }
    printf("the count is %d",count);
    return 0 ;

}

