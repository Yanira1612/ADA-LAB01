#include <iostream>
#include<ctime>
using namespace std;

void merge(int arr[], int p, int q, int r){
  
  int num1=q-p+1;
  int num2=r-q;

  int L[num1], M[num2];

  for (int i=0;i<num1;i++)
    L[i]=arr[p+i];
  for (int j=0;j<num2;j++)
    M[j]=arr[q+1+j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while(i<num1&&j<num2){
    if (L[i]<=M[j]){
      arr[k]=L[i];
      i++;
    } 
    else{
      arr[k]=M[j];
      j++;
    }
    k++;
  }

  while(i<num1){
    arr[k]=L[i];
    i++;
    k++;
  }

  while(j<num2){
    arr[k]=M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[],int l,int r) {
  if (l<r){
    int m=l+(r-l)/2;

    mergeSort(arr,l,m);
    mergeSort(arr,m + 1,r);
    merge(arr, l, m, r);
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
    mergeSort(arr,0,n-1);
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

/*
    for (int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
      */

    return 0;

}