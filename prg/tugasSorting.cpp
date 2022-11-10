#include <iostream>
using namespace std;

//Muhammad Irfan_Kelas PRG8_Prodi Ilmu Komputer
//NIM : 21/474436/PA/20484

void tukar(int *data1, int *data2){
    int temp=*data1;
    *data1=*data2;
    *data2=temp;
}

int *selection_asc(int max, int sel_asc[]){
    cout<<"Sorting dengan selection sort secara ascending: ";
    int podium=0;
    for(podium; podium<max-1; podium++){
        int token=podium;
        for(int j=podium+1; j<max; j++){
            if(sel_asc[j]<sel_asc[token]){
                token=j;
            }
        }
        tukar(&sel_asc[token], &sel_asc[podium]);
    }
    return sel_asc;
}

int *selection_desc(int max, int sel_desc[]){
    cout<<"Sorting dengan selection sort secara descending: ";
    int podium=0;
    for(podium; podium<max-1; podium++){
        int token=podium;
        for(int j=podium+1; j<max; j++){
            if(sel_desc[j]>sel_desc[token]){
                token=j;
            }
        }
        tukar(&sel_desc[token], &sel_desc[podium]);
    }
    return sel_desc;
}

int *bubble_asc(int max, int bu_asc[]){
    cout<<"Sorting dengan bubble sort secara ascending: ";
    bool tukaran;
    do{
        tukaran=0;
        for(int i=0; i<max-1; i++){
            if(bu_asc[i]>bu_asc[i+1]){
                tukar(&bu_asc[i], &bu_asc[i+1]);
            }
            tukaran=1;
        }
        max--;
    }while(tukaran);
    return bu_asc;
}

int *bubble_desc(int max, int bu_desc[]){
    cout<<"Sorting dengan bubble sort secara descending: ";
    bool tukaran;
    do{
        tukaran=0;
        for(int i=0; i<max-1; i++){
            if(bu_desc[i]<bu_desc[i+1]){
                tukar(&bu_desc[i], &bu_desc[i+1]);
            }
            tukaran=1;
        }
        max--;
    }while(tukaran);
    return bu_desc;
}

int *insertion_asc(int max, int in_asc[]){
    cout<<"Sorting dengan insertion sort secara ascending: ";
    for(int i=1; i<max; i++){
        do{
            if(in_asc[i]<in_asc[i-1]){
                tukar(&in_asc[i], &in_asc[i-1]);
            }
            else break;
            i--;
        }while(i>0);
    }
    return in_asc;
}

int *insertion_desc(int max, int in_desc[]){
    cout<<"Sorting dengan insertion sort secara descending: ";
    for(int i=1; i<max; i++){
        do{
            if(in_desc[i]>in_desc[i-1]){
                tukar(&in_desc[i], &in_desc[i-1]);
            }
            else break;
            i--;
        }while(i>0);
    }
    return in_desc;
}

int main (){
    int ukurandata;
    cout<<"Masukkan jumlah data: "; cin>>ukurandata;
    int data[ukurandata];
    cout<<"Masukkan semua data (pisahkan dengan spasi): ";
    for(int i=0; i<ukurandata; i++){
        cin>>data[i];
    }
    
    cout<<"Opsi sorting: ";
    cout<<"\n1. Selection sort (ascending) \n2. Selection sort (descending)";
    cout<<"\n3. Bubble sort (ascending) \n4. Bubble sort (descending)";
    cout<<"\n5. Insertion sort (ascending) \n6. Insertion sort (descending)";
    
    int *dataurut;
    int opsi;
    cout<<"\nPilih opsi untuk sorting (1-6): "; cin>>opsi;
    switch(opsi){
        case 1: dataurut=selection_asc(ukurandata, data); break;
        case 2: dataurut=selection_desc(ukurandata, data); break;
        case 3: dataurut=bubble_asc(ukurandata, data); break;
        case 4: dataurut=bubble_desc(ukurandata, data); break;
        case 5: dataurut=insertion_asc(ukurandata, data); break;
        case 6: dataurut=insertion_desc(ukurandata, data); break;
        default : cout<<"Pilih angka 1 s.d. 6, sesuai keinginan jenis sorting";
    }
    
    cout<<endl;
    for(int i=0; i<ukurandata; i++){
        cout<<dataurut[i]<<" ";
    }
    
    return 0;
}
//Program siap dijalankan.

/*
contoh input:
6
2 5 6 3 1 4

contoh input:
15
8 3 10 4 2 7 9 1 15 14 5 13 6 11 12
*/