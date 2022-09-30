#include <iostream>
#include<fstream>
#include<ctime>
using namespace std;

void heapify(int arr[], int N, int i){
 
    int largest = i;
 
    int l=2*i+1; // izquierda
    int r=2*i+2; // derecha
 
    if (l < N && arr[l] > arr[largest]) // Si el hijo izquierdo es mayor a la raiz
        largest = l;
 
    if (r < N && arr[r] > arr[largest]) //Si el hijo derecho es mayor al mas grande
        largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}
 
void heapSort(int arr[], int N){
 
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
 
int main(){
    unsigned t0, t1;

    int n=1000000;
    int arr[n];

    FILE *file;
    file = fopen("numero.txt","r");
    
   for (int i = 0; i < n; i++){
        fscanf(file, "%d", &arr[i]);
    }
    
    t0=clock();
    heapSort(arr, n);
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

/*
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout <<endl;
*/

}