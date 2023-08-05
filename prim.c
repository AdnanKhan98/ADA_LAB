#include<stdio.h>
int vt[10],vis[10],n,et[10][2],e=0;
float cost[10][10];
float Prims()
{
    int x=1,min,j,k,m,u,v;
    float sum=0;
    vt[x]=1;
    vis[x]=1;
    for(int i=1;i<n;i++)
    {
        j=x;
        min=999;
        while(j>0)
        {
            k=vt[j];
            for(m=2;m<=n;m++)
            {
                if(cost[k][m]<min && vis[m]==0)
                {
                    min=cost[k][m];
                    u=k;
                    v=m;
                }
            }
            j--;
        }
        vt[++x]=v;
        et[i][0]=u;
        et[i][1]=v;
        e++;
        vis[v]=1;
        sum=sum+cost[u][v];
    }
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
    for(int i=1;i<=n;i++)
    {
        vt[i]=0;
        vis[i]=0;
    }
    tot=Prims();
    printf("Total cost:%f\n",tot);

}
