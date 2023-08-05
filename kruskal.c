#include<stdio.h>
int n,t[10][2],parent[10];
float cost[10][10];
void union_ij(int i,int j)
{
    if(i<j)
        parent[j]=i;
    else
        parent[i]=j;
}
int find(int v)
{
    while(parent[v]!=v)
    {
        v=parent[v];
    }
    return v;
}
void kruskal()
{
    int count=0,k=0,p,q,min,u,v;
    float sum=0;
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    while(count!=n-1)
    {
        min=999;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    u=i;
                    v=j;
                }
            }
        }
        p=find(u);
        q=find(v);
        if(p!=q)
        {
            t[k][0]=u;
            t[k][1]=v;
            k++;
            count++;
            sum=sum+cost[u][v];
            union_ij(p,q);
        }
        cost[u][v]=cost[v][u]=999;
    }
    printf("Spanning tree:");
    for(int i=0;i<n;i++)
        printf("%d->%d\n",t[i][0],t[i][1]);
    printf("Tree cost %f",sum);
}


void main()
{
    int m,u,v;
    float tot;
    float w;
    printf("Enter the no. of vertices: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                cost[i][j]=0;
            else
                cost[i][j]=999;
        }
    }
    printf("Enter no. of edges:");
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        printf("Enter edges and cost:");
        scanf("%d%d%f",&u,&v,&w);
        cost[u][v]=w;
        cost[v][u]=w;
    }
    kruskal();
}
