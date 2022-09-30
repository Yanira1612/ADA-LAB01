#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

void bubbleSort(int arr[],int n){
    int i, j, temp;
    for(i=0; i<n; i++)
    {
        for(j=0; j<(n-i); j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){

    unsigned t0, t1;

    int n=1000000;
    int i=0;
    int arr[n];

    FILE *file;
    file = fopen("numero.txt","r");
    
   for (int i = 0; i < n; i++){
        fscanf(file, "%d", &arr[i]);
    }
   t0=clock();
    bubbleSort(arr,n);
   t1 = clock();
   double time = (double(t1-t0)/CLOCKS_PER_SEC);
   cout << "Execution Time: " << time << endl;

/*
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
*/


    return 0;
}

