//Hello, this is a snippet.

#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>

// #include <vector>
// #include <set>
// #include <algorithm>
// #include <map>
// typedef long long ll;
// typedef vector<int> vi;
// typedef pair<int,int> pi;

using namespace std;

class graph
{
public:

    int **AdjMatrix, *visited, *weights;
    int *nodeProcessed, nodes , edges ;
    bool isDirected, isWeighted;
    vector<int> topologicalOrder; 
    vector<int> shortestDistances;
    int count = 0;

    graph(int a, int b){
        nodes = a;
        edges = b;


        AdjMatrix = (int**) calloc(nodes, sizeof(int*));
        visited = (int*) calloc(nodes, sizeof(int));
        weights = (int*) calloc(edges, sizeof(int));
        nodeProcessed = (int*) calloc(nodes, sizeof(int));

        for (int i = 0; i < nodes; i += 1)
            {AdjMatrix[i] = (int*) calloc(nodes, sizeof(int));}
     
        for (int i = 0; i < nodes; ++i)
        {
            shortestDistances.push_back(INT_MAX);
        }

        getEdges();
        printMatrix();
       // topological();
    };

    void getEdges(){

        cout<<"NODE : "<< nodes<<", EDGES : "<<edges<<endl;

        cout<<"Is Directed graph (1/0) : ";
        int k ;
        cin>>k;
        if(k){isDirected = true;}
        else{
            isDirected=false;
        }


        cout<<"Is weighted graph (1/0) : ";
        cin>>k;
        if(k){isWeighted= true;}
        else{
            isWeighted = false;
        }

        printf("enter Edge Pairs : \n");
        for (int i = 0; i < edges; i += 1)
        {   
            cout<<"edge "<<i<<" : ";
            int a,b;
            cin>>a>>b;
            
            if(isWeighted){
                cout<<"weight : ";

                cin>>k;
                if(isDirected){
                    AdjMatrix[a][b] = k;
                }
                else{
                    AdjMatrix[a][b] = k;
                    AdjMatrix[b][a] = k;
                }
            }
            else{
                if(isDirected){
                    AdjMatrix[a][b] = 1;
                }
                else{
                    AdjMatrix[a][b] = 1;
                    AdjMatrix[b][a] = 1;
                }
            }

            
            
        
         
         
        }


    }

    void printMatrix(){
        cout<<"\n\n Adjacency matrix : \n";
           for(int i=0;i<nodes;i++)
              {
                     for(int j=0;j<nodes;j++)
                     {
                          printf("%4d,",AdjMatrix[i][j] );
                       
                     }
                     cout<<endl;
           
           }
        }

    void topological(){
        int n = nodes;
        for (int i = 0; i < nodes; i += 1)
            {
                    if(visited[i] == 0){
                            
                            topological_dfs(i);
                            //cout<<i<<":";
                            topologicalOrder.insert(topologicalOrder.begin(),i);
                            
                    }
            }
            cout << "topological order is : "; 
            for (auto i = topologicalOrder.begin(); i != topologicalOrder.end(); ++i) 
                cout << *i << " ";         
     
    }

    // void dijkshtadfs(int startNode){
        
    //     //cout<<endl<<"dijkshta "<<startNode;

    //     nodeProcessed[startNode] = 1;
        
        

    //     for (int i = 0; i < nodes; ++i)
    //     { 
    //         cout<<endl<<startNode + 1<<"-->"<<i+1<<endl;
    //         for (int i = 0; i < nodes; ++i)
    //         {
    //             cout<<nodeProcessed[i];
    //         }
    //         if(AdjMatrix[startNode][i] != 0  ){
    //             cout<<"  .";
    //             shortestDistances[i] = min(shortestDistances[i],shortestDistances[startNode] + AdjMatrix[startNode][i] );
    //             //cout<<"\n updating "<<i << "from start "<<startNode<<":"<<shortestDistances[i]<<"|"<<shortestDistances[startNode]<<"|"<<AdjMatrix[startNode][i];
    //             if(nodeProcessed[i] == 0){
    //                 dijkshta(i);    
    //             }
                
    //         }
    //     }



    // }               
    
    void dijkshtaBfs(int startNode){
        
        //cout<<endl<<"dijkshta "<<startNode;

        queue<int> q;
        q.push(startNode);

        while(!q.empty()){
            visited[q.front()] = 1;
            for (int i = 0; i < nodes; ++i)
            {   
                //cout<<endl<<q.front()+1<<"-->"<<i+1;
                if(AdjMatrix[q.front()][i]!=0 && visited[i] ==0  ){
                    //cout<<"  |"<<shortestDistances[i]<<"|"<<shortestDistances[q.front()]<<"|"<< AdjMatrix[q.front()][i]<<"|"<<shortestDistances[q.front()] + AdjMatrix[q.front()][i] ;
                    shortestDistances[i] = min(shortestDistances[i],shortestDistances[q.front()] + AdjMatrix[q.front()][i] );
                    q.push(i);
                }
            }

            q.pop();
        }

    }               
    


    
    void topological_dfs(int v){

            count++;
            visited[v] = count;
            
            for (unsigned int i = 0; i < nodes; i += 1)
            {
                    if(AdjMatrix[v][i]==1 && visited[i]==0){
                            topological_dfs(i);
                            //cout<<i<<",";
                            topologicalOrder.insert(topologicalOrder.begin(),i);
                    }
            }

    }


    
};


using namespace std;

int main()
{   
    int nodes,edges;
    cout<<"nodes and edges :"; 
    cin>>nodes>>edges;
    graph g(nodes,edges);

    cout<<"enter starting node : ";
    int startNode;
    cin>>startNode;
 
    g.shortestDistances[startNode] = 0;

    g.dijkshtaBfs(startNode);


    cout << "\nshortestDistances is : "; 
            for (auto i = g.shortestDistances.begin(); i !=g.shortestDistances.end(); ++i) 
                cout << *i << " ";     


  //g.printMatrix();
    return 0;

};


