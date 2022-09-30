#include <iostream>
#include<ctime>
using namespace std;

void swap(int *a, int *b){
  int t=*a;
  *a=*b;
  *b=t;
}

int partition(int array[], int low, int high){
  int pivot=array[high];
  int i =(low-1);

  for (int j=low;j<high; j++) {
    if (array[j]<=pivot) {
      i++;
      swap(&array[i],&array[j]);
    }
  }
  swap(&array[i+1], &array[high]);
  return (i+1);
}

void quickSort(int array[],int low,int high) {
  if (low<high) {
    int pi=partition(array,low,high);
    quickSort(array,low,pi-1);
    quickSort(array,pi+1,high);
  }
}

int main() {

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
    quickSort(arr,0,n-1);
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

 /*   for (int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
   */   
    return 0;
}