#include<iostream>
using namespace std;

int main(){
    cout<<"Program untuk menentukan siapa yang ulang tahun terlebih dulu"<<endl;
    
    struct tKawan{
        string panggilan;
        int tanggal;
        string bulan;
    };
    tKawan kawan[5];
    
    cout<<"Masukan nama kawan, tanggal, dan bulan lahir, lakukan 5 kali"<<endl;
    /* contoh masukan :
    Adi 3 Juni
    Budi 21 April
    Cahya 30 Desember
    Dani 16 April
    Eko 20 September
    */
    
    for(int i=0;i<5;i++){
        cin>>kawan[i].panggilan;
        cin>>kawan[i].tanggal;
        cin>>kawan[i].bulan;
    }

    int temp, temp2=12, temp3=31;
    string awal;
    for(int i=0;i<5;i++){
        if(kawan[i].bulan=="Januari"){
            temp=1;
        } else if(kawan[i].bulan=="Februari"){
            temp=2;
        } else if(kawan[i].bulan=="Maret"){
            temp=3;
        } else if(kawan[i].bulan=="April"){
            temp=4;
        } else if(kawan[i].bulan=="Mei"){
            temp=5;
        } else if(kawan[i].bulan=="Juni"){
            temp=6;
        } else if(kawan[i].bulan=="Juli"){
            temp=7;
        } else if(kawan[i].bulan=="Agustus"){
            temp=8;
        } else if(kawan[i].bulan=="September"){
            temp=9;
        } else if(kawan[i].bulan=="Oktober"){
            temp=10;
        } else if(kawan[i].bulan=="November"){
            temp=11;
        } else if(kawan[i].bulan=="Desember"){
            temp=12;
        } else{
            cout<<"Nama bulan lahir "<<kawan[i].panggilan<<" salah."<<endl;
            cout<<"Periksa ejaan nama bulan! (huruf pertama kapital)"<<endl;
            temp=13;
        }

        if(temp2>temp){
            temp2=temp;
            temp3=kawan[i].tanggal;
            awal=kawan[i].panggilan;
        } else if(temp2==temp){
            if(temp3>kawan[i].tanggal){
                temp3=kawan[i].tanggal;
                awal=kawan[i].panggilan;
            }
        }
        
    }
    
    cout<<"Orang yang pertama kali ulang tahun adalah: ";
    cout<<awal;
    
    //dalam kasus ada yang ulang tahunnya sama :
    string bulanb;
    int tanggalb;
    for(int i=0;i<5;i++){
        if(kawan[i].panggilan==awal){
            bulanb=kawan[i].bulan;
            tanggalb=kawan[i].tanggal;
            for(int j=0;j<5;j++){
                if(j==i) continue;
                if((kawan[j].bulan==bulanb)&(kawan[j].tanggal==tanggalb)){
                    cout<<" dan "<<kawan[j].panggilan;
                }
            }
        }
    }
    /* contoh masukan :
    Adi 12 Mei
    Budi 13 Mei
    Cahya 9 Juli
    Dani 12 Mei
    Eko 9 Juli
    */
    
    return 0;
}

