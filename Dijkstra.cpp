#include<iostream>
#include<stdio.h>
#define INFINITY 9999
#define max 5
using namespace std;

void dij(int G[max][max],int n,int start){
    int cost[max][max],dist[max],pred[max],vis[max],count,mindis,next,i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];

    for(i=0;i<n;i++){
        dist[i]=cost[start][i];
        pred[i]=start;
        vis[i]=0;
    }

    dist[start]=0;
    vis[start]=1;
    count=1;

    while(count<n-1){
        mindis=INFINITY;
    for(i=0;i<n;i++)
        if(dist[i]<mindis && !vis[i]){
            mindis=dist[i];
            next=i;
        }

    vis[next]=1;

    for(i=0;i<n;i++)
        if(!vis[i])
            if(mindis + cost[next][i] < dist[i]){
            dist[i]=mindis + cost[next][i];
            pred[i]=next;
        }
    count++;
    }
    for(i=0;i<n;i++)
        if(i!=start){
            cout<<"\n\nThe Distance of node "<<i<<" : "<<dist[i];
            cout<<"\nPath: "<<i;
            j=i;

            do{
                j=pred[j];
                cout<<" <- "<<j;
            }while(j!=start);
        }
}
int main(){
    int G[max][max]={{0,1,0,3,10},{1,0,5,0,0},{0,5,0,2,1},{3,0,2,0,6},{10,0,1,6,0}};
    int n=5,u=0;
    
    dij(G,n,u);

    return 0;
}