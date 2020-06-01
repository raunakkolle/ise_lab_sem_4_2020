// C++ program for implementation of Heap Sort 
#include <iostream> 
#include <vector>
#include <chrono>
#include <ctime>  
#include <math.h>  
using namespace std; 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 

    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 

    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 

        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
}

// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 

    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 

        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 

/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 

// Driver program 
void iter(int n) 
{ 
    
    int arr[n] ;

    for (int i = 0; i < n; ++i)
     {
         arr[i] = -i;
     } 


    auto start = std::chrono::system_clock::now();
    heapSort(arr, n); 
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    //cout << "Sorted array is \n"; 
    //printArray(arr, n); 

  cout<< "count "<<n<<",elapsed time: "<<elapsed_seconds.count() <<"\tnlog(n)= "<<n*log(n)<<"\tratio = "<<n*log(n)/( elapsed_seconds.count()*1000000)<<" \n";
} 


int main()
{   int a[] = {1024,2048,2048*2,2048*4,2048*8};

    for (int i = 0; i < 5; ++i)
    {
        iter(a[i]);
    }
    /* code */
    return 0;
}