#include<iostream>

#include<stdio.h>
#include<stdlib.h>
// #include <queue> 
#include<bits/stdc++.h>


using namespace std;

int **graph, *visited;
int verbose=0;
int i, nodes = 7, edges = 6;

void printMatrix( ){

   for(int i=0;i<nodes;i++)
      {
             for(int j=0;j<nodes;j++)
             {
                  printf("%4d,",graph[i][j] );
               
             }
             cout<<endl;
   
   }
}



void bfs(){
    




    cout<<"starting node :";
    int a;
    cin>>a;
    queue <int> g;
    g.push(a);
    cout<<"BFS : "<<endl;
    
    while (!g.empty()) 
    {   

        if (verbose)
        {
            cout<<"\n\n-->";
            for (int i = 0; i < nodes; ++i)
            {
                cout<<visited[i];
            }
        }

        //cout<<endl<<endl<<endl; 
        cout  <<endl<< g.front()<<","; 
        visited[g.front()] =1;
        for (unsigned int i = 0; i < nodes; i += 1)
        {   
            if(verbose)
            cout<< "scanning "<<i<<",";

            if( graph[g.front()][i]!=0 && visited[i] ==0 ){
            
            if(verbose)
            cout<<"\nadded "<<":"<<i<<endl;

            g.push(i);
            
                
            
            }
        }
        
        g.pop(); 
    }  
    
    cout<<"\n\nVISITED NODES : | :  ";
            for (int i = 0; i < nodes; ++i)
            {
                cout<<visited[i];
            }

            cout<<endl;
    


}


void dfs(int a){

    if(verbose)
    cout<<a<<",";
    visited[a] = 1;
    for (int i = 0; i < nodes; ++i)
    {
        if(graph[a][i]!=0 && visited[i] == 0){
            dfs(i);

        }
    }




}

void MarkConnections(int a, int b){

    if(verbose)
    cout<<a<<",";
    visited[a] = b;
    for (int i = 0; i < nodes; ++i)
    {
        if(graph[a][i]!=0 && visited[i] == 0){
            dfs(i);

        }
    }




}


int main(){
     
    cout<<"no of nodes : ";
    cin>>nodes;

    cout<<"no of edges : ";
    cin>>edges;
     
     graph = (int**) calloc(nodes, sizeof(int*));
     visited = (int*) calloc(nodes, sizeof(int));
     
     for (i = 0; i < nodes; i += 1)
     {graph[i] = (int*) calloc(nodes, sizeof(int));}
     
     printf("edges : ");
     for (i = 0; i < edges; i += 1)
     {
         int a,b;
         cin>>a>>b;
         
         graph[a][b] = 1;
         graph[b][a] = 1;
         
         
     }
     
     if(verbose)
     printMatrix( );
    

    // FOR BFS 
     bfs();


    //FOR DFS
    /*
    cout<<"starting node :";
    int a;
    cin>>a;
    verbose = 1;
    dfs(a); 
     */

    //FOR CONNECTIVITY
    /*int counter = 1;
     for (int i = 0; i < nodes; ++i)
     {
         if(visited[i] == 0){
            cout<< "\nConnected : ";
            MarkConnections(i,counter);
            
            counter++;
         }
     }
    */
    
     


}
