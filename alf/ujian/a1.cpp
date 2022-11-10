#include<iostream>
using namespace std;

int main(){
    int A[2, 1]; //A[2,1] karena index matriks mulai dari 0
    int B[1, 2]; //karena index matriks mulai dari 0

    //input matriks A
    for(int i = 0; i<3; i++){
        for(int j = 0; j<2; j++)
            cin>>A[i,j];
    };

    //input matriks B
    for(int i = 0; i<2; i++){
        for(int j = 0; j<3; j++)
            cin>>B[i,j];
    };

    //proses perkalian
    int C[2, 2];
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++)
            C[i,j]=A[i,j]*B[i,j] + A[i+1,j]*B[i,j+1];
    };

    //output perkalian diatas
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++)
            cin>>C[i,j];
    };

    return 0;
}