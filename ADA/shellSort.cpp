#include  <iostream>
#include<ctime>

using namespace std;
  
int shellSort(int arr[], int n){

    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i += 1){
            int temp = arr[i];
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
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
    shellSort(arr, n);
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
/*
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout <<endl;
  */    
    return 0;
}