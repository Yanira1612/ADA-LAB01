#include <iostream>
#include<ctime>
using namespace std;
  
void insertionSort(int arr[], int n) 
{ 
    int i,key,j; 
    for (i=1;i<n;i++)
    { 
        key=arr[i]; 
        j=i-1; 
  
        while (j>=0&&arr[j]>key){ 
            arr[j+1]=arr[j]; 
            j=j-1; 
        } 
        arr[j+1]=key; 
    } 
} 
  
int main(){ 
    unsigned t0, t1;

    int n=100000;
    int i=0;
    int arr[n];

    FILE *file;
    file=fopen("numero.txt","r");
    
   for(int i=0;i<n;i++){
        fscanf(file,"%d",&arr[i]);
    }
    t0=clock();
    insertionSort(arr, n); 
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

  /*  for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout <<endl;
  */
    return 0; 
} 