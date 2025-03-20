#include <iostream>
using namespace std;

int** createMtx(int size){
    int** mtx= new int*[size];
    for(int i=0; i<size; i++){
        mtx[i] = new int[size];
    }
    int val=1;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            mtx[i][j]=val;
            val+=1;
        }
    }
    return mtx;
}
void printMtx(int** mtx, int size){
    for(int i=(size*size)-1; i>=0; i--){
        int row = (i / size);
        int col = (i % size);
        cout<<"M["<<row<<"]["<<col<<"] = "<<mtx[row][col]<<endl;
    }
}

int main(){
    int size;
    cout<<"Indice el tamaño de su matriz cuadrada: ";
    cin>>size;
    int** mtx = createMtx(size);
    printMtx(mtx,size);

    for(int i=0; i<size; i++) delete[] mtx[i];
    delete[] mtx;
    return 0;
}