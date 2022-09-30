#include <iostream>
#include<ctime>
using namespace std;
 
void swap(int *xp,int *yp){
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
}
 
void selectionSort(int arr[], int n){
    int i,j,minimum;
 
    for (i = 0; i < n-1; i++){
        minimum = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[minimum])
            minimum = j;

        if(minimum!=i)
            swap(&arr[minimum],&arr[i]);
    }
}
 
int main()
{
    unsigned t0, t1;

    int n=1000;
    int i=0;
    int arr[n];

    FILE *file;
    file=fopen("numero.txt","r");
    
   for(int i=0;i<n;i++){
        fscanf(file,"%d",&arr[i]);
    }
    t0=clock();
    selectionSort(arr, n); 
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

   /* for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout <<endl;
    */
    return 0;
}