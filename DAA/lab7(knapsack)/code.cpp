// Here is the top-down approach of dynamic programming 
// to solve the question, it's a c++ implementation 
#include <bits/stdc++.h> 
using namespace std; 

/* Returns the value of maximum profit */
int knapSackRec(int W, int wt[], int val[], int i, int** dp) 
{ 
    // base condition 
    if (i < 0) 
        return 0; 
    if (dp[i][W] != -1) 
        return dp[i][W]; 

    if (wt[i] > W) { 

        // store the value of function call stack in 
        // table before return 
        dp[i][W] = knapSackRec(W, wt, val, i - 1, dp); 
        return dp[i][W]; 
    } 
    else { 

        // store value in a table before return 
        dp[i][W] = max(val[i] + knapSackRec(W - wt[i], wt, val, i - 1, dp), 
                    knapSackRec(W, wt, val, i - 1, dp)); 

        // return value of table after storing 
        return dp[i][W]; 
    } 
} 

int knapSack(int W, int wt[], int val[], int n) 
{ 
    int** dp; // double pointer to declare the table dynamically 
    dp = new int*[n]; 

    // loop to create the table dynamically 
    for (int i = 0; i < n; i++) 
        dp[i] = new int[W + 1];  

    // loop to initially filled the table with -1 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < W + 1; j++) 
            dp[i][j] = -1; 
    return knapSackRec(W, wt, val, n-1, dp); 
} 

int main() 
{   

    int val[] = { 10, 20, 30 }; 
    int wt[] = { 1, 2, 3 }; 
    int W = 6; 
    int n = sizeof(val) / sizeof(val[0]);
    
    cout<<"val :";
    for (int i = 0; i < n; ++i)
     {
         cout<< val[i]<<", ";

     } 
     cout<<endl;
    cout<<"wt :";

     for (int i = 0; i < n; ++i)
     {
         cout<< wt[i]<<", ";

     } 
     cout<<endl;
    cout<<"Answer : " << knapSack(W, wt, val, n)<< endl; 
    return 0; 
} 
