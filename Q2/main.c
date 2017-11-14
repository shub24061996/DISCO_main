#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
int vis[100]={0};
node *g[100];//array of pointers,points to a node,array of n heads basically
//if 1 is connected to 2 we will add it to the list of 1
void ins(int u,int v)
{
    node *p ;
    p=(node*)malloc(sizeof(node));//typecasting it to the node pointer
    p->data=v ;//this stores the value of the data and the vlaue of the pointer is null
    p->next=NULL;
    if(g[u]==NULL)//p is a node and we are adding this node whose data value is added to the adjacency list of

        g[u]=p;
    else
    {
        node *t=g[u];//decalration statemnet ,it initialises it to the first value of the lonked list
        while(t->next!=NULL)//we want to stop when the last element is reached ,that is the t->next value becomes null
        {
            t=t->next;//we are adding it to the last of the linked list
        }
        t->next=p;//we are making a swap for the vlaues and the data will be stored in the end
    }
}

void dfs(int v)
{
    node *p= g[v];//gets the head of the adjacency list of v
    printf("%d",v );
    vis[v]=1;//visited v
    while(p)
    {
        if(!vis[p->data])//if we haven't marked the
        {
            dfs(p->data);//calling the dfs on the unvisted node
        }
        p=p->next;

    }
}
int main()
{
    int count =0;
    int n,e,u,v;
    printf("number of vertices");
    scanf("%d",&n);//nodes
    scanf("%d",&e);
    int i;
    for(i=0 ; i <e; i++)
    {
        scanf("%d%d",&u,&v);
        ins(v,u);//since this is an undirected graph we will have to add them
        //symmetrically and hence u,v and v,u both are being added to the adjacency list
        ins(u,v);

    }
    for( i=0; i<n; i++)
    {
        if(vis[i]==0)
        {

            dfs(i);
            count++;//this can be used for calculating the total nuber of connected components in  agraph as it will continue along the connected component
        }
//the number of times the dfs funcion is called isbasically the number of connected components
//maintain a count here
    }
    printf("count is %d",count);

}

