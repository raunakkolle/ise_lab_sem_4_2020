

#include<iostream>
#include<bits/stdc++.h>
// #include <vector>
// #include <set>
// #include <algorithm>
// #include <map>
// typedef long long ll;
// typedef vector<int> vi;
// typedef pair<int,int> pi;

#define N 5
using namespace std;

void printSolution(int board[N][N]) 
{ 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    } 
} 

bool isSafe(int board[N][N], int row, int col){
    for (int i = 0; i < N; ++i)
    {
        if(board[i][col]==1){return false;}
    }


    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j]==1){return false;}
    }

    for (int i = row, j = col; i >= 0 && j >= N; i--, j++)
    {
        if(board[i][j]==1){return false;}
    }
    return true;

}



bool solveNQUtil(int board[N][N], int row  ){

    //BASE CASE , if all rows are filled
    if(row >= N){
        return true;
    }



    for (int i = 0; i < N; ++i)
    {
        if(isSafe(board, row, i) ){
            board[row][i] = 1;
        
            if(solveNQUtil( board, row+1 )){
                return true;
            }

            board[row][i] = 0;
            
        }

            
    }
    
    return false;

}

bool solveNQ() 
{ 
    int board[N][N] = { { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 } }; 
  
    if (solveNQUtil(board, 0) == false) { 
        printf("Solution does not exist"); 
        return false; 
    } 
  
    printSolution(board); 
    return true; 
} 
  
// driver program to test above function 
int main() 
{ 
    solveNQ(); 
    return 0; 
} 




/*

STRUCTURE OF BACKTRACKING


def recursive( step ){
    
    BASE CONDITION (   ) {
        ...
    }
    
    if( boundingFunction() ){
        
        DO_SOMETHING
        if( recursive(nextstep) ){
            return True
        }
        
        UNDO_SOMETHING
        if( recursive(nextstep) ){
            return True
        }
    }


    return False


}




























*/