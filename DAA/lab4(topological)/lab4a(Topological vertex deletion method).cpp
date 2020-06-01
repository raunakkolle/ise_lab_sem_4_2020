#include<iostream>

#include<stdio.h>
#include<stdlib.h>
#include <queue> 

using namespace std;

int **graph, *dead, *indegree;
int nodeProcessed, nodes = 7, edges = 6;

void printMatrix( ){
cout<<"\n\n Adjacency matrix : \n";
   for(int i=0;i<nodes;i++)
      {
             for(int j=0;j<nodes;j++)
             {
                  printf("%4d,",graph[i][j] );
               
             }
             cout<<endl;
   
   }
}

int calculateIndegree(){
    for (unsigned int i = 0; i < nodes; i += 1)
    {
        indegree[i] = 0;
        for (unsigned int j = 0; j < nodes; j += 1)
        {   
            //cout<<i<<" "<<j<<" "<<graph[i][j]<<endl;
            //fflush(stdout);
            if(graph[j][i] == 1){
                indegree[i]++;
            }
        }
    }
     
     //cout<<"\n Indegree :";
    // for (unsigned int i = 0; i < nodes; i += 1)
    // {  // cout<<indegree[i]<<" ";
         
    // }
    // cout<<endl;
    
    for (unsigned int i = 0; i < nodes; i += 1)
    {   //cout<<i<<" "<<indegree[i]<<endl;
        if(indegree[i]==0 && dead[i]!=1){
            return i;
        }
    }
    return 0;
}

void topological(){
    
    if(nodeProcessed == nodes){return;}
    
    int x = calculateIndegree();
    cout<<x<<endl;
    for (unsigned int i = 0; i < nodes; i += 1)
    {
        //cout<<i<<" ";
        graph[x][i] = 0;
       
    }
    dead[x] =1;
     nodeProcessed++;
    topological();
    
    

}


int main(){
     
     cout<<"nodes and edges :";
     cin>>nodes>>edges;
     
     
     graph = (int**) calloc(nodes, sizeof(int*));
     //visited = (int*) calloc(nodes, sizeof(int));
     indegree = (int*) calloc(nodes, sizeof(int));
     dead = (int*) calloc(nodes, sizeof(int));
     
     for (int i = 0; i < nodes; i += 1)
     {graph[i] = (int*) calloc(nodes, sizeof(int));}
     
     printf("edges : ");
     for (int i = 0; i < edges; i += 1)
     {
         int a,b;
         cin>>a>>b;
         
         graph[a][b] = 1;
        
         
         
     }
     
     printMatrix( );
      
     topological();
     //calculateIndegree();
     
     
     
     


}
