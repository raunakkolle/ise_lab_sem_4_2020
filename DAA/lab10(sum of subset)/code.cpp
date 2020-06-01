//Hello, this is a snippet.

#include<iostream>
#include<bits/stdc++.h>
// #include <vector>
// #include <set>
// #include <algorithm>
// #include <map>
// typedef long long ll;
// typedef vector<int> vi;
// typedef pair<int,int> pi;


using namespace std;

bool findSum(int A[], int B[], int n , int total, int index, int sum){
    cout<<"index "<<index<<"\tsum "<<sum<< "\t : ";
    for (int i = 0; i < 6; ++i)
        {
            cout<<B[i]<<",";
        }
        cout<<endl;
    if(index >= n){
        return false;
    }

    if(sum == total){
        return true;
    }

    if(sum + A[index] <= total ){
        sum+= A[index];
        B[index] = 1;

        if(findSum(A,B,n,total,index+1,sum)){
            return true;
        }
         cout<<"backtracking\n";
        sum -= A[index];
        B[index] = 0;
        if(findSum(A,B,n,total,index+1,sum)){
            return true;
        }


    }

    return false;






}
int main()
{
    //int n ;
    // std::vector<int> v;
    // for (int i = 0; i < n; ++i)
    // {
    //     int k;
    //     cin>>k;

    // }
    int A[] = {5,10,12,13,15,18};
    int B[] = {0,0,0,0,0,0};
    int total = 30;
    cout<<"Total :" <<total<<endl;
    
    for (int i = 0; i < 6; ++i)
        {
            cout<<A[i]<<",";
        }
        cout<<endl;


    if(findSum(A,B,6,total,0,0)){
        for (int i = 0; i < 6; ++i)
        {
            cout<<B[i]<<",";
        }
    }
    else{
        cout<<"NOT POSSIBLE";
    }

    return 0;
    
};
