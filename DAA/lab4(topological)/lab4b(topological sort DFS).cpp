#include<iostream>

#include<stdio.h>
#include<stdlib.h>
#include <queue> 

using namespace std;

int **graph, *visited, *indegree;
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


int count = 0;
void dfs(int v){

        count++;
        visited[v] = count;
        
        for (unsigned int i = 0; i < nodes; i += 1)
        {
                if(graph[v][i]==1 && visited[i]==0){
                        dfs(i);
                        cout<<i<<",";
                }
        }

}
void topological(){
        int n = nodes;
        for (int i = 0; i < nodes; i += 1)
        {
                if(visited[i] == 0){
                        
                        dfs(i);
                        cout<<i<<":";
                        
                        
                }
        }
    
        for (unsigned int i = 0; i < nodes; i += 1)
        {
                cout<<visited[i]<<"+";
        }
}




int main(){
     
     cout<<"nodes and edges :";
     cin>>nodes>>edges;
     
     
     graph = (int**) calloc(nodes, sizeof(int*));
     //visited = (int*) calloc(nodes, sizeof(int));
     indegree = (int*) calloc(nodes, sizeof(int));
     visited = (int*) calloc(nodes, sizeof(int));
     
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




