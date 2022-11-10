#include<iostream>
using namespace std;

int main(){
    long beliBahan, sewaWarung, gajiKaryawan, bayarListrik;
    cout<<"Masukan total uang untuk keperluan beli bahan : ";
    cin>>beliBahan;
    cout<<"Masukan total uang untuk keperluan sewa warung : ";
    cin>>sewaWarung;
    cout<<"Masukan total uang untuk keperluan gaji karyawan : ";
    cin>>gajiKaryawan;
    cout<<"Masukan total uang untuk keperluan bayar listrik : ";
    cin>>bayarListrik;

    double total;
    total = beliBahan+sewaWarung+gajiKaryawan+bayarListrik;

    cout<<"Total pengeluaran Pak Budi: ";
    cout<<total<<endl;

    double keuntungan = total/10;
    cout<<"\nKeuntungan (10% pengeluaran): ";
    cout<<keuntungan<<endl;
    total += keuntungan;

    cout<<"\nHarga jual setelah diskon : ";
    cout<<total<<endl;

    double diskon = total*15/100;
    cout<<"\nHarga jual sebelum diskon : ";
    cout<<total+diskon<<endl;

    //harga jual setelah diskon adalah harga jual yang sehingga Pak Budi akan menerima keuntungan 10% dari pengeluaran

    return 0;
}
