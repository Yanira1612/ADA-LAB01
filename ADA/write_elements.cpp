#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

int main() {
    string name = "numero.txt";
    int n=1000000;
    srand(time(NULL));
   
    ofstream archivo;
		archivo.open(name.c_str(), fstream::out);

        while(n--){
            archivo << 1 + rand() % (100 - 1)<<" ";
        }
		archivo.close();
}