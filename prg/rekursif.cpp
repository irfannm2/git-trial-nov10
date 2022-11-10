#include <iostream>
using namespace std;

//faktorial dengan perulangan
int faktorial1(int a){
    int hasil=1;
    for(int i=1; i<=a; i++){
        hasil*=i;
    }
    return hasil;
}

//faktorial dengan rekursif
int faktorial2(int a){
    if(a==1){
        return 1;
    } else if(a>1) {
        return a*faktorial2(a-1);
    } else return 0;
}

//fibonacci dengan rekursif
int fibo1(int a){
    if(a==1 || a==2){
        return 1;
    } else {
        return fibo1(a-1)+fibo1(a-2);
    } 
}

//fibonacci dengan array (dynamic programming)
int fibo2(int a){
    int arr[a];
    a=a-1;
    if(a<2){
        return 1;
    }
    arr[0]=1; arr[1]=1;
    for(int i=2; i<=a; i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[a];
}

//fungsi utama/ main
int main(){
    int x=10;  //ubah variabel x disini, bilangan yg dicari
    cout<<fibo2(x);  //ubah fungsi disini, sesuai keperluan
    return 0;
}
